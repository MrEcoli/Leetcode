/**
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * }
; */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
		int n = points.size();
		if(n == 1 || n == 0 || n ==2)
			return n;
		unordered_map<double, int> counter;
		double limit = numeric_limits<double>::infinity();
		int max_point = 0;
		for(int i = 0; i != n-1; ++i){
			counter.clear();
			int same = 0;
			int tempmax = 1;
			for(int j = i + 1; j != n; ++j){
				double slope;
				if(points[i].x == points[j].x){
					if(points[i].y == points[j].y){
						same++;
						continue;
					}
					else{
						slope = limit;
					}
				}else{
					slope = 1.0 *(points[i].y - points[j].y) / (points[i].x - points[j].x);
				}
				if(counter.find(slope) == counter.end())
					counter[slope] = 2;
				else{
					++counter[slope];
				}
				tempmax = tempmax < counter[slope] ? counter[slope]: tempmax;
			}
			max_point = (tempmax + same) > max_point ? (tempmax + same) : max_point;
		}
		return max_point;
    }
};