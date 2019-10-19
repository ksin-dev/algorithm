#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fences;

int runFence(int left, int right)
{
  if (left == right)
    return fences[left];

  int mid = (right + left) / 2;

  int ret = max(runFence(left, mid), runFence(mid + 1, right));

  int lo = mid, hi = mid + 1;

  int height = min(fences[lo], fences[hi]);

  ret = max(ret, height * 2);

  while (lo > left || hi < right)
  {
    if (hi < right && (lo == left || fences[lo - 1] < fences[hi + 1]))
    {
      ++hi;
      height = min(height, fences[hi]);
    }
    else
    {
      --lo;
      height = min(height, fences[lo]);
    }

    ret = max(ret, (hi - lo + 1) * height);
  }
  return ret;
}

int main()
{
  int c;
  int size;

  cin >> c;

  while (c--)
  {
    cin >> size;

    fences.assign(size, 0);

    for (auto &it : fences)
    {
      cin >> it;
    }

    cout << runFence(0, fences.size() - 1) << endl;
  }

  return 0;
}