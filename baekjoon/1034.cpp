#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

void print(vector<vector<bool>> &v)
{
  cout << "##############print############" << endl;
  for (auto &r : v)
  {
    for (auto c : r)
    {
      cout << c << ' ';
    }
    cout << endl;
  }
  cout << "##############end############" << endl;
}

void click(vector<vector<bool>> &v, int idx)
{
  for (int i = 0; i < v.size(); i++)
  {
    v[i][idx] = !v[i][idx];
  }
}

int getCount(vector<vector<bool>> &v)
{
  int count = 0;
  for (auto &c : v)
  {
    bool b = true;
    for (auto r : c)
    {
      b = b && r;
    }
    count += static_cast<int>(b);
  }
  return count;
}

int countingMax(vector<vector<bool>> &v, int K, int start = 0, int count = 0)
{
  int m = 0;

  if ((count % 2) == (K % 2))
  {
    m = getCount(v);
  }

  if (count == v[0].size())
    return m;

  cout << (count == v[0].size()) << " " << count << " " << start << endl;

  for (int i = start; i < v[0].size(); i++)
  {
    m = max(countingMax(v, K, i + 1, count), m);
    click(v, i);
    // print(v);

    m = max(countingMax(v, K, i + 1, count + 1), m);
    click(v, i);
    // print(v);
  }

  return m;
}

int main()
{
  int N = 0, M = 0;
  cin >> N >> M;
  vector<vector<bool>> v(N, vector<bool>(M, false));
  vector<int> rank;
  int K = 0;
  for (auto &r : v)
  {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
      r[i] = s[i] - '0';
    }
  }
  cout << "start" << endl;

  cin >> K;

  cout << countingMax(v, K) << endl;

  return 0;
}
