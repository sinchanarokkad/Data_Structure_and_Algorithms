#include <iostream>

using namespace std ;

void perm(char S[] , int K)
{
    static int A[10] ={0};
    static char res[10] ;
    int i ;

    if(S[K]=='\0')
    {
        res[K]='\0';
        printf(res);
    }
    else
    {
        for(i=0 ;S[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                res[K]=S[i] ;
                A[i]=1;
                perm(S,K+1);
                A[i]=0 ;
            }
        }
    }
}

 main()
{
    char S[ ]="ABC ";
    perm (S,0);
}