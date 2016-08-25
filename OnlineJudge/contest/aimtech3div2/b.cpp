#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n, s;
vector<int> arr;
vector<bool> visited;
int main() {
    scanf("%d%d", &n, &s);
    for(int i=0; i<n; ++i){
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    if(n==1){
        printf("%d" ,0);
    }else{
        int a = min(abs(s-arr[1]), abs(s-arr[n-1])) + arr[n-1]-arr[1];
        int b = min(abs(s-arr[0]), abs(s-arr[n-2])) + arr[n-2]-arr[0];
        printf("%d", min(a,b));
    }
}
