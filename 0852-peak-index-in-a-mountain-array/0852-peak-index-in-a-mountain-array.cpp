class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        int ind = 0;
        if(arr[0] > arr[1]) {
            if(maxi < arr[0]) {
                maxi = arr[0];
                ind = 0;
            }
        }
        if(arr[n-1] > arr[n-2]) {
            if(maxi < arr[n-1]) {
                maxi = arr[n-1];
                ind = n-1;
            }
        }
        int low = 1, high = n-2;
        while(low <= high) {
            int mid = (low+high)>>1;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
                if(maxi < arr[mid]) {
                    maxi = arr[mid];
                    ind = mid;
                }
                break;
            }
            else if(arr[mid-1] < arr[mid]) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ind;
    }
};