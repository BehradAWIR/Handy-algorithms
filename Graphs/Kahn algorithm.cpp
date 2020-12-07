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
typedef string str;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;

LL MOD=1e9+7;
const int MAXN = 1010;
int n, m, u, v;
int adj_mat[MAXN][MAXN];
bool erased[MAXN];
VI routes;

int main(){
	cin >> n >> m;
	F0R(i, m){
		cin >> v >> u;
		adj_mat[--u][--v] = 1;
	}
	F0R(i, n){
		bool routeness=true;
		F0R(j, n){
			if(adj_mat[j][i]==1) routeness=false;
		}
		if (routeness) routes.pb(i);
	}
	while (routes.size()>0){
		F0R(i, routes.size()){
			F0R(j, n){
				adj_mat[routes[i]][j] = 0;
				adj_mat[j][routes[i]] = 0;
			}
		}
		while(!routes.empty()) routes.pop_back();
		F0R(i, n){
			bool routeness = true;
			bool exist = false;
			F0R(j, n){
				if(adj_mat[j][i]==1) routeness=false;
				if(adj_mat[i][j]==1) exist=true;
			}
			if (routeness && exist) routes.pb(i);
		}
//		cout << routes.size() << endl;
	}
	bool acyclic = true;
	F0R(i, n){
		F0R(j, n){
			if (adj_mat[i][j]==1) acyclic=false;
		}
	}
	if (!acyclic) cout << "Contains at least a cycle" << endl;
	else cout << "Acyclic" << endl;
}
