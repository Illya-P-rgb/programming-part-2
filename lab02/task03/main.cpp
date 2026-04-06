#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

int main() 
{
  int index = 1;
  string name = "test1";
  int value = 17;
  float fp_value = 3.7;
  
  std::cout << "Index" << std::setw(10) << "Name" << std::setw(10) << "Value" << std::setw(10) << "FPvalue" << "\n";
  std::cout << std::setw(3) << index << std::setw(12) << name << std::setw(8) <<  value << std::setw(10) << fp_value << "\n";
  std::cout << std::setw(3) << "2" << std::setw(12) << "test2" << std::setw(8) << "18" << std::setw(10) << "2.1" << "\n";
  std::cout << std::setw(3) << "3" << std::setw(12) << "test3" << std::setw(8) << "19" << std::setw(10) << "2.5" << "\n";
  std::cout << std::setw(3) << "4" << std::setw(12) << "test4" << std::setw(8) << "20" << std::setw(10) << "2.6" << "\n";
  std::cout << std::setw(3) << "5" << std::setw(12) << "test5" << std::setw(8) << "21" << std::setw(10) << "2.0" << "\n";
  return 0;
}