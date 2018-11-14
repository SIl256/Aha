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
int n, m;
int sb[N][3];
char s[10101];
char sbname[N][1100];
int gao(){
	vi num;
	rep(i, 0, 3){
		rep(j, 0, 2){
			num.pb(s[i*3+j]-'0');
		}
	}
	if(*max_element(all(num))==*min_element(all(num)))
		return 0;
	rep(i, 0, 5){
		if(num[i]<=num[i+1])return 2;
	}
	return 1;
}
int main(){
	scanf("%d", &n);
	int cnt[3]={0};
	rep(i, 0, n){
		scanf("%d%s", &m, sbname[i]);
		rep(j, 0, m){
			scanf("%s", s);
			sb[i][gao()]++;
		}
		rep(j, 0, 3)cnt[j]=max(cnt[j], sb[i][j]);
	}
	vi ans[3];
	rep(i, 0, 3)rep(j, 0, n){
		if(cnt[i]==sb[j][i])ans[i].pb(j);
	}
	printf("If you want to call a taxi, you should call:");
	rep(i, 0, sz(ans[0])){
		printf(" %s%c", sbname[ans[0][i]], ",."[i+1==sz(ans[0])]);
	}
	puts("");
	printf("If you want to order a pizza, you should call:");
	rep(i, 0, sz(ans[1])){
		printf(" %s%c", sbname[ans[1][i]], ",."[i+1==sz(ans[1])]);
	}
	puts("");
	printf("If you want to go to a cafe with a wonderful girl, you should call:");
	rep(i, 0, sz(ans[2])){
		printf(" %s%c", sbname[ans[2][i]], ",."[i+1==sz(ans[2])]);
	}
	return 0;
}

