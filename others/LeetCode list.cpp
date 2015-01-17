//LeetCode List ÌâÄ¿
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <list>
#include <vector>
#include <random>
#include <queue>
#include <unordered_map>
using namespace std;

struct listNode{
	typedef listNode* pNode;
	listNode* next;
	int value;
	listNode(int x):next(nullptr),value(x){}
	pNode pushfront(int x)
	{
		pNode pNew=new listNode(x);
		pNew->next=this;
		return pNew;
	}
	void printlist(pNode listhead)
	{
		if(listhead!=nullptr){
			cout<<listhead->value<<" ";
			printlist(listhead->next);
		}
	}
};

typedef listNode* pNode;

pNode addList(pNode alist,pNode blist){
	pNode pHead=new listNode(-1);
	pNode prev=pHead;
	int va=0,vb=0;
	int over=0;
	int vc=0;
	for(pNode a=alist,b=blist;a||b;a=a==nullptr?nullptr:a->next,b=b==nullptr?nullptr:b->next)
	{
		va=a==nullptr?0:a->value;
		vb=b==nullptr?0:b->value;
		vc=(va+vb+over)%10;
		over=(va+vb+over)/10;
		pNode pTemp=new listNode(vc);
		prev->next=pTemp;
		prev=prev->next;
	}
	if(over)
	{
		pNode pTemp=new listNode(over);
		prev->next=pTemp;
	}
	return pHead->next;
 }
void swapNode(pNode a,pNode b)
 {
	 int temp=a->value;
	 a->value=b->value;
	 b->value=temp;
 }
pNode nextpNode(pNode aNode, int n)
 {
	 while(--n&&aNode!=nullptr)
		 aNode=aNode->next;
	 return aNode;
 }
pNode partReverse(pNode alist, int m, int n)
 {
	 while(m<n)
	 {
		 swapNode(nextpNode(alist,m++),nextpNode(alist,n--));
	 }
	return alist;
}
pNode partReverse2(pNode alist, int m, int n)
 {
	 pNode pBefore=alist,pAfter,p1,p2=alist;
	 if(m==1)
		 pBefore=alist;
	 else{
		while(--m-1)
			 pBefore=pBefore->next;
	 }
	 while(--n)
		 p2=p2->next;
	 pAfter=p2->next;
	 p1=pBefore->next;
	 pNode pFirst=p1,pLast=p2;
	 pNode pFront=p1;
	 p1=p1->next;
	 pNode pBack=p1?p1->next:nullptr;
	 while(p1!=pAfter)
	 {
		 p1->next=pFront;
		 pFront=p1;
		 p1=pBack;
		 pBack=p1?p1->next:nullptr;
	 }
	 pFirst->next=pAfter;
	 pBefore->next=pLast;
	 return alist;
 }
pNode partReverse3(pNode alist, int m, int n)
 {
	 listNode Head(100);
	 int index=m;
	 pNode pHead=&Head;
	 pNode pPrev,pCur;
	 pHead->next=alist;
	 pNode pBefore=pHead;
	 while(--m)
		 pBefore=pBefore->next;
	 pPrev=pBefore->next;
	 pCur=pPrev->next;
	 for(int i=index;i<n;++i)
	 {
		 pPrev->next=pCur->next;
		 pCur->next=pBefore->next;
		 pBefore->next=pCur;
		 pCur=pPrev->next;
	 }
	 return pHead->next;
 }
pNode partReverseStack(pNode alist,int m, int n)
 {
	 listNode Head(100);
	 int start=m,end=n;
	 pNode pHead=&Head;
	pHead->next=alist;
	stack<pNode> NodeStack;
	pNode pBefore=pHead,pAfter,pFirst,pLast=pHead;
	while(--m)
		pBefore=pBefore->next;
	while(--n)
		pLast=pLast->next;
	
	pAfter=pLast->next;
	pFirst=pBefore->next;
	while(pFirst!=pAfter)
	{
		NodeStack.push(pFirst);
		pFirst=pFirst->next;
	}
	while(!NodeStack.empty())
	{
		pBefore->next=NodeStack.top();
		NodeStack.pop();
		pBefore=pBefore->next;
	}
	pBefore->next=pAfter;

	return pHead->next;
 }
pNode listReverse(pNode alist)
 {
	 listNode Head(10);
	 pNode pHead=&Head;
	 pHead->next=alist;
	 pNode prev=pHead->next;
	 pNode cur=prev->next;
	 while(cur!=nullptr)
	 {
		 prev->next=cur->next;
		 cur->next=pHead->next;
		 pHead->next=cur;
		 cur=prev->next;
	 }
	 return pHead->next;
 }
void deleteRecurse(pNode prev,pNode cur)
 {
	 if(cur==nullptr) return;
	 if(prev->value==cur->value)
	 {
		 prev->next=cur->next;
		 delete cur;
		 deleteRecurse(prev,prev->next);
	 }
	 else
	 {
		 deleteRecurse(prev->next,cur->next);
	 }
 }
void listDelDuplicate(pNode alist)
 {
	 pNode prev=alist,cur=alist->next;
	 deleteRecurse(prev,cur);
 }
pNode doubleReverse(pNode alist){
	if(alist==nullptr||alist->next==nullptr)
		return nullptr;
	listNode head(INT_MAX);
	pNode pHead=&head;
	pHead->next=alist;
	
	pNode pCur=alist,pNext=alist->next,pPrev=pHead;
	while(pCur&&pCur->next){
		pCur->next=pNext->next;
		pNext->next=pCur;
		pPrev->next=pNext;
		pPrev=pCur;
		pCur=pCur->next;
		pNext=pCur->next==nullptr?nullptr:pCur->next;
	}
	return pHead->next;
}
pNode reverseFrontList(pNode alist,int k){
	listNode head(INT_MAX);
	listNode* const pHead=&head;
	pHead->next=alist;
	--k;
	pNode prev=alist,cur=alist->next;
	for(int i=0;i!=k&&cur;++i){
		prev->next=cur->next;
		cur->next=pHead->next;
		pHead->next=cur;
		cur=prev->next;
	}
	return pHead->next;
}
bool isPalindrome(string str)
{
	transform(str.begin(),str.end(),str.begin(),tolower);
	auto left=str.begin();
	auto right=prev(str.end());
	while(left<right){
		if(!isalnum(*left))
			++left;
		else if(!isalnum(*right))
			--right;
		else if(*left!=*right)
			return false;
		else {
			++left,--right;
		}
	}
	return true;
}

int main()  
{
	pNode pHead=new listNode(3);
	int a[6]={4,1,6,2,8,1};
	for(int i=0;i!=6;++i)
	{
		pHead=pHead->pushfront(a[i]);
	}
	pHead->printlist(pHead);
	pHead=reverseFrontList(pHead,7);
	cout<<endl;
	pHead->printlist(pHead);
	cout<<endl;
	cout<<static_cast<char>(tolower('H'))<<endl;
	cout<<"-------------------"<<endl;
	string astr("A man, a plan, a canal: Panama");
	cout<<isPalindrome(astr)<<endl;
	cin.get();
	return 0;
}

