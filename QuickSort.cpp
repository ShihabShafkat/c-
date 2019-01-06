#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int PARTITION(int ar[], int s, int e){
    int pivot,i;
    pivot = ar[e];
    int pindex=s;
    for(i = s;i<=e-1;i++){
        if(ar[i]<= pivot){
            swap(ar[i],ar[pindex]);
            pindex++;
        }
    }
    swap(ar[pindex],ar[e]);
    return pindex;
}
void QuickSort(int ar[], int s, int e){
    int pindex;
    if(s<e){
        pindex = PARTITION(ar,s,e);
        QuickSort(ar,s,pindex-1);
        QuickSort(ar,pindex+1,e);
    }
}
int main(){
        int ar[100], n, j;
    printf("Enter the number of numbers: ");
    scanf("%d",&n);
    printf("Enter the numbers: ");
    for(j = 0; j < n; j++){
        cin >> ar[j];
    }
    QuickSort(ar, 0, n-1);
    for(j = 0; j< n; j++){
        cout<< ar[j] << endl;
    }
}
