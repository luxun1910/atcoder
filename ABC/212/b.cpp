#include <bits/stdc++.h>
using namespace std;

// 2024/07/18
// 各桁の数値を各配列に分けて格納する処理にとまどった
// もっとサクッとできるようにしたい

int main()
{
    int tmp;
    cin >> tmp;

    vector<int> X(4);
    X[0] = tmp/1000;
    X[1] = (tmp/100) % 10;
    X[2] = (tmp/10) % 10;
    X[3] = tmp % 10;

    // Weakな条件
    // 4桁とも同じ数字の場合
    if (X[0] == X[1] && X[1] == X[2] && X[2] == X[3]){
        cout << "Weak" << endl;
        return 0;
    }

    // 4桁とも連続している場合
    if((X[0]+1) % 10 == X[1] % 10
    && (X[1]+1) % 10 == X[2] % 10
    && (X[2]+1) % 10 == X[3] % 10){
        cout << "Weak" << endl;
        return 0;
    }

    cout << "Strong" << endl;
}
