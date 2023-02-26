#include <iostream>
#include <string>
#include"CommandTest.h"

const std::string CommandTest::getName() const
{
  return "Test command";
}

const std::string CommandTest::getDescription() const
{
  return "This command helps validate the basic operation of the program.\nThe validation_code to make it work is \"ok\". \nOtherwise, it must send an error without making the application crash.";
}

bool CommandTest::operator()()
{ 
  std::cout << "The command operator() has just been called." << std::endl;

  Parameters parameters {{"validation_code", ""}};
  Command::askParameters(parameters);
  if (parameters["validation_code"] == "ok")
  {
    std::cout << "The command worked." << std::endl;
  } 
  else
  {
    std::cerr << "The command only works if you enter \"ok\"." << std::endl;
    return false;
  }
  return true;
}