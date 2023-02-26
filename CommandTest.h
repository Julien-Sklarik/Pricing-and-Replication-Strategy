#ifndef COMMAND_TEST_H
#define COMMAND_TEST_H
 
#include"Command.h"

class CommandTest: public Command
{
  public:
  
    const std::string getName() const override;
    const std::string getDescription() const override;
    bool operator()() override;
};

#endif