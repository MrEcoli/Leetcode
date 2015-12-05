


class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		auto p1 = lower_bound(A, A + n, target);
		auto p2 = upper_bound(A, A + n, target);

		if (p1 == p2){
			return vector<int>()={ -1, -1 };
		}
		else
			return vector<int>()={ p1 - A, p2 - A - 1 };

	}

};



