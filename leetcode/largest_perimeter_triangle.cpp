#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),std::greater<int>());

        for(int i =0 ; i < nums.size()-2;i++) {
            if(nums[i]< nums[i+1]+nums[i+2]) return nums[i] + nums[i+1] +nums[i+2];
        }
        return 0;
    }
};

TEST(LargestPerimeter,Case1) {
    Solution s;
    vector<int> v = {
        2,1,2
    };
    int res = s.largestPerimeter(v);

    EXPECT_EQ(res,5);
}

TEST(LargestPerimeter,Case2) {
    Solution s;
    vector<int> v = {
        1,2,1
    };
    int res = s.largestPerimeter(v);

    EXPECT_EQ(res,0);
}