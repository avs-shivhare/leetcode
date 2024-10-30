class Solution {
public:
    int dp[1001][1001][2];
    vector<int> temp;
    int cnt = 0;
    int find(int i,int prev,bool inc,vector<int> &nums,int &n) {
        if(i == n) {
            // for(auto i: temp) {
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            if(inc == false) return 0;
            return -1e9;
        }
        if(prev != -1 && dp[i][prev][inc] != -1) return dp[i][prev][inc];
        int take = -1e9,notTake = -1e9;
        if(inc) {
            if(prev == -1 || nums[prev] < nums[i]) {
                cnt++;
                //temp.push_back(nums[i]);
                take = 1+find(i+1,i,true,nums,n);
                //temp.pop_back();
                cnt--;
            }
            else if(cnt > 1 && nums[prev] > nums[i]) {
                //temp.push_back(nums[i]);
                take = 1+find(i+1,i,false,nums,n);
                //temp.pop_back();
            }
            notTake = 0+find(i+1,prev,true,nums,n);
        }
        else {
            if(nums[prev] > nums[i]) {
                //temp.push_back(nums[i]);
                take = 1+find(i+1,i,false,nums,n);
                //temp.pop_back();
            }
            notTake = 0+find(i+1,prev,false,nums,n);
        }
        //cout<<i<<" ind "<<take<<" "<<notTake<<endl;
        if(prev == -1) return max(take,notTake);
        return dp[i][prev][inc] = max(take,notTake);
    }
    int minimumMountainRemovals(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int ans = find(0,-1,true,nums,n);
        //cout<<ans<<endl;
        return n- ans;
    }
};