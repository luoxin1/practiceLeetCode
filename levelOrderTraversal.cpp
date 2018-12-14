#include <list>
#include <deque>
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
	list<list<int>> levelOrder(TreeNode* root)
	{
		list<list<int>> retDatas;
		if (root == nullptr)
		{
			return retDatas;
		}

		deque<TreeNode*> d;
		d.push_back(root);
		d.push_back(nullptr);

		list<int> subList;
		while (d.size()>0)
		{
			TreeNode* node = d.front();
			d.pop_front();
			if (node!=nullptr)
			{
				subList.push_back(node->data);
				if (node->left!=nullptr)
				{
					d.push_back(node->left);
				}
				if (node->right != nullptr)
				{
					d.push_back(node->right);
				}
			}
			else
			{
				retDatas.push_back(subList);
				if (d.size() > 0)
				{
					subList.clear();
					d.push_back(nullptr);
				}
			}
		}
		return retDatas;
	}
};

int main()
{
	Solution::TreeNode root(3);
	Solution::TreeNode child1(9);
	Solution::TreeNode child2(20);
	Solution::TreeNode child3(15);
	Solution::TreeNode child4(7);

	root.left = &child1;
	root.right = &child2;
	child2.right = &child4;
	child2.left = &child3;
	shared_ptr<Solution> pSolution = make_shared<Solution>();
	list<list<int>> ret = pSolution->levelOrder(&root);
	for (list<int> ls:ret)
	{
		for (int i:ls)
		{
			cout << i<<" ,";
		}
		cout << endl;
	}
}