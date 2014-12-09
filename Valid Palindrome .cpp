




class Solution {
public:
	bool isPalindrome(string s) {
		unsigned n = s.size();
		if(n == 0 || n == 1)
			return true;
		unsigned i;
		for(i = 0; i != n; ++i){
			if(isalnum(s[i]))
				break;
		}
		if(i == n)
			return true;


		i = 0;
		int j = n-1;

		while(i < j){
			if(!isalnum(s[i])){
				++i;
				continue;
			}
			if(!isalnum(s[j])){
				--j;
				continue;
			}
			if(s[i] == s[j] || (isalpha(s[i]) && isalpha(s[j]) && (tolower(s[i]) == tolower(s[j])))){
				++i;
				--j;
				continue;
			}else{
				return false;
			}
		}
		return true;		
	}
};