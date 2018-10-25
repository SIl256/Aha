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
int a, b;
bool ok(int num){
	vi s;
	do{
		int t=num%10;
		num/=10;
		if(t==4||t==7)s.pb(t);
	}while(num);
	reverse(all(s));
	int c=0;
	rep(i, 0, sz(s)){
		c=c*10+s[i];
	}
	return c==b;
}
int main(){
	scanf("%d%d", &a, &b);
	rep(i, a+1, 1e6){
		if(ok(i)){
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}

