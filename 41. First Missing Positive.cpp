class Solution {
public:
int firstMissingPositive(int A[], int n) {
		for(int i=0;i!=n;++i){
			while(A[i]!=i+1){
				if(A[i]>0&&A[i]<=n&&A[A[i]-1]!=A[i])
					swap(A[A[i]-1],A[i]);
				else
					break;
			}
		}
		int index;
		for(index=0;A[index]==(index+1)&&index!=n;++index)
			;
		return index+1;
		
	}
};


class Solution {
public:
	int firstMissingPositive(int A[], int n) {

		if (n == 0){
			return 1;
		}
		
		for (int i = 0; i != n; ++i){
			if (A[i]<=n && A[i] >= 1){
				if (A[i] == i+1){
					continue;
				}
				else{
					if (A[A[i] -1] == A[i]){
						continue;
					}
					swap(A[i], A[A[i] - 1]);
					i--;
				}
			}
		}

		for (int i = 0; i != n; ++i){
			if (A[i] != i+1){
				return i + 1;
			}
		}

		return n+1;
	}
};