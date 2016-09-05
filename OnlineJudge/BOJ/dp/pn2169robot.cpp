#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int arr[1001][1001];
int dp[1001][1001][3];
int m,n;
int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%d", &arr[i][j]);
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][2] = arr[0][0];
    for(int j=1; j<m; ++j){
        dp[0][j][2] = dp[0][j-1][2]+arr[0][j];
    }
    for(int i=1; i<n; ++i){
        dp[i][0][0] = dp[i-1][0][2]+arr[i][0];
        for(int j=1; j<m; ++j){
            dp[i][j][0] = max(dp[i][j-1][0], dp[i-1][j][2])+arr[i][j];
        }
        dp[i][m-1][1] = dp[i-1][m-1][2]+arr[i][m-1];
        for(int j=m-2; j>=0; --j){
            dp[i][j][1] = max(dp[i][j+1][1], dp[i-1][j][2])+arr[i][j];
        }
        for(int j=0; j<m; ++j){
            dp[i][j][2] = max(dp[i][j][0], dp[i][j][1]);
        }
    }
    printf("%d", dp[n-1][m-1][2]);
}
