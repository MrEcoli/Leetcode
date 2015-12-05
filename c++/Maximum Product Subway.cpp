//Maximum Product Subway.cpp


//Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//For example, given the array [2,3,-2,4],
//the contiguous subarray [2,3] has the largest product = 6.


#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int maxProduct(int A[], int n) {
		if(n == 1)
			return A[0];
		vector<int> neg(n, 0);
		vector<int> pos(n, 0);
		int max_val = A[0];
		if(A[0] > 0){
			pos[0] = A[0];
			neg[0] = 0;
		}else{
			pos[0] = 0;
			neg[0] = A[0];
		}

		int max_sigle = A[0];
		for(int i = 1; i != n; ++i){
			
			if(A[i] > 0){
				pos[i] = pos[i-1] == 0 ? A[i]:(pos[i-1] * A[i]);
				neg[i] = neg[i-1] == 0 ? 0 : (neg[i-1] * A[i]);
			}else if(A[i] < 0){
				pos[i] = neg[i-1] == 0 ? 0 :(neg[i-1] * A[i]);
				neg[i] = pos[i-1] == 0 ? A[i]:(pos[i-1] * A[i]);
			}else
				neg[i] = pos[i] = 0;
			max_sigle = A[i] > max_sigle ? A[i] : max_sigle;
			max_val = pos[i] > max_val ? pos[i] : max_val;
		}


		return max_val <= 0 ? max_sigle : max_val;
    }
};


int main(char* argc, char **argv){

	Solution sol = Solution();
	int a[]= {-6, -3, -9, -12, -99, -112, -10, -13, 8};
	int b[] = {1, 2, 3};
	cout<<sol.maxProduct(a, 9)<<endl;
	getchar();
	return 0;
}

