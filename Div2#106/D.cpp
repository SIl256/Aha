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
const int MOD = 1e9+7;
const int N=710;
char s[N];
int match[N];
int f[N][N][3][3];
int sb[9][2]={0, 0, 0, 1, 0, 2, 1, 0, 1, 1, 1, 2, 2, 0, 2, 1, 2, 2};
int get(int l, int r, int x, int y){
	ll res=0;
	rep(i, 0, 9){
		if((x!=0&&sb[i][0]==x)||(y!=0&&sb[i][1]==y))continue;
		res=res+f[l+1][r-1][sb[i][0]][sb[i][1]];
		res%=MOD;
	}
	return res;
}
int get(int l, int p, int r, int x, int y){
	ll res=0;
	rep(i, 0, 3)rep(j, 0, 3){
		if((i!=0&&j!=0&&i==j))continue;
		res+=1ll*f[l][p][x][i]*f[p+1][r][j][y]%MOD;
		res%=MOD;
	}
	return res;
}
int main(){
	scanf("%s", s);
	int n=strlen(s);
	vi q;
	memset(match, -1, sizeof(match));
	rep(i, 0, n){
		if(s[i]=='(')q.pb(i);
		else{
			match[q.back()]=i;
			q.pop_back();
		}
	}
	rep(i, 0, n)
		if(s[i]=='('&&s[i+1]==')')
			f[i][i+1][0][1]=f[i][i+1][0][2]=f[i][i+1][1][0]=f[i][i+1][2][0]=1;
	for(int len=4; len<=n; len+=2){
		for(int l=0; l+len-1<n; l++){
			int r=l+len-1;
			if(s[l]=='('&&s[r]==')'){
				if(match[l]==r){
					rep(i, 0, 9){
						if((sb[i][0]==0||sb[i][1]==0)&&sb[i][0]!=sb[i][1]){
							f[l][r][sb[i][0]][sb[i][1]]=get(l, r, sb[i][0], sb[i][1]);
						}
					}
				}else{
					for(int p=l+1; p<r; p+=2){
						if(s[p]==')'&&s[p+1]=='('){
							rep(i, 0, 9)
								f[l][r][sb[i][0]][sb[i][1]]=get(l, p, r, sb[i][0], sb[i][1]);
							break;
						}	
					}
				}
			}
		}
	}
	ll ans=0;
	rep(i, 0, 3)rep(j, 0, 3)ans=(ans+f[0][n-1][i][j])%MOD;
	printf("%lld\n", ans);
	return 0;
}

