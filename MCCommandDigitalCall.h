#ifndef COMMAND_DIGITAL_CALL
#define COMMAND_DIGITAL_CALL

#include "Command.h"

class MCCommandDigitalCall : public Command {
public:
  static float digitalCall(int number_of_simulations, float s, float r, float sigma, float k, float t);
  const std::string getName() const override;
  const std::string getDescription() const override;
  bool operator()() override;
};

#endif