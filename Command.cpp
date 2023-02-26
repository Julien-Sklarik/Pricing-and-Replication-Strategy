#include <cmath>
#include <iostream>
#include <limits>
#include <random>
#include <utility>

#include "Command.h"

/*
This function takes as argument a collection of parameters whose names we know
but not yet the values (or only the default values). It prompts the user for the
value of each parameter.
 */
void Command::askParameters(Command::Parameters &parameters) const {
  for (auto p = parameters.begin(); p != parameters.end(); p++) {
    std::cout << "Enter the " << p->first << ", please : \n"
              << "> ";
    std::string parameter;
    std::getline(std::cin, parameter);
    p->second = parameter;
  }
}

std::ostream &operator<<(std::ostream &os, const Command &cmd) {
  os << cmd.getName() << "\n" << cmd.getDescription() << "\n";
  return os;
}

// Here is an implementation of the Box-Muller algorithm. 
// We use it to generate gaussian random numbers.
double Command::gaussian_box_muller() {
    constexpr double epsilon = std::numeric_limits<double>::epsilon();
    constexpr double two_pi = 2.0 * M_PI;
    // We initialize the random uniform number generator in a range from 0 to 1.
    static std::mt19937 rg(std::random_device{}()); // Here, we use a global variable of type mt19337 called mersenneTwister, because we want to avoid the bad quality of the rand function. 
    // We are therefore using the standard mersenne_twister_engine, seeded with rd().
    static std::uniform_real_distribution<> runif(0.0, 1.0);
    // We create two random numbers. Then, we make sure u1 is greater than epsilon.
    double u1, u2;
    do
    {u1 = runif(rg);}
    while (u1 <= epsilon);
    u2 = runif(rg);
    // We compute only z0, as we want only one gaussian random number. 
    auto z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
    return z0;
}

// Here is the Heaviside step function. 
// It returns 1 when the value is greater or equal to zero and returns zero otherwise.
double Command::heaviside(double value) {
  if (value >= 0) {return 1;} 
  else {return 0;}
}
// It is necessary for the pay-off in this case of a digital option