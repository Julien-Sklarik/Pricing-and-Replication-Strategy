#ifndef COMMAND_PUT
#define COMMAND_PUT

#include "Command.h"

class BSMCommandPut : public Command
{
  public:

  static float put(float s, float r, float sigma, float k, float t);
  const std::string getName() const override;
  const std::string getDescription() const override;
  bool operator()() override;
};

#endif