#include <cstdio>
#include <cstring>
using namespace std;

char arr[100001];

int main() {
    scanf("%s", arr);
    int l = strlen(arr),i=0;
    int cur=0, res=0;
    while(i<l){
        if(arr[i] == '('){
            if(arr[i+1] == ')'){
                res+= cur;
                i += 2;
                continue;
            }
            cur++;
            i++;
        }else{
            res+=1;
            cur--;
            i++;
        }
    }
    printf("%d\n", res);
}
