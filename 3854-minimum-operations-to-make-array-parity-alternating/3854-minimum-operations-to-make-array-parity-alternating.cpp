class Solution {
public:
    vector<int> find(vector<int> &nums,bool flag) {
        int ans = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto &i: nums) {
            if(flag) {
                if(abs(i)%2 == 1) {
                    ans++;
                    mini = min(mini,i+1);
                    maxi = max(maxi,i-1);
                }
                else {
                    mini = min(mini,i);
                    maxi = max(maxi,i);
                }
            }
            else {
                if(abs(i)%2 == 0) {
                    ans++;
                    mini = min(mini,i+1);
                    maxi = max(maxi,i-1);
                }
                else {
                    mini = min(mini,i);
                    maxi = max(maxi,i);
                }
            }
            flag = !flag;
        }
        return {ans,maxi-mini};
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        if(nums.size() == 1) return {0,0};
        unordered_set<int> st(nums.begin(),nums.end());
        auto a1 = find(nums,true);
        auto a2 = find(nums,false);
        if(st.size() == 1) return {min(a1[0],a2[0]),1};
        if(a1[0] == a2[0]) return {a1[0],min(a1[1],a2[1])};
        else if(a1[0] < a2[0]) return a1;
        return a2;
    }
};