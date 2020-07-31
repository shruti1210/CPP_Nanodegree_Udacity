#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid){
	pid_ = pid;}
// TODO: Return this process's ID
int Process::Pid() { 
  return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const { 
    
  string line;
  string key;
  string utime;
  string stime;
  string cutime;
  string cstime;
  string t1, t2, t3, t4 ,t5 ,t6, t7, t8, t9, t10, t11, t12, t13, t14; 
  float total_time;
  
  std::ifstream filestream(LinuxParser::kProcDirectory + to_string(pid_) + LinuxParser::kStatFilename);
  if (filestream.is_open()) {
    std::getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> t1 >> t2 >> t3 >> t4 >> t5 >> t6>> t7 >> t8 >> t9 >> t10 >> t11 >> t12 >> t13 >> t14 >> utime >> stime >> cutime >> cstime;
  }
  if(utime!= "" && stime!= "" && cutime!= "" && cstime!= ""){
  total_time = std::stof(utime) + std::stof(stime) + std::stof(cutime) + std::stof(cstime);}
  try {return (total_time / sysconf(_SC_CLK_TCK))/LinuxParser::UpTime(pid_);}
   catch (const std::invalid_argument& arg) { return 0.0; }
  return 0.0;
 }

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(Pid()); }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(Pid()); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(Pid()); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { 
   //uptime = LinuxParser::UpTime() - (LinuxParser::UpTime(pid_) / sysconf(_SC_CLK_TCK));
  //return uptime; // already done in linux_parser.cpp
  return LinuxParser::UpTime(Pid());}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { return a.CpuUtilization() < this->CpuUtilization();}