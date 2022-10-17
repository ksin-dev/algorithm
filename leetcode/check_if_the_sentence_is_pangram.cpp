#include <iostream>
#include <string>
#include <algorithm>
#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
  bool checkIfPangram(string sentence)
  {
    sort(sentence.begin(), sentence.end());

    char ch = 'a';
    int index = 0;

    while (index < sentence.size() && ch == sentence[index])
    {
      if (ch == 'z' && ch == sentence[index])
        return true;
      while (ch == sentence[index])
        index++;
      ch++;
    }

    return false;
    ;
  }
};

TEST(CheckIfTheSentenceIsPangram, Case1)
{
  Solution s;
  string str = "vklcfidlkejriwerwewe";
  auto res = s.checkIfPangram(str);

  EXPECT_FALSE(res);
}

TEST(CheckIfTheSentenceIsPangram, Case2)
{
  Solution s;

  string str = "abcdefghijklmnopqrstuvwxyz";

  auto res = s.checkIfPangram(str);

  EXPECT_TRUE(res);
}