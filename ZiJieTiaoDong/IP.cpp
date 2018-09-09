#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


inline bool isLegal(string ss){
    int a = atoi(ss.c_str());
    if(a >= 0 && a <= 255)
        return true;
    return false;
}

void back_trace(string &s, int start, int index, int &count){
    if(index > 3 || start > s.length()) return;
    
    for(int i=1; i<=3; ++i){
        if(start + i <= s.length()){
            if(isLegal(s.substr(start, i))){
                if(start+i == s.length() && index == 3){
                    count++;
                    return;
                }
                back_trace(s, start+i, index+1, count);
            }
            
        }
    }
}

int main(){

    string s;
    cin >> s;    

    int count = 0;
    back_trace(s, 0, 0, count);

    cout << count << endl;

    return 0;
}
