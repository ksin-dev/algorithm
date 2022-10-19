#include <iostream>
#include "gtest/gtest.h"
#include <map>

using namespace std;

class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    map<string, int> m;
    vector<pair<string, int>> v;
    vector<string> res;

    for (auto str : words)
    {
      if (m.find(str) == m.end())
        m[str] = 1;
      else
        m[str]++;
    }

    for (auto &p : m)
    {
      v.push_back(p);
    }

    sort(v.begin(), v.end(), [](pair<string, int> &x, pair<string, int> &y)
         {
        if(x.second == y.second) return x.first < y.first;
        else return x.second > y.second; });

    transform(v.begin(), next(v.begin(), k), back_inserter(res), [](pair<string, int> &p)
              { return p.first; });

    return res;
  }
};

TEST(TopKFrequent, Case1)
{
  Solution s;

  vector<string> v = {
      "i",
      "love",
      "leetcode",
      "i",
      "love",
      "coding"};

  auto res = s.topKFrequent(v, 2);
  auto target = vector<string>{
      "i",
      "love"};

  EXPECT_EQ(target, res);
}

TEST(TopKFrequent, Case2)
{
  Solution s;

  vector<string> v = {
      "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};

  auto res = s.topKFrequent(v, 4);
  auto target = vector<string>{
      "the", "is", "sunny", "day"};

  EXPECT_EQ(target, res);
}