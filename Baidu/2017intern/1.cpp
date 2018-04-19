#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  string name;
  int fight, reputation, special;
  char boss, member;
  
  vector<string> nameset;
  vector<int> fightset;
  vector<int> reputationset;
  vector<int> specialset;
  vector<vector<char>> bossset(n, vector<char>());
  
  int allmoney = 0;
  int tempmoney = 0;
  string maxname;
  int maxmoney =0;
  vector<int> money;
  for (int i = 0; i < n; ++i)
  {
  money.push_back(0);
  }
  for (int i = 0; i < n; ++i)
  {
    cin >> name;
    cin >> fight;
    cin >> reputation;
    cin >> boss;
    cin >> member;
    cin >> special;
  	
    nameset.push_back(name);
    fightset.push_back(fight);
    reputationset.push_back(reputation);
    specialset.push_back(special);
    bossset[i].push_back(boss);
    bossset[i].push_back(member);
    
    if (fightset[i] > 80 && specialset[i] >0){
       tempmoney = 8000;
    	money[i] += tempmoney;
    }
    if (fightset[i] > 85 && reputationset[i] >80){
       tempmoney = 4000;
    	money[i] += tempmoney;
    }
    if (fightset[i] > 90 ){
       tempmoney = 2000;
    	money[i] += tempmoney;
    }
    if (fightset[i] > 85 && bossset[i][1] == 'Y'){
       tempmoney = 1000;
    	money[i] += tempmoney;
    }
    if (reputationset[i] >80 &&  bossset[i][0] == 'Y'){
       tempmoney = 850;
    	money[i] += tempmoney;
    }
    allmoney += money[i];
    if (money[i] > maxmoney){
    	maxmoney = money[i];
      maxname = nameset[i];
    }

  }
  cout << maxname <<endl;
  cout << maxmoney <<endl;
  cout << allmoney <<endl;
  
  
  
  	
return 0;
}
