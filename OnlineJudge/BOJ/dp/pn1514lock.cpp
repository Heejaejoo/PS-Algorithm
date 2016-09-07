#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
using namespace std;
int arr[103];
int goal[103];
int dp[103][10][10][10];
int n;
struct Node{
    int c;
    int nxt;
    int nnxt;
};
Node node[36] = {
    {1,0,0}, {1, 1,0}, {1, 1,1}, {2, 0, 0}, {2, 2, 0}, {2, 2, 2}, {3,0,0},{3,3,0},{3,3,3},
    {-1,0,0}, {-1,-1,0}, {-1, -1, -1}, {-2, 0, 0}, {-2, -2, 0}, {-2, -2, -2}, {-3,0,0},{-3,-3,0},{-3,-3,-3},
    {0, 1, 0}, {0, 0, 1}, {0, 1, 1}, {0, 2, 0}, {0, 2, 2}, {0,0,2},{0, 3, 0}, {0, 0, 3}, {0, 3, 3},
    {0, -1, 0}, {0, 0, -1}, {0, -1, -1}, {0, -2, 0}, {0, -2, -2}, {0, 0, -2}, {0, -3, 0}, {0, 0, -3}, {0, -3, -3}
};

int solve(int cur, int a, int b, int c) {
    if(cur>=n){
        return 0;
    }
    if(dp[cur][a][b][c] != -1){
        return dp[cur][a][b][c];
    }
    int& ret = dp[cur][a][b][c] = 10000;
    if(a == goal[cur]){
        ret = min(ret, solve(cur+1, b, c, arr[cur+3]));
    }else{
        for(int i=0; i<36; ++i){
            ret = min(ret, solve(cur, (a+node[i].c+10)%10, (b+node[i].nxt+10)%10, (c+node[i].nnxt+10)%10)+1);
        }
    }
   return ret;
}

//다보게 다시짜라
int main() {
    scanf("%d", &n);
    char s[101], g[101];
    scanf("%s", s);
    scanf("%s", g);
    int l = strlen(s);
    for(int i=0; i<l; ++i){
        arr[i] = s[i]-'0';
    }
    for(int i=0; i<l; ++i){
        goal[i] = g[i]-'0';
    }
    memset(dp, -1, sizeof(dp));
    int res =solve(0, arr[0], arr[1], arr[2]);
    printf("%d\n", res);
}
