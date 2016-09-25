#include <cstdio>
using namespace std;

int main() {
    int w, h, p, q, t;
    scanf("%d%d%d%d%d", &w, &h, &p, &q, &t);
    int xr = (t%(2*w)+p)%(2*w), yr = (t%(2*h)+q)%(2*h);
    printf("%d %d\n", xr>w ? (2*w-xr): xr, yr>h ? (2*h-yr): yr);
}
