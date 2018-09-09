#include<iostream>
#include <vector>
#include <algorithm>
#include<numeric>

using namespace std;



int main(){
    int N, np = 0;
    int hn=0;
    cin >> N;
    cin >> np;
    vector< vector<int> > G(N, vector<int>(N, 0));
    vector<int> s(N,0);

    for(int i = 0; i < np ; i++){
        int a; scanf("%d",&a);
        int b; scanf("%d",&b);
        G[a-1][b-1] = 1;
    }
    int sum = 0;
    int temp =-1;
    while(temp != sum){
        for(int y =0; y < N; y++){
            int zero_count = 0;
            for(int x = 0; x < N; x++){
                if( G[x][y] == 1){
                    for(int i=0; i<N; i++){
                        G[i][y] += G[i][x];
                    }
                }
                else{
                    zero_count += 1;
                }

            }
            s[y]=zero_count;
        }
        temp = sum;
        sum = accumulate(s.begin() , s.end() , 0);
        
    }
    for(int y =0; y < N; y++){
        for(int x = 0; x < N; x++){
            if(x != y){
                if(G[x][y] == 0)
                {
                    break;
                }
            }
            if(x == N -1){
                hn += 1;

            }


        }
    }
    cout << hn << endl;
    return 0;
}
