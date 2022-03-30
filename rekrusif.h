#include<iostream>
using namespace std;
int rekrusifSamaDengan(int x)
{
	if(x==100){
		return x;
	}
	cout <<"=";
	rekrusifSamaDengan(x+1);
}
int rekrusifStrip(int x)
{
	if(x==100){
		return x;
	}
	cout <<"-";
	rekrusifStrip(x+1);
	return 0;
}
