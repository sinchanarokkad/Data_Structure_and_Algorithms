#include <iostream>

using namespace std ;

int main()
{
    char A[]="PYTHON";
    char B[7];
    int i,j;
    
    for(i=0 ; A[i]!='\0'; i++)
    {

    }
    i =i -1;
    for (i=0 ;i>0 ; i--  ,j++)
    {
        B[j] =A[i] ;
    }
    B[j] ='\0' ;
    printf("%s", B);
}