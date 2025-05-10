#include <iostream>
#include <vector>
using namespace std;

int Binary(const vector<int>& vec, int lo, int hi, int target) {
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (vec[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int LIS() {
    int n, el;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> lis;
    lis.push_back(nums[0]);

    for (int i = 1; i < n; ++i) {
        if (nums[i] > lis.back()) {
            lis.push_back(nums[i]);
        } else {
            int idx = Binary(lis, 0, lis.size(), nums[i]);
            lis[idx] = nums[i];
        }
    }

    return lis.size();
}

int main() {
    cout << LIS() << '\n';
    return 0;
}
