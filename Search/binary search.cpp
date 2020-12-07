#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int l, int r, int x){ 
    if (r >= l){ 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) return mid; 
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return l; 
} 


int main(){
  int td_input; cin >> td_input;
  int inputs[td_input];
  for(int i=0; i<td_input; i++) cin >> inputs[i];
  int find; cin >> find;
  cout << binarySearch(inputs, 0, td_input-1, find) << endl;
}
