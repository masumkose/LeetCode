#include "include.hpp"

template <typename Container>
void print_container(const Container &container)
{
	//cout << "{";
	auto it = container.begin();
	while (it != container.end())
	{
		cout << *it;
		++it;
		if (it != container.end())
		{
			//cout << ", ";
		}
		cout << '\n';
	}
	cout << "------\n";
}

template <typename Container>
void print_nested_container(const Container &container)
{
	std::cout << "{\n";
	for (const auto &inner_container : container)
	{
		print_container(inner_container);
	}
	std::cout << "}\n";
}