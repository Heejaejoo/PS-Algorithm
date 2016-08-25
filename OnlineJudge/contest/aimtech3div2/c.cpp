#include <cstdio>
#include <cstring>
using namespace std;
char s[100001];
int main() {
    scanf("%s", s);
    int len = strlen(s);
    int i=0;
    int start =-1;
    while(i<len){
        if (s[i] != 'a'){
            start = i;
            break;
        }
        i++;
    }
    if (start==-1){
        s[len-1]='z';
    }else{
        while(s[start] !='a' && start <len){
            s[start++]--;
        }
    }
    printf("%s", s);
}
