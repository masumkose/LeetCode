

#include "../include/include.hpp"

class Solution
{
public:


	vector<vector<int>> levelOrder(TreeNode *root)
	{
		vector<vector<int>> res;
		queue<TreeNode *> que;
		if (root == nullptr)
			return res;
		que.push(root);
		while (!que.empty())
		{
			int size = que.size();
			vector<int> level;
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				que.pop();
				level.push_back(node->val);
				if (node->left != nullptr)
					que.push(node->left);
				if (node->right != nullptr)
					que.push(node->right);
			}
			res.push_back(level);
		}
		return res;
	}
};

int main()
{
	Solution ss;

	vector<int> nums = {3,9,20,-1,-1,15,7};
	TreeNode *root = createTree(nums, 0);

	print_nested_container(ss.levelOrder(root));

	return (0);
}
