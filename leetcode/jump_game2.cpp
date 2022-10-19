#include <iostream>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    if (nums.size() == 1)
      return 0;
    if (nums[0] >= nums.size() - 1)
      return 1;
    int size = nums.size();
    int count = 0;
    int next = nums[0];
    int cur = 0;
    while (next < size)
    {
      int prev = cur;
      cur = next;
      next = cur + nums[cur];
      for (int i = cur; i > prev; i--)
      {
        if (i >= size)
        {
          next = size;
          break;
        }
        next = max(i + nums[i], next);
      }

      cout << next << endl;

      count++;
    }

    cout << cur << " " << next << " " << nums.size() << endl;

    return count;
  }
};

TEST(JumpGame2, Case1)
{
  Solution s;

  vector<int> v = {
      1, 2, 3, 1, 1, 4, 2, 5, 6, 4, 3, 3, 2, 4};
  EXPECT_EQ(s.jump(v), 4);
}

TEST(JumpGame2, Case2)
{
  Solution s;

  vector<int> v = {
      19};
  EXPECT_EQ(s.jump(v), 0);
}

TEST(JumpGame2, Case3)
{
  Solution s;

  vector<int> v = {
      3, 1, 2, 0, 2, 1};
  EXPECT_EQ(s.jump(v), 3);
}

TEST(JumpGame2, Case4)
{
  Solution s;

  vector<int> v = {
      3, 0, 1};
  EXPECT_EQ(s.jump(v), 1);
}

TEST(JumpGame2, Case5)
{
  Solution s;

  vector<int> v = {
      1, 1, 1, 1, 1};
  EXPECT_EQ(s.jump(v), 4);
}

TEST(JumpGame2, Case6)
{
  Solution s;

  vector<int> v = {
      1, 1, 1, 1, 1, 1};
  EXPECT_EQ(s.jump(v), 5);
}

TEST(JumpGame2, Case7)
{
  Solution s;

  vector<int> v = {
      1, 1, 1, 1};
  EXPECT_EQ(s.jump(v), 3);
}

TEST(JumpGame2, Case8)
{
  Solution s;

  vector<int> v = {
      1, 1, 1};
  EXPECT_EQ(s.jump(v), 2);
}

TEST(JumpGame2, Case9)
{
  Solution s;

  vector<int> v = {
      2, 3, 1, 1, 4};
  EXPECT_EQ(s.jump(v), 2);
}