from typing import List


def solve() -> None:
    n = int(input())
    k = int(input())

    a = [int(input()) for _ in range(n)]

    cumsum = [0] * (n + 1)
    for i in range(n):
        cumsum[i + 1] = cumsum[i] + a[i]

    b = [cumsum[j + 1] - cumsum[i] for i in range(n) for j in range(i, n)]
    max_val = max(b)

    mask = 1 << (max_val.bit_length() - 1)
    while mask > 0:
        tmp = [e for e in b if e & mask != 0]
        if len(tmp) >= k:
            b = tmp
        mask >>= 1

    if len(b) < k:
        print(0)
    else:
        ans = -1
        for e in b:
            ans &= e
        print(ans)


def main() -> None:
    solve()


if __name__ == "__main__":
    main()
# End of Code
