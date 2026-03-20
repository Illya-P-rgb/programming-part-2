#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

int main() 
{
  float x = 3.14151617181920;
  std::cout << x << "\n";
  std::cout << std::fixed << x << "\n";
  std::cout << std::scientific << x << "\n";
  std::cout << std::fixed << std::setprecision(2) << x << "\n";
  std::cout << std::fixed << std::setprecision(5) << x << "\n";
  return 0;
}