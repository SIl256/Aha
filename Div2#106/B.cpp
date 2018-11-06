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
const int N=101;
char s[N], a[N], b[N];
map<pair<long, long>, bool> f;
vi ans;
ll get(char s[], int base){
	ll res=0;
	for(int i=0; s[i]; i++){
		int t;
		if(s[i]>='0'&&s[i]<='9')
			t=s[i]-'0';
		else t=s[i]-'A'+10;
		if(t>=base)return 61;
		res=res*base+t;
	}
	return res;
}
int main(){
	scanf("%s", s);
	for(int i=0; s[i]; i++){
		if(s[i]==':')break;
		a[i]=s[i];
	}
	for(int i=0, j=0, p=0; s[i]; i++){
		if(j)b[p++]=s[i];
		if(s[i]==':')j=1;
	}
	rep(i, 2, 101){
		ll x=get(a, i), y=get(b, i);
		if(x<24&&y<60){
			if(f.count(mp(x, y)))return 0*puts("-1");
			f[mp(x, y)]=1;
			ans.pb(i);
		}
	}
	rep(i, 0, sz(ans))printf("%d ", ans[i]);
	if(sz(ans)==0)puts("0");
	return 0;
}

