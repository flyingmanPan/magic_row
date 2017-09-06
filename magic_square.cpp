#include <iostream>
#include<cmath>
using namespace std;
bool judge();
bool make();
int main()
{
	int status;
	cout<< "Judge(1) or make(2)"<<endl;
	cin>>status;
	if(status==1)
		if(judge())
			cout<< "true\n";
		else
			cout<< "false\n";
	else
		make();
}
bool judge()
{
	int size;
	cout<< "Input>";
	cin>>size;
	int data[size][size];
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cin>>data[i][j];
		}
	}
	int basic=0;
	for(int i=0;i<size;i++)
	{
		basic+=data[0][i];
	}
	//cout<< "\n"<<basic<< "\n";
	//col
	for(int i=0;i<size;i++)
	{
		int temp=0;
		for(int j=0;j<size;j++)
		{
			temp+=data[i][j];
		}
		if(temp!=basic)
		{
			//cout<<"first"<<i<<endl;
			return false;
		}
			
	}
	//row
	for(int i=0;i<size;i++)
	{
		int temp=0;
		for(int j=0;j<size;j++)
		{
			temp+=data[j][i];
		}
		if(temp!=basic)
		{
			//cout<< "second"<<i<<endl;
			return false;
		}
	}
	//diagonal
	int temp1=0,temp2=0;
	for(int i=0;i<size;i++)
	{
		temp1+=data[i][i];
		temp2+=data[i][size-i-1];
	}
	if(temp1!=basic||temp2!=basic)
	{
		//cout<< "third"<<temp1<< "   "<<temp2<<endl;
		return false;
	}
	return true;
}
bool make()
{
	int size;
	cout<< "Input dimension>";
	cin>>size;
	if(size%2==0)
		return false;
	int max=size*size;
	int x=size/2,y=0;
	int data[size][size]={};
	//begin to make
	for(int i=1;i<=max;i++)
	{
		if(data[y][x]==0)
		{
			data[y][x]=i;
			x++,y--;
			if(x>size-1) x=0;
			if(y<0) y=size-1;
		}
		else
		{
			y++;
			if(y>size-1) y=0;
			y++;
			if(y>size-1) y=0;
			x--;
			if(x<0) x=size-1;
			data[y][x]=i;
			x++,y--;
			if(x>size-1) x=0;
			if(y<0) y=size-1;
		}
		
	}
	//print all
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}
}