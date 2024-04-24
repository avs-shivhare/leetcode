/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(vector<Employee*> &e,Employee* emp,int &ans,unordered_set<int> &st) {
        //if(emp == NULL) return;
        st.insert(emp->id);
        ans += emp->importance;
        for(int i =0; i<emp->subordinates.size(); i++) {
            int id = emp->subordinates[i];
            if(st.find(id) == st.end()) {
                for(int k =0; k<e.size(); k++) {
                    if(e[k]->id == id) {
                        dfs(e,e[k],ans,st);
                    }
                }
            }
        }
    }
    int getImportance(vector<Employee*> emp, int id) {
        unordered_set<int> mpp;
        int ans = 0;
        int n = emp.size();
        for(int i =0; i<n; i++) {
            if(emp[i]->id == id) {
                dfs(emp,emp[i],ans,mpp);
            }
        }
        return ans;
    }
};