#include <cstdio>
using namespace std;
int main() {
    int a,b,t;
    scanf("%d%d%d", &a, &b, &t);
    printf("%d", a*b>t? a*b-t: 0);
}
