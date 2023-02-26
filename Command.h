#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>

// #include "Data.h"

class Command
{
protected:

  using Parameters = std::map<std::string, std::string>;
	void askParameters(Parameters& parameters) const;

  // The following static function are usefull for Monte Carlo methods.
  static double heaviside(double value); 
  static double gaussian_box_muller();

public:
  virtual ~Command() = default; // We want the actual object's destructor to be called when we use delete with dynamic allocation, hence the usefulness of this line.
  
  // The following three methods are pure virtual. They will be defined in the child classes.
  virtual const std::string getName() const = 0;
  // The Command class is therefore abstract.
  virtual const std::string getDescription() const = 0;
  virtual bool operator()() = 0; // with data it would be: "operator()(const Data& data)"

  friend std::ostream& operator << (std::ostream& os, const Command& cmd); // Display operator.
};


#endif