# build array from permutation

class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        result=[]
        for i in range(0,len(nums)):
            ans = nums[nums[i]]
            result.append(ans)
            i=i+1
        return result
