#include <iostream>
#include <stdlib.h>

#include "BSMCommandCall.h"
#include "BSMCommandPut.h"
#include "MCCommandDigitalCall.h"
#include "MCCommandDigitalPut.h"
#include "MCCommandDoubleDigital.h"
#include "PDECommandCall.h"
#include "PDECommandPut.h"
#include "Command.h"
#include "CommandTest.h"
#include "Console.h"
#include "MCasiancall.h"
#include "MCasianput.h"



Console::Console() // or "Console(const std::string file_name)" if we have data,
                   // with the following: "data{Data(file_name)}" if we add a
                   // class named Data
{
  std::function<void(Console *)> command_quit = &Console::quit;
  std::function<void(Console *)> command_help = &Console::help;

  auxiliary_command["quit"] = command_quit;
  auxiliary_command["help"] = command_help;

  CommandTest *command_test = new CommandTest;
  BSMCommandPut *command_put = new BSMCommandPut;
  BSMCommandCall *command_call = new BSMCommandCall;
  MCCommandDigitalCall *command_digital_call = new MCCommandDigitalCall;
  MCCommandDigitalPut *command_digital_put = new MCCommandDigitalPut;
  MCCommandDoubleDigital *command_double_digital = new MCCommandDoubleDigital;
  PDECommandCall *pde_command_call = new PDECommandCall;
  PDECommandPut *pde_command_put = new PDECommandPut;
  mcasiancall *command_asian_call = new mcasiancall;
mcasianput *command_asian_put = new mcasianput;
  // We could use smart pointers here to avoid having to deal with the use of
  // delete.

  pricing_command["test"] = command_test;
  pricing_command["BSMput"] = command_put;
  pricing_command["BSMcall"] = command_call;
  pricing_command["DigitalCall"] = command_digital_call;
  pricing_command["DigitalPut"] = command_digital_put;
  pricing_command["DoubleDigital"] = command_double_digital;
  pricing_command["PDEcall"] = pde_command_call;
  pricing_command["PDEput"] = pde_command_put;
  pricing_command["AsianCall"] = command_asian_call;
  pricing_command["AsianPut"] = command_asian_put;
}

void Console::run() {
  end = false;
  // Test if the user asked to quit (or if the program is tired of working).
  while (!end) {
    std::cout << "\nCommands:\n\n quit\n help\n test\n BSMput\n BSMcall \n DigitalCall \n DigitalPut \n DoubleDigital \n PDEcall \n PDEput \n AsianCall \n AsianPut \n\n";
    // We display a request (a "prompt") a command to the user:
    std::cout << "Enter your command: \n"
              << "> ";
    // Command recovery:
    std::string command;
    std::getline(std::cin, command);

    // This test is used to check if the input is a mistake (like if the user
    // has typed "enter", for instance):
    if (!std::cin)
      break;

    std::map<std::string, Command *>::iterator cmd =
        pricing_command.find(command);
    if (cmd == pricing_command.end()) {
      std::map<std::string, std::function<void(Console *)>>::iterator cmd2 =
          auxiliary_command.find(command);
      if (cmd2 == auxiliary_command.end()) {
        std::cout << "This command does not exist." << std::endl;
      } else {
        auto fonction_command = auxiliary_command[command];
        fonction_command(this);
      }
    } else {
      executeCommand(*pricing_command[command]);
    }
  }
  delete pricing_command["test"];
  delete pricing_command["BSMput"];
  delete pricing_command["BSMcall"];
  delete pricing_command["DigitalCall"];
  delete pricing_command["DigitalPut"];
  delete pricing_command["DoubleDigital"];
  delete pricing_command["PDEcall"];
  delete pricing_command["PDEput"];
  delete pricing_command["asiancall"];
  delete pricing_command["asianput"];
  
  // As we use dynamic allocation, you have to think about freeing the memory
  // space "manually".
  exit(0);
}

void Console::executeCommand(Command &command) {
  std::cout << "\n Command name: " << command.getName()
            << "\n\n Command description: " << command.getDescription()
            << std::endl;

  bool resultat = command(); // Or "command(data);" if we use data
  if (resultat == false) {
    std::cerr << "The command encountered an error during execution."
              << std::endl;
  }
}

void Console::quit() {
  std::cout << "Thank you for using our pricing program!" << std::endl;
  end = true;
}

void Console::help() {
  std::cout << "\nHello, this pricing program responds to different commands "
               "that you can enter manually.\nBelow you will find the list of "
               "available commands, followed by their name to use them and by "
               "a short description:\n\n"
            << std::endl;

  for (std::pair<std::string, Command *> command : pricing_command) {
    std::cout << "\n " << command.second->getName() << "\n "
              << "Name: " << command.first << "\n "
              << command.second->getDescription() << "\n"
              << std::endl;
  }
  std::cout << "\n \n You also have the following auxiliary commands which "
               "participate in the operation of the program and which work as "
               "their (recognized) name indicates:"
            << std::endl;

  for (std::pair<std::string, std::function<void(Console *)>> command :
       auxiliary_command) {
    std::cout << "\n " << command.first << "\n" << std::endl;
  }
}