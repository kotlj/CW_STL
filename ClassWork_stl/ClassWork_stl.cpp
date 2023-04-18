
#include <iostream>
#include <map>
#include <fstream>
#include <Windows.h>

void Find(std::map<std::string, std::string> &_dict, const char* word)
{
	bool find = false;
	for (auto it : _dict)
	{
		if (it.first == word)
		{
			std::cout << "First: " << it.first << " Second: " << it.second << '\n';
			find = true;
		}
	}
	if (!find)
	{
		std::cout << "No such word\n";
	}
}
inline void add(std::map<std::string, std::string>& _dict, const char* key, const char* second)
{
	_dict[key] = second;
}
inline void del(std::map<std::string, std::string>& _dict, const char* key)
{
	_dict[key].erase();
}
void expt(std::map<std::string, std::string> &_dict, const char* path)
{
	std::ofstream exp(path);
	if (exp.is_open())
	{
		for (auto it : _dict)
		{
			exp << it.first << '|' << it.second << '\n';
		}
		exp << ']';
		exp.close();
	}
}
void impt(std::map < std::string, std::string> &_dict, const char* path)
{
	std::ifstream imp(path);
	char* storage = new char[100000];
	char* first = new char[100];
	char* second = new char[100];
	int indx = 0;
	if (imp.is_open())
	{
		imp.getline(storage, 100000, ']');
		imp.close();
		while (indx < strlen(storage))
		{
			if (first != nullptr)
			{
				delete[] first;
				first = new char[100];
			}
			if (second != nullptr)
			{
				delete[] second;
				second = new char[100];
			}
			for (int i = 0; storage[indx] != '|'; indx++, i++)
			{
				first[i] = storage[indx];
				first[i + 1] = '\0';
			}
			indx++;
			for (int i = 0; storage[indx] != '\n'; indx++, i++)
			{
				second[i] = storage[indx];
				second[i + 1] = '\0';
			}
			indx++;
			_dict[first] = second;
		}
		delete[] storage;
		delete[] first;
		delete[] second;
	}
}

int main()
{
	std::map<std::string, std::string> dict;
	//add(dict, "something", "sommething");
	//add(dict, "what", "whatt");
	//expt(dict, "test.txt");
	impt(dict, "test.txt");
	Find(dict, "what");
}