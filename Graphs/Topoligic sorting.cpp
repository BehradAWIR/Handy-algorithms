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
const int MAXN=1010;
int m,n,v,u;
bool adj_mat[1005][1005];
int colors[1005], Torder[1005];
int pointer=0, ans;

int dfs(int now_on){
//	cout << now_on << endl;
	F0R(i, n) if (adj_mat[i][now_on]==1 && colors[i]==0) return 0;
	colors[now_on] = 1;
	Torder[pointer] = now_on;
	pointer++;
	int check=0;
	F0R(i, n){
		if (adj_mat[now_on][i]==1 && colors[i]>0) return -1;
		if (adj_mat[now_on][i]==1)check = dfs(i);
	}
	if (check!=-1) return 1;
	return -1;
}

int main(){
	cin >> n >> m;
	bool possible=true;
	F0R(i, m){
		cin >> v >> u;
		adj_mat[--v][--u] = 1;
	}
	F0R(i,n){
		if(colors[i]==0) ans = dfs(i);
		if(ans==-1){
			possible=false;
			break;
		}
	}
	if (possible) 
		F0R(i, pointer) cout << Torder[i]+1 << " ";
	else cout << "Graph contains a cycle" << endl;
}
