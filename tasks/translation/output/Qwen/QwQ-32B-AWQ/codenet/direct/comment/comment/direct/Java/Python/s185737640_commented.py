def is_even_string(s):
    half = len(s) // 2
    return s[:half] == s[half:]

s = input().strip()

if len(s) % 2 == 1:
    s = s[:-1]
else:
    s = s[:-2]

current_s = s

while len(current_s) > 0:
    if is_even_string(current_s):
        break
    else:
        current_s = current_s[:-2]

print(len(current_s))
# End of Code
