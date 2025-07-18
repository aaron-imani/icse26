def main():
    t = 1
    for _ in range(t):
        parts = input().split()
        n = int(parts[0])
        m = int(parts[1])
        if n == 0:
            print(0)
            continue
        if n == m:
            print(0)
            continue
        if n > m:
            rem = n % m
            print(min(rem, m - rem))
        else:
            print(min(m - n, n))
# End of Code
