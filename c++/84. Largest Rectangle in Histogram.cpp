






class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		if (height.size() == 0){
			return 0;
		}
		height.push_back(0);
		vector<int> past_hist;
		past_hist.push_back(0);
		int max_rec = height.back();

		for (int i = 1; i != height.size(); ++i){
			while (!past_hist.empty() && height[i] <= height[past_hist.back()])
			{
				int cur_height = height[past_hist.back()];
				past_hist.pop_back();

				int from = past_hist.empty() ? -1 : past_hist.back();

				int cur_rec = (i - from -1)*cur_height;
				max_rec = cur_rec > max_rec ? cur_rec : max_rec;
			}
			past_hist.push_back(i);
		}
		return max_rec;
	}
};
