


// Gray Code Total Accepted: 23542 Total Submissions: 72892 My Submissions Question Solution 
// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note:
// For a given n, a gray code sequence is not uniquely defined.

// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

// Show Tags Backtracking
// Have you met this question in a real interview









class Solution {
public:
	vector<int> grayCode(int n) {

		if (n <= 0){
			vector<int> res;
			res.push_back(0);
			return res;
		}
		vector<int> gc_array;
		gc_array.resize(1 << n);
		gc_array[0] = 0;
		gc_array[1] = 1;

		int last = 1 << 1;

		for (int i = 1; i != n; ++i){
			int Last_graycode_count = 1 << i;
			int Cur_Cycle_Add = 1 << i;
			for (int j = 0; j != Last_graycode_count; ++j){
				gc_array[j + Last_graycode_count] = gc_array[Last_graycode_count - j - 1] + Cur_Cycle_Add;
			}
		}
		return gc_array;
	}
};
