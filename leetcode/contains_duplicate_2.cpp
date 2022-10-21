#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include "gtest/gtest.h"
using namespace std;

struct pair_compare
{

  bool operator()(pair<int, int> &x, pair<int, int> &y)
  {
    if (x.second == y.second)
      return x.first > y.first;

    return x.second > y.second;
  }
};

class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    if (k == 0)
      return false;
    priority_queue<pair<int, int>, vector<pair<int, int>>, pair_compare> pairs;

    for (int i = 0; i < nums.size(); i++)
    {
      pairs.push(make_pair(i, nums[i]));
    }

    pair<int, int> cur = pairs.top();

    pairs.pop();
    while (!pairs.empty())
    {
      auto next = pairs.top();

      if (abs(cur.first - next.first) <= k and cur.second == next.second)
        return true;

      cur = next;
      pairs.pop();
    }

    return false;
  }
};

TEST(ContainsDuplicate2, Case1)
{
  Solution s;
  vector<int> v = {
      1, 2, 3, 1};
  auto res = s.containsNearbyDuplicate(v, 3);

  EXPECT_EQ(true, res);
}

TEST(ContainsDuplicate2, Case2)
{
  Solution s;
  vector<int> v = {
      1, 0, 1, 1};
  auto res = s.containsNearbyDuplicate(v, 2);

  EXPECT_EQ(true, res);
}

TEST(ContainsDuplicate2, Case3)
{
  Solution s;
  vector<int> v = {
      1, 2, 3, 1, 2, 3};
  auto res = s.containsNearbyDuplicate(v, 2);

  EXPECT_EQ(false, res);
}