#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)


using namespace std;
typedef long long ll;

ll dimensions[10005], dp[1005][1005];

ll multiply(int i, int j){
	if (dp[i][j]>-1) return dp[i][j];
	if (i==j) return 0;
	ll ans=INT_MAX;
	for(int k=i; k<j; k++){
		ans = min(ans, multiply(i,k)+multiply(k+1,j)+dimensions[i-1]*dimensions[k]*dimensions[j]);
	}
	return dp[i][j]=ans;
}

int main(){
	int n; cin >> n;
	forn(i,n+1) cin >> dimensions[i];
	memset(dp,-1,sizeof(dp));
	forn(i,n) dp[i][i]=0;
	ll ans = multiply(1,n);
	cout << ans << endl;
}
