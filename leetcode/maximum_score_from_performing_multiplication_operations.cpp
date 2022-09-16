#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <cmath>

using namespace std;

class Solution
{
public:
  vector<map<int, int>> cached;
  vector<int> nums;
  vector<int> multipliers;

  int maximumScore(vector<int> &nums, vector<int> &multipliers)
  {
    this->nums = nums;
    this->multipliers = multipliers;

    for (auto &n : multipliers)
    {
      auto m = map<int, int>();
      cached.push_back(m);
    }

    return maximumScore(0, nums.size() - 1, 0);
  }

  int maximumScore(size_t n_start, size_t n_last, size_t m_start)
  {
    if (m_start == multipliers.size())
      return 0;
    if (n_start == n_last)
      return nums[n_start] * multipliers[m_start];
    if (cached[m_start].find(n_start) != cached[m_start].end())
    {
      return cached[m_start][n_start];
    }

    auto start_val = nums[n_start] * multipliers[m_start] + maximumScore(n_start + 1, n_last, m_start + 1);
    auto last_val = (nums[n_last] * multipliers[m_start]) + maximumScore(n_start, n_last - 1, m_start + 1);

    cached[m_start][n_start] = max(start_val, last_val);

    return cached[m_start][n_start];
  }
};

void case1()
{
  Solution s;

  auto nums = vector<int>{1, 2, 3},
       multipliers = vector<int>{3, 2, 1};

  auto end = prev(nums.end(), 1);
  auto rbe = nums.rbegin();

  cout << s.maximumScore(nums, multipliers) << endl;
}

void case2()
{
  Solution s;

  auto nums = vector<int>{-5, -3, -3, -2, 7, 1},
       multipliers = vector<int>{-10, -5, 3, 4, 6};

  cout << s.maximumScore(nums, multipliers) << endl;
}

int main()
{

  case1();
  case2();

  return 0;
}