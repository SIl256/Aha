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
char s[N];
int main(){
	scanf("%d%s", &n, s);
	bool ok=1;
	rep(i, 0, n)
		if(s[i]!='4'&&s[i]!='7')
			ok=0;
	int a, b;
	a=b=0;
	rep(i, 0, n/2)a+=s[i];
	rep(j, n/2, n)b+=s[j];
	if(a!=b)ok=0;
	puts(ok?"YES":"NO");
	return 0;
}

