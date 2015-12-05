class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix){
		int hgt=matrix.size();
		int len=matrix.size();
		vector<int> height(len+1,0);
		int maxarea=0;
		for(int i=0;i!=hgt;++i){
			for(int j=0;j!=len;++j){
				if(matrix[i][j]='1')
					height[j]=height[j]+1;
				else 
					height[j]=0;
			}
			maxarea=max(maxarea, largestRectangle(height));
		}
		return maxarea;
	}
	int largestRectangle(vector<int> height){
		stack<int> s;
		int length=height.size();
		int maxarea=0,area;
		for(int i=0;i!=length;){
			if(s.empty()||height[i]>s.top()){
				s.push(i++);
			}
			else{
					int temp=s.top();
					s.pop();
					area=height[temp]*(s.empty()?i:(i-s.top()-1));
					maxarea=max(area,maxarea);
			}
		}
		return maxarea;
	}
};