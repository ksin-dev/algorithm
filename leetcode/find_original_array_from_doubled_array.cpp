#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<int>&& v)
{
    for(auto& value:v)
    {
        cout << value << ",\t";
    }

    cout <<endl;
}

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 == 1) return vector<int>();
        
        sort(changed.begin(),changed.end());
        queue<int> q;
        vector<int> result;

        for(auto& value:changed)
        {
            if(q.empty() || (!q.empty() && (q.front()*2) > value))
            {
                q.push(value);
            }
            else if((q.front()*2) == value)
            {   
                result.push_back(q.front());
                q.pop();
            }
            else
            {
                break;
            }
            
        }

        if(q.size()) return vector<int>();

        return result;
    }
};


void case1()
{
    Solution s;
    vector<int> v{
        1,3,4,2,6,8
    };
    
    print(s.findOriginalArray(v));
}

void case2()
{
    Solution s;
    vector<int> v{
        6,3,0,1
    };
    
    print(s.findOriginalArray(v));
}

void case3()
{
    Solution s;
    vector<int> v{
        1
    };
    
    print(s.findOriginalArray(v));
}

void case4()
{
    Solution s;
    vector<int> v{
        0,1,2,0
    };
    
    print(s.findOriginalArray(v));
}

int main()
{
    case1();
    case2();
    case3();
    case4();
    return 0;
}