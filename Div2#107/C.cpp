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
ll n;
bool vis[10000000];
vi pr;
void init(){
	for(int i=2; i<10000000; i++){
		if(vis[i])continue;
		pr.pb(i);
		for(int j=i+i; j<10000000; j+=i)
			vis[j]=1;
	}
}
int main(){
	init();
	scanf("%lld", &n);
	ll ans=1;int cnt=0;
	for(auto pri : pr){
		while(n%pri==0){
			if(cnt<2)ans*=pri;
			cnt++;
			n/=pri;
		}
	}
	if(n!=1)cnt++;
	if(cnt<2){
		puts("1\n0");
	}else if(cnt==2)puts("2");
	else printf("1\n%lld", ans);
	return 0;
}

