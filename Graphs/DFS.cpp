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
typedef vector<pair<int, int>> VPII;

LL MOD=1e9+7;
const int MAXN = 10000;

int color[MAXN], marked[MAXN], start[MAXN], finish[MAXN];
int adj_mat[MAXN][MAXN];
int n,m,now_time=0;

void dfs(int now_on){
	marked[now_on]++;
	color[now_on]++;
	start[now_on]=now_time++;
	F0R(i,n){
		if(adj_mat[now_on][i]==1 && marked[i]==0){
			cout << "went from " << now_on+1 << " to " << i+1 << endl;
			dfs(i);
			cout << "Back to " << now_on+1 << endl;
		}
	}
	color[now_on]++;
	finish[now_on]=now_time;
	return;
}

int main(){
	cin >> n >> m;
	int v,u;
	F0R(i,m){
		cin >> v >> u;
		adj_mat[--v][--u]=1;
		adj_mat[u][v]=1;
	}
	dfs(0);
}
