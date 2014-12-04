
/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
Show Tags
*/

class Solution {
public:
    void reverseWords(string &s) {
		int pos;
		if((pos = s.find_first_not_of(' ')) == string::npos){
			s ="";
			return;
		}
		string res;
		istringstream str_in(s);
		s = s.substr(s.find_first_not_of(' '));
		vector<string> tmp;
		while(getline(str_in, res, ' ')){
			if(res.empty() || res == " ")
				continue;
			res = res.substr(res.find_first_not_of(' '));
			tmp.push_back(res);
		}
		reverse(tmp.begin(), tmp.end());
		res = "";
		for(auto iter = tmp.begin(); iter != tmp.end(); ++iter){
			res.append(*iter);
			if(iter != tmp.end() -1)
				res.append(" ");
		}
		s = res;
    }
};