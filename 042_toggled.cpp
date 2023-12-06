#include <iostream>

using namespace std ;

int main()
{
    char C[] = "DArShaNa";
    int i;
    for (i=0 ; C[i]!= '\0';i++)
    {
        if (C[i]>=65 && C[i]<=90)
        C[i] = C[i]+ 32;
        else if(C[i]>=97 && C[i]<=122)
        C[i] = C[i]-32;
    }
    printf(C);
}