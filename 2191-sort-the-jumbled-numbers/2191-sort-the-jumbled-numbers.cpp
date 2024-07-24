class Solution {
public:
    static bool compare(pair<int,pair<int,int>> &t1,pair<int,pair<int,int>> &t2) {
        if(t1.first < t2.first) return true;
        else if(t1.first > t2.first) return false;
        else if(t1.second.second < t2.second.second) return true;
        return false;
    }
    vector<int> sortJumbled(vector<int>& mpp, vector<int>& nums) {
        vector<pair<int,pair<int,int>>> temp;
        int n = nums.size();
        for(int i =0; i<n; i++) {
            string s = to_string(nums[i]);
            for(int j =0; j<s.size(); j++) {
                s[j] = mpp[s[j]-'0']+'0';
            }
            int t = stoi(s);
            temp.push_back({t,{nums[i],i}});
        }
        sort(temp.begin(),temp.end(),compare);
        vector<int> ans;
        for(auto i: temp) {
            ans.push_back(i.second.first);
        }
        return ans;
    }
};