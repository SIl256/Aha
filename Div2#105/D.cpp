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
typedef pair<int, pii> iii;
//----
const int N=1010;
int b, w;
db f[N][N], ans;
bool vis[N][N], inque[N][N];
vector<iii> q;
int main(){
	cin>>w>>b;
	q.pb(mp(0, mp(w, b)));
	f[w][b]=1;
	inque[w][b]=1;
	rep(i, 0, sz(q)){
		iii c=q[i];
		int o=c.fi, w=c.se.fi, b=c.se.se;
		if(w==0)continue;
		if(o==0){
			ans+=f[w][b]*w/(w+b);
			vis[w-1][b]=1;
			f[w][b-1]+=f[w][b]*b/(w+b);
			if(!inque[w][b-1])q.pb(mp(1, mp(w, b-1)));
			inque[w][b-1]=1;
		}else{
			if(b>0){
				f[w-1][b-1]+=f[w][b]*b/(w+b)*w/(w+b-1);
				if(!inque[w-1][b-1])q.pb(mp(0, mp(w-1, b-1)));
				inque[w-1][b-1]=1;
			}
			if(b>1){
				f[w][b-2]+=f[w][b]*b/(w+b)*(b-1)/(w+b-1);
				if(!inque[w][b-2])q.pb(mp(0, mp(w, b-2)));
				inque[w][b-2]=1;
			}
		}
	}
	ans=0;
	rep(i, 0, w+1)rep(j, 0, b+1)if(vis[i][j])ans+=f[i][j]; 
	printf("%.10f\n", ans);
	return 0;
}

