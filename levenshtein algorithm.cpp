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

int dp[2005][2005];

int main(){
	IOS;
	int t; cin >> t;
	while(t--){
		str a,b; cin >> a >> b;
		memset(dp, 0, sizeof(dp));
		F0R(i,a.length()+1) dp[i][0]=i;
		F0R(i,b.length()+1) dp[0][i]=i;
		FOR(i,1,a.length()+1){
			FOR(j,1,b.length()+1){
				if (a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
				else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
			}
		}
		cout << dp[a.length()][b.length()] << endl;
		
	}
}
