/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		if (intervals.empty()){
			return intervals;
		}
		auto cmp_first = [](const Interval &left, const Interval &right)->bool{
			if (left.start == right.start){
				return left.end < right.end;
			}
			return left.start < right.start;
		};

		sort(intervals.begin(), intervals.end(), cmp_first);

		vector<Interval> ret;
		ret.push_back(intervals[0]);
		for (int i = 1; i != intervals.size(); ++i){
			if (intervals[i].start > ret.back().end){
				ret.push_back(intervals[i]);
			}else {
				ret.back().end = max(intervals[i].end, ret.back().end);
			}
		}
		return ret;
	}
};
