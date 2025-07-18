def main():
    s = input().strip()
    n = len(s)
    ans = 0
    cnt = 0
    for c in s:
        if c == 'S':
            cnt += 1
        else:
            if cnt == 0:
                continue
            ans += 1
            cnt -= 1
    print(n - 2 * ans)

if __name__ == "__main__":
    main() # End of Code
