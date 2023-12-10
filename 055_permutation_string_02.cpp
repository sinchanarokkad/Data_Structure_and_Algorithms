#include <iostream>
#include <cstring> // Include for strlen function

using namespace std;

void perm(char S[], int l, int h)
{
    if (l == h)
    {
        cout << S << endl;
    }
    else
    {
        for (int i = l; i <= h; i++)
        {
            swap(S[l], S[i]);
            perm(S, l + 1, h);
            swap(S[l], S[i]);
        }
    }
}

int main()
{
    char S[] = "ABC";
    int n = strlen(S);
    perm(S, 0, n - 1);

    return 0;
}
