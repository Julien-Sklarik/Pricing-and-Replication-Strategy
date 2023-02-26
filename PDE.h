#ifndef PDE
#define PDE

#include "Option.h"

// an abstract base class, providing an interface for all subsequent inherited classes
class ConvectionDiffusionPDE {
 public:
  // PDE Coefficients 
  virtual double diffusion_coefficient(double t, double x) = 0;
  virtual double convection_coefficient(double t, double x) = 0;
  virtual double zero_coefficient(double t, double x) = 0;
  virtual double source_coefficient(double t, double x) const = 0;

  // Boundary and initial conditions
  virtual double bound_l(double t, double x) = 0;
  virtual double bound_r(double t, double x) = 0;
  virtual double init_cond(double x) = 0;
};

// Black-Scholes PDE
class BlackScholes : public ConvectionDiffusionPDE {
 public:
  Option option;
  BlackScholes(Option option);
  
  double diffusion_coefficient(double t, double x);
  double convection_coefficient(double t, double x);
  double zero_coefficient(double t, double x);
  double source_coefficient(double t, double x) const;

  double bound_l(double t, double x);
  double bound_r(double t, double x);
  double init_cond(double x);
};

#endif