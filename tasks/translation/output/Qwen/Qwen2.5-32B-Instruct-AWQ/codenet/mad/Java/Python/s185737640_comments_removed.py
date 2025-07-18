def is_even_string(s):
    return s[:len(s)//2] == s[len(s)//2:]

s = input().strip()

if len(s) % 2 == 1:
    s = s[:-1]
else:
    s = s[:-2]

while len(s) > 0:
    if is_even_string(s):
        break
    s = s[:-2]

print(len(s))  # End of Code
