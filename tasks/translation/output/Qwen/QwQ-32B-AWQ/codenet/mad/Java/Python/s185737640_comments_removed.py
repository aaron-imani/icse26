def is_even_string(s):
    half = len(s) // 2
    return s[:half] == s[half:]

S = input()  # Matches Java's nextLine() behavior

if len(S) % 2 == 1:
    S = S[:-1]
else:
    S = S[:-2]

while len(S) > 0:
    if is_even_string(S):
        break
    S = S[:-2]

print(len(S))  # End of Code
