#include <iostream>
#include <limits>
#include <cmath>

#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int maximum = numeric_limits<int>::min();
    int high = numeric_limits<int>::min();
    for (auto num : nums)
    {
      if (high < num && high < 0)
      {
        high = num;
      }
      else
      {
        high += num;
      }

      maximum = max(maximum, high);
    }

    return maximum;
  }
};

TEST(MaximumSubArray, Case1)
{
  Solution s;
  vector<int> v = {
      -2, 1, -3, 4, -1, 2, 1, -5, 4};

  auto res = s.maxSubArray(v);

  EXPECT_EQ(res, 6);
}

TEST(MaximumSubArray, Case2)
{
  Solution s;
  vector<int> v = {
      1};

  auto res = s.maxSubArray(v);

  EXPECT_EQ(res, 1);
}

TEST(MaximumSubArray, Case3)
{
  Solution s;
  vector<int> v = {
      5, 4, -1, 7, 8};

  auto res = s.maxSubArray(v);

  EXPECT_EQ(res, 23);
}

TEST(MaximumSubArray, Case4)
{
  Solution s;
  vector<int> v = {
      -2, -1, -5, 1, 0, -5, 3, 2};

  auto res = s.maxSubArray(v);

  EXPECT_EQ(res, 5);
}

TEST(MaximumSubArray, Case5)
{
  Solution s;
  vector<int> v = {
      1, 2};

  auto res = s.maxSubArray(v);

  EXPECT_EQ(res, 3);
}

TEST(MaximumSubArray, Case6)
{
  Solution s;
  vector<int> v = {
      5, -1, -2, -4, 6, -1};

  auto res = s.maxSubArray(v);

  EXPECT_EQ(res, 6);
}

TEST(MaximumSubArray, Case7)
{
  Solution s;
  vector<int> v = {
      5, -1, -2, -1, 6, -1};

  auto res = s.maxSubArray(v);

  EXPECT_EQ(res, 7);
}