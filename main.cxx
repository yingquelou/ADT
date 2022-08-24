#include "MDBC.cpp"
int main(int argc, char** argv)
{
	auto& os = std::cout;
	MDBC m(1, 3, 12);

	os << MDBC::AssignValuesRandomly(2, 3, 0, 10);
	return 0;
}