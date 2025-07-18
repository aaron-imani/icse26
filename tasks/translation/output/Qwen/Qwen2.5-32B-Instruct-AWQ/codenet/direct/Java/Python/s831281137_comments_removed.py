import sys

sc = Scanner()
so = sys.stdout

def main():
    N = nint()
    W = nint()

    v = [0] * (N + 1)
    w = [0] * (N + 1)
    
    for i in range(1, N + 1):
        v[i] = nint()
        w[i] = nint()
    
    sumV = [[0] * (W + 1) for _ in range(N + 1)]
    
    for i in range(1, N + 1):
        for i_sum in range(w[i]):
            sumV[i][i_sum] = sumV[i-1][i_sum]
        
        for i_sum in range(w[i], W + 1):
            sumV[i][i_sum] = max(sumV[i-1][i_sum], sumV[i-1][i_sum-w[i]] + v[i])
    
    so.write(str(sumV[N][W]) + '\n')

def nint():
    return int(sc.next())

def nstr():
    return sc.next()

def nlong():
    return int(sc.next())

def nints(n):
    return [nint() for _ in range(n)]

def nlongs(n):
    return [nlong() for _ in range(n)]

def nstrs(n):
    return [nstr() for _ in range(n)]

class Scanner:
    def __init__(self):
        self.tokens = []
        self.token_index = 0

    def next(self):
        if self.token_index == len(self.tokens):
            self.tokens = input().split()
            self.token_index = 0
        current_token = self.tokens[self.token_index]
        self.token_index += 1
        return current_token

if __name__ == "__main__":
    main()  # End of Code
