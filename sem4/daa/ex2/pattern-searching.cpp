#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text, pattern;
    bool found = false;

    cout << "Text: ";
    cin >> text;

    cout << "Pattern: ";
    cin >> pattern;

    int n=0, m=0, index = 0;
    while(text[n] != '\0')
    {
       n++;
    }

    while(pattern[m] != '\0')
    {
       m++;
    }

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }

        if (j == m)
        {
            found = true;
            index=i;
            break;
        }
    }

    if (found)
        cout << "\nPattern found at index : " <<index << endl;
    else
        cout << "\nPattern not found" << endl;
    cout<<endl;

    return 0;
}