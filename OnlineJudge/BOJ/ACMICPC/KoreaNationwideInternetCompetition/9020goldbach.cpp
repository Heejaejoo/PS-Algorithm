#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> prime(10001, true);

void che(){
    prime[1] = false;
    for(int i=2; i<3334; ++i){
        if(!prime[i]){
            continue;
        }
        for(int j=i*i; j<10001; j+=i){
            prime[j] = false;
        }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    che();
    vector<int> p;
    for(int i=1; i<10001; ++i){
        if(prime[i]){
            p.push_back(i);
        }
    }
    int plen = (int)p.size();
    while(t--){
        int n;
        scanf("%d", &n);
        int a, b, min=987543;
        for(int i=0; i<plen && n-2*p[i]>=0; ++i){
            if(binary_search(p.begin(), p.end(), n-p[i])){
                if(min > n-2*p[i]){
                    min = n-2*p[i];
                    a = p[i];
                    b = n-p[i];
                }
            }
        }
        printf("%d %d\n", a,b);
    }
}
