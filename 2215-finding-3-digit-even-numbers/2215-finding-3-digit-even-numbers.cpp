class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(auto i: digits) mpp[i]++;
        for(int i = 100; i<1000; i+=2) {
            string x = to_string(i);
            unordered_map<int,int> temp;
            for(auto j: x) {
                temp[j-'0']++;
            }
            bool flag = true;
            for(auto j: temp) {
                if(j.second > mpp[j.first]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};