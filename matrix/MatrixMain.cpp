#include "Matrix.h"
int main(void)
{
     Matrix B{{0, 1, 1},
              {1, 0, -1},
              {1, 1, 0}};
     cout << B.RowSimplestFormOfMatrix();
     return 0;
}