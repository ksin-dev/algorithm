#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        list<list<int>> l;
        vector<int> route;
        for (auto &row : nums)
        {
            list<int> tmp;
            for (auto &col : row)
            {
                tmp.push_back(col);
            }
            l.push_back(tmp);
        }

        auto last = l.begin();

        while (!l.empty())
        {
            auto up = last;

            while (up != --l.begin())
            {
                if (!up->empty())
                {
                    route.push_back(up->front());
                    up->pop_front();
                }

                up = prev(up, 1);
            }

            if (last != --l.end())
            {
                last = std::next(last, 1);
            }
            else
            {
                while (last->empty())
                {
                    last = l.erase(last);
                }

                last = --l.end();
            }
        }

        return route;
    }
};

// int main(int argc, char *argv[])
// {
//     Solution s;
//     auto v = vector<vector<int>>{
//         vector<int>{1, 2, 3},
//         vector<int>{4, 5, 6},
//         vector<int>{7, 8, 9}};
//     auto res = s.findDiagonalOrder(v);

//     return 0;
// }

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
TEST(FindDiagonalOrder, Case1)
{
    Solution s;
    auto v = vector<vector<int>>{
        vector<int>{1, 2, 3},
        vector<int>{4, 5, 6},
        vector<int>{7, 8, 9}};
    auto res = s.findDiagonalOrder(v);
    auto result = vector<int>{1, 4, 2, 7, 5, 3, 8, 6, 9};
    EXPECT_EQ(result, res);
}

TEST(FindDiagonalOrder, Case2)
{
    Solution s;
    auto v = vector<vector<int>>{
        vector<int>{1, 2, 3, 4, 5}, vector<int>{6, 7}, vector<int>{8}, vector<int>{9, 10, 11}, vector<int>{12, 13, 14, 15, 16}};
    auto res = s.findDiagonalOrder(v);
    ;
    auto result = vector<int>{1, 6, 2, 8, 7, 3, 9, 4, 12, 10, 5, 13, 11, 14, 15, 16};
    EXPECT_EQ(result, res);
}

TEST(FindDiagonalOrder, Case3)
{
    Solution s;
    auto v = vector<vector<int>>{
        vector<int>{1, 2, 3, 4, 5},
        vector<int>{6, 7},
        vector<int>{12, 13, 14, 15, 16},
        vector<int>{8},
        vector<int>{9, 10, 11}};
    auto res = s.findDiagonalOrder(v);
    auto result = vector<int>{1, 6, 2, 12, 7, 3, 8, 13, 4, 9, 14, 5, 10, 15, 11, 16};
    EXPECT_EQ(result, res);
}

TEST(FindDiagonalOrder, Case4)
{
    Solution s;
    auto v = vector<vector<int>>{
        vector<int>{1, 36, 9, 7, 4, 20, 1, 7},
        vector<int>{11, 27, 7, 38, 32, 17, 13},
        vector<int>{35, 16, 7, 7, 21, 13},
        vector<int>{5, 40, 27, 37, 26},
        vector<int>{12, 17, 2, 3, 17, 9, 6, 4},
        vector<int>{29, 5, 19, 37, 4, 7, 34, 32, 9},
        vector<int>{13, 34, 20, 24, 32}};
    auto res = s.findDiagonalOrder(v);
    auto result = vector<int>{1, 11, 36, 35, 27, 9, 5, 16, 7, 7, 12, 40, 7, 38, 4, 29, 17, 27, 7, 32, 20, 13, 5, 2, 37, 21, 17, 1, 34, 19, 3, 26, 13, 13, 7, 20, 37, 17, 24, 4, 9, 32, 7, 6, 34, 4, 32, 9};
    EXPECT_EQ(result, res);
}