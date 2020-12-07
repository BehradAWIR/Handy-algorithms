#include <bits/stdc++.h>

using namespace std;

int const MAXS=2005;
int const MAXN=2005;

int dp[MAXN][MAXS];

struct twos{
	int weight, value;
};

twos inputs[MAXN];

int knapsack(int now_at, int size){
	if (size<=0 || now_at<0) return 0;
	
	if (dp[now_at][size]>0) return dp[now_at][size];
	
	int ans=knapsack(now_at-1, size);
	
	if (size >= inputs[now_at].weight)
		ans = max(ans, knapsack(now_at-1, size-inputs[now_at].weight)+inputs[now_at].value);
	
	return dp[now_at][size] = ans;
}

int main(){
	int n, s; cin >> s >> n;
//	memset(dp, -1, sizeof(dp));
	for(int i=0; i<n; i++)
		cin >> inputs[i].weight >> inputs[i].value;
	int ans = knapsack(n-1, s);
	cout << ans << endl;
}
