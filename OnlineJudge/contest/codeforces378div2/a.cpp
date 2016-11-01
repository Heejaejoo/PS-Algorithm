#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int main() {
    char s[101];
    scanf("%s", s);
    int n = strlen(s);
    int pos = -1;
    int minjmp = 0;
    for(int i=0; i<n; ++i){
        if(s[i] == 'U' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] =='O' || s[i] == 'Y'){
            minjmp = max(i-pos, minjmp);
            pos = i;
        }
    }
    minjmp = max(n-pos, minjmp);
    printf("%d\n", minjmp);
}
