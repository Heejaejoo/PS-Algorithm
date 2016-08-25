#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <utility>
using namespace std;
vector<bool> visited;
vector<pair<int, int> > parent;
int leftshift(int a){
    int q = a/1000;
    int r = a%1000;
    return r*10 + q;
}
int rightshift(int a){
    int q = a/10;
    int r = a%10;
    return r*1000 + q;
}

void bfs(int a, int b){
    queue<int> q;
    q.push(a);
    visited[a] = true;
    parent[a] = make_pair(a, -1);
    while(!q.empty() && !visited[b]){
        int cur = q.front();
        q.pop();
        vector<int> s(4);
        s[0] = leftshift(cur);
        s[1] = rightshift(cur);
        s[2] = (cur+9999)%10000;
        s[3] = (cur*2)%10000;
        for(int i=0; i<4; ++i){
            if(!visited[s[i]]){
                q.push(s[i]);
                visited[s[i]] = true;
                parent[s[i]] = make_pair(cur, i);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--){
        int a,b;
        scanf("%d%d", &a, &b);
        visited = vector<bool>(10001, false);
        parent = vector<pair<int, int> > (10001);
        bfs(a,b);
        string s = "";
        int cur =b;
        while(parent[cur].second != -1){
            int op = parent[cur].second;
            int p = parent[cur].first;
            if(op ==0){
                s= 'L'+s;
            }else if (op==1){
                s='R'+s;
            }else if (op==2){
                s='S'+s;
            }else {
                s='D'+s;
            }
            cur = p;
        }
        printf("%s\n", s.c_str());
    }
}
