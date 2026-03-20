#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

int main() 
{
  int x = 20;
  std::cout << std::dec << "Decimal: " << x << "\n";
  std::cout << std::hex << "Hexadecimal: " << x << "\n";
  std::cout << std::oct << "Octal: " << x << "\n";
  return 0;
}