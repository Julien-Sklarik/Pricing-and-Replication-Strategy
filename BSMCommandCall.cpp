#include <cmath>
#include <iostream>

#include "BSMCommandCall.h"
#include "Option.h"


const std::string BSMCommandCall::getName() const {
  return "Command giving the valuation of a call";
}

const std::string BSMCommandCall::getDescription() const {
  return "This command gives the valutation of a call after entering "
         "parameters like the strike price and the interest rate by using "
         "the Black Scholes Merton equation.";
}

float BSMCommandCall::call(float s, float r, float sigma, float k,
                        float t) // To complete
{
  float num = log(s / k) + t* (r + sigma * sigma / 2);
  float denom = sigma * sqrt(t);
  float d1 = num / denom;
  float d2 = d1 - denom;
  
  float Nd1=0.5 * erfc(-d1 * sqrt(0.5));
  float Nd2=0.5 * erfc(-d2 * sqrt(0.5));

  
  // We put 1 in the meanwhile.
  return -exp(-r * t) * k * Nd2 + s * Nd1;
};

bool BSMCommandCall::operator()() {
  Parameters parameters{{"spot_price", ""},
                        {"interest_rate", ""},
                        {"volatility", ""},
                        {"strike_price", ""},
                        {"day_of_maturity", ""}, 
                        {"month_of_maturity", ""}, 
                        {"year_of_maturity", ""}};

  BSMCommandCall::askParameters(parameters);
  Option option(parameters);

  float s = option.getSpotPrice();
  float r = option.getInterestRate();
  float sigma = option.getVolatility();
  float k = option.getStrikePrice();
  float t = option.periodDiff();

  std::cout << "The value of the option is " << call(s, r, sigma, k, t) << std::endl;
  return true;
}