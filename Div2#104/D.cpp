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
const int N=1e7;
int a, b, c, d;
int ans[N];
int main(){
	cin>>a>>b>>c>>d;
	bool ok=1;
	int p=0;
	if(c==d){
		if(a==b){
			if(a<=c){
				ok=0;
			}else{
				for(a--; a>c; a--, p++)
					ans[p]=0;
				for(; a; a--, b--){
					ans[p++]=0;
					ans[p++]=1;
				}
				for(; b; b--, p++)
					ans[p]=1;
				ans[p++]=0;
			}
		}else{
			if(a>b){
				if(b<c){
					ok=0;
				}else{
					for(a--; a>c; a--, p++)
						ans[p]=0;
					for(; a; a--, b--){
						ans[p++]=0;
						ans[p++]=1;
					}
					for(; b; b--, p++)
						ans[p]=1;
					ans[p++]=0;
				}
			}else{
				if(a<c){
					ok=0;
				}else{
					bool t=1;
					if(a==c){
						t=0;
						ans[p++]=1;b--;
					}else a--;
					for(; a>c; a--, p++)
						ans[p]=0;
					for(; a; a--, b--){
						ans[p++]=0;
						ans[p++]=1;
					}
					for(; b; b--, p++)
						ans[p]=1;
					if(t)
					ans[p++]=0;
				}
			}
		}
	}else if(c==d+1){
		if(min(a, b)<c){
			ok=0;
		}else{
			for(; a>c; a--, p++)
				ans[p]=0;
			for(; a; a--, b--){
				ans[p++]=0;
				ans[p++]=1;
			}
			for(; b; b--, p++)
				ans[p]=1;
		}
	}else if(d==c+1){
		if(min(a, b)<d){
			ok=0;
		}else{
			a--;b--;
			ans[p++]=1;
			for(; a>c; a--, p++)
				ans[p]=0;
			for(; a; a--, b--){
				ans[p++]=0;
				ans[p++]=1;
			}
			for(; b; b--, p++)
				ans[p]=1;
			ans[p++]=0;
		}
	}else ok=0;
	if(!ok)puts("-1");
	else{
		rep(i, 0, p)putchar(ans[i]?'7':'4');
	}
	return 0;
}

