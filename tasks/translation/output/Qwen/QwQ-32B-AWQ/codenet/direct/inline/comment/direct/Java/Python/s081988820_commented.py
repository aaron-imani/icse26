import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    ptr = 0
    H = data[ptr]; ptr += 1
    W = data[ptr]; ptr += 1

    c = [[0]*10 for _ in range(10)]
    for i in range(10):
        for j in range(10):
            c[i][j] = data[ptr]
            ptr += 1

    min_ = [0] * 10
    for i in range(10):
        min_[i] = c[i][1]

    for tc in range(10):
        for i in range(10):
            for j in range(10):
                if min_[i] > c[i][j] + min_[j]:
                    min_[i] = c[i][j] + min_[j]

    ans = 0
    for _ in range(H):
        for _ in range(W):
            A = data[ptr]
            ptr += 1
            if A >= 0:
                ans += min_[A]

    print(ans)

if __name__ == "__main__":
    main()
# End of Code
