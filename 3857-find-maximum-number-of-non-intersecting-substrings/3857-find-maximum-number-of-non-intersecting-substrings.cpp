class Solution {
public:
    int maxSubstrings(string word) {
        unordered_map<char,deque<int>> mpp;
        int n = word.size();
        for(int i = 0; i<n; i++) {
            mpp[word[i]].push_back(i);
        }
        int i = 0;
        int cnt = 0;
        while(i<n) {
            int last = -1;
            while(!mpp[word[i]].empty() && mpp[word[i]].front()-i+1 < 4) mpp[word[i]].pop_front();
            if(mpp[word[i]].empty()) {
                i++;
                continue;
            }
            last = mpp[word[i]].front();
            while(i<last) {
                i++;
                while(!mpp[word[i]].empty() && mpp[word[i]].front()-i+1 < 4 && mpp[word[i]].front() < last) mpp[word[i]].pop_front();
                if(!mpp[word[i]].empty() && mpp[word[i]].front()-i+1 >= 4 && mpp[word[i]].front() < last) {
                    last = mpp[word[i]].front();
                }
            }
            cnt++;
            i = last+1;
        }
        return cnt;
    }
};