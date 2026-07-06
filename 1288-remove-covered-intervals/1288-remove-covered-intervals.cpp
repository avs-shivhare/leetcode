class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] <= b[0];
        });
        vector<vector<int>> temp;
        for(auto &i: arr) {
            while(!temp.empty() && i[0] <= temp.back()[0] && temp.back()[1] <= i[1]) temp.pop_back();
            if(temp.empty() || !(temp.back()[0] <= i[0] & i[1] <= temp.back()[1])) temp.push_back(i);
        }
        return temp.size();
    }
};