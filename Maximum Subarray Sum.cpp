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
#define FILL(a, b) memset(a, b, sizeof(a));
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
typedef vector<string> VSTR;
typedef vector<pair<int, int>> VPII;

LL MOD=1e9+7;
const int MAXN=1e5+7;

int n, sum = 0, best = 0;
int ns[MAXN];

int main(){
	IOS;
	cin >> n;
	F0R(i, n){
		cin >> ns[i];
		sum = max(ns[i], sum+ns[i]);
		best = max(best, sum);
	}
	cout << best << endl;
}
