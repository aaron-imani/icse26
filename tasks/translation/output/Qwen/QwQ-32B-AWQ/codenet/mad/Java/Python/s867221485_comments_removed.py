s = input().strip()
total = 0
current_dots = 0
current_shas = 0
prev_char = '.'
for c in s:
    if c == '.':
        if prev_char == '#':
            if current_shas <= current_dots:
                total += current_shas
            current_dots = 0
            current_shas = 0
        current_dots += 1
        prev_char = '.'
    else:
        if prev_char == '.':
            current_shas = 1
        else:
            current_shas += 1
        prev_char = '#'
if current_shas <= current_dots:
    total += current_shas
print(total)  # End of Code
