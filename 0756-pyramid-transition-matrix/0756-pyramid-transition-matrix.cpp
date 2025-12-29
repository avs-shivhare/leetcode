class Solution {
public:
    unordered_map<string,vector<char>> mpp;
    bool find(int len,string &b,int i,string &temp) {
        if(len == 1) return true;
        if(i == len-1) {
            string t = "";
            if(find(len-1,temp,0,t)) return true;
            return false;
        }
        string s = b.substr(i,2);
        for(auto &j: mpp[s]) {
            temp.push_back(j);
            if(find(len,b,i+1,temp)) return true;
            temp.pop_back();
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        string temp = "";
        for(auto i: allowed) {
            mpp[i.substr(0,2)].push_back(i[2]);
        }
        return find(bottom.size(),bottom,0,temp);
    }
};