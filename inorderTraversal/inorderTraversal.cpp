

#include "../include/include.hpp"

class Solution
{
public:
	void traversal(TreeNode *root, vector<int> &vec)
	{
		if (!root)
			return ;
		traversal(root->left, vec);
		vec.push_back(root->val);
		traversal(root->right, vec);
	}

	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> res;
		traversal(root, res);
		return (res);
	}
};

int main()
{
	Solution ss;
	TreeNode *node;
	vector<int> input = {1,2,2,3};
	
	node = createTree(input, 0);
	printInOrder(node);
	print_container(ss.inorderTraversal(node));

	return (0);
}
