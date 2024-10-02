class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>> mpp;
        int n = arr.size();
        for(int i =0; i<n; i++) {
            mpp[arr[i]].push_back(i);
        }
        int rank =1;
        for(auto i: mpp) {
            for(auto j: i.second) {
                arr[j] = rank;
            }
            rank++;
        }
        return arr;
    }
};