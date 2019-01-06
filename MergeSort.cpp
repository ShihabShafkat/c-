#include<stdio.h>
#include<iostream>
using namespace std;

void Merge(int ar[], int s, int m, int l){
    int i,j,k;
    int n1 = m-s+1;
    int n2 = l-m;
    int L[n1+1], R[n2+1];
    for(i = 1; i<= n1;i++){
        L[i] = ar[s+i-1];
    }
    for(j=1;j<=n2;j++){
        R[j] = ar[m+j];
    }
     L[n1+1] = 10000000;
     R[n2+1] = 10000000;
     i =1;
     j=1;
     for(k = s;k<=l;k++){
        if(L[i] <= R[j]){
            ar[k] = L[i];
            i++;
        }else{
            ar[k] = R[j];
            j++;
        }

     }
}

void Merge_Sort(int ar[], int s, int l){
    int m;
    if(s<l){
        m = (s+l)/2;
        Merge_Sort(ar,s,m);
        Merge_Sort(ar, m+1,l);
        Merge(ar,s,m,l);
    }
}

int main(){
    int ar[100],num;
    printf("enter the number of elements: ");
    scanf("%d",&num);
    for(int i = 0;i< num;i++){
        scanf("%d",&ar[i]);
    }
    Merge_Sort(ar,0,num-1);
      printf("\nSorted List\n");
    for(int i=0; i<num; i++)
    {
        printf(" %d",ar[i]);
    }
    return 0;

}
