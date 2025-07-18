import sys

def nint():
    return int(input())

def nlong():
    return int(input())

def nstr():
    return input()

def nsToChars():
    return list(input())

def nlongs(n, padL=0, padR=0):
    return [nlong() for _ in range(padL + n + padR)][padL:padL+n]

def nints(n, padL= 0, padR=0):
    return [nint() for _ in range(padL + n + padR)][padL:padL+n]

def nstrs(n):
    return [nstr() for _ in range(n)]

def nsToChars2D(h, w, pad=0):
    return [nsToChars() for _ in range(h)]

N = nint()
W = nint()

v = [0] * (N + 1)
w = [0] * (N + 1)

for i in range(1, N + 1):
    v[i] = nint()
    w[i] = nint()

sumV = [[0 for _ in range(W + 1)] for _ in range(N + 1)]

for i in range(1, N + 1):
    for i_sum in range(w[i]):
        sumV[i][i_sum] = sumV[i-1][i_sum]
    
    for i_sum in range(w[i], W + 1):
        sumV[i][i_sum] = max(sumV[i-1][i_sum], sumV[i-1][i_sum - w[i]] + v[i])

print(sumV[N][W])  # End of Code
