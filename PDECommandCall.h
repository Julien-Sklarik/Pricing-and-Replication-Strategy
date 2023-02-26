#ifndef PDE_COMMAND_CALL
#define PDE_COMMAND_CALL

#include "Command.h"

class PDECommandCall : public Command {
public:
  static double pdecall(double s, double r, double sigma, double k,
                        double T, double x_dom, unsigned long J , double t_dom,  unsigned long N );
  const std::string getName() const override;
  const std::string getDescription() const override;
  bool operator()() override;
};

#endif