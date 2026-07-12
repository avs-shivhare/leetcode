class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int,vector<int>> mpp;
        for(int i = 0; i<n; i++) {
            mpp[arr[i]].push_back(i);
        }
        int cnt = 1;
        for(auto &i: mpp) {
            for(auto &j: i.second) {
                arr[j] = cnt;
            }
            cnt++;
        }
        return arr;
    }
};