#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <array>
#include <algorithm>

using namespace std;

class Solution
{
public:
  array<array<int, 11>, 301> cached;
  int minDifficulty(vector<int> &jobDifficulty, int d)
  {
    if (jobDifficulty.size() < d)
      return -1;
    for (auto &arr : cached)
    {
      arr.fill(-1);
    }
    auto res = solve(jobDifficulty, 0, d);
    if (res < 0)
      return -1;

    return res;
  }

  int solve(vector<int> &jobDifficulty, int index, int d)
  {
    if (cached[index][d] != -1)
      return cached[index][d];
    if (d == 1)
      return *std::max_element(jobDifficulty.begin() + index, jobDifficulty.end());

    int result = numeric_limits<int>::max();
    int maximum = numeric_limits<int>::min();

    for (int i = index; i < jobDifficulty.size() - (d - 1); i++)
    {
      maximum = max(maximum, jobDifficulty[i]);

      result = min(solve(jobDifficulty, i + 1, d - 1) + maximum, result);
    }

    return cached[index][d] = result;
  }
};

int main()
{
  Solution s;
  vector<int> v = {
      186, 398, 479, 206, 885, 423, 805, 112, 925, 656, 16, 932, 740, 292, 671, 360};

  // [  ]

  auto res = s.minDifficulty(v, 4);
  cout << res << endl;
  return 0;
}