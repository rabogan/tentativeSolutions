# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        id_to_emp = {}  # Allows us to map from an id to the corresponding employee
        for emp in employees:
            id_to_emp[emp.id] = emp  # Map id to the corresponding employee
        
        return self.dfs(id, id_to_emp)

    def dfs(self, id: int, id_to_emp: Dict[int, Employee]) -> int:
        emp = id_to_emp[id]  # Get the employee from the ID

        result = emp.importance  # Get the importance value of that employee
        for subEmp in emp.subordinates:  # Iterate through all subordinates
            result += self.dfs(subEmp, id_to_emp)  # Sum the importances of each subordinate

        return result
