#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXN (100000+10)

bool check(int x);
int k; //��A�ƶq
int f; //�M�����O
int r=0; //�����̤[����A
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
    if (k==1) cout<< r; //�M�����O����@
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
bool check(int x){  //�P�_�h��x�����O�_����
    int m=0;  //��l�ƻݭn�M������ɶ�
    for (int i=0; i<k; i++){
          if (cloth[i] > x){
            m+=cloth[i]-x-1/(f-1)+1; //�ߧP�_�M����`�@�n���ɶ�
          }
    }
    if (m>x){
        return 0;
    }
    if (m<=x){
        return 1;
    }
}
