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
	int maxVal = INT_MIN;
	int maxPathSum(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		maxSum(root);
		return maxVal;
	}

private:
	int maxSum(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}

		int curVal = root->data;
		int lmaxSum = maxSum(root->left);
		int rmaxSum = maxSum(root->right);
		if (lmaxSum>0)
		{
			curVal += lmaxSum;
		}
		if (rmaxSum>0)
		{
			curVal += rmaxSum;
		}

		if (curVal > maxVal)
		{
			maxVal = curVal;
		}
		return max(root->data,max(root->data+lmaxSum,root->data+rmaxSum));
	}
};

int main()
{
	Solution::TreeNode root(-10);
	Solution::TreeNode child1(9);
	Solution::TreeNode child2(20);
	Solution::TreeNode child3(15);
	Solution::TreeNode child4(7);

	root.left = &child1;
	root.right = &child2;
	child2.left = &child3;
	child2.right = &child4;

	shared_ptr<Solution> pSolution = make_shared<Solution>();
	int ret = pSolution->maxPathSum(&root);
	cout << ret << endl;

	return 0;
}