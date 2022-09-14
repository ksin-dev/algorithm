#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>
#include <iterator>

// link = https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;

        vector<int> gaps;
        int sum = 0;
        for(auto it = prices.begin()+1;it != prices.end();it=next(it,1))
        {
            auto prev = std::prev(it,1);
            if(*it - *prev >= 0)
            {
                if(sum >= 0 )
                {
                    sum += (*it - *prev);
                }   
                else
                {
                    gaps.push_back(sum);
                    sum = (*it - *prev);
                }
            }
            else 
            {
                if(sum > 0 )
                {
                    gaps.push_back(sum);
                    sum = (*it - *prev);
                }
                else 
                {
                    sum += (*it - *prev);
                }
            }
        }
        if(sum !=0)
        {
            gaps.push_back(sum);
        }

        for(auto& gap:gaps)
        {
            cout << gap << '\t';
        }
        cout <<endl;
        return 0;
    }



};

void case1() {
    Solution s;

    auto v = vector<int> {
        2,4,1
    };
    

    cout << s.maxProfit(2,v) << endl;
}

void case2() {
    Solution s;

    auto v = vector<int> {
        3,2,6,5,0,3
    };

    cout << s.maxProfit(2,v) << endl;

}


void case3() {
    Solution s;

    auto v = vector<int> {
        6,1,3,2,4,7
    };

    cout << s.maxProfit(2,v) << endl;

}

void case4() {
    Solution s;

    auto v = vector<int> {
        0,2,6,7,0,8,5,7
    };

    cout << s.maxProfit(2,v) << endl;

}

int main() {
    case1();
    case2();
    case3();
    case4();
    return 0;
}