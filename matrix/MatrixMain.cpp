#include "Matrix.cpp"
int main(void)
{
     Matrix B{{1, 0},
              {0, 1}},
         A{{0, 1.0}, {1.0, 0}};
     cout << (A * B);
     return 0;
}