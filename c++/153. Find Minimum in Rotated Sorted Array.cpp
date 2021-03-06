/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

if there is duplicates exists in the array, the run-time complexity will be O(n);

consider the array int a[]= {3, 3, 3, 3, 0, 1, 3, 3}, we couldn't shrink the area by half, and could only almost
decrease the area by one

*/

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