#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
  int maxLength(vector<string> &arr)
  {
    vector<bitset<26>> bitsets = {
        bitset<26>()};

    int maximum = 0;
    for (auto &s : arr)
    {
      bitset<26> source;
      for (auto ch : s)
        source.set(ch - 'a');

      int count = source.count();
      if (count < s.size())
        continue;

      for (int i = bitsets.size() - 1; i >= 0; i--)
      {
        auto target = bitsets[i];
        if ((source & target).any())
          continue;

        bitsets.push_back(source | target);

        maximum = max(maximum, (int)target.count() + count);
      }
    }
    return maximum;
  }
};

TEST(MaxLength, Case1)
{
  Solution s;
  vector<string> v = {
      "un", "iq", "ue"};

  EXPECT_EQ(s.maxLength(v), 4);

  // EXPECT_EQ(res, 3);
}

TEST(MaxLength, Case2)
{
  Solution s;
  vector<string> v = {
      "cha", "r", "act", "ers"};

  EXPECT_EQ(s.maxLength(v), 6);

  // EXPECT_EQ(res, 3);
}

TEST(MaxLength, Case3)
{
  Solution s;
  vector<string> v = {
      "aa", "bb"};

  EXPECT_EQ(s.maxLength(v), 0);

  // EXPECT_EQ(res, 3);
}
TEST(MaxLength, Case4)
{
  Solution s;
  vector<string> v = {
      "abcdefghijklmnopqrstuvwxyz"};

  EXPECT_EQ(s.maxLength(v), 26);

  // EXPECT_EQ(res, 3);
}
TEST(MaxLength, Case5)
{
  Solution s;
  vector<string> v = {
      "abcdefghu", "ijklmnopqrstuvwxyz"};

  EXPECT_EQ(s.maxLength(v), 18);

  // EXPECT_EQ(res, 3);
}

TEST(MaxLength, Case6)
{
  Solution s;
  vector<string> v = {
      "abcdefghu", "ijklmnopqrstuvwxyzz"};

  EXPECT_EQ(s.maxLength(v), 9);

  // EXPECT_EQ(res, 3);
}

TEST(MaxLength, Case7)
{
  Solution s;
  vector<string> v = {
      "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p"};

  EXPECT_EQ(s.maxLength(v), 16);

  // EXPECT_EQ(res, 3);
}

TEST(MaxLength, Case8)
{
  Solution s;
  vector<string> v = {
      "a", "abc", "d", "de", "def"};

  EXPECT_EQ(s.maxLength(v), 6);

  // EXPECT_EQ(res, 3);
}