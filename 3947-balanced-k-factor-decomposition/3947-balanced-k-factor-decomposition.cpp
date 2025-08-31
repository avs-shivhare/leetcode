class Solution {
public:
    int maxi = 1e9;
    vector<int> ans;
    vector<int> temp;
    void find(int i,int k,long long pro,int &n,vector<int> &arr) {
        if(pro > n || k < 0) return;
        if(i >= arr.size()) {
            if(k == 0 && n == pro) {
                if(!temp.empty() && temp.back()-temp.front() < maxi) {
                    ans = temp;
                    maxi = temp.back()-temp.front();
                }
            }
            return;
        }
        temp.push_back(arr[i]);
        find(i,k-1,pro*arr[i],n,arr);
        temp.pop_back();
        find(i+1,k,pro,n,arr);
        return;
    }
    vector<int> minDifference(int n, int k) {
        vector<int> arr;
        for(int i = 1; i*i<=n; i++) {
            if(n%i == 0) {
                arr.push_back(i);
                if(i != (n/i)) arr.push_back(n/i);
            }
        }
        sort(arr.begin(),arr.end());
        find(0,k,1,n,arr);
        return ans;
    }
};