class Solution {
public:
    string ans = "";
    unordered_set<int> mpp;
    bool find(int i,string &pat) {
        if(i == pat.size()+1) {
            return true;
        }
        for(int j = 1; j<=9; j++) {
            if(i == 0) {
                mpp.insert(j);
                ans.push_back(j+'0');
                if(find(i+1,pat)) return true;
                ans.pop_back();
                mpp.erase(j);
            }
            else if(pat[i-1] == 'I' && (ans.back()-'0') < j && mpp.count(j) == 0) {
                mpp.insert(j);
                ans.push_back(j+'0');
                if(find(i+1,pat)) return true;
                ans.pop_back();
                mpp.erase(j);
            }
            else if(pat[i-1] == 'D' && (ans.back()-'0') > j && mpp.count(j) == 0) {
                mpp.insert(j);
                ans.push_back(j+'0');
                if(find(i+1,pat)) return true;
                ans.pop_back();
                mpp.erase(j);
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        //int n = pattern.size();
        find(0,pattern);
        return ans;
    }
};