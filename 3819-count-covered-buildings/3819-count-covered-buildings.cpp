class Solution {
public:
    bool isLess(vector<int> &arr,int el) {
        int l = 0,r = arr.size()-1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid] < el) return true;
            else r = mid-1;
        }
        return false;
    }
    bool isGreater(vector<int> &arr,int el) {
        int l = 0,r = arr.size()-1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid] > el) return true;
            else l = mid+1;
        }
        return false;
    }
    int countCoveredBuildings(int n, vector<vector<int>>& build) {
        unordered_map<int,vector<int>> xmpp,ympp;
        for(auto i: build) {
            xmpp[i[0]].push_back(i[1]);
            ympp[i[1]].push_back(i[0]);
        }
        for(auto &i: xmpp) {
            sort(i.second.begin(),i.second.end());
        }
        for(auto &i: ympp) {
            sort(i.second.begin(),i.second.end());
        }
        int cnt = 0;
        for(auto i: build) {
            if(isLess(xmpp[i[0]],i[1]) && isGreater(xmpp[i[0]],i[1]) && isLess(ympp[i[1]],i[0]) && isGreater(ympp[i[1]],i[0])) cnt++;
        }
        return cnt;
    }
};