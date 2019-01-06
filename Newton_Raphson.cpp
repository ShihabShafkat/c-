#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define EPS 0.001

using namespace std;

int deg;
double mainsa[100], diffe[100];

void get_Input(double arr[], int deg){
    for(int i = 0; i<=deg; i++){
        cout<<"a"<<deg-1;
        cin>>arr[i];
    }
}

double get_Value(double arr[], double x, double deg){
    double resu = arr[0];
    for(int i = 0; i<=deg; i++){
        resu = resu*x + arr[i];
    }
    return resu;
}

double getroot(double mainsa[100], double diffe[100], double x){
    double f, f1, x1;
    double er = 1001;
    while(er>=EPS){
        f = get_Value(mainsa,x,deg);
        f1 = get_Value(diff,x,deg-1);
        x1 = x - f/f1;
        er = fabs((x1-x)/x1);
        x = x1;
        cout<<"Iteration";
        cout<<fixed<<setprecision(3)<<x<<"\t";
        cout<<fixed<<setprecision(3)<<x1<<"\t";
        printf("\n");
    }
    return x;
}

int main(){
    count<<"Enter Degree";
    cin>>deg;
    get_Input(mainsa,deg);
    get_Input(diffe,deg-1);
    double x;
    cout<<"Enter x: ";
    cin>>x;
    double root = getroot(mainsa,diffe,x);
    cout<<"\n"<<roots;

}
