#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <utility>
#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
  vector<pair<int, int>> visited;
  int rob(vector<int> &nums)
  {
    if (nums.size() < 4)
      return *max_element(nums.begin(), nums.end());

    return max(solve(nums, 0, nums.size() - 1), solve(nums, 1, nums.size()));
  }

  int solve(vector<int> &nums, int start, int last)
  {
    int pre = 0, cur = 0;

    for (int i = start; i < last; i++)
    {
      int temp = max(pre + nums[i], cur);
      pre = cur;
      cur = temp;
    }

    return cur;
  }
};

TEST(HouseRobber, Case1)
{
  Solution s;
  vector<int> v = {
      1, 2, 3, 1};

  auto res = s.rob(v);

  EXPECT_EQ(res, 4);
}

TEST(HouseRobber, Case2)
{
  Solution s;
  vector<int> v = {
      2, 3, 2};

  auto res = s.rob(v);

  EXPECT_EQ(res, 3);
}

TEST(HouseRobber, Case3)
{
  Solution s;
  vector<int> v = {
      1, 2, 3};

  auto res = s.rob(v);

  EXPECT_EQ(res, 3);
}

TEST(HouseRobber, Case4)
{
  Solution s;
  vector<int> v = {
      2, 7, 9, 3, 1};

  auto res = s.rob(v);

  EXPECT_EQ(res, 11);
}

TEST(HouseRobber, Case5)
{
  Solution s;
  vector<int> v = {
      2, 7, 9, 3, 1, 4, 6};

  auto res = s.rob(v);

  EXPECT_EQ(res, 16);
}