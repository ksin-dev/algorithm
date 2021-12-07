#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename std::vector<T>::iterator partition(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
{
  auto pivot = *begin;
  auto left = begin + 1;
  auto right = end;

  while (true)
  {
    std::cout << pivot << " " << *left << " " << *right << std::endl;
    while (*left <= pivot && std::distance(left, right) > 0)
      left++;

    while (*right > pivot && std::distance(left, right) > 0)
      right--;

    if (left == right)
      break;
    else
      std::iter_swap(left, right);
  }

  if (pivot >= *right)
    std::iter_swap(begin, right);

  return right;
}

template <typename T>
void quick_sort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
{
  if (std::distance(begin, end) >= 1)
  {
    typename std::vector<T>::iterator mid = partition<T>(begin, end);

    quick_sort<T>(begin, mid - 1);
    quick_sort<T>(mid, end);
  }
}

int main()
{
  std::vector<int> c = {2, 3, 6, 7, 84, 1, 2, 354, 56, 34, 45, 33};

  quick_sort<int>(c.begin(), c.end() - 1);

  for (auto i : c)
  {
    std::cout << i << ", ";
  }

  std::cout << std::endl;

  return 0;
}