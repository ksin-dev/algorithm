#include <vector>

using namespace std;

class Solution {
public:
    vector<int> cached;
    int climbStairs(int n) {
        if(cached.empty()) cached.assign(n+1,0);
        if(n<0) return 0;
        if(n==0) return 1;
        if(cached[n] != 0) return cached[n];
        
        cached[n] = climbStairs(n-1) + climbStairs(n-2);
        
        return cached[n];
    }
};