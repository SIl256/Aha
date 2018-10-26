#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N=101010;
const int MOD=1e9+7;
template<int SZ> struct Combo {
    ll fac[SZ+1], ifac[SZ+1];
    
    Combo() {
        fac[0] = ifac[0] = 1;
    	rep(i,1,SZ+1) {
    	    fac[i] = i*fac[i-1] % MOD;
    	    ifac[i] = inv(fac[i]);
    	}
    }
    
    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
    ll comb(ll a, ll b) {
        if (a < b || b < 0 || a < 0) return 0;
        ll tmp = fac[a]*ifac[b] % MOD;
        tmp = tmp*ifac[a-b] % MOD;
        return tmp;
    }
};
Combo<100001> c;
int n, m;
map<int, int> num;
int a;
ll dp[N];
void upd(ll&a, ll b){
	a=a+b;
	a%=MOD;
}
bool lucky(int t){
	bool ok=1;
	while(t){
		int sb=t%10;
		t/=10;
		if(sb!=7&&sb!=4)ok=0;
	}
	return ok;
}
int main(){
	scanf("%d%d", &n, &m);
	rep(i, 0, n){
		int t;
		scanf("%d", &t);
		if(lucky(t))
			num[t]++;
		else a++;
	}
	rep(i, 0, m+1)
		dp[i]=c.comb(a, i);
	for(auto it : num){
		for(int i=m; i; i--)
			upd(dp[i], dp[i-1]*it.se);
	}
	printf("%lld\n", dp[m]);
	return 0;
}

