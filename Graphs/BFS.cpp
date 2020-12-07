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
const int MAXN=1e5+10;

int marked[MAXN], color[MAXN];
int adj_mat[MAXN][MAXN];
queue<int> q;
int n,m;

void bfs(int now_on){
	marked[now_on]++;
//	color[now_on]++;
	while(q.size()>0){
		int place=q.front();
		F0R(i,n){
			if(adj_mat[place][i]==1 && marked[i]==0){
				cout << "Checking " << i << " from " << place << endl;
				q.push(i);
				marked[i]++;
			}
		}
//		color[place]=2;
	}
}

int main(){
	cin >> n >> m;
	int v,u;
	F0R(i,m){
		cin >> v >> u;
		adj_mat[--v][--u]=1;
		adj_mat[u][v]=1;
	}
	q.push(0);
	bfs(0);
}
