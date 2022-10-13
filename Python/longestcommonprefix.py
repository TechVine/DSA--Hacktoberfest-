class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        str1=strs
        if len(str1) == 0:
            return ""
        chars=str1[0]
        for i in range(1,len(str1)):
            a=""
            if len(chars)==0:
                break
            for j in range(len(str1[i])):
                if j<len(chars) and chars[j] == str1[i][j]:
                    a+=chars[j]
                else:
                    break
            chars=a
        return chars
"""Code provided by Akshaj Vishwanathan"""
