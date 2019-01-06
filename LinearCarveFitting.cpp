#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,n;
	cout<<"\nEnter the no of data pairs to be entered:"<<endl;
	cin>>n;
	double x[n],y[n],a,b;
	cout<<"\nEnter the x axis values: "<<endl;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	cout<<"Enter the y-axis values"<<endl;
	for(int i=0;i<n;i++){
		cin>>y[i];
	}
	double y_fit[n];
	double xsum=0,ysum=0,x2sum=0,xysum=0;
	for(int i=0;i<n;i++){
		xsum+=x[i];
		ysum+=y[i];
		x2sum+=pow(x[i],2);
		xysum+=x[i]*y[i];
	}
	a=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);
	b=(x2sum*ysum-xsum*xysum)/(n*x2sum-xsum*xsum);
	for(int i=0;i<n;i++){
		y_fit[i]=a*x[i]+b;
	}
	for(int i=0;i<n;i++){
		cout<<i+1<<setw(4)<<x[i]<<setw(5)<<y[i]<<setw(4)<<y[i]<<endl;
	}
	cout<<"a :"<<a<<" b: "<<b;


}
