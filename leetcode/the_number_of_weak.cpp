#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
  if (a[0] != b[0])
    return a[0] > b[0];
  return a[1] < b[1];
}

void print(vector<vector<int>> &v)
{
  for (auto &item : v)
  {
    cout << "[" << item[0] << "," << item[1] << "]"
         << "\t";
  }

  cout << endl;
}

class Solution
{
public:
  int numberOfWeakCharacters(vector<vector<int>> &properties)
  {
    sort(properties.begin(), properties.end(), cmp);
    int count = 0;
    int maxDefense = numeric_limits<int>::min();

    for (auto &p : properties)
    {
      if (p[1] < maxDefense)
        count++;
      else
        maxDefense = p[1];
    }

    return count;
  }
};

void case1()
{
  Solution s;
  auto v = vector<vector<int>>{
      vector<int>{5, 5},
      vector<int>{6, 3},
      vector<int>{3, 6}};

  auto res = s.numberOfWeakCharacters(v);
  cout << res << endl;
}

void case2()
{
  Solution s;
  auto v = vector<vector<int>>{
      vector<int>{2, 2},
      vector<int>{3, 3}};

  auto res = s.numberOfWeakCharacters(v);
  cout << res << endl;
}

void case3()
{
  Solution s;
  auto v = vector<vector<int>>{
      vector<int>{1, 5},
      vector<int>{10, 4},
      vector<int>{4, 3}};

  auto res = s.numberOfWeakCharacters(v);
  cout << res << endl;
}
int main()
{
  case1();
  case2();
  case3();
  return 0;
}
