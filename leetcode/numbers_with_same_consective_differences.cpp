#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

// link =https://leetcode.com/problems/numbers-with-same-consecutive-differences/
using namespace std;

void print(vector<int> &v)
{
  for (auto i : v)
    cout << i << '\t';
  cout << endl;
}

class Solution
{
public:
  vector<int> numsSameConsecDiff(int n, int k)
  {
    vector<int> v;
    vector<int> st;

    for (int i = 1; i < 10; i++)
    {
      st.push_back(i);
      auto r = getNumber(st, n, k);
      for (auto &s : r)
      {
        v.push_back(std::stoi(s));
      }
      st.pop_back();
    }

    sort(v.begin(), v.end());
    return v;
  }

  vector<string> getNumber(vector<int> &s, int n, int k)
  {
    vector<string> v;

    if (s.size() == n)
    {
      v.push_back(to_string(s.back()));

      return v;
    }

    int less = s.back() - k;
    int more = s.back() + k;
    if (k == 0)
    {
      s.push_back(s.back());
      auto r = getNumber(s, n, k);
      s.pop_back();
      v.insert(v.begin(), r.begin(), r.end());
    }
    else
    {
      if (less >= 0)
      {
        s.push_back(less);
        auto r = getNumber(s, n, k);
        s.pop_back();
        v.insert(v.begin(), r.begin(), r.end());
      }
      if (more < 10)
      {
        s.push_back(more);
        auto r = getNumber(s, n, k);
        s.pop_back();
        v.insert(v.end(), r.begin(), r.end());
      }
    }

    for (int i = 0; i < v.size(); i++)
      v[i] = to_string(s.back()) + v[i];

    return v;
  }
};

int main()
{
  Solution s;

  auto v = s.numsSameConsecDiff(3, 7);
  print(v);
  return 0;
}