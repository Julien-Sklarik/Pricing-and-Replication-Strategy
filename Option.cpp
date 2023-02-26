#include <iostream>
#include <cmath>
#include "Option.h"

Option::Option(std::map<std::string, std::string> parameters){
  spot_price = std::stof(parameters["spot_price"]);
  interest_rate = std::stof(parameters["interest_rate"]);
  volatility = std::stof(parameters["volatility"]);
  strike_price = std::stof(parameters["strike_price"]);
  day_of_maturity = std::stof(parameters["day_of_maturity"]);
  month_of_maturity = std::stof(parameters["month_of_maturity"]);
  year_of_maturity = std::stof(parameters["year_of_maturity"]);
  
  pay_off = 0;
  type = 1;
  number_of_simulations = 100000; // We decide to fix the number of simulation for Monte Carlo methods in our program.
}

double Option::periodDiff()
{
  double day = getDayOfMaturity();
  double month = getMonthOfMaturity();
  double year = getYearOfMaturity();
  Date t = Date(day, month, year);
  double diff = t.period_diff();
  return diff;
}

void Option::setStrikePrice(double s){
  strike_price = s;
}

double Option::getStrikePrice() {
  return strike_price;
}

void Option::setVolatility(double v){
  volatility = v;
}

double Option::getVolatility() {
  return volatility;
}

void Option::setSpotPrice(double sp){
  spot_price = sp;
}

double Option::getSpotPrice() {
  return spot_price;
}

void Option::setInterestRate(double i){
  interest_rate = i;
}

double Option::getInterestRate() {
  return interest_rate;
}

void Option::setYearOfMaturity(double y){
  year_of_maturity = y;
}

double Option::getYearOfMaturity() {
  return year_of_maturity;
}

void Option::setMonthOfMaturity(double m){
  month_of_maturity = m;
}

double Option::getMonthOfMaturity() {
  return month_of_maturity;
}

void Option::setDayOfMaturity(double d){
  day_of_maturity = d;
}

double Option::getDayOfMaturity() {
  return day_of_maturity;
}

void Option::setType(int t){
  type = t;
}
        
int Option::getType(){
  return type;
}

void Option::setPayOff(PayOff* p){
  pay_off = p;
}
        
PayOff* Option::getPayOff(){
  return pay_off;
}

void Option::setNumberOfSimulations(int n){
  number_of_simulations = n;
}
        
int Option::getNumberOfSimulations(){
  return number_of_simulations;
}



