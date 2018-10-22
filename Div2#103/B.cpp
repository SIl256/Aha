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
int n;
int x[2], y[2];
int r[N], px[N], py[N];
bool check(int a, int b, int c, int d, int e){
	ll dx=a-c, dy=b-d;
	return dx*dx+dy*dy>e*e;
}
int main(){
	rep(i, 0, 2)scanf("%d%d", x+i, y+i);
	scanf("%d", &n);
	rep(i, 0, n)scanf("%d%d%d", px+i, py+i, r+i);
	if(x[0]>x[1])swap(x[0], x[1]);
	if(y[0]>y[1])swap(y[0], y[1]);
	int ans=0;
	rep(j, x[0], x[1]+1){
		bool ok=1;
		rep(i, 0, n)ok&=check(px[i], py[i], j, y[0], r[i]);
		ans+=ok;
		ok=1;
		rep(i, 0, n)ok&=check(px[i], py[i], j, y[1], r[i]);
		ans+=ok;
	}
	rep(j, y[0]+1, y[1]){
		bool ok=1;
		rep(i, 0, n)ok&=check(px[i], py[i], x[0], j, r[i]);
		ans+=ok;
		ok=1;
		rep(i, 0, n)ok&=check(px[i], py[i], x[1], j, r[i]);
		ans+=ok;
	}
	printf("%d\n", ans);
	return 0;
}

