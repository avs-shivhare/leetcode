class Solution {
public:
    static bool comparator(vector<int> t1,vector<int> t2) {
        if(t1[1] < t2[1]) return true;
        else return false;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        sort(pairs.begin(),pairs.end(),comparator);
        int n = pairs.size();
        int cnt =1;
        int b = pairs[0][1];
        // for(auto i : pairs) {
        //     cout<<i[0]<<"->"<<i[1]<<" ";
        // }
        for(int i = 1; i<n; i++) {
            if(b<pairs[i][0]) {
                cnt++;
                b = pairs[i][1];
            }
        }
        return cnt;
    }
};