#include <cmath>
#include <iostream>
#include <limits>
#include <random>
#include <utility>

#include "MCCommandDoubleDigital.h"
#include "Option.h"

const std::string MCCommandDoubleDigital::getName() const {
  return "Command giving the valuation of a digital call";
}

const std::string MCCommandDoubleDigital::getDescription() const {
  return "This command gives the valutation of a digital call by using "
         "the Monte Carlo Method.";
}

float MCCommandDoubleDigital::doubleDigital(int number_of_simulations, float s, float r, float sigma, float k_low, float k_up, float t) 
{
  float s_adjust = s * exp(t*(r-0.5*sigma*sigma));
  float s0 = 0.;
  float payoff_sum = 0.;
  float payoff_double = 0.;

  for (int i = 0; i<number_of_simulations; i++) {
    float gauss_bm = MCCommandDoubleDigital::gaussian_box_muller();
    s0 = s_adjust * exp(sqrt(sigma*sigma*t)*gauss_bm);
    if (s0 >= k_low && s0 <= k_up) {
    payoff_double = 1.;} 
    else {payoff_double = 1.;}
    payoff_sum += payoff_double;
  }
  return (payoff_sum / static_cast<double>(number_of_simulations)) * exp(-r*t);
}

bool MCCommandDoubleDigital::operator()() {
  Parameters parameters{{"spot_price", ""},
                        {"interest_rate", ""},
                        {"volatility", ""},
                        {"strike_price_lower_bound", ""},
                        {"strike_price_upper_bound", ""},
                        {"day_of_maturity", ""}, 
                        {"month_of_maturity", ""}, 
                        {"year_of_maturity", ""}};

  MCCommandDoubleDigital::askParameters(parameters);
  parameters.insert({"strike_price", "0"});
  Option option(parameters);

  float k_low = std::stof(parameters["strike_price_lower_bound"]);
  float k_up = std::stof(parameters["strike_price_upper_bound"]);
  
  float s = option.getSpotPrice();
  float r = option.getInterestRate();
  float sigma = option.getVolatility();
  int n = option.getNumberOfSimulations();
  float t = option.periodDiff();

  std::cout << "The value of the option is " << doubleDigital(n, s, r, sigma, k_low, k_up, t) << std::endl;
  return true;
}