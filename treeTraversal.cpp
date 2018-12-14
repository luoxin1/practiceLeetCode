#include <list>
#include <iostream>
#include <memory>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

class Solution
{
public:
	struct TreeNode
	{
		int data;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int d) :data(d), left(nullptr), right(nullptr) {}
	};

public:
	void inOrder(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		if(node->left!=nullptr)
		{
			inOrder(node->left);
		}
		l.push_back(node->data);
		if (node->right != nullptr)
		{
			inOrder(node->right);
		}
	}

	list<int> const getRetDatas() const
	{
		return l;
	}

private:
	list<int> l;
};


int main()
{
	Solution::TreeNode t1(1);
	Solution::TreeNode t2(2);
	Solution::TreeNode t3(3);

	t1.right = &t2;
	t2.left = &t3;

	shared_ptr<Solution> pSolution(new Solution);
	pSolution->inOrder(&t1);

	list<int> ll = pSolution->getRetDatas();
	for (int i:ll)
	{
		cout << i << ",";
	}
	cout << endl;
	return 0;
}