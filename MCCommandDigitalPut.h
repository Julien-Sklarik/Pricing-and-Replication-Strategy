#ifndef COMMAND_DIGITAL_PUT
#define COMMAND_DIGITAL_PUT

#include "Command.h"

class MCCommandDigitalPut : public Command {
public:
  static float digitalPut(int number_of_simulations, float s, float r, float sigma, float k, float t);
  const std::string getName() const override;
  const std::string getDescription() const override;
  bool operator()() override;
};

#endif