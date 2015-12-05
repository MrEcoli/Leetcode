class Solution {
public:
	int maxArea(vector<int> &height) {
		if (height.size() < 2){
			return 0;
		}
		int left = 0, right = height.size() - 1;
		int max_area = 0;

		while (left < right){
			int min_height;
			if (height[left] < height[right]){
				min_height = height[left];
				left++;
			}
			else{
				min_height = height[right];
				right--;
			}
			max_area = max(max_area, (right - left + 1) * min_height);
		}

		return max_area;
	}
};