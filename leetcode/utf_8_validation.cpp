#include <iostream>
#include <vector>
#include <numeric>
#include <utility>


using namespace std;


pair<int,int> COMMON_CONDITION =  make_pair(
    128,
    1+2+4+8+16+32
);

vector<vector<pair<int,int>>> CONDITIONS = {
    vector<pair<int,int>> { make_pair(
        0,
        127
    )},
    vector<pair<int,int>> { make_pair(
            128+64,
            1+2+4+8+16
        ),
        COMMON_CONDITION
    },
    vector<pair<int,int>> { make_pair(
            128+64+32,
            1+2+4+8
        ),
        COMMON_CONDITION,
        COMMON_CONDITION
    },
    vector<pair<int,int>> { make_pair(
            128+64+32+16,
            1+2+4
        ),
        COMMON_CONDITION,
        COMMON_CONDITION,
        make_pair(0,255)
    }
} ;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        return validUtf8(data.begin(),data.end());
    }

    bool validUtf8(vector<int>::iterator begin, vector<int>::iterator end) {
        if(distance(begin,end) <= 0) return true;
        bool success = false;
        auto start = begin;
        for(auto& cons:CONDITIONS) {
            start = begin;
            success = valid(start,end,cons);
            if(success) break;
        }

        if(!success) return false;

        return validUtf8(start,end);
    }

    bool valid(vector<int>::iterator& start,vector<int>::iterator& end,vector<pair<int,int>>& cons) {
        if(distance(start,end) < cons.size()) return false;
        for(auto& con: cons) {
            if((*start < con.first) || (*start > (con.first + con.second))) 
            {
                return false;
            }
            start = next(start,1);
        }
        return true;
    }

};



void case1() {
    Solution s;

    auto v = vector<int> {
        197,
        130,
        1
    };

    cout << s.validUtf8(v) <<endl;
    

}

void case2() {
    Solution s;

    auto v = vector<int> {
        235,
        140,
        4
    };


    cout << s.validUtf8(v) << endl;
}

void case3() {
    Solution s;

    auto v = vector<int> {
        10
    };


    cout << s.validUtf8(v) << endl;
}

int main() {
    case1();
    case2();
    case3();

    return 0;
}