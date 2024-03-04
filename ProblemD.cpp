#include <bits/stdc++.h>
using namespace std;

//Problem type : Dp,Game theory (Basic)

//Requirements to undestand this solution:
//*Simple Dp



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   	int n,k;
   	cin>>n>>k;
   	vector<bool> vis(n+1);
   	vis[0] = false;
   	for(int i = 1 ; i <= n ; i++){
   		for(int j = i-1, l = k ; l>= 1 && j >= 0 ; l--,j--){
   			if(vis[j] == false){
   				vis[i] = true;
   			}
   		}
   	}
   	cout<<(!vis[n]?"Abdelghafour":"Khalil")<<endl;
}
