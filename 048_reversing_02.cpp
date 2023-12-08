#include <iostream>

using namespace std ;

int main()
{
    char A[] = "python" ;
    char t ;
    int i, j ;

    for (i=0 ;i<j ;i++,j++)
    {
        t= A[i];
        A[i] = A[j];
        A[j] = t ;
    }
    printf("%s", A) ;
}