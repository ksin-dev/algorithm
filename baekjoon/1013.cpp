#include <iostream>
#include <string>

using namespace std;

bool match(string &s)
{
  if (s.size() == 0)
    return true;
  if (s.compare(0, 2, "01") == 0)
  {
    string sub = s.substr(2);
    return match(sub);
  }

  string m1 = "100";
  string m2 = "1";
  string pad = "";

  while (true)
  {
    string pad2 = "";
    while (true)
    {
      string maked = m1 + pad + m2 + pad2;
      if (maked.size() > s.size())
        break;

      string ss = s.substr(maked.size());
      if (s.compare(0, maked.size(), maked) == 0 && match(ss))
        return true;

      pad2 += "1";
    }

    if (m1.size() + pad.size() > s.size())
      return false;

    pad += "0";
  }

  return true;
}

int main()
{
  int count = 0;
  cin >> count;
  while (count--)
  {
    string s;
    cin >> s;

    std::cout << (match(s) ? "YES\n" : "NO\n");
  }
  return 0;
}
