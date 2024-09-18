class Solution {
public:
    static bool compare(int &t1,int &t2) {
        string s1 = to_string(t1);
        string s2 = to_string(t2);
        if(s1+s2 > s2+s1) return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        string ans = "";
        for(auto i: nums) {
            ans += to_string(i);
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};