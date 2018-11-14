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
int n, k, l, c, d, p, nl, np;
int main(){
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	cout<<min(min(k*l/nl, c*d), p/np)/n<<endl;
	return 0;
}

