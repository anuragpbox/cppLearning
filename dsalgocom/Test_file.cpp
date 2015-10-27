
#include <iostream>
#include <stdio.h>

using namespace std;

int maxof(int a , int b)
{
	if (a>b)
		{return a;}
	else
		{return b;}
		 
}


int* getmax(int sarr,int* arr)
{
	if (sarr ==1)
		return arr;
	else
		{
			int* maxhalf = new int[sarr / 2 + sarr % 2];
			for (int i = 0; i < sarr / 2 + sarr % 2; i++)
			{
				if (i == sarr /2)
					{maxhalf[i] = arr[sarr];}
				else
					{maxhalf[i] =  maxof(arr[2*i],arr[2*i+1]);}
			}
			return getmax(sarr / 2 + sarr % 2, maxhalf);
		}
	}


void main(){

	int intarray[] = {4,5,6,7,2,3,4,2123,3,43,431,2,76,81,68,345,65,87,1};

	for(int i=0;i<sizeof(intarray)/sizeof(intarray[0]);i++)
	{
		cout << intarray[i] << ' ';
	}
	cout << endl;
	int* maxnumber = getmax(sizeof(intarray) / sizeof(intarray[0]), intarray);
	cout << "The max of given array is " << *maxnumber << endl;

}
