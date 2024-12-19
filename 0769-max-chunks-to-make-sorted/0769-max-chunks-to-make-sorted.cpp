class Solution {
public:
    vector<vector<int>> temp;
    int ans = 0;
    int find(int i,vector<int> &arr) {
        if(i == arr.size()) {
            vector<vector<int>> t = temp;
            vector<int> x;
            for(auto &j: t) {
                sort(j.begin(),j.end());
                for(auto p: j) x.push_back(p);
            }
            for(int j =1; j<x.size(); j++) {
                if(x[j-1] > x[j]) return -1;
            }
            return temp.size();
        }
        int take = 0,notTake = 0;
        if(temp.empty()) {
            temp.push_back({arr[i]});
            take = find(i+1,arr);
            temp.pop_back();
        }
        else {
            temp.back().push_back(arr[i]);
            take = find(i+1,arr);
            temp.back().pop_back();
        }
        temp.push_back({arr[i]});
        notTake = find(i+1,arr);
        temp.pop_back();
        return max(take,notTake);
    }
    int maxChunksToSorted(vector<int>& arr) {
        return find(0,arr);
    }
};