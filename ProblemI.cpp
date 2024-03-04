#include <bits/stdc++.h>
using namespace std;
//Problem type : Topological Sort, Graph
//Requirements to undestand this solution:
//*DFS,Topological Sort


void dfs(int i ,vector<int>& in, pair<int,int> arr[],string s,vector<bool>& vis,vector<int>& val){
	if(vis[i])
		return ;
	vis[i] = true;
	int l = arr[i].first,r = arr[i].second;
	val[l] += val[i]/2;
	val[r] += val[i]/2;
	if(s[i] == 'L')
		val[l] += val[i]%2;
	else
		val[r] += val[i]%2;
	in[l]--;
	in[r]--;
	if(in[r] == 0 && !vis[r]){
		dfs(r,in,arr,s,vis,val);
	}
	if(in[l] == 0 && !vis[l]){
		dfs(l,in,arr,s,vis,val);
	}
}


void dfs0(int i ,vector<int>& in, pair<int,int> arr[],vector<bool>& vis,vector<int>& val){
	if(vis[i])
		return ;
	vis[i] = true;
	if(in[i] == 0){
		in[arr[i].first]--;
		in[arr[i].second]--;
		dfs0(i,in,arr,vis,val);
	}
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,p;
    cin>>n>>p;
    int a,b;
    pair<int,int> arr[p+2];
    vector<int> in(p+2);
    for(int i = 1; i <= p ; i++){
    	cin>>a>>b;
    	arr[i].first  = a;
    	arr[i].second = b;
    	in[a]++;
    	in[b]++;
    }
    vector<bool> vis(p+2);
    vector<int> val(p+2);
    string s;
    cin>>s;
    s = "0"+s;
    val[1] = n;
    //dfs0 bach n7eydo douk nodes li node 1 machi one of his ancestors 
    for(int i = 2; i <= p ; i++){
    	if(in[i] == 0){
    		dfs0(i,in,arr,vis,val);
    	}
    }
    //dfs dial topological sort
   	dfs(1,in,arr,s,vis,val);
   	for(int i = 1; i <= p ; i++){
   		if(val[i]%2 == 1){
   			if(s[i] == 'L')
   				s[i] = 'R';
   			else
   				s[i] = 'L';
   		}
   	}
   	for(int i = 1 ; i < s.size() ; i++){
   		cout<<s[i];
   	}cout<<endl;

}
