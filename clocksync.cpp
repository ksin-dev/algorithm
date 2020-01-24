#include <iostream>
#include <array>
#include <vector>
#include <algorithm>


using namespace std;

array<vector<int>,10> buttons = {
    vector<int>{0,1,2},
    vector<int>{3,7,9,11},
    vector<int>{4,10,14,15},
    vector<int>{0,4,5,6,7},
    vector<int>{6,7,8,10,12},
    vector<int>{0,2,14,15},
    vector<int>{3,14,15},
    vector<int>{4,5,7,14,15},
    vector<int>{1,2,3,4,5},
    vector<int>{3,4,5,9,13}
};

array<int,16> switches;
int c = 0;

void on(){
    
}

int main()
{
    cin >> c;

    while(c--) {
        for(auto& iter:switches){
            cin >> iter;
        }

        auto count = std::count_if(switches.begin(),switches.end(),[&](int i){
            return i == 12;
        });

        if(count==12) {
            cout << endl;
        } else {

        }
    }


    return 0;
}