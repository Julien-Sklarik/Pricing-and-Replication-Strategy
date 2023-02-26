#include <cmath>
#include <iostream>
#include <limits>
#include <random>
#include <utility>

#include "MCCommandDigitalCall.h"
#include "Option.h"

const std::string MCCommandDigitalCall::getName() const {
  return "Command giving the valuation of a digital call";
}

const std::string MCCommandDigitalCall::getDescription() const {
  return "This command gives the valutation of a digital call by using "
         "the Monte Carlo Method.";
}

float MCCommandDigitalCall::digitalCall(int number_of_simulations, float s, float r, float sigma, float k, float t) 
{
  double s_adjust = s * exp(t*(r-0.5*sigma*sigma));
  double s0 = 0.;
  double payoff_sum = 0.;

  for (int i = 0; i<number_of_simulations; i++) {
    double gauss_bm = MCCommandDigitalCall::gaussian_box_muller();
    s0 = s_adjust * exp(sqrt(sigma*sigma*t)*gauss_bm);
    payoff_sum += MCCommandDigitalCall::heaviside(s0 - k);
  }
  return (payoff_sum / static_cast<double>(number_of_simulations)) * exp(-r*t);
}

bool MCCommandDigitalCall::operator()() {
  Parameters parameters{{"spot_price", ""},
                        {"interest_rate", ""},
                        {"volatility", ""},
                        {"strike_price", ""},
                        {"day_of_maturity", ""}, 
                        {"month_of_maturity", ""}, 
                        {"year_of_maturity", ""}};

  MCCommandDigitalCall::askParameters(parameters);
  Option option(parameters);

  float s = option.getSpotPrice();
  float r = option.getInterestRate();
  float sigma = option.getVolatility();
  float k = option.getStrikePrice();
  int n = option.getNumberOfSimulations();
  float t = option.periodDiff();

  std::cout << "The value of the option is " << digitalCall(n, s, r, sigma, k, t) << std::endl;
  return true;
}