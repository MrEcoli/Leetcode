// Decode Ways Total Accepted: 25217 Total Submissions: 155044 My Submissions Question Solution 
// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

// The number of ways decoding "12" is 2.

// Show Tags
// Have you met this question in a real interview? Yes  No
// Discuss



class Solution {
public:
	int numDecodings(string s) {
		int sz = s.size();
		if (sz == 0)
			return 0;

		if (s[0] == '0')
			return 0;

		vector<int> f(sz, 0);

		f[0] = 1;

		for (int i = 1; i != sz; ++i){
			if (s[i] == '0'){
				if (s[i - 1] == '1' || s[i - 1] == '2'){
					if (i == 1)
						f[i] = 1;
					else
						f[i] = f[i - 2];
				}
				else{
					return 0;
				}
			}
			else{
				if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
					if (i == 1){
						f[i] = 2;
					}
					else
					{
						f[i] = f[i - 1] + f[i - 2];
					}
				}
				else{
					f[i] = f[i - 1];
				}
			}
		}
		return f[sz - 1];
	}
};