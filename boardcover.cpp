#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int blocks[4][3][2] = {
    {
        {0,0},
        {0,1},
        {1,1}
    },
    {
        {0,0},
        {0,1},
        {1,0}      
    },
    {
        {0,0},
        {1,0},
        {1,-1}
    },
    {
        {0,0},
        {1,0},
        {1,1}
    },
};

int c = 0;
int h = 0, w = 0;
vector<vector<int>> board;

bool isCover(int x,int y,int type) {
    int blockX=0,blockY =0;
    for(int i=0;i<3;i++) {
        blockY = blocks[type][i][0]+y;
        blockX = blocks[type][i][1]+x;
        if(blockY>=h || blockX >= w || blockY <0 || blockX < 0) return false;

        if(board[blockY][blockX]) return false;

    }
    return true;
}

void doCover(int x,int y,int type,int val) {
    int blockX=0,blockY =0;
    for(int i=0;i<3;i++) {
        blockY = blocks[type][i][0] + y;
        blockX = blocks[type][i][1] + x;

        board[blockY][blockX] +=val;
    }
}

void paint(){
    for(int i =0;i<h;i++){
        for(int j=0;j<w;j++){
            cout <<board[i][j];
        }
        cout <<endl;
    }
    cout << endl;
}

int f() {
    int y=-1,x=-1;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!board[i][j]){
                y=i;
                x=j;
                break;
            }
        }
        if(y>-1) break;
    }

    if(y==-1) return 1;

    int ret = 0;

    for(int type=0;type<4;type++){
        if(isCover(x,y,type)){
            doCover(x,y,type,1);
            //paint();
            ret += f();
            doCover(x,y,type,-1);
        }
    }
    return ret;
}


int main() {
    
    cin >> c;
    char ch;

    while(c--) {
        cin >> h >> w;
        board.resize(h);
        
        for(auto& i:board){
            i.resize(w);
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++) {
                cin >> ch;
                board[i][j] = ch == '#'? 1:0;
            }
        }

        cout << f()<<endl;

    }

    return 0;
}