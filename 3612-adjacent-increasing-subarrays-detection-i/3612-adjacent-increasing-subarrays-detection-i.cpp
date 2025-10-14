class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& arr, int k) {
        int len = 0;
        int n = arr.size();
        for(int i = 0; i<n; i++) {
            if(i == 0 || arr[i-1] < arr[i]) len++;
            else len = 1;
            if(len >= k && n-(i+1) >= k) {
                bool flag = true;
                for(int j = i+1; j<n-1 && j-i < k; j++) {
                    if(arr[j] >= arr[j+1]) {
                        flag = false;
                        break;
                    }
                }
                //cout<<i<<" "<<len<<endl;
                if(flag) return true;
            }
        }
        return false;
    }
};