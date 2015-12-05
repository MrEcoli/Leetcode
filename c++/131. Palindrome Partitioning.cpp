class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> result;   
		vector<string> path;
		palindrome_DFS(result,path, s, 0, 0);
		return result;
    }

	void palindrome_DFS(vector<vector<string>> &result, vector<string> &path, string str, int start, int end){
	    if(end==str.size())
			return;
		if(end==str.size()-1)
			if(is_palindrome(str,start,end)){
				path.push_back(str.substr(start,end-start+1));
				result.push_back(path);
				path.pop_back();
				return;
			}
		palindrome_DFS(result,path,str,start,end+1);
		if(is_palindrome(str,start,end)){
			path.push_back(str.substr(start,end-start+1));
			palindrome_DFS(result,path,str,end+1,end+1);
			path.pop_back();
		}
	}
	bool is_palindrome(string &s, int start, int end){
		while(s[start]==s[end]&&start<end){
			start++;
			end--;
		}
		return start>=end;
	}
};