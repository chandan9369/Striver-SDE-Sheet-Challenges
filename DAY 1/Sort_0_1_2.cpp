#include <bits/stdc++.h>
void sort012(int *nums, int n)
{
    int s = 0, m = 0, e = n - 1;
    while (m <= e) {
        if (nums[m] < 1) {
            swap(nums[s], nums[m]);
            s++;
            m++;
        }
        else if (nums[m] == 1) {
            m++;
        }
        else {
            swap(nums[m], nums[e]);
            e--;
        }
    }
}