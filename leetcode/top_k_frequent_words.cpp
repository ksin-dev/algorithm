#include <iostream>
#include "gtest/gtest.h"
#include <map>
#include <queue>

using namespace std;
using string_counter = pair<string, int>;
struct pair_less_count
{
  bool operator()(string_counter &x, string_counter &y)
  {
    if (x.second == y.second)
      return x.first > y.first;
    else
      return x.second < y.second;
  }
};

class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    priority_queue<string_counter, vector<string_counter>, pair_less_count> q;
    string s;

    vector<string> res;
    int count = 0;
    sort(words.begin(), words.end());

    for (auto &str : words)
    {
      if (count == 0 || s == str)
      {
        count++;
      }
      else
      {
        q.push(make_pair(s, count));
        count = 1;
      }
      s = str;
    }
    q.push(make_pair(s, count));

    while (k--)
    {
      res.push_back(q.top().first);
      q.pop();
    }
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