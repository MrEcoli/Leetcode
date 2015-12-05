








//尾递归，斐波拉切数组

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0)
			return 0;
		else return f(n, 1, 1);
	}

	int f(int n, int x, int y){
		if (n == 1)
			return x;
		else
			return f(n - 1, x + y, x);
	}
};