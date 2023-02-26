#include <cmath>
#include <iostream>
#include <limits>
#include <random>
#include <utility>

#include "MCCommandDigitalPut.h"
#include "Option.h"

const std::string MCCommandDigitalPut::getName() const {
  return "Command giving the valuation of a digital put";
}

const std::string MCCommandDigitalPut::getDescription() const {
  return "This command gives the valutation of a digital put by using "
         "the Monte Carlo Method.";
}

float MCCommandDigitalPut::digitalPut(int number_of_simulations, float s, float r, float sigma, float k, float t) 
{
  double s_adjust = s * exp(t*(r-0.5*sigma*sigma));
  double s0 = 0.;
  double payoff_sum = 0.;

  for (int i = 0; i<number_of_simulations; i++) {
    double gauss_bm = MCCommandDigitalPut::gaussian_box_muller();
    s0 = s_adjust * exp(sqrt(sigma*sigma*t)*gauss_bm);
    payoff_sum += MCCommandDigitalPut::heaviside(k - s0);
  }
  return (payoff_sum / static_cast<double>(number_of_simulations)) * exp(-r*t);
}

bool MCCommandDigitalPut::operator()() {
  Parameters parameters{{"spot_price", ""},
                        {"interest_rate", ""},
                        {"volatility", ""},
                        {"strike_price", ""},
                        {"day_of_maturity", ""}, 
                        {"month_of_maturity", ""}, 
                        {"year_of_maturity", ""}};

  MCCommandDigitalPut::askParameters(parameters);
  Option option(parameters);

  float s = option.getSpotPrice();
  float r = option.getInterestRate();
  float sigma = option.getVolatility();
  float k = option.getStrikePrice();
  int n = option.getNumberOfSimulations();
  float t = option.periodDiff();

  std::cout << "The value of the option is " << digitalPut(n, s, r, sigma, k, t) << std::endl;
  return true;
}