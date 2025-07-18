def ni():
    return int(input())

def nl():
    return int(input())

def nf():
    return float(input())

def nd():
    return float(input())

def ns():
    return input().strip()

def nst(s):
    return s.split()

def ia(n):
    return [int(input()) for _ in range(n)]

def la(n):
    return [int(input()) for _ in range(n)]

def fa(n):
    return [float(input()) for _ in range(n)]

def da(n):
    return [float(input()) for _ in range(n)]

def sa(arr, empty):
    if empty:
        for i in range(len(arr)):
            arr[i] = ""
    else:
        for i in range(len(arr)):
            arr[i] = ns()
    return arr

def ida(n, m):
    arr = []
    for _ in range(n):
        row = list(map(int, input().split()))
        arr.append(row)
    return arr

def lda(n, m):
    arr = []
    for _ in range(n):
        row = list(map(int, input().split()))
        arr.append(row)
    return arr

def dda(n, m):
    arr = []
    for _ in range(n):
        row = list(map(float, input().split()))
        arr.append(row)
    return arr

def imin(arr):
    return min(arr)

def lmin(arr):
    return min(arr)

def imax(arr):
    return max(arr)

def lmax(arr):
    return max(arr)

def ibs(arr, toFind):
    arr.sort()
    left = 0
    right = len(arr) - 1
    found = False
    while left <= right and not found:
        mid = (left + right) // 2
        if arr[mid] == toFind:
            found = True
        elif toFind > arr[mid]:
            left = mid + 1
        else:
            right = mid - 1
    return found

def lbs(arr, toFind):
    arr.sort()
    left = 0
    right = len(arr) - 1
    found = False
    while left <= right and not found:
        mid = (left + right) // 2
        if arr[mid] == toFind:
            found = True
        elif toFind > arr[mid]:
            left = mid + 1
        else:
            right = mid - 1
    return found

def stb(s):
    s = s[::-1]
    total = 0
    for i in range(len(s)):
        bit = int(s[i])
        total += bit * (2 ** i)
    return total

def stoi(s):
    return int(s)

def stod(s):
    return float(s)

def solve():
    a = ni()
    b = ni()
    print(max(0, a - 2 * b))

solve()  # End of Code
