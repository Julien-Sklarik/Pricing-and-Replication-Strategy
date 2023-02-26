#include "PDE.h"
#include <math.h>

BlackScholes::BlackScholes(Option option) : option(option) {}

// Diffusion coefficient
// x is the spot price
double BlackScholes::diffusion_coefficient(double t, double x) {
  double sigma = option.getVolatility();
  return sigma*sigma*x*x/2; }

// Convection coefficient
double BlackScholes::convection_coefficient(double t, double x) {
  return (option.getInterestRate())*x; }
// Zero-term coefficient
double BlackScholes::zero_coefficient(double t, double x) {
  return -(option.getInterestRate());}

// Source coefficient
double BlackScholes::source_coefficient(double t, double x) const {
  return 0;}

// Left boundary-condition
double BlackScholes::bound_l(double t, double x) {
  if (option.getType() == 1)
    return 0; // for call
  else return (option.getStrikePrice()) * exp(-(option.getInterestRate()) * (option.periodDiff()-t)); } // for put

// Right boundary-condition 
double BlackScholes::bound_r(double t, double x) {
  // Using call-put parity
  if (option.getType() == 1)
    return (x-(option.getStrikePrice())*exp(-(option.getInterestRate())*    ((option.periodDiff())-t))); // for call
  else return 0;} //for put

// Initial condition
double BlackScholes::init_cond(double x) {
  return option.getPayOff() -> operator()(x);}