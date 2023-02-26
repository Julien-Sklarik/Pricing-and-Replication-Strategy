#include <cmath>
#include <ctime>
#include <iostream>

#include "Date.h"

Date::Date() {}
Date::Date(int day1, int month1, int year1)
{
  day = day1;
  month = month1;
  year = year1;
}

double Date::period_diff()
{  
  
  time_t rawtime;
  struct tm * timeinfo;
   
  
  
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month - 1;
  timeinfo->tm_mday = day;

  return difftime(mktime(timeinfo),rawtime)/(60 * 60 * 24* 365);
}