#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#include "gtest/gtest.h"


using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0;
        int true_sum = 0;
        int find_num = -1;
        sort(nums.begin(),nums.end());
        for(int i=0; i < nums.size(); i++) 
        {
            sum+=nums[i];
            true_sum+=i+1;

            if(i+1 < nums.size() && nums[i] == nums[i+1]) {
                find_num = nums[i];
                break;
            }
        }

        if(find_num == -1) return vector<int>{};

        return vector<int>{
            find_num,
            find_num+(true_sum-sum)
        };
    }
};


TEST(FindErrorNums, Case1)
{
    Solution s;

    vector<int> v = {1,2,2,4};
    vector<int> answer = {
        2,3
    };
    auto res = s.findErrorNums(v);

    EXPECT_EQ(res,answer);
}



TEST(FindErrorNums, Case2)
{
    Solution s;

    vector<int> v = {1,1};
    vector<int> answer = {
        1,2
    };
    auto res = s.findErrorNums(v);

    EXPECT_EQ(res,answer);
}

TEST(FindErrorNums, Case3)
{
    Solution s;

    vector<int> v = {2,2};
    vector<int> answer = {
        2,1
    };
    auto res = s.findErrorNums(v);

    EXPECT_EQ(res,answer);
}


TEST(FindErrorNums, Case4)
{
    Solution s;

    vector<int> v = {3,2,2};
    vector<int> answer = {
        2,1
    };
    auto res = s.findErrorNums(v);

    EXPECT_EQ(res,answer);
}



TEST(FindErrorNums, Case5)
{
    Solution s;

    vector<int> v = {3,2,3,4,6,5};
    vector<int> answer = {
        3,1
    };
    auto res = s.findErrorNums(v);

    EXPECT_EQ(res,answer);
}