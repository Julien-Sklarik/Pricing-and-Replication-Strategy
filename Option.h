#ifndef OPTION_H
#define OPTION_H

#include "Payoff.h"
#include <iostream>
#include <map>
#include <string>
#include "Date.h"

class Option // This class members correspond to options object. 
{
    private:
        double strike_price, volatility, spot_price, interest_rate, day_of_maturity, month_of_maturity, year_of_maturity;
        int type, number_of_simulations;
        PayOff* pay_off;

    public:
        Option(std::map<std::string, std::string> parameters);

        double periodDiff();

        void setStrikePrice(double);
        double getStrikePrice();

        void setVolatility(double);
        double getVolatility();

        void setSpotPrice(double);
        double getSpotPrice();

        void setInterestRate(double);
        double getInterestRate();

        void setYearOfMaturity(double);
        double getYearOfMaturity();

        void setMonthOfMaturity(double);
        double getMonthOfMaturity();

        void setDayOfMaturity(double);
        double getDayOfMaturity();

        void setType(int);
        int getType();

        void setPayOff(PayOff*);
        PayOff* getPayOff();

        void setNumberOfSimulations(int);
        int getNumberOfSimulations();
        

};

#endif