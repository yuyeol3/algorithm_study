#include <iostream>
using namespace std;


int func2(int arr[], int n) {
    bool existNum[101] = {0,};
    // // fill(existNum, existNum+101, false);

    // for (int i = 0; i < n; i++)
    //     existNum[arr[i]]++;

    // for (int i = 0; i < n; i++) {
    //     int counterPart = 100 - arr[i];
    //     if (existNum[counterPart]) {
    //         if (counterPart == arr[i]) {
    //             return existNum[counterPart] >= 2;
    //         }
    //         else return 1;
    //     }
    // }

    // 쌍이 존재한다면 어차피 순회하며 찾아지므로
    // 굳이 먼저 존재하는 원소를 다 표시하고 체크할 필요가 없다.
    for (int i = 0; i < n; i++) {
        if (existNum[100 - arr[i]]) {
            return 1;
        }
        existNum[arr[i]] = 1;
    }

    return 0;
}

int main() {
    int arr1[] = {1, 52, 48};
    int arr2[] = {50, 42};
    int arr3[] = {4, 13, 63, 87};

    cout << func2(arr1, 3) << endl;
    cout << func2(arr2, 2) << endl;
    cout << func2(arr3, 4) << endl;
    // 시간복잡도 O(N^2)
    return 0;
}