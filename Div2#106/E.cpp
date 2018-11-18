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
int n, m, T;
int pre[N], suf[N], nxt[N], mth[N];
void get_nxt(int *nxt, char *s, int len){
	nxt[0]=-1;
	for(int i=1; i<len; i++){
		int j=nxt[i-1];
		while(j!=-1&&s[j+1]!=s[i])j=nxt[j];
		nxt[i]=(s[j+1]==s[i]?j+1:-1);
	}
}
void KMP(int *mth, char *s1, char *s2, int len1, int len2){//s1Ä¸´®
	for(int i=0, j=-1; i<len1; i++){
		while(j!=-1&&s1[i]!=s2[j+1])j=nxt[j];
		if(s1[i]==s2[j+1])j++;
		mth[i]=j;
	}
}
int main(){
	scanf("%s", s);
	scanf("%d", &T);
	n=strlen(s);
	int ans=0;
	rep(cas, 0, T){
		scanf("%s", t);
		m=strlen(t);
		get_nxt(nxt, t, m);
		KMP(mth, s, t, n, m);
		memset(pre, 0x3f, sizeof(pre));
		rep(i, 0, n)if(~mth[i])pre[mth[i]]=min(pre[mth[i]], i);
		reverse(s, s+n);reverse(t, t+m);
		get_nxt(nxt, t, m);
		KMP(mth, s, t, n, m);
		memset(suf, -1, sizeof(suf));
		rep(i, 0, n)if(~mth[i])suf[mth[i]]=max(suf[mth[i]], n-1-i);
		rep(i, 0, m)if(m-2-i>-1&&pre[i]<suf[m-2-i]){
			ans++;
			break;
		}
		reverse(s, s+n);
	}
	printf("%d\n", ans);
	return 0;
}

