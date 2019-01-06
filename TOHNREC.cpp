#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
using namespace std;
struct Henoi{
    int disk;
    char i,j,k;
}s,p;
int main(){
    int n,counter = 0;
    printf("Enter the number of disk: ");
    scanf(" %d",&n);
    stack<struct Henoi>s1;
    s.disk = n;
    s.i = 'a';
    s.j = 'b';
    s.k = 'c';
    s1.push(s);
    while(s1.size()!= 0){
        s=s1.top();
        s1.pop();
        if(s.disk == 1){
            printf("\nMove the disk from %c to %c",s.i,s.k);
            counter++;
        }
        else{
            p.disk = s.disk -1;
            p.i = 'b';
            p.j = 'a';
            p.k = 'c';
            s1.push(p);
            p.disk = 1;
            p.i = 'a';
            p.j = 'b';
            p.k = 'c';
            s1.push(p);
            p.disk = s.disk -1;
            p.i = 'a';
            p.j = 'c';
            p.k = 'b';
            s1.push(p);
        }
    }
    printf("\nNumber of data movement: %d",counter-7);

    return 0;
}
