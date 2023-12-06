#include <iostream>

using namespace std ;

int main ()
{
    char v[] = "how are you";
    int i , word =1 ;
    for (i =0 ;v[i]!=0;i++)
    {
        if (v[i]=' ')
        word++;
    }
    printf("%d", word);
}