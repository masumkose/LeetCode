

#include "../include/include.hpp"

class Solution
{
public:
	int numTrees(int n)
	{
		vector <int> res(n, 1);
		for (int i = 1; i <= n; i++)
		{
			res[i] = i + (res[i - 1]);
		}
		return res[n - 1];
	}

	vector<TreeNode *> generete(TreeNode *left, TreeNode *right, vector<TreeNode *> &node)
	{
		if (left == right)
	}

	vector<TreeNode *> generateTrees(int n)
	{
		vector<TreeNode *> node;
		return node;
	}
};

int main()
{
	Solution ss;

	vector<TreeNode *> trees = ss.generateTrees(3);
	int treesNum = ss.numTrees(3);

	cout << treesNum << '\n';
	
	for (auto tree : trees)
	{
		printInOrder(tree);
	}



	return (0);
}
