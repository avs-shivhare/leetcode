class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1;
        long long cnt = 1;
        bool flag = true;
        if(nums[0] == 0) {
            //cout<<"Done"<<endl;
            flag = false;
        }
        for(int i =1; i<n; i++) {
            if(nums[i] == 0 && flag) {
                //cout<<"0 or true ";
                cnt++;
                flag = !flag;
            }
            else if(nums[i] == 0 && !flag) {
                //cout<<"zero or false ";
                cnt = 1;
                //flag = !flag;
            }
            else if(nums[i] == 1 && !flag) {
                cnt++;
                //cout<<"one or false ";
                flag = !flag;
            }
            else if(nums[i] == 1 && flag){
                cnt = 1;
                //cout<<"one or true ";
                //flag = !flag;
            }
            ans += cnt;
            //cout<<cnt<<" "<<ans<<endl;
        }
        return ans;
    }
};