#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

vector<int> v;
vector<int> cached;

int classyfi(int a, int b){
    auto&& begin = next(v.begin(),a);
    auto&& end = next(v.begin(),b+1);
    auto&& rbegin = next(v.begin(),b);
    auto&& rend = next(v.begin(),a-1);
    
    auto&& f = find_if_not(begin,end,[=](int n){ return n == v[a]; });

    if(f==end ) return 1;

    int differential = 10;

    bool isDifferential = true;
    for(int i = b;i>a;b--) {
        if(differential == 10) {
            differential = v[i]-v[i-1];
        }
        if(v[i] - v[i-1] != differential) {
            isDifferential = false;
            break;
        }
    }

    if(abs(isDifferential)==1 && isDifferential) return 2;

    bool isPare = true;
    for(int i=a;i<b;i++) {
        if(i+2==b) continue;
        if(v[i+2]!=v[i]) {
            isPare = false;
            break;
        }
    }
    if(isPare) return 4;
    if(isDifferential) return 5;

    return 10;
    
}


int memorize(){
    return 0;
}

int main() {
    int c;
    string s;

    cin >> c;

    while(c--) {
        cin >> s;
        cached.assign(s.size(),-1);
        for(auto& it:s) {
            v.push_back(it-'0');
        }

        classyfi(0,v.size()-2);
    }
}