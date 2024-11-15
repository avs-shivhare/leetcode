class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        while(left+1<n) {
            if(arr[left] > arr[left+1]) break;
            left++;
        }
        if(left == n-1) return 0;
        int right = n-1;
        while(right > 0 ) {
            if(arr[right-1] > arr[right]) break;
            right--;
        }
        if(right == 0) return n-1;
        int ans = min(n-left-1,right);
        int i =0,j = right;
        while(i<=left && j<n) {
            if(arr[i] <= arr[j]) {
                ans = min(ans,j-i-1);
                i++;
            }
            else j++;
        }
        return ans;
    }
};