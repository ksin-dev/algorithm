#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>


using namespace std;
vector<int> n,m;
vector<deque<int>> nCached,mCached;

array<array<int,100>,100> cached;


deque<int>& lis(vector<int>& v, vector<deque<int>>& cached,int pos = 0) {
    if(cached[pos].size()>0) return cached[pos];

    if(pos == v.size()-1) {
        cached[pos].push_back(v[pos]);
        return cached[pos];
    }

    auto& ret = cached[pos];
    for(int i=pos+1; i < v.size();i++) {
        auto& temp = lis(v,cached,i);
        if(temp[0] > v[pos]) {
            if(ret.size()>temp.size()) {
                ret =  ret;

            }else if(ret.size()<temp.size()){
                ret = temp;
            }else {
                
            }
        }
    }
    ret.push_front(v[pos]);


    return ret;   
}

int jlis(deque<int>& a,deque<int>& b,int aSz=0,int bSz=0) {
    if(aSz == a.size() && bSz == b.size()) return 0;
    if(aSz == a.size()) return jlis(a,b,aSz,bSz+1)+1;
    if(bSz == b.size()) return jlis(a,b,aSz+1,bSz)+1;

    int ret = a[aSz]!=b[bSz];

    return ret += a[aSz] < b[bSz] ? jlis(a,b,aSz+1,bSz):jlis(a,b,aSz,bSz+1);
}



int main(){
    int c =0;
    int nSz,mSz =0;
    cin >>c ;

    while(c--) {
        cin >> nSz >> mSz;

        n.assign(nSz,0);
        nCached.assign(nSz,deque<int>());
        m.assign(mSz,0);
        mCached.assign(mSz,deque<int>());

        for(auto& it: n) {
            cin >>it;
        }

        for(auto& it: m) {
            cin >>it;
        }

        lis(n,nCached);
        lis(m,mCached);

        int l = 0;
        for(int i = 0; i < n.size();i++) {
            for(int j = 0; j< m.size();j++) {
                l = max(l,jlis(nCached[i],mCached[j]));
            }
        }
        cout << l <<endl;
    }
    return 0;
}