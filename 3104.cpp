#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXN (100000+10)

bool check(int x);
int k; //衣服數量
int f; //烘衣機能力
int r=0; //紀錄最久的衣服
int mid,l=1;
int cloth[MAXN];
int main(){

    cin >> k;
    for (int i=0; i<k; i++){
        cin >> cloth[i];
        if (cloth[i]>r){
            r=cloth[i];
        }
    }
    cin >> f;
    if (k==1) cout<< r; //烘衣機能力等於一
    else {
        while (l <= r){
            mid = (r+l)/2;
            if (check(mid)) r=mid-1;
            else l = mid+1;
    }
        cout<<l;
    }
    return 0;

}
bool check(int x){  //判斷多少x分鐘是否夠用
    int m=0;  //初始化需要烘衣機的時間
    for (int i=0; i<k; i++){
          if (cloth[i] > x){
            m+=cloth[i]-x-1/(f-1)+1; //盼判斷烘衣機總共要的時間
          }
    }
    if (m>x){
        return 0;
    }
    if (m<=x){
        return 1;
    }
}
