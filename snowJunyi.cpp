#include <iostream>
using namespace std;
int r,c;
int xue[100][100];

int deep = 1;
int snow(int n,int ci){
    if (deep > 101) {
        return 0;
    }

    deep++;

    int a,b,m,q;
    a = n/c;
    b = n%c-1;
    if (b==-1){
        b = c-1;
    }
    if (n%c==0){
        a-=1;
    }
    ci++;
    m = 0;
    bool yes = false;
    if (a-1>=0 && xue[a-1][b]<xue[a][b]){
        yes = true;
        q = snow(n-r,ci);
        if (q>m){
            m = q;
        }
    }
    if (a+1<r && xue[a+1][b]<xue[a][b]){
        q = snow(n+r,ci);
        yes = true;
        if (q>m){
            m = q;
        }
    }
    if (b-1>=0 && xue[a][b-1]<xue[a][b]){
        q = snow(n-1,ci);
        yes = true;
        if (q>m){
            m = q;
        }
    }
    if (b+1<c && xue[a][b+1]<xue[a][b]){
        q = snow(n+1,ci);
        yes = true;
        if (q>m){
            m = q;
        }
    }
    if (yes==false){
        deep--;
        return ci;
    }
    deep--;
    return m;

}
int snowJunyi(){
    cin >> r >> c;
    for (int i = 0;i<r;i++)
    {
        for (int j = 0;j<c;j++)
        {
            scanf("%d",&xue[i][j]);
        }
    }
    int m = 0;
    int q;
    for (int i = 0;i<r*c;i++){
        q = snow(i,0);
        if (m<q){
            m = q;
        }
    }
    cout << m;
    return 0;

}
