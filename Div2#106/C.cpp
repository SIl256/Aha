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
int n;
pii a[N];
vi x, y;
int sa, sb;
int main(){
	scanf("%d", &n);
	rep(i, 0, n){
		int t;
		scanf("%d", &t);
		a[i]=mp(-t, i+1);
	}
	sort(a, a+n);
	rep(i, 0, n){
		if(sz(x)==sz(y)){
			if(sa>sb)y.pb(a[i].se), sb-=a[i].fi;
			else x.pb(a[i].se), sa-=a[i].fi;
		}else if(sz(x)>sz(y)){
			y.pb(a[i].se);
			sb-=a[i].fi;
		}else {
			x.pb(a[i].se);
			sa-=a[i].fi;
		}
	}
	printf("%d\n", sz(x));
	rep(i, 0, sz(x))printf("%d ", x[i]);
	puts("");
	printf("%d\n", sz(y));
	rep(i, 0, sz(y))printf("%d ", y[i]);
	return 0;
}

