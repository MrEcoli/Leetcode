//LeetCode List ÌâÄ¿
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <list>
#include <vector>
#include <random>
#include <queue>
#include <unordered_map>
using namespace std;

bool validParenthese(string s){
	stack<char> cstack;
	string left="([{",right=")]}";
	
	for(unsigned int i=0;i!=s.size();++i){
		if(left.find(s[i])!=string::npos)
			cstack.push(s[i]);
		else if((!cstack.empty())&&cstack.top()==left[right.find(s[i])])
			cstack.pop();
		else
			return false;
	}
	return cstack.empty();

}
int longestValidParenthese(string s){
	int maxlen=0,len=0;
	stack<pair<int,char>> chstack;
	vector<bool> valid(s.size(),false);
	for(unsigned int i=0;i<s.size();++i){
		if(s[i]=='(')
			chstack.push(make_pair(i,s[i]));
		else if(!chstack.empty()){
			valid[chstack.top().first]=true;
			valid[i]=true;
			chstack.pop();
		}
	}
	for(unsigned int i=0;i!=valid.size();++i){
		if(valid[i]==true){
			++len;
			if(len>maxlen)
				maxlen=len;
		}
		else
			len=0;
	}
	return maxlen;
}
int longestParatheseDP(string s){
	int maxlen=0;
	vector<int> f(s.size(),0);
	int match;
	for(unsigned int i=1;i<s.size();++i){
		match=i-f[i-1]-1;
		if(s[i]==')'&&match>0&&s[match]=='(')
			f[i]=f[i-1]+2;
		if(match-1>0)
			f[i]+=f[match-1];
		maxlen=f[i]>maxlen?f[i]:maxlen;
	}
	return maxlen;
}
int largestArea(vector<int> &height){
	stack<int> s;
	height.push_back(0);
	int last_result=0;
	for(int i=0;i!=height.size();){
		if(s.empty()||height[i]>height[s.top()])
			s.push(i++);
		else{
			int temp=s.top();
			s.pop();
			last_result=max(last_result,height[temp]*(s.empty()?i:(i-s.top()-1)));
		}
	}
	return last_result;
}
int reverse_Polish(vector<string> strs){
	stack<int> cstack;
	string opera("+-*/");
	int temp1,temp2;
	for(unsigned int i=0;i!=strs.size();++i){
		if(opera.find(strs[i])==string::npos){
			cstack.push(stoi(strs[i]));
		}else{
			temp1=cstack.top();
			cstack.pop();
			temp2=cstack.top();
			cstack.pop();
			if(strs[i]=="/")
				cstack.push(temp2/temp1);
			else if(strs[i]=="*")
				cstack.push(temp2*temp1);
			else if(strs[i]=="*")
				cstack.push(temp2-temp1);
			else
				cstack.push(temp1+temp2);
		}
	}
	return cstack.top();
}
int main(){
	
	string s=")(()())";
	int ary[]={1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,5,3,2,3};
	vector<int> height(ary,ary+sizeof(ary)/sizeof(int));
	cout<<largestArea(height)<<endl;


	cin.get();
	return 0;
}

