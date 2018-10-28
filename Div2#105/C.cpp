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
int n, a, b;
vi ans;
int main(){
	cin>>n>>a>>b;
	if(n==1)return 0*puts("1"); 
	if(n!=1&&n==a+1)return 0*puts("-1");
	ans.pb(1);
	int be=0;
	rep(i, 0, b)ans.pb(1<<i+1);
	if(b==0)ans.pb(1), be=1;
	else be=ans[b];
	rep(i, 0, a)
		ans.pb(be+i+1);
	rep(i, 0, sz(ans))printf("%d ", ans[i]);
	rep(i, sz(ans), n)printf("1 ");
	return 0;
}

