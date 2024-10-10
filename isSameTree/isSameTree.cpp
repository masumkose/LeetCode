

#include "../include/include.hpp"

class Solution
{
public:
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
	}
};

int main()
{
	Solution ss;

	return (0);
}
