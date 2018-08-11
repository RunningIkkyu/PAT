#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> haswon;
int main(void){
	int m, n, s, cnt;
	string t;
	cin>>m>>n>>s;
	cnt = 0;
	for(int i = 1; i <= m; i++){
		cin>>t;
		if(i < s) continue;
		if(find(haswon.begin(), haswon.end(), t) != haswon.end())continue;
		if(cnt%n == 0) haswon.push_back(t);
		cnt++;
	}
	for(int i = 0; i < haswon.size();i++){
		cout<<haswon[i]<<endl;
	}
	if(haswon.size() == 0) cout<<"Keep going..."<<endl;
	return 0;
}