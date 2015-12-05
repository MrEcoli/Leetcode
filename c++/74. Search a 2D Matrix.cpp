class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if(matrix.empty()) return false;
		auto len=matrix.size();
		int start=0;
		while(start<len&&matrix[start].back()<target)
			++start;
		if(start==len)
			return false;
		return binary_search(matrix[start].begin(),matrix[start].end(),target);
	}

};