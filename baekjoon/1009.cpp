#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int count = 0;
  long long a = 0, b = 0;

  std::cin >> count;
  while (count--)
  {
    std::cin >> a >> b;
    long long mod = 1;
    while (b--)
    {
      mod = (mod * a) % 10;
    }

    std::cout << (mod == 0 ? 10 : mod) << std::endl;
  }
  return 0;
}