class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<int> temp;
        int n = words.size();
        for(int i = 0; i<n; i++) {
            if(temp.empty()) {
                temp.push_back(i);
            }
            else {
                unordered_map<char,int> mpp;
                for(auto &j: words[temp.back()]) mpp[j]++;
                for(auto &j: words[i]) {
                    mpp[j]--;
                    if(mpp[j] == 0) mpp.erase(j);
                }
                //cout<<i<<" "<<mpp.size()<<endl;
                if(!mpp.empty()) temp.push_back(i); 
            }
        }
        vector<string> ans;
        for(auto i: temp) ans.push_back(words[i]);
        return ans;
    }
};