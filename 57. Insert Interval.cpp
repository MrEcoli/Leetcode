class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
		vector<Interval> res;

		int n = intervals.size();

		for (int i = 0; i != n; ++i){
			if (newInterval.start > intervals[i].end){
				res.push_back(intervals[i]);
			}else if (newInterval.end < intervals[i].start){
				res.push_back(newInterval);
				newInterval = intervals[i];
			}
			else{
				newInterval.start = min(intervals[i].start, newInterval.start);
				newInterval.end = max(intervals[i].end, newInterval.end);
			}
		}
		res.push_back(newInterval);
		return res;
	}
};
