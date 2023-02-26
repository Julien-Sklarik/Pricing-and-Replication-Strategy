#ifndef COMMAND_DOUBLE_DIGITAL
#define COMMAND_DOUBLE_DIGITAL

#include "Command.h"

class MCCommandDoubleDigital : public Command {
public:
  static float doubleDigital(int number_of_simulations, float s, float r, float sigma, float k_low, float k_up, float t);
  const std::string getName() const override;
  const std::string getDescription() const override;
  bool operator()() override;
};

#endif