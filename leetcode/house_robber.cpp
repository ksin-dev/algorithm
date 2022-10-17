#include <iostream>
#include <vector>
#include <cmath>
#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
  vector<int> visited;
  int rob(vector<int> &nums)
  {
    visited.assign(nums.size() + 1, -1);

    return max(solve(nums, 0), solve(nums, 1));
  }

  int solve(vector<int> &nums, int start)
  {
    int pre = 0, cur = 0;

    for (int i = start; i < nums.size(); i++)
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
      2, 7, 9, 3, 1};

  auto res = s.rob(v);

  EXPECT_EQ(res, 12);
}

TEST(HouseRobber, Case3)
{
  Solution s;
  vector<int> v = {
      1};

  auto res = s.rob(v);

  EXPECT_EQ(res, 1);
}

TEST(HouseRobber, Case4)
{
  Solution s;
  vector<int> v = {
      2, 7, 9, 3, 1, 4};

  auto res = s.rob(v);

  EXPECT_EQ(res, 15);
}

TEST(HouseRobber, Case5)
{
  Solution s;
  vector<int> v = {
      2, 7, 9, 3, 1, 4, 6};

  auto res = s.rob(v);

  EXPECT_EQ(res, 18);
}