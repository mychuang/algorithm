# Function to return the only odd
# occurring element

def findOdd(arr, length):
    res = 0

    for i in range(len(arr)):
        res = res ^ arr[i]
    return res

arr = [12, 12 ,14, 90, 14, 14, 14]
length = len(arr)
print("The odd occurring element is ", findOdd(arr, length))
