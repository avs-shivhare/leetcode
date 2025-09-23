class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> a,b;
        stringstream s(version1);
        stringstream s1(version2);
        string temp = "";
        while(getline(s,temp,'.')) {
            a.push_back(stoi(temp));
        }
        while(getline(s1,temp,'.')) {
            b.push_back(stoi(temp));
        }
        int i = 0, j = 0;
        while(i<a.size() && j < b.size()) {
            if(a[i] > b[j]) return 1;
            else if(a[i] < b[j]) return -1;
            i++;
            j++;
        }
        while(i<a.size()) {
            if(a[i] != 0) return 1;
            i++;
        }
        while(j<b.size()) {
            if(b[j] != 0) return -1;
            j++;
        }
        return 0;
    }
};