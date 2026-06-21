class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            long long sum = 0;
            for(int j = i; j<n; j++) {
                sum += nums[j];
                long long el = sum;
                int first = 0;
                while(el) {
                    first = el%10;
                    el /= 10;
                }
                if(first == x && sum%10 == x) cnt++;
                //cout<<j<<" "<<sum<<endl;
            }
        }
        return cnt;
    }
};