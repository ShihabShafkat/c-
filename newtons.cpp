#include<bits/stdc++.h>
using namespace std;
float ar[100];
float b[100];
float x0=0;
void synfun(int deg,float x)
{
    b[deg]=0;
    for(int i=deg-1; i>=0; i--)
    {
        b[i]=ar[i+1]+b[i+1]*x;

    }
}
float  horner(int deg,float x)
{
    float p=ar[deg];
    cout<<"p :"<<p<<endl;
    for(int i=deg-1; i>=0; i--)
    {
        p=p*x+ar[i];
    }

    return p;
}


float derivative2(int x)
{
  //  float result=(-20*x)-4;
   float result=2*x-4;
    return result;
}


float newton(float deg,float x0)
{
    float fx,fp,xr,e,e0=.001,root;

    while(1){
        fx=horner(deg,x0);

            fp=derivative2(x0);

        xr=x0-(fx/fp);
        e=(xr-x0)/xr;
        e=fabs(e);
        if(e<=e0){
            root=xr;
            break;
        }
        else{
            x0=xr;
        }
    }
    x0=root;
    return root;


}
int main()
{
    float deg,roots[100];
    cout<<"Enter degree"<<endl;
    cin>> deg;
    for(int i=deg; i>=0; i--)
    {
        cin>>ar[i];

    }

    cout<<"Enter X"<<endl;
    cin>>x0;
    ///synfun(deg,x0);
    int c=0;

    for(int i=deg; i>1; i--)
    {
        // fx=horner(i,x);
        float s=   newton(i,x0);
        cout<<" s "<<s<<endl;
        roots[c]=s;
        c++;
        synfun(i,s);
        for(int i=0; i<deg; i++)
        {
            ar[i]=b[i];

        }


    }

    for(int k=0; k<c; k++)
    {
        cout<<endl<<roots[k];

    }
    float f=(ar[0]/ar[1]);
    f=-f;
    cout<<" "<<f;

}
