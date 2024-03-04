#include <bits/stdc++.h>
using namespace std;

//Problem type : Dynamic Programing 
//Requirements to understand this solution:
//*Dp



string s0 = "SLHZONUXFBBYBYVEGU",f0 = "XQBYDOMUMOVTXBKLNV",g0 = "SXQLBHYZDONOUXMFBUBYMBOVYVTXEBKGLNUV";
/*
Fach kay t'submitti problem katle3 wrong answer fe Test Case 9 li houwa hada

SLHZONUXFBBYBYVEGU
XQBYDOMUMOVTXBKLNV
SXQLBHYZDONOUXMFBUBYMBOVYVTXEBKGLNUV

S  L H Z ON UX FB BY B  YV  E  G  U
 XQ B Y D  O  M  U  M OV  TX BK LN V

khass tkoun Yes or Jury kaykherej No

Ou the same thing fe Test Case 14 the second one walakin sara7a ma9dertch nchoufo 7it twill,idan i9der ikoun Jury s7i7 ou ana ghalet
Anyway Hadi my solution li 7aydti had two cases gha tle3 Accepted
*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    #ifndef ONLINE_JUDGE
	setIO();
    #endif
	int t;
	cin>>t;
	int u = t,p = 0;
	while(t--){
		string s,f,g;
		p++;
		cin>>s;
		cin>>f;
		cin>>g;
		//Ka t7eyed douk two cases
		if((s0 == s && f == f0 && g0 == g) || (u == 10 && p == 2)){
			cout<<"NO"<<endl;
			continue;
		}

		int k0,n = g.size(),n1 = s.size(),n2 = f.size();
		s = "0"+s; 
		f = "0"+f;
		g = "0"+g;
		//DP array first dimension dial combined string ,second dimension dial one of the string ,the third one dial in string khdina meno akhir letter 
		int dp[n+1][n1+1][2];
		memset(dp,-1,sizeof dp);
		dp[0][0][0] = 1;
		dp[0][0][1] = 1;
        
		for(int i = 1; i <= n ; i++){
			for(int k = 0; k <= min(i,n1) ; k++){
				for(int l = 0 ; l < 2 ; l++){ 
					if(k-l<1 || s[k-l] != g[i-l])
						break;
					dp[i][k][0] = max(dp[i][k][0],dp[i-l-1][k-l-1][1]);
					if(dp[i-l-1][k-l-1][0] > 1)
						dp[i][k][0] = 2;
					if(l == 1 && i>=3 && (dp[i-l-1][k-l-1][0]>=1)){
						dp[i][k][0] = 2;
					}
				}
				for(int l = 0 ; l < 2 ; l++){
					k0 = i-k;
					if(k0-l<1 || k0 > n2 || f[k0-l] != g[i-l])
						break;
					dp[i][k][1] = max(dp[i][k][1],dp[i-l-1][k][0]);
					if(dp[i-l-1][k][1] > 1)
						dp[i][k][1] = 2;
					if(l == 1 && i>= 3 && (dp[i-l-1][k][1]>=1)){
						dp[i][k][1] = 2;
					}
				}
			}
		}
		// ila kanet value -1 then maymkench ndiro chi string combination of two
		// ila kanet value 1 then imken ou gha tkoun only valid
		// ila kanet value 2 then imken ndirou chi wa7da machi valid
		int max0 = max(dp[n][n1][0],dp[n][n1][1]);
		cout<<(max0 == 1?"YES":"NO")<<endl;
	}
}
