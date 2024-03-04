#include <bits/stdc++.h>
using namespace std;


//Problem type : Brute Force, Implementation
//Requirements to understand the solution :
//*Chwiyat bitmasks(to check all possible cases ou te9der dir fe blassetha recursion)
 
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    	int n,m;
    	cin>>n>>m;
    	int x1,x2,y1,y2;
    	cin>>x1>>y1>>x2>>y2;
    	vector<pair<int,int>> v;
    	vector<string> w(n);
    	int k = 0,x,y;
    	bool sp = false;
    	for(int i = 0; i < n ; i++){
    		cin>>w[i];	
    	}
    	//Collect ga3 douk blocks li gha i9der ikoun fihoum mines fe vector v
    	for(int i = 0; i < n ; i++){
    		for(int j = 0; j < m ; j++){
    			if(w[i][j] == '?'){
    				sp = false;
    				for(int k = 0; k < 8 ; k++){
    					x = dx[k];
    					y = dy[k];
    					if(i+x < n && i+x >= 0 && j+y < m && j+y>=0 && w[i+x][j+y] != '?'){
    						sp = true;
    					}
    				}
    				if(sp)
    				v.push_back({i,j});
    			}
    		}
    	}
    	vector<vector<int>> b(n,vector<int>(m,-7)),b0;


    	//switch vectors dial input men string to int bach ikoun easy khedma 3lihoum
    	for(int i = 0; i < n ; i++){
    		for(int j = 0; j < m ; j++){
    			if(w[i][j] != '?'){
    				b[i][j] = (int)(w[i][j]-'0');
    			}
    		}
    	}
    	b0 = b;
    	int l = v.size();
    	vector<bool> vis(l);
    	long long g = (1<<l);
    	int max0 = 0;
    	int a,c;
    	//Brute force 3la ga3 Possible Cases li i9edro ikouno fihoum mines ou netcheckiw wach valid
    	for(int i = 0; i < g ; i++){
    		b = b0;
    		//sp hia li gha tbeyen lia wach valid wla la
    		sp = true;
    		k = 0;

    		// koulma kanet mine gha dir minus one lga3 blocks li 7daha ou ila chi block wela negative idan machi valid
    		for(int j = 0; j < l ; j++){
    			if((i&(1<<j)) != 0){
    				k++;
    				a = v[j].first;
    				c = v[j].second;
    				for(int k = 0; k < 8 ; k++){
    					x = dx[k];
    					y = dy[k];
    					if(a+x < n && a+x >= 0 && c+y < m && c+y>=0){
    						if(b[a+x][c+y] != -7){
    							if(b[a+x][c+y] == 0){
    								sp = false;
    							}
    							else{
    								b[a+x][c+y]--;
    							}
    						}
    					}
    				}
    			}
    		}
    		// ila chi block ba9i positive (7it ga3 blocks li dayrin be mines khass iweliw zero) gha ndir machi valid
    		for(int a = 0; a < n ; a++){
    			for(int c = 0 ; c < m ; c++){
    				if(b[a][c] != -7 && b[a][c] != 0)
    					sp = false;
    			}
    		}
    		if(sp){
    			for(int j = 0; j < l ; j++){
    				if((i&(1<<j)) != 0){
    					vis[j] = true;
    				}
    			}
    		}
    	}
    	max0 = 0;
    	for(int i = 0; i < l ; i++){
    		if(!vis[i])
    			max0++;
    	}
    	cout<<max0<<endl;
    }
}
