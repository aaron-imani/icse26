The user's Python code is correct as provided. It precisely mirrors the Java code's logic and calculations, handling both even and odd cases correctly with proper integer division and variable adjustments. No changes are needed.


n, a, b = map(int, input().split())
sa = abs(a - b)
ans = 0
if sa % 2 == 0:
    ans = sa // 2
else:
    AAA = min(n - a, a - 1)
    BBB = min(n - b, b - 1)
    ans = min(AAA, BBB)
    sa -= 1
    ans += 1
    ans += sa // 2
print(ans)  # End of Code
