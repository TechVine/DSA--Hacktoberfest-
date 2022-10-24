# maximum-number-of-words-found-in-sentences

class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:

        count1=[]
        for i in range(0,len(sentences)):
            a=sentences[i].split()         
            b=len(a)
            count1.append(b)
            # count1.pop(0)
            i=i+1
            c=max(count1)
        # print(count1)
        # print(max(count1))
        
        return c
