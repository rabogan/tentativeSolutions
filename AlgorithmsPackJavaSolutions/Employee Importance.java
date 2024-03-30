class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> idToEmp = new HashMap<>();  
        for (Employee emp : employees) {
            idToEmp.put(emp.id, emp);
        }
        
        return dfs(id, idToEmp);
    }

    private int dfs(int id, Map<Integer, Employee> idToEmp) {
        Employee emp = idToEmp.get(id); 

        int result = emp.importance; 
        for (int subEmp : emp.subordinates) { 
            result += dfs(subEmp, idToEmp);
        }

        return result;
    }
}
