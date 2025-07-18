import sys

for line in sys.stdin:
    d = int(line.strip())
    ans = 0
    i = 1
    while i * d < 600:
        x = i * d
        y = x * x
        ans += y * d
        i += 1
    print(ans)
# End of Code
