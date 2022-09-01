#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
void split(std::ifstream &is, int index);
int main(int argc, char **argv)
{
	try
	{
		if (argc != 3)
			throw std::invalid_argument("invalid_argument");
		std::ifstream is(argv[1]);
		std::stringstream ss;
		ss << argv[2];
		int i = 0;
		ss >> i;
		split(is, i);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
void split(std::ifstream &is, int index)
{
	std::string s, fileBaseName("file");
	std::map<char, std::string> maps;
	int num = 0;
	while (is >> s)
	{
		if (maps.end() == maps.find(s[index]))
		{
			std::stringstream ss;
			ss << fileBaseName << num << ".txt";
			++num;
			auto &&n = ss.str();
			std::ofstream(n) << s << '\n';
			maps[s[index]] = n;
		}
		else
		{
			std::ofstream(maps[s[index]], std::ios_base::app) << s << '\n';
		}
	}
	std::cout << maps.size() << std::endl;
	for (auto &i : maps)
		std::cout << i.first;
}