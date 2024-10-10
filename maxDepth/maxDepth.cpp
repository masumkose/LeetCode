

#include "../include/include.hpp"

class Solution
{
public:
	int maxDepth(TreeNode *root)
	{
		if (!root)
			return 0;
		return (max({maxDepth(root->left), maxDepth(root->right)}) + 1);
	}
};

int main()
{
	Solution ss;

	vector<int> nums = {1,2,3,4,-1,-1,5};
	TreeNode *root = createTree(nums, 0);

	cout << (ss.maxDepth(root)) << '\n';

	return (0);
}
