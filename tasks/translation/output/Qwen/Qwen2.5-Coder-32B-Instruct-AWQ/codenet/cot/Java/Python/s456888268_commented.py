def solve():
    tmp = ns()
    s = list(tmp)
    n = len(s)
    ans = 0
    cnt = 0
    for i in range(n):
        if s[i] == 'S':
            cnt += 1
        else:
            if cnt == 0:
                continue
            ans += 1
            cnt -= 1
    print(n - 2 * ans)

# Input methods
def ns():
    return input().strip()

# Main execution
if __name__ == "__main__":
    solve()
# End of Code
