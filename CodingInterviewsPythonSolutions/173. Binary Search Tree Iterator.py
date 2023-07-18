class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.stk = []
        self.addLeftChain(root)

    def addLeftChain(self, root):
        while root:
            self.stk.append(root)
            root = root.left

    def next(self) -> int:
        t = self.stk.pop()
        if t.right:
            self.addLeftChain(t.right)
        return t.val

    def hasNext(self) -> bool:
        return len(self.stk) > 0
