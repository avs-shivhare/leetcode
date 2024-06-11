class Solution {
public:
    // first approach using unordered map to store key and count of element 
    // start iterating in arr2 and store all occurance of element into arr1
    // store the remaining element in arr1
    // sort the remaining element 
    // vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    //     unordered_map<int,int> mpp;
    //     int n = arr1.size();
    //     for(int i =0; i<n; i++) mpp[arr1[i]]++;
    //     int j = 0;
    //     int i = 0;
    //     while(j<arr2.size()) {
    //         while(mpp[arr2[j]]--) {
    //             arr1[i++] = arr2[j];
    //         }
    //         mpp.erase(arr2[j]);
    //         j++;
    //     }
    //     j = i;
    //     for(auto x: mpp) {
    //         int cnt = x.second;
    //         int val = x.first;
    //         while(cnt--) {
    //             arr1[i++] = val;
    //         }
    //     }
    //     sort(arr1.begin()+j,arr1.end());
    //     return arr1;
    // }


    // using ordered map
    // this approach same as first approach but no need to sort remaining element at the end
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mpp;
        int n = arr1.size();
        for(int i =0; i<n; i++) mpp[arr1[i]]++;
        int j = 0;
        int i = 0;
        while(j<arr2.size()) {
            while(mpp[arr2[j]]--) {
                arr1[i++] = arr2[j];
            }
            mpp.erase(arr2[j]);
            j++;
        }
        for(auto x: mpp) {
            int cnt = x.second;
            int val = x.first;
            while(cnt--) {
                arr1[i++] = val;
            }
        }
        return arr1;
    }
};