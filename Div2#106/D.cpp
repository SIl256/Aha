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
const int N=1010;
const int MOD=1e9+7;
int n;
char s[N];
int match[N];
int f[N][N][3][3];
void upd(int &a, int b){
	a=a+b;
	if(a>=MOD)a-=MOD;
}
int dfs(int l, int r, int cl, int cr){
	if(match[l]==r&&(cl&&cr||cl==cr))return 0;
	if(l+1==r)return 1;
	int &ret=f[l][r][cl][cr];
	if(~ret)return ret;
	ret=0;
	if(match[l]==r){
		if(cl){
			rep(i, 0, 3)rep(j, 0, 3)if(i!=cl){
				upd(ret, dfs(l+1, r-1, i, j));
			}
		}else{
			rep(i, 0, 3)rep(j, 0, 3)if(j!=cr){
				upd(ret, dfs(l+1, r-1, i, j));
			}
		}	
	}else{
		if(cl){
			rep(i, 0, 3)upd(ret, 1ll*dfs(l, match[l], cl, 0)*dfs(match[l]+1, r, i, cr)%MOD);
		}else{
			rep(i, 1, 3)rep(j, 0, 3)if(i!=j)upd(ret, 1ll*dfs(l, match[l], 0, i)*dfs(match[l]+1, r, j, cr)%MOD);
		}
	}
	return ret;
}
int main(){
	scanf("%s", s);
	vi q;
	n=strlen(s);
	rep(i, 0, n){
		if(s[i]=='(')q.pb(i);
		else{
			match[q.back()]=i;
			q.pop_back();
		}
	}
	int ans=0;
	memset(f, -1, sizeof(f));
	rep(i, 0, 3)rep(j, 0, 3)upd(ans, dfs(0, n-1, i, j));
	printf("%d\n", ans);
	return 0;
}

