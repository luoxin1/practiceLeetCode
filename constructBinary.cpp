#include <vector>
#include <deque>
#include <iostream>
#include <memory>
#include <algorithm>
#include <limits.h>
#include <string>
#include <unordered_map>
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inoder)
	{
		TreeNode* root = NULL;
		createTree(root, preorder.begin(), preorder.end(), inoder.begin(), inoder.end());
		return root;
	}

	void preOder(TreeNode* root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->data << endl;
		preOder(root->left);
		preOder(root->right);
	}

private:
	//指针引用实现构建二叉树
	void createTree(TreeNode*& t,
		vector<int>::iterator pre_beg,
		vector<int>::iterator pre_end,
		vector<int>::iterator in_beg,
		vector<int>::iterator in_end)
	{
		//空树
		if (pre_beg== pre_end)
		{
			t = NULL;
			return;
		}
		t = new TreeNode(*pre_beg);

		//cout << "==>" << t->data<<"\t";

		vector<int>::iterator result = find(in_beg,in_end,t->data);//中序遍历找到根节点,返回迭代指针
		int len = distance(in_beg, result);
		createTree(t->left, pre_beg + 1, pre_beg + len + 1, in_beg, result);//构建左子树
		createTree(t->right, pre_beg +len+ 1, pre_end, result+1, in_end);//构建右子树
	}
};



int main(int argc, char** argv)
{
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inoder = { 9,3,15,20,7 };
	shared_ptr<Solution> pSolution(new Solution());
	Solution::TreeNode* root = pSolution->buildTree(preorder, inoder);
	pSolution->preOder(root);
	return 0;
}