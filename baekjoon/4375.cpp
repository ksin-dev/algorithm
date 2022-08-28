/**
 *
 * 문제
2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, n이 주어진다.

출력
1로 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다.
 * */

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;

pair<bool, int> isAllOne(long long n)
{
  string s = to_string(n);

  for (auto &c : s)
  {
    if (c == '1')
      continue;
    return make_pair(false, 0);
  }

  return make_pair(true, s.size());
}

int getCompleteDigit(long long n)
{
  string s = to_string(n);

  reverse(s.begin(), s.end());

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != '1')
      return i;
  }

  return s.size();
}

int main()
{
  long long n;
  long long c_n = n;
  int cnt = 0;
  int completedDigit = 0;

  while (cin >> n)
  {
    cnt = 0;
    completedDigit = 0;
    c_n = n;

    while (true)
    {
      // std::this_thread::sleep_for(std::chrono::milliseconds(1000));

      auto p = isAllOne(c_n);
      if (p.first)
      {
        std::cout << (p.second + cnt) << endl;
        break;
      }

      completedDigit = getCompleteDigit(c_n);
      if (completedDigit > 0)
      {
        c_n /= pow(10, completedDigit);
        cnt += completedDigit;
      }

      c_n += n;

      // cout << c_n << ' ' << cnt << endl;
    }
  }

  return 0;
}