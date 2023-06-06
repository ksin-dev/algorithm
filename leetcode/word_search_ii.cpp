#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include "gtest/gtest.h"

using namespace std;

vector<pair<int, int>> moves = {
    make_pair(-1, 0),
    make_pair(0, -1),
    make_pair(1, 0),
    make_pair(0, 1)};

struct word_graph
{
  char val;
  list<word_graph> next;
};
class Solution
{
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
  {
    vector<string> results;
    list<word_graph> l;

    for (auto rows : board)
    {
      vector<bool> v(rows.size(), false);
      visited.push_back(v);
    }

    for (int i = 0; i < words.size(); i++)
    {
      bool isFound = false;
      for (int y = 0; y < board.size(); y++)
      {
        for (int x = 0; x < board[y].size(); x++)
        {
          isFound = solve(board, visited, y, x, words[i].begin(), words[i].end());

          if (isFound)
            break;
        }
        if (isFound)
          break;
      }
      if (isFound)
        results.push_back(words[i]);
    }

    sort(results.begin(), results.end());

    return results;
  }

  bool solve(vector<vector<char>> &board, vector<vector<bool>> &visited, int y, int x, string::iterator begin, string::iterator end)
  {
    if (begin == end)
      return true;
    if (y == board.size() || y < 0 || x < 0 || x == board[y].size())
      return false;
    if (visited[y][x] || *begin != board[y][x])
      return false;
    cout << y << " " << x << " " << *begin << endl;
    visited[y][x] = true;
    begin = std::next(begin);
    bool found = false;
    for (auto &move : moves)
    {
      found = found || solve(board, visited, y + move.first, x + move.second, begin, end);
    }

    visited[y][x] = false;

    return found;
  }
};

TEST(WordSearch2, Case1)
{
  vector<vector<char>> v = {
      vector<char>{'o', 'a', 'a', 'n'},
      vector<char>{'e', 't', 'a', 'e'},
      vector<char>{'i', 'h', 'k', 'r'},
      vector<char>{'i', 'f', 'l', 'v'}};
  vector<string> words = {
      "oath", "pea", "eat", "rain"};
  vector<string> answer = {
      "eat",
      "oath"};
  Solution s;

  auto res = s.findWords(v, words);

  EXPECT_EQ(res, answer);
}