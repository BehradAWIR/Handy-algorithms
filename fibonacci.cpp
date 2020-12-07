#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long a = 1;
    long long b = 1;
    while(--n){
        b=a+b;
        a=b-a;
    }
    cout << b << "\n";
}
