#include <cstdio>
int main() {
    int m,n,k;
    scanf("%d%d%d", &m, &n, &k);
    if(m*n<k){
        printf("0");
        return 0;
    }
    int a=1, b=0, dir=1,ubx = m, uby = n, lbx = 1, lby = 1;
    while(k--){
        if(dir==1){
            if(b<uby){
                b++;
            }else if (b==uby){
                dir = 2;
                a++;
                lbx++;
            }
        }else if(dir==2){
         if(a<ubx){
            a++;
         }else if(a==ubx){
            dir = 3;
            b--;
            uby--;
         }
        }else if(dir==3){
          if(b>lby){
            b--;
          }else if (b==lby){
            dir = 4;
            a--;
            ubx--;
          }
        }else{
            if(a>lbx){
                a--;
            }else if (a==lbx){
                dir = 1;
                b++;
                lby++;
            }
        }
    }
    printf("%d %d", a, b);
}
