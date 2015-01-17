class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		unsigned xx = x;
		unsigned ret = 0;

		while (x){
			ret = ret * 10 + x % 10;
			x = x / 10;
			
			if (x && ret > INT_MAX / 10){
				return false;
			}
		}
		
		return xx == ret;
	}
};
