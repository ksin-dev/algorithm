#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

vector<vector<int>> friendsInFoods;
vector<bool> friendsInFoodsUsed;

vector<string> friends;
vector<int> friendsAble;
int minRoute = numeric_limits<int>::max();

void setCache(int idx, int count) {
    count = count < 0 ? -1:1;

    friendsInFoodsUsed[idx] = count < 0 ? false:true;

    for(auto& it: friendsInFoods[idx]){
        friendsAble[it] += count;
    }


}

int allergy(int next=0,int route = 0) { 
    if(next == friendsInFoodsUsed.size() ||  route > minRoute) return numeric_limits<int>::max(); 
    auto&& falseIter = find(friendsAble.begin(),friendsAble.end(),0);
    if(falseIter == friendsAble.end()) return minRoute = route;
    int ret = numeric_limits<int>::max();
    for(int i = next; i< friendsInFoodsUsed.size();i++) {
        setCache(i,1);
        ret = min(ret,allergy(i+1,route+1));
        setCache(i,-1);
    }

    return ret;
}

int main()
{
  int c;
  int n, m;
  int temp;
  string in;
  cin >> c;

  while (c--)
  {
    cin >> n >> m;
    friends.assign(n, string());
    friendsAble.assign(n,0);
    friendsInFoodsUsed.assign(m,false);
    friendsInFoods.assign(m, vector<int>());
    minRoute =  numeric_limits<int>::max();
    for (auto &it : friends)
    {
      cin >> it;
    }
    int i = 0;
    while (m--)
    {
      cin >> temp;
     
      while (temp--)
      {
        cin >> in;
        auto &&f = find_if(friends.begin(), friends.end(), [=](string &e) {
          return !e.compare(in);
        });

        friendsInFoods[i].push_back(f - friends.begin());
      }
 
      i++;
    }
    sort(friendsInFoods.begin(),friendsInFoods.end(),[](vector<int>& a, vector<int>& b){
        return a.size() < b.size();
    });

    cout << allergy() <<endl;
  }
  return 0;
}