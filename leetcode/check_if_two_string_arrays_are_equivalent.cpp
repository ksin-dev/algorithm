#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1,s2;

        s1 = accumulate(word1.begin(),word1.end(),string{});
        s2 = accumulate(word2.begin(),word2.end(),string{});

    
        return s1 == s2;
    }
};

TEST(ArrayStringsAreEqual,Case1) {
    Solution s;
    vector<string> v1 ={
        "ab", "c"
    };
    vector<string> v2 = {
        "a", "bc"
    };
    EXPECT_TRUE(s.arrayStringsAreEqual(v1,v2));
}


TEST(ArrayStringsAreEqual,Case2) {
    Solution s;
    vector<string> v1 ={
        "ab", "cc"
    };
    vector<string> v2 = {
        "a", "bc"
    };
    EXPECT_FALSE(s.arrayStringsAreEqual(v1,v2));
}