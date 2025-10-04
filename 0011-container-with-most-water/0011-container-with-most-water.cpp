class Solution {
public:
    int maxArea(vector<int>& arr) {
        int ans = 0;
        int l = 0,r = arr.size()-1;
        while(l<r) {
            int len = r-l;
            int mini = min(arr[l],arr[r]);
            ans = max(ans,len*mini);
            if(arr[l] < arr[r]) l++;
            else r--;
        }
        return ans;
    }
};