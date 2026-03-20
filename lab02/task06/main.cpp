#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

int main() 
{
  std::ofstream file ("file.txt");
  std::ifstream file2("file.txt");
  file << "Index" << std::setw(10) << "Name" << std::setw(10) << "Value" << std::setw(10) << "FPvalue" << "\n"; 
  file << std::setw(3) << "1" << std::setw(12) << "test1" << std::setw(8) << "17" << std::setw(10) << "2.7" << "\n"; 
  file << std::setw(3) << "2" << std::setw(12) << "test2" << std::setw(8) << "18" << std::setw(10) << "2.1" << "\n"; 
  file << std::setw(3) << "3" << std::setw(12) << "test3" << std::setw(8) << "19" << std::setw(10) << "2.5" << "\n";
  file << std::setw(3) << "4" << std::setw(12) << "test4" << std::setw(8) << "20" << std::setw(10) << "2.6" << "\n";
  file << std::setw(3) << "5" << std::setw(12) << "test5" << std::setw(8) << "21" << std::setw(10) << "2.0" << "\n"; return 0;
  file.close();
  
  
  return 0;
}