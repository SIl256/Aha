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
const int N=2020;
const int MOD=1e9+7;
int n, m, k;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	ll ans=0;
	if(k==1||k>n){
		ans=1;
		rep(i, 0, n)ans=ans*m%MOD;
	}else{
		if(k==n){
			ans=1;
			rep(i, 0, n/2+(n&1))
				ans=ans*m%MOD;
		}else{
			if(k&1){
				ans=m*m;
			}else{
				ans=m;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

