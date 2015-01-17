class Solution {
public:
    int findMin(vector<int> &num) {
        unsigned len = num.size();
        if(len == 1)
			return num[0];
		unsigned start = 0, end = len-1;
		unsigned mid;
		int val;
		while(start < end){
			mid = (start + end)>>1;
			if(start == mid){
				val = num[start]<num[end]?num[start]:num[end];
				return val;
			}
			if(num[start] < num[mid]){
				if(num[mid] > num[end])
					start = mid;
				else
					end = mid;
			}else if(num[start] > num[mid]){
				end = mid;
			}else{
				if(num[mid]<num[end])
					start = mid;
				else if(num[mid] > num[end])
					start = mid;
				else
					++start;
			}

		}
		return val;
    }
};