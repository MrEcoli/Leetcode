//LeetCode List 题目
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <list>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(l1==nullptr||l2==nullptr)
			return l1==nullptr?l2:l1;
		if(l1->val<l2->val){
			l1->next=mergeTwoLists(l1->next,l2);
			return l1;
		}
		else{
			l2->next=mergeTwoLists(l1,l2->next);
			return l2;
		}
    }
	ListNode *sortList(ListNode *head) {
        if(head==nullptr||head->next==nullptr)
			return head;
		ListNode* Cur, *second, *first=head;
		for(ListNode* p1=head, *p2=head;p2!=nullptr&&p2->next!=nullptr;p1=p1->next,p2=p2->next->next){
			Cur=p1;
		}
		second=Cur->next;
		Cur->next=nullptr;
		second=sortList(second);
		first=sortList(first);
		return mergeTwoLists(first,second);
    }
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if(lists.empty()) return nullptr;
		int curSize=lists.size(),halfSize;
		while(curSize>1){
			halfSize=(curSize+1)/2;
			for(int i=0;i<halfSize&&(i+halfSize)<curSize;++i){
				lists[i]=mergeTwoLists(lists[i],lists[i+halfSize]);
			}
		}

		return lists[0];
    }
	ListNode *insertionSortList(ListNode *head) {
		if(head==nullptr||head->next==nullptr)
			return head;
		int Min=INT_MAX;
		ListNode* pCur,*pMin,*pTrva;
		for(pCur=head;pCur->next!=nullptr;pCur=pCur->next){
			Min=INT_MAX;
			for(pTrva=pCur;pTrva!=nullptr;pTrva=pTrva->next){
				if(pTrva->val<Min){
					pMin=pTrva;
					Min=pTrva->val;
				}
			}
			pMin->val=pCur->val;
			pCur->val=Min;
		}
		return head;
    }
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
    vector<int> searchRange(int A[], int n, int target) {
        int start=lower_bound_LQ(A,A+n,target)-A;
		int end=upper_bound(A,A+n,target)-A-1;
		int result[2];
		
		if(!binary_search(A,A+n,target)){
			result[0]=-1;
			result[1]=-1;
		}else{
			result[0]=start;
			result[1]=end;
		}
		return vector<int>(result,result+2);
    }
	template<typename Iterator,typename T> 
	Iterator lower_bound_LQ(Iterator first, Iterator last, T input){
		auto len=distance(first,last);
		int half;
		Iterator mid;
		while(len>0){
			half=len>>1;
			mid=first+half;
			if(*mid>=input){
				len=half;
			}else {
				len=len-1-half;
				first=mid+1;
			}
		}
		return first;
	}
	template<typename InputIter,typename T>
	InputIter lower_bound_iter(InputIter first,InputIter last, T input){
		auto len = distance(first, last);
		while(first!=last){
			auto mid=next(first,distance(fist,last)/2);
			if(*mid<input)
				first=mid+1;
			else
				end=mid;             //end表示first迭代器能够达到的极限
		}
		return first;
	}
	template<typename InputIter, typename T>
	InputIter upper_bound_iter(InputIter first, InputIter last, T input){
		auto mid=next(first, distance(first, last)/2);
		while(first!=last){
			if(*mid<=value)
				first=++mid;
			else
				last=mid;
		}
		return first;
	}
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if(matrix.empty()) return false;
		auto len=matrix.size();
		size_t start=0;
		while(start<len&&matrix[start].back()<target)
			++start;
		if(start==len)
			return false;
		return binary_search(matrix[start].begin(),matrix[start].end(),target);
	}
    vector<vector<int> > subsets(vector<int> &S) {
		const int len=S.size();

		sort(S.begin(),S.end());
		vector<vector<int>> matrix(1);
		for(int i=0;i!=len;++i){
			for(int j=0;j!=matrix.size();j++){
				vector<int> temp(matrix[j]);
				temp.push_back(S[i]);
				matrix.push_back(temp);
			}
		}
		return matrix;
    }
	vector<vector<int> > subsets_recurse(vector<int> &S){
		vector<vector<int>> result;
		vector<int> path;
		subsets_recurse(result, path,0, S);
	}
	void subsets_recurse(vector<vector<int>> &result, vector<int> &path,int step, vector<int> &S){
		if(step==S.size()){
			result.push_back(path);
			return;
		}
		subsets_recurse(result, path,step+1, S);
		path.push_back(S[step]);
		subsets_recurse(result, path,step+1, S);
		path.pop_back();
	}
	vector<vector<int>> subsets_by_bit(vector<int> &S){
		long len=S.size();
		sort(S.begin(),S.end());
		int num=1<<len;
		vector<vector<int>> result;
		for(int i=0;i!=num;++i){
			int index=i;
			vector<int> temp;
			for(int j=0;j!=len;++j){
				if(index>>j&1){
					if(j==0||S[j]!=S[j-1])
						temp.push_back(S[j]);
					else if(S[j]=S[j-1]){
					
					}
				}
			}
			result.push_back(temp);
		}
		return result;
	}
	vector<vector<int>> subsetsWithDup(vector<int> &S){
		sort(S.begin(),S.end());
		set<vector<int>> sort_vec;
		const int len=S.size();
		const unsigned int num=1U<<len;
		for(int i=0;i!=num;++i){
			vector<int> one_vec;
			for(int j=0;j!=len;++j){
				if(1>>j&1)
					one_vec.push_back(S[j]);
			}
			sort_vec.insert(one_vec);
		}
		return vector<vector<int>>(sort_vec.begin(),sort_vec.end());
	}
	vector<vector<int> > subsetsWithDup2(vector<int> &S) {
		sort(S.begin(), S.end()); // 必须排序
		vector<vector<int> > result(1);
		size_t previous_size = 0;
		for (size_t i = 0; i < S.size(); ++i) {
		const size_t size = result.size();
			for (size_t j = 0; j < size; ++j) {
				if (i == 0 || S[i] != S[i-1] || j >= previous_size) {
					result.push_back(result[j]);
					result.back().push_back(S[i]);
				}
			}
			previous_size = size;
		}
		return result;
	}
	vector<vector<int>> permuteUnique(vector<int> &num){
		set<vector<int>> result;
		int step=0,len=num.size();
		permute(result,num,step,len);
		return vector<vector<int> >(result.begin(), result.end());
	}
	void permute(set<vector<int>> &result, vector<int> &one, int step, const int len){
		if(step==len){
			result.insert(one);
			return;
		}
		for(int i=step;i!=len;++i){
			swap(one[i],one[step]);
			permute(result, one, step+1, len);
			swap(one[i],one[step]);
		}
	}
    vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int>> result;
		vector<int> path;

       
    }
	template<typename Iter>
	bool next_permutation_LQ(Iter first, Iter last){
		Iter i=first;
		if(++i==last)
			return false;
		Iter ii=last;
		--ii;
		for(--ii;ii!=first&&*ii>*(ii+1);--ii)
			;
		if(ii==first){
			reverse(first,last);
			return false;
		}else{
			Iter iii=--last;
			while(*iii<*ii){
				--iii;
			}
			swap(*iii,*ii);
			reverse(iii,last);
			return true;
		}

	}
	vector<vector<int> > combine(int n, int k){
		vector<vector<int>> result;
		vector<int> input;
		vector<int> path;
		for(int i=1;i<=n;++i){
			input.push_back(i);
		}
		combine(result, input, path, n, k, 0);
		return result;
	}
	void combine(vector<vector<int>> &result, vector<int> &input, vector<int> &path, int n, int k, int start){
		if(k==0){
			result.push_back(path);
			return;
		}
		for(int i=start;i!=n-k+1;++i){
			path.push_back(input[i]);;
			combine(result,input,path,n,k-1,i+1);
			path.pop_back();
		}

	}
	int ladderLength(const string& start, const string &end, const unordered_set<string> &dict){
		vector<string> dict_vec;
		dict_vec.push_back(start);
		dict_vec.insert(dict_vec.end(),dict.begin(),dict.end());
		dict_vec.push_back(end);
		const size_t len=dict_vec.size();
		vector<vector<bool>> path(len, vector<bool>(len, false));
		for(size_t i=0;i!=len;++i){
			for(size_t j=0;j!=i;++j){
				if(is_a_path(dict_vec[i],dict_vec[j]))
					path[i][j]=path[j][i]=true;
			}
		}
		vector<bool> is_path(len,false);
		vector<int> level_index(len,0);
		queue<int> cur_bfs;
		queue<int> next_bfs;
		int level=1;
		cur_bfs.push(0);
		is_path[0]=true;
		++level;
		bool found=false;
		while(!(cur_bfs.empty()&&next_bfs.empty())){
			if(cur_bfs.empty()){
				++level;
				cur_bfs.swap(next_bfs);
			}
			int temp=cur_bfs.front();
			cur_bfs.pop();
			for(int i=0;i!=len;++i){
				if(path[temp][i]==true&&is_path[i]==false){
					is_path[i]=true;
					next_bfs.push(i);
					level_index[i]=level;
					if(is_path.back()) found=true;
				}
			}
			if (found==true) break;
		}
		
		return level_index.back();
	}
	bool is_a_path(const string &a, const string &b){
		size_t alen=a.size();
		size_t blen=b.size();

		if(alen!=blen)
			return false;
		size_t count=0;
		for(size_t i=0;i!=alen;++i){
			if(a[i]!=b[i]){
				++count;
				if(count>1)
					return false;
			}
		}
		return count==1 ? true: false;
	}
	void solve(vector<vector<char>> &board){
		if(board.empty()) return;
		auto hgt=board.size();
		auto len=board[0].size();
		for(size_t i=0;i!=len;++i){
			block_bfs(board,0,i);
			block_bfs(board,hgt-1,i);
		}
		for(size_t j=0;j!=hgt;++j){
			block_bfs(board,j,0);
			block_bfs(board,j,len-1);
		}

		for(size_t i=0;i!=hgt;++i){
			for(size_t j=0;j!=len;++j){
				if(board[i][j]=='O')
					board[i][j]='X';
				if(board[i][j]=='A')
					board[i][j]='O';
			}
		}
		return;
	}
	void block_bfs(vector<vector<char>> &board, int i, int j){
		int hgt=board.size();
		int len=board[0].size();
		if(board[i][j]=='X')
			return;
		board[i][j]='A';
		typedef pair<int,int> state;
		auto is_valid=[&](const state &pos)->bool{
			int m=pos.first;
			int n=pos.second;
			if(m<0||n<0||m>=hgt||n>=len||board[m][n]!='O')
				return false;
			board[m][n]='A';
			return true;
		};
		auto find_next_block=[&](const state &pos)->vector<state>{
			vector<state> result;
			int x=pos.first;
			int y=pos.second;
			state adjcent_pos[4]={make_pair(x,y-1),make_pair(x,y+1),make_pair(x-1,y),make_pair(x+1,y)};
			for(int k=0;k!=4;++k){
				if(is_valid(adjcent_pos[k])){
					result.push_back(adjcent_pos[k]);
				}
			}
			return result;
		};
		queue<state> blocks_queue;
		blocks_queue.push(make_pair(i,j));
		while(!blocks_queue.empty()){
			state temp=blocks_queue.front();
			blocks_queue.pop();
			auto newblocks=find_next_block(temp);
			if(!newblocks.empty()){
				for(int i=0;i!=newblocks.size();++i){
					blocks_queue.push(newblocks[i]);
				}
			}
		}
	}
};


int main(){

	Solution sol;

	cin.get();
	return 0;
}