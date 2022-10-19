#include <iostream>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
  vector<int> cached;
  bool canJump(vector<int> &nums)
  {
    cached.assign(nums.size() + 1, -1);

    return solve(nums, 0);
  }

  bool solve(vector<int> &nums, int i)
  {
    if (i >= nums.size() - 1)
      return true;

    if (cached[i] != -1)
      return cached[i];
    if (nums[i] == 0)
      return nums[i] = false;

    int count = nums[i];
    while (count or !(cached[i] = solve(nums, i + count)))
      count--;

    return cached[i];
  }
};

TEST(JumpGame, Case1)
{
  Solution s;

  vector<int> v = {
      1, 3, 3, 4, 0};
  EXPECT_TRUE(s.canJump(v));
}

TEST(JumpGame, Case2)
{
  Solution s;

  vector<int> v = {
      19};
  EXPECT_TRUE(s.canJump(v));
}

TEST(JumpGame, Case3)
{
  Solution s;

  vector<int> v = {
      1, 0, 1};
  EXPECT_FALSE(s.canJump(v));
}

TEST(JumpGame, Case4)
{
  Solution s;

  vector<int> v = {
      3, 0, 1};
  EXPECT_TRUE(s.canJump(v));
}

TEST(JumpGame, Case5)
{
  Solution s;

  vector<int> v = {
      2, 1, 0, 0};
  EXPECT_FALSE(s.canJump(v));
}