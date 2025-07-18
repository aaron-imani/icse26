def solve():
    s = input().strip()
    n = len(s)
    cnt = 0
    ans = 0
    for c in s:
        if c == 'S':
            cnt += 1
        else:
            if cnt > 0:
                cnt -= 1
                ans += 1
    print(n - 2 * ans)

solve()  # End of Code
