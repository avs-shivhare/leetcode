class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>> temp;
        for(auto i: nums) {
            int cnt = 0;
            for(int j =0; j<32; j++) {
                if(i & (1<<j)) cnt++;
            }
            temp.push_back({i,cnt});
        }
        int n = nums.size();
        for(int i =1; i<n; i++) {
            for(int j = i-1; j>=0; j--) {
                if(temp[j].second == temp[j+1].second && temp[j].first > temp[j+1].first) {
                    //cout<<temp[i].first<<" "<<temp[i+1].first<<endl;
                    swap(temp[j],temp[j+1]);
                }
                
            }
        }
        //for(auto i: temp) cout<<i.first<<" "<<i.second<<endl;
        for(int i =1; i<n; i++) {
            if(temp[i].first < temp[i-1].first) return false;
        }
        return true;
    }
};