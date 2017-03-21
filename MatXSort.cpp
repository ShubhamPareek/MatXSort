#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int size,no,sum=0,max=0,repeat=0,rep=0;
	cout<<"Enter Total Number of Elements : ";
	cin>>size;
	size++; 
	int arr[size][size+1],list[size],count[size];		// arr is the 2D array, List is the Sorted array

	for(int i=0;i<size;i++)
	list[i]=0,count[i]=0;

	arr[0][0]=0;
	arr[0][size]=0;				    
	for(int j=1;j<size;j++)												            
	{								            
		cin>>no;					       
		arr[0][j]=no;			
		arr[j][0]=no;
	}

    for(int i=1;i<size;i++)				// Main Logic to compute matrix
    {
    	for(int j=1;j<size;j++)
    	{
    		if(arr[i][0]<arr[0][j])
    		 arr[i][j]=-1;
    		
    		if(arr[i][0]>arr[0][j])
    		arr[i][j]=1;
    		
    		if(arr[i][0]==arr[0][j])
    		arr[i][j]=0;
			
			sum=sum+arr[i][j];
		}
		arr[i][size]=sum;
		if(sum>max)
		max=sum;				// max is the maximum sum.
		sum=0;
	}
	
	for(int i=1;i<size;i++)			// to place number to their position with respect to their sum.
	{
		if(list[(max+arr[i][size])/2]!=0)
		count[(max+arr[i][size])/2]++,repeat+=1,rep++;
		else
		{
			list[(max+arr[i][size])/2]=arr[0][i];
		}
		repeat=0;
	}
	size--;
	for(int i=0;i<size-rep;i++)
	cout<<list[i]<<" ";
	cout<<"\n";
	for(int i=0;i<size-rep;i++)
	cout<<count[i]<<" ";
	 
}
