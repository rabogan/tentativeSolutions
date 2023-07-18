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
private:
    unordered_map<int, Employee*> id_to_emp;   //Allows us to map from an id to the corresponding employee...
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto& emp : employees)
            id_to_emp[emp->id] = emp;  //We take in an id, and our vector.
//We use the map to 'map' id to the corresponding employee.
        return dfs(id);    //We then 'employ' DFS on the ID.
    }
    // return sum of all the nodes under this node
    // Why no boolean 'visited' array? No need for a visited array in DAG, as there are no cycles :)
    int dfs(int id) {
        Employee* emp = id_to_emp[id];   //We grab the 'Employee' from the ID

        int result = emp->importance;   //We get the importance value of that employee.
        for (auto& subEmp : emp->subordinates)   //We iterate through all(or any) subordinates, plopping their ID (subordinates is a vector<int>) into the DFS.
            //We sum all importances of each subordinate under 'this employee', i.e. the employee id given in getImportance
            result += dfs(subEmp);

        return result;
    }
};