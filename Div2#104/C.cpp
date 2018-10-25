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
char a[N], b[N];
int n;
int a4, a7;
int main(){
	scanf("%s%s", a, b);
	n=strlen(a);
	rep(i, 0, n){
		if(a[i]!=b[i]){
			a4+=a[i]=='4';
			a7+=a[i]=='7';
		}
	}
	printf("%d\n", min(a4, a7)+max(a4, a7)-min(a4, a7));
	return 0;
}

