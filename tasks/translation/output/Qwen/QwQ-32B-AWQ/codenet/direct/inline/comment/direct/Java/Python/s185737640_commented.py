def is_even_string(s):
    half = len(s) // 2
    return s[:half] == s[half:]

s = input().strip()

if len(s) % 2 == 1:
    s = s[:-1]
else:
    s = s[:-2]

while s:
    if is_even_string(s):
        break
    s = s[:-2]

print(len(s))  # End of Code
