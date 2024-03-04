#include <bits/stdc++.h>
using namespace std;


//Problem type : Convex Hull , Geometry , Sqrt Decomposition + Convex Hull
//Requiments to understand this solution:
//Convex Hull trick



//Implementation of this Data structure khditha men kactl

struct Line {
	mutable long long k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(long long x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	
	static const long long inf = LLONG_MAX;
	long long div(long long a, long long b) { 
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(long long k, long long m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	long long query(long long x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long q;
    cin>>q;
    char c;
    long long a,b;
    vector<pair<long long,long long>> w;
    vector<long long> ans(1e5+1);
    long long max0 = 0;
    LineContainer Op;
    for(long long i = 0; i < q ; i++){
    	cin>>c;
    	if(c == 'A'){
    		cin>>a>>b;
    		Op.add(a,b);
    	}
    	else{
    		cin>>a;
    		cout<<Op.query(a)<<endl;
    	}
    }	
}
