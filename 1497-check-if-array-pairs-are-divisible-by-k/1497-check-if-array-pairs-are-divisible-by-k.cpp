class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        for(auto i: arr) {
            mpp[((i%k)+k)%k]++;
        }
        //cout<<mpp[0]<<endl;
        if(mpp[0]&1) return false;
        int l =1,r = k-1;
        while(l<r) {
            //cout<<mpp[l]<<" "<<mpp[r]<<" "<<l<<" "<<r<<endl;
            if(mpp[l] != mpp[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};