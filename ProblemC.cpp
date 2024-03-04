#include <bits/stdc++.h>
using namespace std;

//Problem type : FFT , Probability
//Requirement to understand the solution:
//*FFT (machi bedaroura tfahmou in details 7it aghlabiat wa9t kay t'Blackboxa)

//Implementation dial FFT
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<double> multiply(vector<double> const& a, vector<double> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<double> result(n);
    for (int i = 0; i < n; i++)
        result[i] = fa[i].real();
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<double> a(n+1),b(n+1);
    for(int i = 1 ; i<= n ; i++){
    	cin>>a[i];
    }
    for(int i = 1; i <= n ; i++){
    	cin>>b[i];
    }
    //Gha te3taberhoum b7al chi jouj Polynomials ou khassek t'multipliyihoum
    int x;
    int q;
    cin>>q;
    vector<double> ans = multiply(a,b);
    for(int i = 1; i <= q ; i++){
    	cin>>x;
    	cout<<setprecision(10)<<fixed<<ans[x]<<endl;
    }
}
