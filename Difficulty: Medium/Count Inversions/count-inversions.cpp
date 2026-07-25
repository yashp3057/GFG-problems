class Solution {
public:

    long long merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        long long invCount = 0;

        while (left <= mid && right <= high) {

            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                // All remaining elements in left half are greater than arr[right]
                invCount += (mid - left + 1);
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy merged array back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return invCount;
    }

    long long mergeSort(vector<int>& arr, int low, int high) {

        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        long long leftInv = mergeSort(arr, low, mid);
        long long rightInv = mergeSort(arr, mid + 1, high);
        long long mergeInv = merge(arr, low, mid, high);

        return leftInv + rightInv + mergeInv;
    }

    long long inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};