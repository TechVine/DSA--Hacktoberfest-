def getMAX(a):
    found = False
    n = len(a)
    for i in range(1, n + 2):
        found = False
        for j in range(n):
            if a[j] == i:
                found = True
                break
        if found == False:
            return i

#Driving Code

a = [2, 3, 7, 6, 8, -1, -10, 15]

print(getMAX(a))