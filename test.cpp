#include <iostream>
#include <string>

using namespace std;

string s = "*OOXOOOOXOOOXOOOOOOXO*";
int k = 2;

int f(int idx=0) {
    if(s.size()==idx) return 0;
    if(s.size()-1==idx) return 1; 
    int ret = 1;

    for(int i=1;i<=k;i++) {
        if(s.size()<=(idx+i)) break;
        if(s[idx+i]=='X') continue;
        ret += f(idx+i);
    }
    return ret;
}

int main() {
    cout <<f(0)<<endl;
    return 0;
}