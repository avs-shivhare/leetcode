class Solution {
public:
    static bool compare(long long t1,long long t2) {
        return to_string(t1)+to_string(t2) > to_string(t2)+to_string(t1);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        string ans = "";
        for(int i : nums) {
            ans += to_string(i);
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};