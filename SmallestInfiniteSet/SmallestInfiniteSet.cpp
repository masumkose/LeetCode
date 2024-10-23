

#include "../include/include.hpp"

class SmallestInfiniteSet
{
private:
	set<int> mySet;

public:
	SmallestInfiniteSet()
	{
		for (int i = 1000; i >= 1; i--)
		{
			mySet.insert(i);
		}
	}

	int popSmallest()
	{
		int i = *mySet.begin();
		mySet.erase(mySet.begin());
		return i;
	}

	void addBack(int num)
	{
		if (num <= 0 || mySet.find(num) != mySet.end())
			return;
		mySet.insert(num);
	}
};

int main()
{
	SmallestInfiniteSet *obj = new SmallestInfiniteSet();

	int param_1 = obj->popSmallest();
	cout << param_1 << '\n';
	obj->addBack(1);
	param_1 = obj->popSmallest();
	cout << param_1 << '\n';
	param_1 = obj->popSmallest();
	cout << param_1 << '\n';
	param_1 = obj->popSmallest();
	cout << param_1 << '\n';
	obj->addBack(2);
	obj->addBack(3);
	param_1 = obj->popSmallest();
	cout << param_1 << '\n';
	param_1 = obj->popSmallest();
	cout << param_1 << '\n';
	

	return (0);
}
