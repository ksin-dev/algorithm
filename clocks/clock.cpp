#include <iostream>
#include <vector>
#include <array>
#include <limits>
#include <algorithm>

using namespace std;

array<vector<int>, 10> swiches = {
    vector<int>{0, 1, 2},
    vector<int>{3, 7, 9, 11},
    vector<int>{4, 10, 14, 15},
    vector<int>{0, 4, 5, 6, 7},
    vector<int>{6, 7, 8, 10, 12},
    vector<int>{0, 2, 14, 15},
    vector<int>{3, 14, 15},
    vector<int>{4, 5, 7, 14, 15},
    vector<int>{1, 2, 3, 4, 5},
    vector<int>{3, 4, 5, 9, 13}};

array<int, 16> clocks;
array<bool, 10> used;

void click(vector<int> v)
{
  for (auto sw : v)
  {
    clocks[sw] = clocks[sw] == 12 ? 3 : clocks[sw] + 3;
  }
}

void print()
{
  for (auto use : used)
  {
    cout << use << " ";
  }
  cout << endl;
}

int func(int count = 0)
{
  auto it = std::find_if_not(clocks.begin(), clocks.end(), [](int c) { return c == 12; });
  if (it == clocks.end())
    return count;

  int pick = -1;
  int ret = numeric_limits<int>::max();

  for (int i = 0; i < used.size(); i++)
  {
    if (!used[i])
    {
      pick = i;
      break;
    }
  }
  if (pick == -1)
    return ret;

  used[pick] = true;
  for (int subCnt = 0; subCnt < 4; subCnt++)
  {
    ret = min(ret, func(count + subCnt));
    click(swiches[pick]);
  }
  used[pick] = false;
  return ret;
}

int main()
{
  int c;

  cin >> c;

  while (c--)
  {
    used.fill(false);
    for (auto &clock : clocks)
    {
      cin >> clock;
    }
    int ret = func();

    ret = ret == numeric_limits<int>::max() ? -1 : ret;
    cout << ret << endl;
  }
}