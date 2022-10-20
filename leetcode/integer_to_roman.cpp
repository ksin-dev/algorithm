#include <iostream>
#include <map>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

vector<pair<string, int>> v = {
    make_pair("M", 1000),
    make_pair("CM", 900),
    make_pair("D", 500),
    make_pair("CD", 400),
    make_pair("C", 100),
    make_pair("XC", 90),
    make_pair("L", 50),
    make_pair("XL", 40),
    make_pair("X", 10),
    make_pair("IX", 9),
    make_pair("V", 5),
    make_pair("IV", 4),
    make_pair("I", 1)};

class Solution
{
public:
  string intToRoman(int num)
  {
    string s = "";

    for (auto [str, val] : v)
    {
      if (val > num)
        continue;

      int count = num / val;
      num = num % val;

      while (count--)
      {
        s += str;
      }
    }

    return s;
  }
};

TEST(IntegerToRoman, Case1)
{
  Solution s;

  auto res = s.intToRoman(3);

  EXPECT_EQ("III", res);
}

TEST(IntegerToRoman, Case2)
{
  Solution s;

  auto res = s.intToRoman(58);

  EXPECT_EQ("LVIII", res);
}

TEST(IntegerToRoman, Case3)
{
  Solution s;

  auto res = s.intToRoman(1994);

  EXPECT_EQ("MCMXCIV", res);
}

TEST(IntegerToRoman, Case4)
{
  Solution s;

  auto res = s.intToRoman(1844);

  EXPECT_EQ("MDCCCXLIV", res);
}