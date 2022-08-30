#include <iostream>
#include <vector>
#include <map>
#include <cmath>

// link = https://leetcode.com/problems/rotate-image/

using namespace std;

void print(vector<vector<int>> &matrix);

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    vector<vector<int>> new_v;

    for (auto &arr : matrix)
    {
      vector<int> v(arr);
      new_v.push_back(v);
    }

    for (int y = 0; y < matrix.size(); y++)
    {
      for (int x = 0; x < matrix.size(); x++)
      {
        matrix[x][(matrix.size() - 1) - y] = new_v[y][x];
      }
    }
  }
};

void print(vector<vector<int>> &matrix)
{
  for (auto &arr : matrix)
  {
    for (auto &x : arr)
      cout << x << '\t';

    cout << endl;
  }
  cout << endl;
}

int main()
{
  Solution solution;

  auto matrix = vector<vector<int>>{
      vector<int>{1, 2, 3},
      vector<int>{4, 5, 6},
      vector<int>{7, 8, 9}};

  auto matrix2 = vector<vector<int>>{
      vector<int>{5, 1, 9, 11},
      vector<int>{2, 4, 8, 10},
      vector<int>{13, 3, 6, 7},
      vector<int>{15, 14, 12, 16}};

  print(matrix2);
  solution.rotate(matrix2);
  print(matrix2);

  return 0;
}