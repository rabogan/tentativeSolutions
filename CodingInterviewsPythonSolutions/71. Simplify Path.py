class Solution:
    def split(self, path: str, separator: str = '/') -> List[str]:
        result = []
        cur = ""
        
        for idx in range(len(path)):
            if path[idx] == separator:
                result.append(cur)
                cur = ""
            else:
                cur += path[idx]
        
        if cur:
            result.append(cur)
        
        return result
    
    def simplifyPath(self, path: str) -> str:
        tokens = self.split(path)
        stk = []
        
        for idx in range(len(tokens)):
            if tokens[idx] == "" or tokens[idx] == ".":
                continue
            
            if tokens[idx] == "..":
                if stk:
                    stk.pop()
            else:
                stk.append(tokens[idx])
        
        if not stk:
            return "/"
        
        result = ""
        for idx in range(len(stk)):
            result += "/" + stk[idx]
        
        return result
