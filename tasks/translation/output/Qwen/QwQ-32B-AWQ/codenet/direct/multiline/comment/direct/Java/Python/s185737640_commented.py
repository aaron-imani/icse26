def isEvenString(s):
    half = len(s) // 2
    return s[:half] == s[half:]

S = input().strip()
if len(S) % 2 == 1:
    S = S[:-1]
else:
    S = S[:-2]

while len(S) > 0:
    if isEvenString(S):
        break
    S = S[:-2]

print(len(S))
# End of Code
