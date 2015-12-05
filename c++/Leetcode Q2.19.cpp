//offer come 40 求数组中只出现一次的数
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <unordered_map>
using namespace std;

int RandInt(int start,int end)
{
	return	(rand()%(end-start+1))+start;
}

int Sum3Closet(vector<int> &ary,int sum)
{
	sort(ary.begin(),ary.end());
	vector<int>::iterator p1=ary.begin(),p2=--ary.end(),p3=next(ary.begin()),p4=ary.end()-2;
	int mingap=INT_MAX,gap;
	while(next(p1)!=p2)
	{
		int redius=sum-*p1-*p2;
		if(*p3>=redius)
		{
			gap=abs(*p3-redius);
			--p2;
			p4=prev(p2);
		}
		else if(*p4<=redius)
		{
			gap=abs(redius-*p4);
			++p1;
			p2=next(p1);
		}
		else 
		{
			while(next(p3)!=p4)
			{
				auto mid=p3+(p4-p3)/2;
				if(*mid==redius)
				{
					gap=abs(redius-*mid);
					break;
				}
				else if(*mid>redius)
				{
					p4=mid-1;
				}
				else
				{
					p3=mid+1;
				}
			}
			if(gap!=0)
				gap=min(abs(*p3-redius),abs(*p4-redius));
		}
		mingap=min(mingap,gap);
		if(mingap==0)
			break;
	}
	return mingap;
}



int main()  
{  
	int ary[]={-1,2,1,-4};
	vector<int> ivec;
	for(int i=0;i!=4;i++)
		ivec.push_back(ary[i]);
	cout<<Sum3Closet(ivec,1)<<endl;
	
	cin.get();
	return 0;
}

