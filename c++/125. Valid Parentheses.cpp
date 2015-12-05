class Solution {
public:
    bool isValid(string s) {
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
};