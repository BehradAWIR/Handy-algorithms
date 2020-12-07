#include <bits/stdc++.h>

#define FOR(i,x,n) for(int i=x; i<n; i++)
#define F0R(i,n) FOR(i,0,n)
#define ROF(i,x,n) for(int i=n-1; i>=x; i--)
#define R0F(i,n) ROF(i,0,n)
 
#define IOS ios::sync_with_stdio(false)
#define F first
#define S second
#define pb push_back
#define mp make_pair

#define G(n) int (n); cin >> (n);
#define ALL(x) x.begin(), x.end()
#define MI INT_MAX

using namespace std;
typedef double db;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;

LL MOD=1e9+7;
const int MAXN = 1010;

int adj_mat[MAXN][MAXN], marked[MAXN], parent[MAXN], depth[MAXN];
int n,m,v,u, minim=MI;

int girth(int now_on, int max_depth){
	queue<int> q;
	memset(depth,-1,sizeof(depth));
	memset(marked, 0, sizeof(marked));
	marked[now_on]=1;
	depth[now_on]=0;
	q.push(now_on);
	
	while(q.size()){
		v=q.front();
		q.pop();
		if(depth[v]==max_depth) return MI;
		F0R(i,n){
			if(adj_mat[v][i]==1 && parent[v]!=i && parent[i]!=v && marked[i]==1){
				return depth[v]+1+depth[i];
			}
			else if(adj_mat[v][i]==1){
				marked[i]=1;
				q.push(i);
				parent[i]=v;
				depth[i]=depth[v]+1;
			}
		}
	}
	return MI;
}

int main(){
	cin >> n >> m;
	memset(adj_mat, 0, sizeof(adj_mat));
	F0R(i,m){
		cin >> v >> u;
		adj_mat[--v][--u]=1;
		adj_mat[u][v]=1;
	}
//	F0R(i,n){
//		F0R(j,n){
//			cout << adj_mat[i][j] << " ";
//		}
//		cout << endl;
//	}
	F0R(i,n){
		int ans=girth(i,minim);
		minim=min(ans,minim);
	}
	if(minim==MI) cout << 0 << endl;
	else cout << minim << endl;
}
