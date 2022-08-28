#include <iostream>
#include <cmath>
#include <vector>
#include <array>

using namespace std;

array<int, 3> getLess(array<int, 3> &prev, array<int, 3> &current)
{
  array<int, 3> res;

  res[0] = min(prev[1] + current[0], prev[2] + current[0]);
  res[1] = min(prev[2] + current[1], prev[0] + current[1]);
  res[2] = min(prev[0] + current[2], prev[1] + current[2]);

  return res;
}

int main()
{
  int count = 0;

  std::cin >> count;

  vector<array<int, 3>> houses(count);

  for (auto &house : houses)
  {
    std::cin >> house[0] >> house[1] >> house[2];
  }

  array<int, 3> prev(houses[0]);

  for (int i = 1; i < houses.size(); i++)
  {

    prev = getLess(prev, houses[i]);
  }

  std::cout << min(min(prev[0], prev[1]), prev[2]) << endl;
  return 0;
}