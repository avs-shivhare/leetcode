class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        stack<int> st,st2;
        int n = nums.size();
        vector<int> temp(n,0),temp2(n,0);
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && nums[i] >= nums[st.top()]) {
                st.pop();
            }
            if(!st.empty()) {
                temp[i] = st.top()-1;
            }
            else temp[i] = n-1;
            st.push(i);
        }
        for(int i = n-1; i>=0; i--) {
            while(!st2.empty() && nums[i] <= nums[st2.top()]) st2.pop();
            if(!st2.empty()) temp2[i] = st2.top()-1;
            else temp2[i] = n-1;
            st2.push(i);
        }
        // for(auto i: temp) cout<<i<<" ";
        // cout<<endl;
        priority_queue<pair<int,int>> maxi;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mini;
        int l = 0,r = 0;
        long long ans = 0;
        while(r<n) {
            maxi.push({nums[r],r});
            mini.push({nums[r],r});
            while(l<=r && !maxi.empty() && !mini.empty() && maxi.top().first == maxK && mini.top().first == minK) {
                //cout<<l<<" "<<r<<" "<<temp[maxi.top().second]<<" "<<maxi.top().second<<endl;
                ans += min(temp[maxi.top().second],temp2[mini.top().second])-r+1;
                l++;
                while(!maxi.empty() && maxi.top().second < l) maxi.pop();
                while(!mini.empty() && mini.top().second < l) mini.pop();
            }
            while(l<=r && !maxi.empty() && maxi.top().first > maxK) {
                l++;
                while(!maxi.empty() && maxi.top().second < l) maxi.pop();
                while(!mini.empty() && mini.top().second < l) mini.pop();
            }
            while(l<=r && !mini.empty() && mini.top().first < minK) {
                l++;
                while(!maxi.empty() && maxi.top().second < l) maxi.pop();
                while(!mini.empty() && mini.top().second < l) mini.pop();
            }
            r++;
        }
        return ans;
    }
};