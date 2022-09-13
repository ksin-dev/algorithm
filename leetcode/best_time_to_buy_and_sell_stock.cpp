#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

// link = https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        return maxProfit(k,prices.begin(),prices.end());
    }

    int maxProfit(int k, vector<int>::iterator begin,vector<int>::iterator end,int profit=0)
    {
        if(k == 0 || distance(begin,end) < 2) return profit;
        auto start = begin+1;
        auto buy = begin;
        auto sell = start;
        while(distance(start,end) > 0  || (*sell < *start)) {
            if(*buy > *start) 
            {
                buy = start;
                sell = start;
            }

            if(*sell < *start (*buy < *start && sell == end)){
                sell = start;
            }
        }
        profit = maxProfit(k-1,start,end,profit);
        

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


void case2() {
    Solution s;

    auto v = vector<int> {
        6,1,3,2,4,7
    };

    cout << s.maxProfit(2,v) << endl;

}

int main() {
    case1();
    case2();
    return 0;
}