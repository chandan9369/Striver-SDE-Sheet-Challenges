class Solution {
public:
    int search(vector<int>& arr, int key) {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (arr[mid] == key) {
                return mid;
            }
            // increasing route
            else if (arr[mid] >= arr[low]) {
                if (arr[mid] >= key and arr[low] <= key) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            // decreasing route
            else {
                if (arr[mid] <= key and arr[high] >= key) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};