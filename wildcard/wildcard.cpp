#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


std::string w,s;
vector<string> words;
vector<vector<int>> cached;


//he*p
//helpi
//*p*

bool match(int wPos=0, int sPos=0) {

    if(cached[wPos][sPos]!=-1) return cached[wPos][sPos]; 

    while(wPos < w.size() && sPos < s.size() && (w[wPos] == '?' || s[sPos]==w[wPos])) {
        wPos++;
        sPos++;
    }

    int& ret = cached[wPos][sPos];
    if(wPos==w.size()) return (ret = s.size()==sPos);

    if(w[wPos] == '*') {
        for(int pos=0; pos+sPos <= s.size();pos++){
            if(match(wPos+1,sPos+pos)){
                return ret = 1;
            }
        }
    }

    return ret = 0;
}



int main() {
    int c;
    int size;

    cin >>c;

    while(c--) {
        cin >> w;
        cin >> size;
        
        
        words.assign(size,string());

        for(auto& it:words) {
            cin >>it;
        }

        sort(words.begin(),words.end());
        

        for(auto& it:words) {
            cached.assign(w.size()+1,vector<int>());

            for(auto& i:cached) {
                i.assign(it.size()+1,-1);
            }
            s = it;
            bool ret = match();
            

            if(ret) cout <<it<<endl;
        }


    }
}