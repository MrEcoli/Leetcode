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

int StrToInt(const char *ch){
	while(*ch==' ')
		ch++;
	int sign=1;
	int num=0;
	if(*ch=='-')
		sign=-1;
	else if(isdigit(*ch)||*ch=='+')
		sign=1;
	else 
		return 0;
	while(*ch++!='\0'){
		if(!isdigit(*ch))
			continue;
		num=num*10+(*ch-'0');
	}
	return num*sign;
}
string addBinary(string astr,string bstr){
	if(astr.size()<bstr.size())
		return addBinary(bstr,astr);
	char ca,cb;
	char cover=0;
	for(string::reverse_iterator i=astr.rbegin(),j=bstr.rbegin();i!=astr.rend()||j!=bstr.rend();i=i==astr.rend()?astr.rend():next(i),j=j==bstr.rend()?bstr.rend():next(j)){
		ca=i==astr.rend()?0:(*i-'0');
		cb=j==bstr.rend()?0:(*j-'0');
		*i=(ca+cb+cover)%2+'0';
		cover=(ca+cb+cover)/2;
	}
	if(cover!=0){
		cover+='0';
		astr.insert(astr.begin(),cover);
	}
	return astr;
}
string longestPaliStr(const char* ch)
{
	int maxlen=1,start=0,len=strlen(ch);
	vector<vector<bool>> f(len,vector<bool>(len,false));
	for(int i=0;i!=len;++i){
		f[i][i]=true;
		for(int j=0;j!=i;++j){
			f[i][j]=(ch[i]==ch[j])&&(i==j+1||f[i-1][j+1]);
				if(f[i][j]&&maxlen<(i-j+1)){
					maxlen=i-j+1;
					start=j;
				}
		}
	}
	return string(ch+start,ch+start+maxlen);
}
bool reIsMatch(const char * input, const char* regexp){
	if(*regexp=='\0') 
		return *input=='\0';
	if(*(regexp+1)!='*'){
		if(*input==*regexp||(*regexp=='.'&&*input!='\0'))
			return reIsMatch(input+1,regexp+1);
		else return false;
	}
	else{
		while(*regexp==*input||'.'==*regexp&&*input!='\0'){
			if(reIsMatch(input,regexp+2))
				return true;
			input++;
		}
		return reIsMatch(input,regexp+2);
	}

}
bool reIsMatch2(const char* input, const char* regexp){
	if(*regexp=='\0'||*input=='\0')
		return *input==*regexp;
	if(*regexp!='*'){
		if(*input==*regexp||*regexp=='?')
			return reIsMatch2(input+1,regexp+1);
		else
			return false;
	}
	else{
		while(*regexp=='*') ++regexp;
		while(*input!='\0'){
			if(reIsMatch2(input,regexp))
				return true;
			input++;
		}
		return reIsMatch2(input,regexp);
	}
}
bool reIsMatch3(const char* input, const char* regexp){
	const char *i,*r;
	bool star=false;
	for(i=input,r=regexp;*i!='\0';++i,++r){
		switch(*r){
		case'?':
			break;
		case'*':
			star=true;
			input=i,regexp=r;
			while(*regexp!='*') 
				++regexp;
			if(*regexp=='\0') 
				return true;
			i=input-1;
			r=regexp-1;
		default:
			if(*i!=*r){
				if(!star)
					return false;
			++input;
			i=input-1;
			r=regexp-1;
			}
		}
	}
	while(*r=='*')
		++r;
	return *r=='\0';
}
string prefixFind(vector<string> &strs){
	if(strs.empty())
		return "";
	for(unsigned int i=0;i<strs[0].size();++i)
		for(unsigned int j=0;j<strs.size();++j)
			if(strs[j][i]!=strs[0][i])
				strs[0]=string(0,i);
	return strs[0];
}
string IntToRoman(int aint){
	string result;
	int count=0;
	string roman[]={"X","IX","V","IV","I"};
	int ary[]={10,9,5,4,1};
	for(int i=0;i!=sizeof(ary)/sizeof(int);++i){
		count=aint/ary[i];
		aint=aint%ary[i];
		while(count--)
			result+=roman[i];
	}
	return result;
}
vector<string> anagrams(vector<string> strs){
	unordered_map<string,vector<string>> groups;
	for(auto i=strs.begin();i!=strs.end();++i){
		string key=*i;
		sort(key.begin(),key.end());
		remove_if(key.begin(),key.end(),[](char ch){return ch==' ';});
		groups[key].push_back(*i);
	}
	vector<string> result;
	for(auto i=groups.begin();i!=groups.end();++i){
		if(i->first.size()>1)
			result.insert(result.end(),i->second.begin(),i->second.end());
	}
	return result;
}
string CountAndSay(string &str){
	string next_str;
	char count=1;
	for(unsigned int i=0;i!=str.size();++i){
		if(i!=(str.size()-1)&&str[i]==str[i+1]){
			++count;
		}
		else{
			count='0'+count;
			next_str+=string(1,count)+string(1,str[i]);
			count=1;
		}
	}
	return next_str;
}
int lengOfLastWord(string s){
	auto lastspace=fill
	if (lastspace==string::npos)
		return -1;
	return s.size()-lastspace-1;
}

int main(){
	
	string::size_type
	cout<<CountAndSay(string("11133322221"))<<endl;
	string s("Hello World!");
	auto iter=find_if(s.rbegin(),s.rend(),[](char ch){return ch=='a';});
	cout<<s.rend()-iter<<endl;
	cout<<string::npos<<endl;
	cout<<lengOfLastWord(string("Helloworld"))<<endl;
	cin.get();
	return 0;
}

