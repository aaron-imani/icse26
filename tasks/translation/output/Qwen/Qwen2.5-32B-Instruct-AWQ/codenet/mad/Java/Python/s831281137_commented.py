import sys

sc = sys.stdin
so = sys.stdout

def main():
    N = nint()
    W = nint()

    # 品物i
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
            sumV[i][i_sum] = max(sumV[i-1][i_sum], sumV[i-1][i_sum - w[i]] + v[i])

    so.write(f'{sumV[N][W]}\n')


def nlong():
    return int(sc.readline())

def nint():
    return int(sc.readline())

def nstr():
    return sc.readline().strip()

def nsToChars():
    return list(sc.readline().strip())

def nlongs(n):
    return nlongs(n, 0, 0)

def nints(n):
    return nints(n, 0, 0)

def nints(n, padL, padR):
    a = [0] * (padL + n + padR)
    for i in range(n):
        a[padL + i] = nint()
    return a

def nlongs(n, padL, padR):
    a = [0] * (padL + n + padR)
    for i in range(n):
        a[padL + i] = nlong()
    return a

def nstrs(n):
    a = [None] * n
    for i in range(n):
        a[i] = nstr()
    return a

def nsToChars2D(h, w):
    return nsToChars2D(h, w, 0)

def nsToChars2D(h, w, pad):
    a2 = [[' '] * (w + pad * 2) for _ in range(h + pad * 2)]
    for i in range(h):
        a2[pad + i][pad:pad + w] = nsToChars()
    return a2

if __name__ == '__main__':
    main()  # End of Code
