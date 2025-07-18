import sys

def next():
    return input().strip()

def next_int():
    return int(next())

def next_long():
    return float(next())

def next_double():
    return float(next())

def next_str_array():
    return next().split()

def next_char_array():
    return list(next())

def next_int_array():
    return list(map(int, next().split()))

def next_long_array():
    return list(map(float, next().split()))

def solve():
    N = next_int()
    lst = next_int_array()
    max_val = 0
    output = 0
    for i in range(N):
        if max_val <= lst[i]:
            max_val = lst[i]
            output += 1
    print(output)

if __name__ == "__main__":
    solve()
# End of Code
