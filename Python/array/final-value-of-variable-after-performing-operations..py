# final-value-of-variable-after-performing-operations

class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
    
        # A=B=C=D=0
        A=operations.count("++X")
        B=operations.count("X++")
        C=operations.count("--X") 
        D=operations.count("X--")

        return A+B-C-D

