import sys

def main():
    input = sys.stdin.read().split()
    n = int(input[0])
    a = int(input[1])
    b = int(input[2])

    sa = abs(a - b)

    ans = 0

    if sa % 2 == 0:
        ans = sa // 2
    else:
        AAA = min((n - a), (a - 1))
        BBB = min((n - b), (b - 1))

        ans = min(AAA, BBB)  # 片方が端っこに来るまで。

        # 差を1減らす⇒差が偶数になる
        sa -= 1
        ans += 1

        # 差は偶数
        ans += sa // 2

    print(ans)

if __name__ == "__main__":
    main()

# End of Code
