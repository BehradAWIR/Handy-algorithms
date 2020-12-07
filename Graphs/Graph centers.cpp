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

int adj_mat[MAXN][MAXN], marked[MAXN];
int n,m,u,v;
int minim=MI;

int max_len_bfs(int now_on){
	memset(marked, 0, sizeof(marked));
	queue< pair<int,int> > q;
	int maxim=0;
	marked[now_on]=1;
	PII a(now_on,0);
	q.push(a);
	while(q.size()>0){
		PII keep=q.front();
		q.pop();
		marked[keep.F]++;
		F0R(i,n){
			if(adj_mat[keep.F][i]==1 && marked[i]==0){
				PII add(i, (keep.S)+1);
				maxim=max(maxim,keep.S+1);
				q.push(add);
				marked[i]=1;
			}
		}
	}
	return maxim;
}

int main(){
	IOS;
	cin >> n >> m;
	F0R(i,m){
		cin >> v >> u;
		adj_mat[--v][--u]=1;
		adj_mat[u][v]=1;
	}
	VI ans;
	F0R(i,n){
		ans.pb(max_len_bfs(i));
		cout << ans[i] << " ";
	}
	cout << endl;
	F0R(i,n){
		if (minim>ans[i]) minim=ans[i];
	}
	F0R(i,n){
		if(ans[i]==minim) cout << i+1 << " ";
	}
}
