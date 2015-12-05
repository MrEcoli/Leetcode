class Solution {
public:
	int maxSubArray(int A[], int n){
		int maxSum=INT_MIN;
		int curSum=0;
		for(int i=0;i!=n;++i){
			curSum+=A[i];
			maxSum=max(curSum,maxSum);
			if(curSum<0){
				curSum=0;
			}
		}
		return maxSum;
	}
};