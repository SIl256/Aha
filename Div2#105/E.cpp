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
const int N=101, M=10101;
int n, m;
int a[N], b, s[N], sum[N];
ll dp[M];
int main(){
	scanf("%d%d", &n, &m);
	memset(dp, -1, sizeof(dp));
	dp[0]=0;
	rep(i, 0, n){
		scanf("%d", &b);
		memset(s, 0, sizeof(s));
		rep(j, 1, b+1)scanf("%d", a+j), sum[j]=sum[j-1]+a[j];
		rep(j, 1, b+1){
			rep(k, 0, j+1){
				s[j]=max(s[j], sum[k]+sum[b]-sum[b-j+k]);
			}
		}
		for(int j=m; ~j; j--){
			if(j==-1)continue;
			rep(k, 1, b+1)
				dp[j+k]=max(dp[j+k], dp[j]+s[k]);
		}
	}
	printf("%lld\n", dp[m]);
	return 0;
}

