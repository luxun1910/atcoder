#include <bits/stdc++.h>
using namespace std;

// 2024/07/14
// int answer = 0にしてて一瞬つまずいた
// 最初から車両は1つ以上必要なのでint answer = 1が正しい

int main()
{
    int N,K;
    cin >> N >> K;

    vector<int> A(N);
    for(auto i = 0; i < N; i++){
        cin >> A.at(i);
    }

    int answer = 1;

    int tempVehicleRiderNum = 0;

    for (auto i : A){
        if(tempVehicleRiderNum + i <= K){
            tempVehicleRiderNum += i;
        }else{
            answer ++;
            tempVehicleRiderNum = i;
        }
    }

    cout << answer << endl;
}
