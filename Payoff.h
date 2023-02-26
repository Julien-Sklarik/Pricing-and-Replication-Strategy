#ifndef PAY_OFF
#define PAY_OFF

#include <algorithm> // Include to use max function

class PayOff {
 public:
  PayOff(); // constructor
  virtual ~PayOff() {}; //  destructor

  // We use overloaded operator to make a Payoff a functional object
  virtual double operator() (const double& S) const = 0;};

class PayOffCall : public PayOff {
 private:
  double K; // Strike 
  public:
  PayOffCall(const double& K_); // constructor
  virtual ~PayOffCall() {}; //  destructor
  // This function is not pure-virtual 
  virtual double operator() (const double& S) const; };

// do the same for put

class PayOffPut : public PayOff {
 private:
  double K; // Strike
  public:
  PayOffPut(const double& K_); // constructor
  virtual ~PayOffPut() {};//  destructor
  virtual double operator() (const double& S) const;};

#endif