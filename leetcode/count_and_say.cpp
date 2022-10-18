#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 2; i <= n; i++) {
            s = count(s);
        }
        return s;
    }

    string count(string& s) {
        char prev = s[0];
        int count = 1;
        string res = "";

        for(int i = 1; i< s.size();i++)
        {
            if(prev == s[i]) count++;
            else 
            {
                res += to_string(count) + prev;
                prev = s[i];
                count = 1;
            }
        }
        res += to_string(count) + prev;

        return res;
    }
};


TEST(CountAndSay,Case1) {
    Solution s;

    auto res = s.countAndSay(1);

    EXPECT_EQ("1",res);
}

TEST(CountAndSay,Case2) {
    Solution s;

    auto res = s.countAndSay(3);

    EXPECT_EQ("21",res);
}

TEST(CountAndSay,Case3) {
    Solution s;

    auto res = s.countAndSay(5);

    EXPECT_EQ("111221",res);
}