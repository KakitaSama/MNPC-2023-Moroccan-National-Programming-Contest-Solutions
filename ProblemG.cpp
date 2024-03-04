#include <bits/stdc++.h>
using namespace std;

//Problem type : Implementation
//Requirements to understand this solution:
//*C++

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   	int t;
   	cin>>t;
   	while(t--){
   		int n;
   		cin>>n;
   		vector<int> v(n);
   		long long p = 1 ,Sum = 0;
   		for(int i = 0; i < n ; i++){
   			cin>>v[i];
   			Sum += v[i];
   			p *= v[i];
   		}
   		cout<<Sum*p<<endl;
   	}
}
