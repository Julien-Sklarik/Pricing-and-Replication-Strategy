#ifndef COMMAND_CALL
#define COMMAND_CALL

#include "Command.h"

class BSMCommandCall : public Command {
public:
  static float call(float s, float r, float sigma, float k, float t);
  const std::string getName() const override;
  const std::string getDescription() const override;
  bool operator()() override;
};

#endif