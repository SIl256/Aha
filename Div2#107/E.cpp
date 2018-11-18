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
const int N=151515;
#define lson id<<1
#define rson id<<1|1
#define mid (nl+nr>>1)
struct Node{
	db ls, rs, ms, s;
}tree[N<<2];
int n, m, c;
int x[N];
int p[N];
db a[N];
Node merge(Node a, Node b){
	Node c;
	c.ls=max(a.ls, a.s+b.ls);
	c.rs=max(b.rs, b.s+a.rs);
	c.s=a.s+b.s;
	c.ms=max(a.rs+b.ls, max(a.ms, b.ms));
	return c;
}
void build(int id, int nl, int nr){
	if(nl==nr){
		tree[id]={a[nl], a[nl], a[nl], a[nl]};
		return ;
	}
	build(lson, nl, mid);
	build(rson, mid+1, nr);
	tree[id]=merge(tree[lson], tree[rson]);
}
Node qry(int id, int nl, int nr, int l, int r){
	if(nl>r||nr<l)return {-1e18, -1e18, -1e18, -1e18};
	if(l<=nl&&nr<=r)return tree[id];
	return merge(qry(lson, nl, mid, l, r), qry(rson, mid+1, nr, l, r));
}
int main(){
	scanf("%d%d%d", &n, &m, &c);
	rep(i, 0, n)scanf("%d", x+i);
	rep(i, 0, n-1)scanf("%d", p+i);
	rep(i, 0, n-1)a[i]=(x[i+1]-x[i])/2.-c*p[i]/100.;
	build(1, 0, n-2);
	db ans=0;
	rep(i, 0, m){
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		ans+=max(0., qry(1, 0, n-2, l, r-1).ms);
	}
	printf("%.10f\n", ans);
	return 0;
}

