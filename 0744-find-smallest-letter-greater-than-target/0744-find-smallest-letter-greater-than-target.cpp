class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        int l = 0,r = arr.size()-1;
        int ans = 0;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid] > target) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return arr[ans];
    }
};