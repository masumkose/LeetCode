

#include "../include/include.hpp"

class Solution
{
public:
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode *root)
	{
		vector<vector<int>> res;
		int zigzag = 0;
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
				TreeNode *node = que.front();
				que.pop();
				level.push_back(node->val);
				if (node->left != nullptr)
					que.push(node->left);
				if (node->right != nullptr)
					que.push(node->right);
			}
			if (zigzag % 2 == 1)
				reverse(level.begin(), level.end());
			res.push_back(level);
			zigzag++;
		}
		return res;
	}

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
				TreeNode *node = que.front();
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

	vector<vector<int>> levelOrderBottom(TreeNode *root)
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
				TreeNode *node = que.front();
				que.pop();
				level.push_back(node->val);
				if (node->left != nullptr)
					que.push(node->left);
				if (node->right != nullptr)
					que.push(node->right);
			}
			res.push_back(level);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	Solution ss;

	vector<int> nums = {1, 2, 3, 4, -1, -1, 5};
	TreeNode *root = createTree(nums, 0);

	print_nested_container(ss.levelOrderBottom(root));

	return (0);
}
