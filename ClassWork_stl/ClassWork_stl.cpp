
#include <iostream>
#include <forward_list>

int main()
{
	std::forward_list<int> fl;
	fl.push_front(10);
	fl.push_front(20);
	fl.push_front(30);
	int counter = 0;
	for (auto it : fl)
	{
		counter++;
	}
	auto it = fl.begin();
	for (int i = 0; i < counter; i++)
	{
		if (i != 0)
		{
			it++;
		}
	}
	fl.insert_after(it, 5);
	for (auto it : fl)
	{
		std::cout << it << '\n';
	}
}