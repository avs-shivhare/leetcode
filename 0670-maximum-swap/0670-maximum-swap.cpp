class Solution {
public:
    int maximumSwap(int num) {
        string temp = to_string(num);
        int n = temp.size();
        priority_queue<int> q;
        q.push(num);
        for(int i =0; i<n; i++) {
            for(int j =i+1; j<n; j++) {
                swap(temp[i],temp[j]);
                q.push(stoi(temp));
                swap(temp[i],temp[j]);
            }
        }
        return q.top();
    }
};