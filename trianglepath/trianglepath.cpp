#include <iostream>
#include <vector>
#include <array>


using namespace std;


int sz;
vector<vector<int>> v;
array<array<int,101>,101> cached;

int triangle(int y=0,int x=0) {
    if(y == v.size() || x == v[y].size()) return 0;

    int& ret = cached[y][x];

    if(ret != 0) return ret;

    ret += v[y][x];

    int b = triangle(y+1,x);
    int rb = triangle(y+1,x+1);


    return ret += max(b,rb);
}

int main() {
    int c = 0;
    int temp;

    cin >> c;

    while(c--) {
        cin >> sz;
        for(auto& cache:cached){
            cache.fill(0);
        }
        v.assign(sz,vector<int>());

        int i=0;

        for(auto& it:v) {
            it.assign(++i,0);
            for(auto& val:it){
                cin >>val;
            }

        }
        cout << triangle()<<endl;
    }

    return 0;
}