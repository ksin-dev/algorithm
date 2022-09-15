#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    map<int,int> m;
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;

        auto cache = m.find(n);

        
        if(cache != m.end()) return cache->second;

        auto res = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
        m[n] = res;

        return res;
    }
};

void case1()
{
    Solution s;
    cout <<s.tribonacci(25)<<endl;
}

int main()
{
    case1();
    return 0;
}