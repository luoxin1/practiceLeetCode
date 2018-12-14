#include <list>
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

class Solution
{
public:
	class ListNode
	{
	public:
		int data;
		ListNode* next;
		ListNode(int x) : data(x), next(NULL) {}
	};
public:
	ListNode* addTwoNums(ListNode* l1, ListNode* l2)
	{
		ListNode head(0);
		ListNode* p = &head;
		int carry = 0;
		while (l1 != nullptr || l2 != nullptr || carry)
		{
			int sum = (l1 != nullptr ? l1->data:0) + (l2 != nullptr ? l2->data : 0) + carry;
			carry = sum / 10;
			p->next = new ListNode(sum%10);

			p = p->next;
			l1 = l1 != nullptr ? l1->next : l1;
			l2 = l2 != nullptr ? l2->next : l2;
		}
		return head.next;
	}
};


int main()
{
	Solution::ListNode d11(2);
	Solution::ListNode d12(4);
	Solution::ListNode d13(3);
	d11.next = &d12;
	d12.next = &d13;

	Solution::ListNode d21(5);
	Solution::ListNode d22(6);
	//Solution::ListNode d23(4);
	d21.next = &d22;
	//d22.next = &d23;

	shared_ptr<Solution> pSolution(new Solution());
	Solution::ListNode* pRet = pSolution->addTwoNums(&d11, &d21);
	while (pRet !=nullptr)
	{
		cout << pRet->data << "";
		pRet = pRet->next;
	}
	cout << endl;
	return 0;
}

