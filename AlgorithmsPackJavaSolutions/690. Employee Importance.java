class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> idToEmp = new HashMap<>();  // Allows us to map from an id to the corresponding employee
        for (Employee emp : employees) {
            idToEmp.put(emp.id, emp);  // Map id to the corresponding employee
        }
        
        return dfs(id, idToEmp);
    }

    private int dfs(int id, Map<Integer, Employee> idToEmp) {
        Employee emp = idToEmp.get(id);  // Get the employee from the ID

        int result = emp.importance;  // Get the importance value of that employee
        for (int subEmp : emp.subordinates) {  // Iterate through all subordinates
            result += dfs(subEmp, idToEmp);  // Sum the importances of each subordinate
        }

        return result;
    }
}