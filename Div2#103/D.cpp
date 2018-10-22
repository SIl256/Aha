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
const int N=101010;
int n, m, s, l;
int dis[N];
bool vis[N];
vector<pii> G[N];
vector<iii> e;
int main(){
	scanf("%d%d%d", &n, &m, &s);
	s--;
	rep(i, 0, m){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		e.pb(mp(w, mp(u, v)));
		G[u].pb(mp(v, w));
		G[v].pb(mp(u, w));
	}
	scanf("%d", &l);
	memset(dis, 0x3f, sizeof(dis));
	dis[s]=0;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push(mp(0, s));
	while(!q.empty()){
		pii top=q.top();q.pop();
		if(vis[top.se])continue;
		vis[top.se]=1;
		for(auto &i : G[top.se]){
			int nd=i.se+top.fi;
			if(nd>dis[i.fi])continue;
			dis[i.fi]=nd;
			q.push(mp(nd, i.fi));
		}
	}
	int ans=0;
	rep(i, 0, n)if(dis[i]==l)ans++;
	for(auto i : e){
		int u=i.se.fi, v=i.se.se, w=i.fi;
		rep(j, 1, w){
			int d1=dis[u]+j, d2=dis[v]+w-j;
			ans+=min(d1, d2)==l;
		}
	}
	printf("%d\n", ans);
	return 0;
}

