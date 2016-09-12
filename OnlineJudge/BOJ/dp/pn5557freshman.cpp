#include <cstdio>
using namespace std;
int n;
int arr[101];
long long dp[101][21];
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &arr[i]);
    }
    dp[1][arr[0]] = 1;
    for(int i=1; i<n-1; ++i){
        for(int j=0; j<21; ++j){
            if(dp[i][j]>0){
                if(j+arr[i]<=20){
                    dp[i+1][j+arr[i]] += dp[i][j];
                }
                if(j-arr[i] >=0){
                    dp[i+1][j-arr[i]] += dp[i][j];
                }
            }
        }
    }
    printf("%lld", dp[n-1][arr[n-1]]);
}
