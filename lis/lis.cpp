#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>


using namespace std;
vector<int> v;
vector<int> cached;

int lis(int pos = 0) {
    if(cached[pos]) return cached[pos];

    auto& ret = cached[pos];

    if(pos == v.size()-1) {
        return ret = 1;
    }

    for(int i=pos+1; i < v.size();i++) {
        auto temp = lis(i);
        if(v[i] > v[pos]) {
            ret = ret > temp ? ret:temp;
        }
    }
    return ++ret;   
}

int main(){
    int c =0;
    int sz =0;
    cin >>c ;

    while(c--) {
        cin >> sz;

        v.assign(sz,0);
        cached.assign(sz,0);

        for(auto& it: v) {
            cin >>it;
        }
        lis();
        auto&& it = max_element(cached.begin(),cached.end());
        cout << *it;
        
        cout <<endl;
    }
    return 0;
}