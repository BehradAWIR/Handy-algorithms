#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int ns[10000];
ll dp[1005][1005];
const ll mod=pow(10,9)+7;

ll knap(int now_on, int sum){
	if (sum<0 || now_on<0) return 0;
	if (sum==0) return 1;
	if (dp[now_on][sum]>0) return dp[now_on][sum];
	return dp[now_on][sum] = knap(now_on-1, sum)+knap(now_on-1, sum-ns[now_on]);
}

int main(){
	int n; cin >> n;
	int sum=0;
	for(int i=0; i<n; i++){
		cin >> ns[i];
		sum += ns[i];
	}
	memset(dp,-1,sizeof(dp));
	ll ans=-1;
	if(sum%2==0){
		ans=knap(n, sum/2);
		cout << ans << endl;
	}
	else cout << -1 << endl;
}
