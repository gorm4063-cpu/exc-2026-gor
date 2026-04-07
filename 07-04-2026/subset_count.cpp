
#include <iostream>
using namespace std;
int sum(int arr[], int a, int b) {
    int s = 0;
    for (int i = a; i <= b; i++) {
        s += arr[i];
    }
    return s;
}
int main() {
    int count = 0;
    int k = 2;
    int nums[] = { 1,1,1 };
    int size = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < size; i++) {
        for (int j = size; j >= 0; j--) {
            if (sum(nums, i, j) == k) {
                if (i == j) {
                    continue;
                }
                count++;
            }
        }
    }

    cout << count;
    return 0;
}