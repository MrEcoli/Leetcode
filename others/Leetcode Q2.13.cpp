//offer come 40 求数组中只出现一次的数
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <random>
#include <queue>
using namespace std;

int RandInt(int start,int end)
{
	return	(rand()%(end-start+1))+start;
}
void swap_ref(int &a,int &b)
{
	if(a!=b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
}

int removeDuplicate2(int ary[],int length)
{
	if(ary==nullptr||length<=2)
		return 0;
	int index=2;
	for(int i=2;i!=length;i++)
	{
		if(ary[i]!=ary[index-2])
			ary[index++]=ary[i];
	}
	return index;
}

int removeDuplicate3(int ary[],int length)
{
	int index=0;
	for(int i=0;i!=length;i++)
	{
		if(i>0&&i<length-1&&ary[i]==ary[i-1]&&ary[i]==ary[i+1])
			continue;
		ary[index++]=ary[i];
	}
	return index;
}

int BinarySearchRotated(int ary[],int length,int findnum)
{
	int *begin=ary,*end=ary+length-1;
	int *mid;
	while(begin!=end)
	{
		mid=begin+(end-begin)/2;
		if(*mid==findnum)
			return mid-ary;
		if(findnum<=*end)
		{
			if(*mid<findnum)
			{
				begin=mid+1;
			}
			else
			{
				end=mid-1;
			}
		}
		else if(findnum>=*begin)
		{
			if(*mid>findnum)
				end=mid-1;
			else
				begin=mid+1;
		}
	}
	if(*begin==findnum)
		return begin-ary;
	return -1;
}

int main()  
{  
	int a[]={4,5,6,8,9,0,1,2,3};
	
	int pos=BinarySearchRotated(a,10,8);
	cout<<pos<<endl;
	cin.get();
	return 0;
}

