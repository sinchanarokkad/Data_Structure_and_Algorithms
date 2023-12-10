#include <iostream>

using namespace std;

int main()
{
    char A[] = "decimal";
    char B[] = "medical";

    int i, H[26] = {0};

    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 'a'] += 1; // Fix: 'a' instead of 97
    }

    for (i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 'a'] -= 1; // Fix: 'a' instead of 97
        if (H[B[i] - 'a'] < 0)
        {
            cout << "Not an anagram" << endl; // Fix: Use cout instead of printf
            break;
        }
    }

    if (B[i] == '\0') // Fix: Correct the condition
        cout << "It's an anagram" << endl;

    return 0;
}