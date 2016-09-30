#include <cstdio>
using namespace std;
#define ll long long
ll dp[1000001];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll mod= 1000000009LL;
    dp[0] = 1;
    for(int i=1; i<=5; ++i){
        dp[i] = dp[i-1]*k;
    }
    dp[5]-=2;
    for(int i=6; i<=n; ++i){
        dp[i] = (((dp[i-1]%mod)*k)%mod - (dp[i-5]*2)%mod + mod)%mod;
        if(i>6){
            dp[i] = (dp[i] + dp[i-7])%mod;
        }
    }
    printf("%lld", dp[n]);
}
