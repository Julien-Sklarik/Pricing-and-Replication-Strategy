#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cmath>
#include <ctime>

class Date
{    
    public:
        int year, month, day;
        Date();
        Date(int day, int month, int year);
        double period_diff();  
};

#endif