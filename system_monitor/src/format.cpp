#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
  
  char formatted_time[10];
  int h = seconds/3600;
  int m = (seconds%3600)/60;
  int s = (seconds%3600)%60; 
  sprintf(formatted_time, "%.2d:%.2d:%.2d", h, m, s);
  return formatted_time; }