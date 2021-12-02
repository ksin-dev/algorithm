#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
bool linear_search(int N, std::vector<int> &S);
bool linear_search(int N, std::vector<int> &&S);

bool linear_search(int N, std::vector<int> &S)
{
  if (S.size() == 0)
    return false;
  int mid = S.size() / 2;

  if (S[mid] == N)
    return true;

  return N < S[mid] ? linear_search(N, std::vector<int>(S.begin(), S.begin() + mid)) : linear_search(N, std::vector<int>(S.begin() + mid + 1, S.end()));
}

bool linear_search(int N, std::vector<int> &&S)
{
  return linear_search(N, S);
}

int main()
{
  std::random_device rd;
  std::mt19937 rand(rd());
  int64_t size = 10000000;

  std::uniform_int_distribution<std::mt19937::result_type>
      uniform_dist(1, size);
  std::vector<int> v;

  for (int i = 0; i < size; i++)
    v.push_back(uniform_dist(rand));

  std::sort(v.begin(), v.end());

  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  auto res = linear_search(36543, v);

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

  std::cout << (res ? "true" : "false") << std::endl;

  std::cout << "걸린 시간: " << diff.count() << std::endl;

  return 0;
}
