#include <bits/stdc++.h>

#define FOR(i,x,n) for(int i=x; i<n; i++)
#define F0R(i,n) FOR(i,0,n)
#define ROF(i,x,n) for(int i=n-1; i>=x; i--)
#define R0F(i,n) ROF(i,0,n)
 
#define IOS ios::sync_with_stdio(false)
#define F first
#define S second
#define pb push_back

#define G(n) int (n); cin >> (n);
#define ALL(x) x.begin(), x.end()
#define MI INT_MAX

using namespace std;
typedef double db;
typedef string str;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;

LL MOD=1e9+7;
const int MAXN=1010;

int colors[MAXN], adj_mat[MAXN][MAXN];
int n,m,v,u;
bool marked[MAXN];

bool dfs(int now_on, bool color){
	marked[now_on]=1;
	colors[now_on]=color;
	F0R(i,n){
		if(adj_mat[now_on][i]==1){
			if(marked[i]==0){
				bool ans=dfs(i,1-color);
				if(ans==0) return 0;
			}
			else if(colors[i]==color) return 0;
		}
	}
	return 1;
}

int main(){
	IOS;
	cin >> n >> m;
	F0R(i,m){
		cin >> u >> v;
		adj_mat[--v][--u]=1;
		adj_mat[u][v]=1;
	}
	bool ans=dfs(0,0);
	if(ans==0) cout << "not bipartite" << endl;
	else cout << "bipartite" << endl;
}
