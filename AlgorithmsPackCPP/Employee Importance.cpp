class Solution {
private:
    unordered_map<int, Employee*> id_to_emp; 
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto& emp : employees)
            id_to_emp[emp->id] = emp; 
        return dfs(id); 
    }

    int dfs(int id) {
        Employee* emp = id_to_emp[id]; 

        int result = emp->importance; 
        for (auto& subEmp : emp->subordinates) 
            result += dfs(subEmp);

        return result;
    }
};

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
