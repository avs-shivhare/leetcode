class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> mpp;
        for(auto i: word) {
            mpp[i]++;
        }
        vector<int> temp;
        for(auto i: mpp) {
            temp.push_back(i.second);
        }
        sort(temp.begin(),temp.end());
        int ans = word.size();
        for(int i = 0; i<temp.size(); i++) {
            int sum = 0;
            for(int j = 0; j<temp.size(); j++) {
                if(temp[i] > temp[j]) sum += temp[j];
                else sum += max(temp[j]-(temp[i]+k),0);
            }
            ans = min(ans,sum);
        }
        return ans;
    }
};