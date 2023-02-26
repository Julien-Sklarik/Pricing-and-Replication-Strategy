#include <cmath>
#include <iostream>

#include "PDECommandCall.h"
#include "Option.h"
#include "PDEparams.h"
#include "Payoff.h"
#include "PDE.h"
#include "FDM.h"

const std::string PDECommandCall::getName() const {
  return "Command giving the valuation of a call by Partial Differential Equtions";
}

const std::string PDECommandCall::getDescription() const {
  return "This command gives the valutation of a call after entering "
         "parameters of option and FDM discretisation parameters by using "
         "the Black Scholes Merton solution by Partial Differential Equations.";
};
double PDECommandCall::pdecall(double s, double r, double sigma, double k,
                        double T, double x_dom, unsigned long J , double t_dom,  unsigned long N ) // To complete
{
 return 0;
};

bool PDECommandCall::operator()() {
  Parameters parameters{{"spot_price", ""},
                        {"interest_rate", ""},
                        {"volatility", ""},
                        {"strike_price", ""},
                        {"day_of_maturity", ""}, 
                        {"month_of_maturity", ""}, 
                        {"year_of_maturity", ""},
                        {"spatial_differencing_points", ""},
                        {"temporal_differencing_points", ""}};

  PDECommandCall::askParameters(parameters);
  Option option(parameters);

  float s = option.getSpotPrice();
  float r = option.getInterestRate();
  float sigma = option.getVolatility();
  float k = option.getStrikePrice();
  float t = option.periodDiff();
  option.setType(1);
  pde_params pde_params(parameters);
  // FDM discretisation parameters
  double x_dom = option.getSpotPrice(); 
  double J = pde_params.spatial_differencing_points;         // Number of spatial differencing points
  double t_dom = t;         // Time period as for the option
  double N = pde_params.temporal_differencing_points;       // Number of temporal differencing points

  // Create the PayOff and Option objects
  PayOff* pay_off_call = new PayOffCall(k);
  option.setPayOff(pay_off_call);

  // Create the PDE and FDM objects
  BlackScholes* bs_pde = new BlackScholes(option);
  FDMEulerExplicit fdm_euler(x_dom, J, t_dom, N, bs_pde);

  // Run the FDM solver
  fdm_euler.step_march();

  std::cout << "To get a graph, please call a 'display.py' file. "  << std::endl;

  // Delete the PDE, PayOff and Option objects
  delete bs_pde;
  delete pay_off_call;
  
  return true;
}