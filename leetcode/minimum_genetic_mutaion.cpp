#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
  int minMutation(string start, string end, vector<string> &bank)
  {
    auto found = find(bank.begin(), bank.end(), end);
    if (found == bank.end())
      return -1;
    list<string> remaining;

    for (auto s : bank)
    {
      remaining.push_back(s);
    }

    queue<string> prev;
    prev.push(start);
    int count = 1;
    while (!remaining.empty() && !prev.empty())
    {
      queue<string> next;
      while (!prev.empty())
      {
        auto str = prev.front();
        prev.pop();
        auto it = remaining.begin();
        while (it != remaining.end())
        {
          if (count_not_matched(str, *it) == 1)
          {
            if (*it == end)
              return count;
            next.push(*it);
            it = remaining.erase(it);
          }
          else
          {
            it = std::next(it);
          }
        }
      }
      if (!next.empty())
        count++;
      prev = next;
    }

    return -1;
  }

  int count_not_matched(string s, string e)
  {
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
      count += (s[i] != e[i]);
    }
    return count;
  }
};

TEST(minimumGeneticMutation, case1)
{
  Solution s;
  vector<string> v = {
      "AACCGGTA", "AACCGCTA", "AAACGGTA"};
  auto res = s.minMutation("AACCGGTT", "AAACGGTA", v);

  EXPECT_EQ(res, 2);
}

TEST(minimumGeneticMutation, case2)
{
  Solution s;
  vector<string> v = {
      "AACCGGTA"};
  auto res = s.minMutation("AACCGGTT", "AACCGGTA", v);

  EXPECT_EQ(res, 1);
}

TEST(minimumGeneticMutation, case3)
{
  Solution s;
  vector<string> v = {
      "AAAACCCC", "AAACCCCC", "AACCCCCC"};
  auto res = s.minMutation("AAAAACCC", "AACCCCCC", v);

  EXPECT_EQ(res, 3);
}

TEST(minimumGeneticMutation, case4)
{
  Solution s;
  vector<string> v = {
      "AAAACCCC", "AAACCCCC"};
  auto res = s.minMutation("AAAAACCC", "AACCCCCC", v);

  EXPECT_EQ(res, -1);
}

TEST(minimumGeneticMutation, case5)
{
  Solution s;
  vector<string> v = {
      "AAAAAAAA", "AAAAAAAC", "AAAAAACC", "AAAAACCC", "AAAACCCC", "AACACCCC", "ACCACCCC", "ACCCCCCC", "CCCCCCCA", "CCCCCCCC"};
  auto res = s.minMutation("AAAAAAAA", "CCCCCCCC", v);

  EXPECT_EQ(res, 8);
}

int main()
{
  Solution s;
  vector<string> v = {
      "AAAAAAAA", "AAAAAAAC", "AAAAAACC", "AAAAACCC", "AAAACCCC", "AACACCCC", "ACCACCCC", "ACCCCCCC", "CCCCCCCA", "CCCCCCCC"};
  auto res = s.minMutation("AAAAAAAA", "CCCCCCCC", v);

  EXPECT_EQ(res, 8);

  return 0;
}