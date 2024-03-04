#include <bits/stdc++.h>
using namespace std;

//Problem type : Math, Number theory,Graph
//Requirements to understand solution :
//*Euler totient function (phi funtion)
//*Gauss formula : Sum of phi(d) = n  (d houwa divisors dial n)
//DFS

vector<long long> cmp;
void dfs(int i,vector<long long> arr[],vector<bool>& vis){
	if(vis[i])
		return ;
	vis[i] = true;
	cmp.push_back(i);
	for(int x:arr[i]){
		if(!vis[x])
			dfs(x,arr,vis);
	}
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    //Phi Function up to 1e5
    long long MAX0 = 1e5;
  	vector<long long> phi(MAX0 + 1);
    for (long long i = 0; i <= MAX0; i++)
        phi[i] = i;
    for (long long i = 2; i <= MAX0; i++) {
        if (phi[i] == i) {
            for (long long j = i; j <= MAX0; j += i)
                phi[j] -= phi[j] / i;
        }
    }


    long long n,m;
    cin>>n>>m;
    vector<long long> v(n+1);
    vector<bool> vis(n+1);
    for(long long i = 1; i <= n ; i++){
    	cin>>v[i];
    }
    long long a,b;
    vector<long long> arr[n+1];
    for(long long i = 0; i < m ; i++){
    	cin>>a>>b;
    	arr[a].push_back(b);
    	arr[b].push_back(a);
    }
    map<long long,long long> mp;
    long long ans = 0;
    for(long long i = 1 ; i <= n ; i++){
    	if(!vis[i]){

    		//Ntel3o Koula Connected Component
    		cmp.clear();
    		mp.clear();
    		dfs(i,arr,vis);

    		//N7essbou gcd dial koula pair fe had Component
    		for(long long x: cmp){
    			for(long long j = 1; j*j <= v[x] ; j++){
    				if(v[x]%j == 0){
    					mp[j]++;
    					if(j*j != v[x]){
    						mp[v[x]/j]++;
    					}
    				}
    			}
    		}
    		for(auto& [x,y]:mp){
    			ans += phi[x]*(y*(y-1)/2);
    		}
    	}
    }
    cout<<ans<<endl;
}
