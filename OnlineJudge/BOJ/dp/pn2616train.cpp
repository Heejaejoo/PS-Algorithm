#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
int tr[50001];
int sum[50001];
int dp[50001][4];
int n,m;
int solve(int a, int k){
    if(k==0 || a<m){
        return dp[a][k]=0;
    }
    if(dp[a][k] != -1){
        return dp[a][k];
    }
    int& ret = dp[a][k];
    ret = max(solve(a-m,k-1)+tr[a],solve(a-1, k));
    return ret;
}
int main() {
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    memset(tr, 0, sizeof(tr));
    sum[0] = 0;
    for(int i=1; i<=n; ++i){
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    memset(tr, 0, sizeof(tr));
    scanf("%d", &m);
    for(int i=m; i<=n; ++i){
        tr[i] = sum[i] - sum[i-m];
    }
    printf("%d", solve(n, 3));
}

