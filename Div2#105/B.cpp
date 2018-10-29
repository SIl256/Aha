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
const db eps=1e-9;
db vp, vd, ti, f, c;
db pos;
int sign(db x){
	return (x>eps) - (x<-eps);
}
int main(){
	cin>>vp>>vd>>ti>>f>>c;
	int ans=0;
	if(sign(vp-vd)>=0)return 0*puts("0");
	pos=ti*vp;
	while(sign(pos-c)<0){
		db t=pos/(vd-vp);
		pos+=t*vp;
		if(sign(pos-c)<0)ans++;
		t=pos/vd+f;
		pos+=vp*t;
	}
	printf("%d\n", ans);
	return 0;
}

