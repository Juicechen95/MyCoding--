#include <iostream>
#include <vector>

using namespace std;

int main()
{
 int n;
 int soldier_number;
 int hight;
 //vector<int> hightset;
 vector <int> answer;
 cin >>n;

 for (int i = 0; i < n; ++i)
 {
     int count = 0;
     int max = -1;     
     cin >> soldier_number;
     int hset[soldier_number];
     for (int j = 0; j < soldier_number; ++j)
     {
         cin >> hight;
         //cout << hight << endl;
         //hightset[j] = hight;
         hset[j] = hight;
         if (hset[j] > max){
             count ++;
             max = hset[j];
         }
     }
     answer.push_back(count);
     
 }
 for (int i = 0; i < answer.size(); ++i)
 {
     cout << answer[i] << endl;
 }

 return 0;
}