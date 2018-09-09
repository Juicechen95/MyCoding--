#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void back_trace(vector<vector<int> > &MM, int i, int j, int M, char orient){
    if(i<0 || (i+1)>M || j<0 || (j+1)>M || MM[i][j] == 0)    return;
    MM[i][j] = 2;
    switch (orient){
        case 'R':{
            if(i+1<M)
                back_trace(MM, i+1, j, M, 'R');
            if(j>0)
                back_trace(MM, i, j-1, M, 'U');
            if(j+1<M)
                back_trace(MM, i, j+1, M, 'D');
            break;
        }
        case 'L':{
            if(i>0)
                back_trace(MM, i-1, j, M, 'L');
            if(j>0)
                back_trace(MM, i, j-1, M, 'U');
            if(j+1<M)
                back_trace(MM, i, j+1, M, 'D');
            break;
        }
        case 'U':{
            if(i+1<M)
                back_trace(MM, i+1, j, M, 'R');
            if(j>0)
                back_trace(MM, i, j-1, M, 'U');
            if(i>0)
                back_trace(MM, i-1, j, M, 'L');
            break;
        }
        case 'D':{
            if(i+1<M)
                back_trace(MM, i+1, j, M, 'R');
            if(i>0)
                back_trace(MM, i-1, j, M, 'L');
            if(j+1<M)
                back_trace(MM, i, j+1, M, 'D');
            break;
        }
        default:{
            std::cerr << "error orient\n";
            return;
        }
    }
}

int main(){

    int M;
    vector<vector<int> > MM;
    cin >> M;
    for(int i=0; i<M; ++i){
        vector<int> tmp;
        for(int j=0; j<M; ++j){
            int m;
            cin >> m;
            tmp.push_back(m);
        }
        MM.push_back(tmp);
    }

    // back_trace();
    int group = 0;
    for(int i=0; i<M; ++i){
        for(int j=0; j<M; ++j){
            if(MM[i][j] == 1){
                group++;
                back_trace(MM, i, j, M, 'R');
            }
        }
    }

    cout << group << endl;
    
    return 0;
}
