#include <iostream>
#include <vector>

// link = https://leetcode.com/problems/sort-the-matrix-diagonally/
using namespace std;

class Solution
{
public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
  {
    for (int i = 1; i < mat.size(); i++)
    {
      sortVector(mat, 0, i);
    }

    for (int j = 1; j < mat[0].size(); j++)
    {
      sortVector(mat, j, 0);
    }

    sortVector(mat, 0, 0);

    return mat;
  }

  void sortVector(vector<vector<int>> &mat, int x, int y)
  {
    vector<int> arr;
    int position_x = x, position_y = y;
    while (position_x < mat[0].size() && position_y < mat.size())
    {
      arr.push_back(mat[position_y][position_x]);
      position_x++;
      position_y++;
    }
    std::sort(arr.begin(), arr.end());

    for (auto &i : arr)
    {
      mat[y][x] = i;
      x++;
      y++;
    }
  }
};

void print(vector<vector<int>> &mat)
{
  for (auto &arr : mat)
  {
    for (auto &i : arr)
    {
      cout << i << ' ';
    }

    cout << endl;
  }
}

int main()
{
  auto solution = Solution();
  auto mat = vector<vector<int>>{
      vector<int>{3, 3, 1, 1},
      vector<int>{2, 2, 1, 2},
      vector<int>{1, 1, 1, 2}};
  print(mat);

  solution.diagonalSort(mat);
  cout << endl;

  print(mat);

  return 0;
}