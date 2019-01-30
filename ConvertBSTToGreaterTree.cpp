#include <iostream>
#include <memory>
using namespace std;

class Solution
{
public:
	struct TreeNode
	{
		int data;
		TreeNode* right;
		TreeNode* left;
		TreeNode(int d, TreeNode* r =NULL, TreeNode* l = NULL)
			:data(d)
			,right(r)
			,left(l){}
	};
public:
	TreeNode* convertBST(TreeNode* root)
	{
		int sum = 0;
		helper(root, sum);
		return root;
	}

	void preOrder(TreeNode* root)
	{
		if (root==NULL)
		{
			return;
		}
		cout<< root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}

private:
	void helper(TreeNode*& node, int& sum)
	{
		if (node==NULL)
		{
			return;
		}
		helper(node->right, sum);
		node->data += sum;
		sum = node->data;
		helper(node->left, sum);
	}
};

int main(int argc,char** argv)
{
	Solution::TreeNode t1(5);
	Solution::TreeNode t2(2);
	Solution::TreeNode t3(13);
	t1.left = &t2;
	t1.right = &t3;

	std::shared_ptr<Solution> pSolution = std::make_shared<Solution>();
	Solution::TreeNode* root = pSolution->convertBST(&t1);

	pSolution->preOrder(root);
}