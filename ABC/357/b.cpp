#include <bits/stdc++.h>
using namespace std;

// 2024/07/11
// isupperとかtoupperの関数がchar型にしか使えないことを把握した

int main()
{
    string S;
    cin >> S;

    auto lowerCaseNum = 0;
    auto upperCaseNum = 0;

    for (auto i : S)
    {
        if (isupper(i))
        {
            upperCaseNum++;
        }
        else
        {
            lowerCaseNum++;
        }
    }

    if (upperCaseNum > lowerCaseNum)
    {
        for (int i = 0; i < S.size(); i++)
        {
            S[i] = toupper(S[i]);
        }
    }
    else
    {
        for (int i = 0; i < S.size(); i++)
        {
            S[i] = tolower(S[i]);
        }
    }

    cout << S << endl;
}
