class Solution {
public:
    int singleNumber(int A[], int n) {
        int temp=A[0];
        for(int i=1;i!=n;++i)
            temp^=A[i];
        return temp;
    }
};