#include <bits/stdc++.h>
using namespace std;

//Problem type : Brute Force

//Requirements to understand the solution : 
//Simple looping


long long k0;
string ans;
long long uu(string g){
	long long a = stoi(g.substr(0,2)),b = stoi(g.substr(3));
	long long S = a*60 + b;
	return S;
}
bool check(string s){
	long long a = stoi(s.substr(0,2)),b = stoi(s.substr(3));
	if(a>=24 || b >= 60)
		return false;
	return true;
}
void dd(string tst,string s2){
	if(!check(tst)){
		return ;
	}
	long long d = min(abs(uu(tst)-uu(s2)),24*60 - abs(uu(tst)-uu(s2)));
	if(k0 > d){
		k0 = d;
		ans = tst;
	}

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		bool sp = false;
		vector<int> l(5,10);
		for(long long i = 0; s1[i] ; i++){
			if(s1[i] == '?')
				sp = true;
		}
		if(!sp){
			cout<<s1<<endl;
			continue;
		}
		string g = "0123456789";
		string tst = s1;
		k0 = 1e9;
		//Brute force dial koula valid Time ou ka tchecki 
		for(long long i = 0 ; i < 3 ; i++){
			for(long long j = 0 ; j < 10 ;j++){
				for(long long k = 0; k < 7 ; k++){
					for(long long d = 0; d < 10 ; d++){
						if(s1[0] == '?')
							tst[0] = g[i];
						if(s1[1] == '?')
							tst[1] = g[j];
						if(s1[3] == '?')
							tst[3] = g[k];
						if(s1[4] == '?')
							tst[4] = g[d];
						dd(tst,s2);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
