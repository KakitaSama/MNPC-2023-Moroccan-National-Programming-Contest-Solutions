#include <bits/stdc++.h>
using namespace std;

//Problem type : Sorting,Data structures
//Requirements to undestand the solution : 
//Simple use of map,multiset

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    multiset<tuple<long long,long long,string>> mul;
    map<string,long long> mp0,mp1;
   	string s;
   	long long a,b;
    for(long long i = 1 ; i <= n; i++){
    	cin>>a;
    	if(a == 1){
    		cin>>s>>b;
    		if(mp0[s] != 0){
    			mul.erase({-mp0[s],-mp1[s],s});
    		}
    		mp0[s]++;
    		mp1[s]+= b;
    		mul.insert({-mp0[s],-mp1[s],s});
    	}
    	else{
    		cout<<get<2>(*(mul.begin()))<<endl;
    	}
    }
}
