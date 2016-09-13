#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int dp[6][6][11];
char boggle[6][6];
int solve(int m, int n, int pos, int len, string& s){
    if(m<0 || m>=5 || n<0 || n>=5 || pos >=len){
        return 0;
    }
    if(dp[m][n][pos] != -1){
        return dp[m][n][pos];
    }
    int& ret = dp[m][n][pos]= 0;
    if(boggle[m][n] == s[pos]){
        if(pos==len-1){
            return ret = 1;
        }
        for(int i=-1; i<2; ++i){
            for(int j=-1; j<2; ++j){
                if(i==0 && j==0){
                    continue;
                }
                if(solve(m+i, n+j, pos+1, len, s)==1){
                    return ret=1;
                }
            }
        }
    }
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    while(n--){
        for(int i=0; i<5; ++i){
            scanf("%s", boggle[i]);
        }
        int tc;
        scanf("%d", &tc);
        for(int i=0; i<tc; ++i){
            char s[11];
            scanf("%s", s);
            memset(dp, -1, sizeof(dp));
            string st = s;
            bool flag = false;
            for(int i=0; i<5; ++i){
                for(int j=0; j<5; ++j){
                    if(solve(i, j, 0, st.length(), st)){
                        flag = true;
                        printf("%s YES\n", s);
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag){
                printf("%s NO\n", s);
            }
        }

    }
}
