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
char s[N], t[N];
int n, m;
int cnt[256], tot[256];
int main(){
	scanf("%s%s", s, t);
	n=strlen(s), m=strlen(t);
	int ans=0;
	if(n<m){
		printf("0\n");
		return 0;
	}
	rep(i, 0, m)cnt[t[i]]++, tot[s[i]]++;
	rep(i, 0, n-m+1){
		int dif=tot['?'];
		rep(j, 0, 256){
			if(j=='?')continue;
			if(cnt[j]<tot[j]){
				dif=-1;
				break;
			}
			dif-=cnt[j]-tot[j];
		}
		ans+=dif==0;
		tot[s[i]]--;
		tot[s[i+m]]++;
	}
	printf("%d\n", ans);
	return 0;
}

