#include <cstdio>
using namespace std;
const int INT_MAX=987654321;
int adj[101][101];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(i==j){
                adj[i][j] =0;
            }else
                adj[i][j] = INT_MAX;
        }
    }
    for(int i=0; i<m; ++i){
        int a,b;
        scanf("%d %d", &a, &b);
        adj[b][a] = 1;
    }
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(adj[i][k] + adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    int arr[101];
    for(int i=1; i<=n; ++i){
        arr[i] = n;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(adj[i][j] <INT_MAX || adj[j][i]<INT_MAX){
                arr[i]--;
            }
        }
        printf("%d\n", arr[i]);
    }
}

