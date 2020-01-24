#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c=0; //테스트 케이스
int n=0, m=0; //학생의 수 n, 친구 쌍의 수 m
vector<bool> used;

bool isAllUsed() {
    for(auto b:used) {
        if(b==false) return false;
    }
    return true;
}

int f(vector<vector<bool>>& friends,int start=0) {
    if(isAllUsed()) return 1;
    int sum = 0;

    bool isNotFound = true;
    for(int i = start;i<n;i++) {
        if(used[i]) continue;
        for(int j=i+1;j<n;j++) {
            if(used[j]) continue;

            if(friends[i][j]) {
                used[i] = used[j] = true;
                sum += f(friends,i);
                used[i] = used[j] = false;
            }
        }
    }

    return sum;
}

int main() {
    vector<vector<bool>> friends; // 친구목록

    cin >> c;
    while(c--) {
        cin >> n>> m;

        friends.resize(n);
        used.assign(n,false);
        for(auto &iter:friends){
            iter.resize(n);
            iter.assign(n,false);
        }

        int tmp1,tmp2;

        for(int i=0;i<m;i++) {
            cin >> tmp1 >> tmp2;
            if(tmp1 > tmp2){
                std::swap(tmp1,tmp2);
            }
            friends[tmp1][tmp2] = true;
        } 

        cout << f(friends) <<endl;
    }

    return 0;
}