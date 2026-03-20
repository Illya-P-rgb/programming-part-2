#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() 
{
  int x;
  float y;
  string z;
  string w;
  
  std::cout << "test" << "\n";
  std::cin >> x;
  std::cin >> y;
  std::cin >> z;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, w);
  
  std::cout << x << "\n";
  std::cout<< y << "\n";
  std::cout << z << "\n";
  std::cout << w << "\n";
  return 0;
}