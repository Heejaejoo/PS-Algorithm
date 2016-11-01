#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
int n;
int c[100001];
using namespace std;
typedef long long ll;
int main() {
    scanf("%d", &n);
    int res = 0;
    for(int i=0; i<n; ++i){
        int a1, b1;
        scanf("%d %d", &a1, &b1);
        c[i] = a1-b1;
        res+=c[i];
    }
    int curmax = abs(res);
    int idx = 0;
    for(int i=0; i<n; ++i){
        if(abs(res-2*c[i]) > curmax){
            curmax = abs(res-2*c[i]);
            idx = i+1;
        }
    }
    printf("%d\n", idx);
}
