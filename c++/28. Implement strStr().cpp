class Solution {
public:
	int strStr(char *haystack, char *needle) {
		int n = strlen(haystack), m = strlen(needle);

		int index = -1;
		for (int cur = 0; cur + m <= n; ++cur){
			int i = cur;
			int j = 0;

			while (j < m && haystack[i] == needle[j])
			{
				++j;
				++i;
			}
			if (j == m){
				index = cur;
				break;
			}
		}
		return index;
	}
};