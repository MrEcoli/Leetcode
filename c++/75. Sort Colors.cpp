class Solution {
public:
        void sortColors(int A[], int n) {
		if(A==nullptr||n<=0)
			return;
		int *p1=A, *p2=A+n-1,*pCur=A;
		while(pCur<=p2){
			if(*pCur==1)
				++pCur;
			else if(*pCur==2){
				swap(*pCur,*p2);
				--p2;
			}else{
					swap(*p1,*pCur);
					++pCur;
					++p1;
			}
		}
        
    }
};