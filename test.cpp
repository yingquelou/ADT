#include <iostream>
int main(int argc, char *argv[])
{
  auto &os = std::cout;
  for (size_t i = 0; i < argc; i++)
    os << argv[i] << '\n';
  return 0;
}