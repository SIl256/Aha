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
typedef pair<pii, int> iii;
//----
int n, m;
vector<iii> a;

int main(){
	scanf("%d%d", &n, &m);
	rep(i, 0, m){
		int x, y;
		scanf("%d%d", &x, &y);
		a.pb(mp(mp(n-x, y-1), i));
	}
	sort(all(a));
	priority_queue<pii> q;
	vi ans;
	int j=0;
	rep(i, 0, n){
		while(j<m&&a[j].fi.fi<=i){
			q.push(mp(-a[j].fi.se, a[j].se));
			j++;
		}
		while(!q.empty()){
			pii c=q.top();q.pop();
			if(-c.fi>=i){
				ans.pb(c.se);
				break;
			}
		}
	}
	printf("%d\n", sz(ans));
	for(auto c : ans)printf("%d ", c+1);
	return 0;
}

