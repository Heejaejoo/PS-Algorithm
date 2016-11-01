#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <utility>
using namespace std;
int n,m;
int arr[501];
int arr2[501];
vector<int> idx(501);
vector<vector<pair<int, char> > > result(501);
typedef long long ll;

bool possible(int start, vector<int>& lst){
    while(lst.size()>1){
        int m1 =0;
        int n1 = lst.size();
        for(int i=0; i<n1; ++i){
            if(lst[i] > m1){
                m1 = lst[i];
            }
        }
        bool flag = false;
        for(int i=0; i<n1; ++i){
           if (m1 != lst[i]){
             flag = true;
             break;
           }
        }
        //if all elements are same
        if(!flag){
            return false;
        }else{
            if(lst[0] == m1 && lst[1] != m1){
                lst[0] += lst[1];
                lst.erase(lst.begin() + 1);
                result[start].push_back(make_pair(start+0, 'R'));
                continue;
            }
            flag = false;
            for(int i=1; i<n-1; ++i){
                if(lst[i] == m1){
                    if(lst[i-1]!=m1){
                        lst[i] += lst[i-1];
                        lst.erase(lst.begin() + i-1);
                        flag = true;
                        result[start].push_back(make_pair(start+i, 'L'));
                        break;
                    }
                    if(lst[i+1] != m1){
                        lst[i] += lst[i+1];
                        lst.erase(lst.begin() + i+1);
                        flag = true;
                        result[start].push_back(make_pair(start+i, 'R'));
                        break;
                    }
                }
            }
            if(flag)
                continue;
            if(lst[n-1] == m1){
                lst[n-1] += lst[n-2];
                lst.erase(lst.end() -2);
                result[start].push_back(make_pair(start+n-1, 'L'));
            }
        }
    }
    return true;
}


int main() {
    scanf("%d", &n);
    scanf("%d", &arr[0]);
    int sum = arr[0];
    for(int i=1; i<n; ++i){
        scanf("%d", &arr[i]);
        sum+=arr[i];
    }
    scanf("%d", &m);
    for(int i=0; i<m; ++i){
        scanf("%d", &arr2[i]);
        sum-=arr2[i];
    }
    if(m==n){
        for(int i=0; i<n; ++i){
            if(arr[i] != arr2[i]){
                printf("NO");
                return 0;
            }
        }
    }
    if(sum!=0){
        printf("NO");
        return 0;
    }
    int q = 0, r= 0;
    for(int i=0; i<n; ++i){
       q+=arr[i];
       if( q == arr2[r]){
            idx[r] = i;
            q=0;
            r++;
        }else if(q > arr2[r]){
            printf("NO");
            return 0;
        }
    }
    vector<int> ar0;
    for(int j = 0; j<= idx[0]; ++j){
        ar0.push_back(arr[j]);
    }
    if(!possible(0, ar0)){
        printf("NO");
        return 0;
    }
    for(int i=1; i<m; ++i){
        vector<int> ar;
        for(int j= idx[i-1]+1; j<=idx[i]; ++j){
            ar.push_back(arr[j]);
        }
        if(!possible(i, ar)){
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    for(int i=0; i<m; ++i){
        for(int j=0; j<(int)result[i].size(); ++j){
            printf("%d %c\n", result[i][j].first+1, result[i][j].second);
        }
    }
}
