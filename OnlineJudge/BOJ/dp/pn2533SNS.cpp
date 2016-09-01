#include <vector>
#include <cstdio>
#include <utility>
#include <cstring>
#include <cstdlib>
using namespace std;
int n;
vector<vector<int> > adj(1000001);
vector<bool> visited(1000001, false);
int dp[1000001][2];
pair<int, int> dfs(int cur){
    if(visited[cur])
        return make_pair(dp[cur][0], dp[cur][1]);
    visited[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for(int i=0; i<(int)adj[cur].size(); ++i){
        int there = adj[cur][i];
        if(!visited[there]){
            dp[cur][0] += dfs(there).second;
            dp[cur][1] += min(dfs(there).first, dfs(there).second);
        }
    }
    return make_pair(dp[cur][0], dp[cur][1]);
}

int main() {
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    int a,b;
    for(int i=0; i<n-1; ++i){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pair<int,int> a1 = dfs(1);
    printf("%d\n", min(a1.first, a1.second));
}
