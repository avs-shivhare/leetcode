class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mpp,mpp2;
        int n = A.size();
        vector<int> ans(n,0);
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            mpp[A[i]]++;
            mpp2[B[i]]++;
            if(mpp[A[i]] > 0 && mpp2[A[i]] > 0) {
                cnt++;
                mpp[A[i]]--;
                mpp2[A[i]]--;
            }
            if(mpp[B[i]] > 0 && mpp2[B[i]] > 0) {
                cnt++;
                mpp[B[i]]--;
                mpp2[B[i]]--;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};