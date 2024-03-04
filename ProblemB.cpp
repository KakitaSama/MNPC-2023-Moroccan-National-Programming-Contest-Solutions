#include <bits/stdc++.h>
using namespace std;
//Problem type : DFS & BFS
//Requirements to understand the solution:
//*DFS

map<long long,long long> mp;
void dfs(long long i, vector<bool>& vis, vector<long long> arr[],long long k){
	if(vis[i])
		return ;
	mp[i] = k;
	vis[i] = true;
	for(long long x:arr[i]){
		if(!vis[x]){
			dfs(x,vis,arr,k);
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
    	long long n,m,q;
    	cin>>n>>m>>q;
    	
   		vector<long long> arr[n+1];
   		long long a,b,c;
   		for(long long i = 0; i <m ; i++){
   			cin>>a>>b;
   			arr[a].push_back(b);
   			arr[b].push_back(a);
   		}
   		
   		vector<bool> vis(n+1);
   		long long k = 1;
   		//Koula Elements fe Connected Component gha n3ezlouhoum bou7edhoum 
   		for(long long i = 1;  i<= n ; i++){
   			if(!vis[i]){
   				dfs(i,vis,arr,k);
   				k++;
   			}
   		}
   		map<pair<long long,long long>,long long> mp0;
   		long long max0 = 0,l,r;
   		long long ans = 0;

   		//Gha nchoufo koula two elements fe two different components ila connectenahoum ch7al gha i3tewna
   		for(long long i = 0; i < q ; i++){
   			cin>>a>>b>>c;
   			l = mp[a];
   			r = mp[b];
   			if(r < l)
   				swap(l,r);
   			if(l == r){
   				ans += c;
   			}
   			else{
   				mp0[{l,r}] += c;
   			}
   		}
   		//Gha nakhdou max dial dik value awla li kanet negative magha nakhdouch
   		for(auto x : mp0){
   			max0 = max(max0,x.second);
   		}
   		cout<<ans+max0<<endl;
   		mp.clear();
   	}
}
