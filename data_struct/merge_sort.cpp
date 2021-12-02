#include <iostream>
#include <vector>

std::vector<int> merge_sort(std::vector<int> &v);
std::vector<int> merge_sort(std::vector<int> &&v);
std::vector<int> merge(std::vector<int> &s, std::vector<int> &n);
void print(std::vector<int> &v);

std::vector<int> merge_sort(std::vector<int> &v)
{
  if (v.size() <= 1)
    return v;

  auto mid = v.size() / 2;
  auto left = merge_sort(std::vector<int>(v.begin(), v.begin() + mid));
  auto right = merge_sort(std::vector<int>(v.begin() + mid, v.end()));

  return merge(left, right);
}

std::vector<int> merge_sort(std::vector<int> &&v)
{
  return merge_sort(v);
}

std::vector<int> merge(std::vector<int> &s, std::vector<int> &n)
{
  std::vector<int> newV;

  std::cout << "s size" << std::endl;
  print(s);

  std::cout << "n size" << std::endl;
  print(n);

  size_t sStart = 0;
  size_t nStart = 0;

  while ((nStart + sStart) < (s.size() + n.size()))
  {
    if (sStart == s.size())
    {
      newV.push_back(n[nStart++]);
    }
    else if (nStart == n.size())
    {
      newV.push_back(s[sStart++]);
    }
    else
    {
      if (s[sStart] < n[nStart])
      {
        newV.push_back(s[sStart++]);
      }
      else if (s[sStart] > n[nStart])
      {
        newV.push_back(n[nStart++]);
      }
      else
      {
        newV.push_back(n[nStart++]);
        newV.push_back(s[sStart++]);
      }
    }
  }
  print(newV);
  std::cout << std::endl
            << std::endl;
  return newV;
}

void print(std::vector<int> &v)
{
  for (auto i : v)
    std::cout << i << ", ";
  std::cout << std::endl;
}

int main()
{
  std::vector<int> v = {5, 3, 2, 87, 45, 23, 293, 56703458, 3423, 5, 34, 23};

  auto result = merge_sort(v);
  std::cout << "result: " << std::endl;
  print(result);

  std::cout << std::endl;

  return 0;
}