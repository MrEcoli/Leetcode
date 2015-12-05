//LeetCode List ÌâÄ¿
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <list>
#include <vector>
#include <random>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;
int maxsum=0;
typedef struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int value;
	TreeNode(int x):value(x),left(nullptr),right(nullptr){};
}* pNode;

pNode insert_node(pNode root,int input){
	if(root==nullptr){
		pNode newnode=new TreeNode(input);
		return newnode;
	}
	if(input>root->value){
		root->right=insert_node(root->right,input);
	}
	else
		root->left=insert_node(root->left,input);
	return root;
}
vector<int> PreOrderIt(pNode root){
	vector<int> result;
	stack<pNode> tree_stack;
	if(root==nullptr)
		return result;
	tree_stack.push(root);
	while(!tree_stack.empty()){
		pNode temp=tree_stack.top();
		result.push_back(temp->value);
		if(temp->right!=nullptr)
			tree_stack.push(temp->right);
		if(temp->left!=nullptr)
			tree_stack.push(temp->left);
	}
	return result;
}
void PreOrderItPrint(pNode root){
	stack<pNode> tree_stack;
	if(root==nullptr)
		return;
	tree_stack.push(root);
	while(!tree_stack.empty()){
		pNode temp=tree_stack.top();
		cout<<temp->value<<" ";
		tree_stack.pop();
		if(temp->right!=nullptr)
			tree_stack.push(temp->right);
		if(temp->left!=nullptr)
			tree_stack.push(temp->left);
	}
	cout<<endl;
}
vector<int> InOrderIt(pNode root){
	vector<int> result;
	stack<pNode> tstack;
	if(root==nullptr)
		return result;
	pNode p=root;
	tstack.push(p);
	while(!tstack.empty()){
		if(p->left!=nullptr){
			tstack.push(p->left);
			p=p->left;
		}
		else{
			pNode temp=tstack.top();
			tstack.pop();
			result.push_back(temp->value);
			p=temp->right;
		}
	}
	return result;
}

void InOrderItPrint(pNode root){
	stack<pNode> tstack;
	if(root==nullptr)
		return;
	pNode p=root;
	while(!tstack.empty()||p!=nullptr){
		if(p!=nullptr){
			tstack.push(p);
			p=p->left;
		}
		else{
			pNode temp=tstack.top();
			tstack.pop();
			cout<<temp->value<<" ";
			p=temp->right;
		}
	}
	cout<<endl;;
}
int height(pNode root){
	if(root==nullptr)
		return 0;
	int lhs=height(root->left),rhs=height(root->right);
	return max(lhs,rhs)+1;
}
bool isBlance(pNode root, int *hgt){
	return false;
}
int LCS(string lhs,string rhs){
	auto m=lhs.size();
	auto n=rhs.size();
	vector<int> lcsary(n,0);
	vector<vector<int>> lcsmatrix(m,vector<int>(n,0));
	for(unsigned int i=0;i<m;++i){
		for(unsigned int j=0;j<n;++j){
			if(lhs[i]==rhs[j])
				lcsary[j]=j==0?1:lcsary[j-1]+1;
			else
				lcsary[j]=j==0?0:max(lcsary[j],lcsary[j-1]);
		}
	}
	return lcsary[n-1];
}
int LIS(vector<int> ary){
	vector<int> L_ary;
	L_ary.push_back(ary[0]);
	for(unsigned int i=1;i!=ary.size();++i){
		if(ary[i]<L_ary.front())
			L_ary[0]=ary[i];
		else if(ary[i]>L_ary.back())
			L_ary.push_back(ary[i]);
		else{
			auto temp=lower_bound(L_ary.begin(),L_ary.end(),ary[i]);
			*temp=ary[i];
		}
	}
	return L_ary.size();
}

vector<pNode> uniqueBST(int start,int end){
	vector<pNode> result;
	if(start>end){
		result.push_back(nullptr);
		return result;
	}
	for(int k=start;k<=end;++k){
		vector<pNode> leftSubs=uniqueBST(start,k-1);
		vector<pNode> rightSubs=uniqueBST(k+1,end);
		for(auto i=leftSubs.begin();i!=leftSubs.end();++i)
			for(auto j=rightSubs.begin();j!=rightSubs.end();++j){
				pNode temp=new TreeNode(k);
				temp->left=*i;
				temp->right=*j;
				result.push_back(temp);
			}
	}
	return result;
}

vector<pNode> uniqueBST(int n){
	return uniqueBST(1,n);
}
int minDepth(pNode root){
	if(root->left==nullptr||root->right==nullptr)
		return 0;
	return min(minDepth(root->left),minDepth(root->right))+1;
}
bool PathSum(pNode root,int sum, int num){
	if(root==nullptr)
		return false;
	sum+=root->value;
	if(root->left==nullptr&&root->right==nullptr)
		return sum==num;
	
	return PathSum(root->right,sum,num)||PathSum(root->left,sum,num);
}
void Path(pNode root, int sum, vector<int> path_node,vector<vector<int>> &total_path){
	if(root==nullptr)
		return;
	sum-=root->value;
	path_node.push_back(root->value);
	if(root->left==nullptr&&root->right==nullptr){
		if(sum==0)
			total_path.push_back(path_node);
	}

	Path(root->right,sum,path_node,total_path);
	Path(root->left,sum,path_node,total_path);

}
int max_path_sum(pNode root){
	if(root==nullptr) return 0;
	int sum=root->value;
	int lhs=max_path_sum(root->right);
	int rhs=max_path_sum(root->left);
	if(lhs>0) sum+=lhs;
	if(rhs>0) sum+=rhs;
	maxsum=max(maxsum,sum);
	return max(lhs,rhs)>0?max(lhs,rhs)+root->value:root->value;
}

vector<vector<int>> Path_of_sum(pNode root, int sum){
	vector<vector<int>> paths;
	vector<int> path_node;
	Path(root,sum,path_node,paths);
	return paths;
}



int sum_of_path(pNode root){
	if(root==nullptr) 
		return 0;
	if(root->left==nullptr&&root->right==nullptr)
		return root->value;
	int lhs=root->left==nullptr?0:sum_of_path(root->left)+10*root->value;
	int rhs=root->right==nullptr?0:sum_of_path(root->right)+10*root->value;;
	return lhs+rhs;
}

int main(){

	vector<pNode> result=uniqueBST(2);
	cout<<result.size()<<endl;
	for(auto i=result.begin();i!=result.end();++i){
		cout<<sum_of_path(*i)<<" ";
	}
	
	cin.get();
	return 0;
}