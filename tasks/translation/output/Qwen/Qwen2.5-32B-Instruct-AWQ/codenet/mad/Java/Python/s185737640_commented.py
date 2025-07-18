def is_even_string(s):
    return s[:len(s)//2] == s[len(s)//2:]

s = input().strip()

# Ensure the length of s is even
if len(s) % 2 == 1:
    s = s[:-1]

# Further ensure the length of s is at least 2
if len(s) > 1:
    s = s[:-2]

while len(s) > 0:
    if is_even_string(s):
        break
    s = s[:-2]

print(len(s))  # End of Code
