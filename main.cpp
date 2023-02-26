#include <iostream>
#include <chrono>
#include <iterator>
#include <algorithm>

#include "Console.h"

// Formatting for dates: (we will have to deal with that)
// %d : day, %m : month, %Y : year, %H : hour, %M : minutes
const char* FORMAT_TIMESTAMP = "%d/%m/%Y %Hh%M";

int main()
{
	
//Console console{"data.csv"}; We could add our data file as an argument, if we have data that we want to use.
Console console{};
console.run();
}