class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream s(sentence);
        vector<string> arr;
        string temp = "";
        while(s>>temp) {
            arr.push_back(temp);
        }
        int n = arr.size();
        if(arr[n-1][arr[n-1].size()-1] != arr[0][0]) return false;
        for(int i =1; i<n; i++) {
            if(arr[i][0] != arr[i-1][arr[i-1].size()-1]) return false;
        }
        return true;
    }
};