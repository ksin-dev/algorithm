#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>
#include <cmath>
#include <numeric>
#include <queue>

using namespace std;

class Solution
{
public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
  {
    long E = 1e9 + 7;
    vector<pair<int, int>> pairs;

    for (int i = 0; i < n; i++)
    {
      pairs.push_back({efficiency[i], speed[i]});
    }

    sort(pairs.rbegin(), pairs.rend());
    priority_queue<int, vector<int>, greater<int>> q;
    long long ans = 0, speed_sum = 0;

    for (auto &[e, s] : pairs)
    {
      q.push(s);

      speed_sum += s;
      if (q.size() > static_cast<long unsigned long>(k))
      {
        auto speed = q.top();
        speed_sum -= speed;

        q.pop();
      }

      ans = max(ans, speed_sum * e);
    }
    return ans % E;
  }
};

void case1()
{
  Solution s;
  auto speed = vector<int>{
      2, 10, 3, 1, 5, 8};
  auto efficiency = vector<int>{
      5, 4, 3, 9, 7, 2};

  cout << s.maxPerformance(speed.size(), speed, efficiency, 2) << endl;
}

void case2()
{
  Solution s;
  auto speed = vector<int>{
      2, 10, 3, 1, 5, 8};
  auto efficiency = vector<int>{
      5, 4, 3, 9, 7, 2};

  cout << s.maxPerformance(speed.size(), speed, efficiency, 3) << endl;
}

void case3()
{
  Solution s;
  auto speed = vector<int>{
      2, 10, 3, 1, 5, 8};
  auto efficiency = vector<int>{
      5, 4, 3, 9, 7, 2};

  cout << s.maxPerformance(speed.size(), speed, efficiency, 4) << endl;
}

void case4()
{
  Solution s;
  auto speed = vector<int>{
      2, 8, 2};
  auto efficiency = vector<int>{
      2, 7, 1};

  cout << s.maxPerformance(speed.size(), speed, efficiency, 3) << endl;
}

int main()
{
  case1();
  case2();
  case3();
  case4();
  return 0;
}