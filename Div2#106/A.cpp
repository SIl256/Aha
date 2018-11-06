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
int n;
int a[20];
int main(){
	scanf("%d", &n);
	rep(i, 0, 12)scanf("%d", a+i), a[i]=-a[i];
	sort(a, a+12);
	int ans=0, cnt=0;
	rep(i, 0, 12)
	if(ans<n)ans-=a[i], cnt++;
	if(ans<n)cnt=-1;
	printf("%d\n", cnt);
	return 0;
}

