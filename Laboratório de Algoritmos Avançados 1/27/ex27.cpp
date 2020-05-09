#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#define pb push_back
using namespace std;

int n, tot;
int v[21];
int dp[201][21];

int read(){
	vector<int>a;
	int x;
	char c;
	string s = "";

	while(scanf("%c", &c)){
		if(c == '\n')break;
		if(c == ' '){
			x = stoi(s);
			s.clear();
			a.pb(x);
		}
		else s += c;
	}
	x = stoi(s);
	a.pb(x);
	
	v[0] = 0;
	for(int i=0; i<(int)a.size(); i++) v[i+1] = a[i];
	
	return a.size();
}

int solve(int i, int sum){
	
	if(i > n){
		int ret;
		(tot-sum == sum) ? ret = 1 : ret = -1;
		return ret;
	}
	if(dp[sum][i] != 0) return dp[sum][i];	
		
	return dp[sum][i] = max(solve(i+1, sum+v[i]), solve(i+1, sum)); 	
}


int main(){
	
	int t;
	cin >> t;
	cin.ignore();
	
	while(t--){	
		n = read();
		string ans;
		
		tot = 0;
		for(int i=1; i<=n; i++) tot+=v[i];
		
		(solve(0,0) == 1) ? ans = "YES" : ans= "NO";
		
		cout << ans << endl;
	
		memset(v, 0, sizeof v);
		memset(dp, 0, sizeof dp);
	}	
		
	
	return 0;
}
