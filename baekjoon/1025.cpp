#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int getSqrt(int number)
{
  auto sq = sqrt(number);
  return pow(sq, 2) == pow((int)sq, 2) ? number : -1;
}

int createMaximum(vector<string> &v, int N, int M, int row, int col)
{
  int m = -1;

  for (int i = -N + 1; i < N; i++)
  {
    for (int j = -M + 1; j < M; j++)
    {
      if (i == 0 && j == 0)
        continue;
      int _row = row;
      int _col = col;
      string num = "";
      while (_row < N && _col < M & _row >= 0 && _col >= 0)
      {
        num += v[_row][_col];
        m = max(getSqrt(stoi(num)), m);
        _row += i;
        _col += j;
      }
    }
  }
  return m;
}

int main()
{
  int N = 0, M = 0;
  cin >> N >> M;
  vector<string> v(N);

  for (auto &row : v)
  {
    cin >> row;
  }

  int m = -1;

  if (N == 1 && M == 1)
  {
    cout << getSqrt(v[0][0] - '0');
    return 0;
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {

      m = max(createMaximum(v, N, M, i, j), m);
    }
  }

  std::cout << m << endl;
  return 0;
}
