# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        id_to_emp = {} 
        for emp in employees:
            id_to_emp[emp.id] = emp
        
        return self.dfs(id, id_to_emp)

    def dfs(self, id: int, id_to_emp: Dict[int, Employee]) -> int:
        emp = id_to_emp[id]

        result = emp.importance 
        for subEmp in emp.subordinates:
            result += self.dfs(subEmp, id_to_emp)

        return result
