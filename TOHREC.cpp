#include<stdio.h>
int counter = 0;
void Henoi(int n,char i,char j,char k){
    if(n == 1){
        printf("\nMove the  disk from %c to %c",i,k);
        counter++;
    }else{
        Henoi(n - 1,i,k,j);
        printf("\nMove the disk from %c to %c",i,k);
        Henoi(n-1,j,i,k);
    }
}
int main(){
    int num;
    printf("Enter the number of disk: ");
    scanf(" %d",&num);
    Henoi(num,'a','b','c');
    printf("\nNumber of data movement : %d",counter);
    return 0;
}

