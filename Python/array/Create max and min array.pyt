def findSum(self,arr,arr_size): 
        max = 0
        min = 0
        i = 0
        if arr_size % 2 == 1:
            max = arr[0]
            min = arr[0]
            i = 1
        else:
            if arr[0] < arr[1]:
                max = arr[1]
                min = arr[0]
            else:
                max = arr[0]
                min = arr[1]
            i = 2
        while i < arr_size:
            if arr[i] < arr[i + 1]:
                if arr[i] < min:
                    min =arr[i]
                if arr[i + 1] > max:
                    max = arr[i + 1]
            else:
                if arr[i] > max:
                    max = arr[i]
                if arr[i + 1] < min:
                    min = arr[i + 1]
            i = i + 2
        return max + min
