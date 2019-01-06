#include<bits/stdc++.h>
using namespace std;
float eq(float x)
{
    return x*x-4*x-10;

}
int main()
{
    float a,b;
    cout<<"enter a b"<<endl;
    cin>>a>>b;
    float x1,x2,x,fx1,fx2,f,e,e0=.01;
    x1=a;
    x2=a+.01;
    //cout<<"test 1";
    while(x2<b)
    {
   // cout<<"test 2";


        fx1=eq(x1);
        fx2=eq(x2);
       // cout<<endl<<" fx1  "<<fx1<<"  f2 "<<fx2;
        if(fx1*fx2>0)
        {
             x1=x2;
             x2=x2+.01;
        }
        else
        {
       // cout<<"test 3";
            x=(x1+x2)/2;
            f=eq(x);
            if(fx1*f<0)
            {
                x2=x;
                fx2=f;
            }else{
            x1=x;
            fx1=f;

            }
            e=(x2-x1)/x2;
            e=fabs(e);
            if(e<=e0){
            cout<<"root "<<x<<endl;
            x1=x2;
            x2=x1+.01;


            }else{
            x1=x2;
            x2=x2+.01;

            }


        }


    }

}
