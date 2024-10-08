

#include "../include/include.hpp"



class Solution
{
public:
	bool isMirror(TreeNode *root1, TreeNode *root2)
	{
		if (!root1 && !root2)
			return (true);
		if (!root1 || !root2)
			return (false);
		if (root1->val != root2->val)
			return (false);
		return (isMirror(root1->left, root2->right) && isMirror(root2->left, root1->right));
	}

	bool isSymmetric(TreeNode *root)
	{
		if (root == NULL)
			return (true);
		return (isMirror(root->left, root->right));
	}
};

int main()
{
	Solution ss;

	vector<int> root = {1,2,2,nullptr,3,nullptr,3};
	TreeNode* tree = createTree(root, 0);
	printLevelOrder(tree);
	cout << ss.isSymmetric(tree) << '\n';

	return (0);
}
