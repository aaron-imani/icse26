import math

#update 2019/12/13

def next():
    return input()

def next_int():
    return int(input())

def next_long():
    return int(input())

def next_double():
    return float(input())

def split_string(s):
    return s.split("")

def split_char(s):
    return list(s)

def char_to_int(aaa):
    return ord(aaa) - 48

def max_int(a, lng):
    max_val = a[0]
    for i in range(1, lng):
        max_val = max(max_val, a[i])
    return max_val

def min_int(a, lng):
    min_val = a[0]
    for i in range(1, lng):
        min_val = min(min_val, a[i])
    return min_val

def max_long(a, lng):
    max_val = a[0]
    for i in range(1, lng):
        max_val = max(max_val, a[i])
    return max_val

def min_long(a, lng):
    min_val = a[0]
    for i in range(1, lng):
        min_val = min(min_val, a[i])
    return min_val

def main():
    n = next_long()
    a = next_long()
    b = next_long()

    sa = abs(a - b)

    ans = 0

    if sa % 2 == 0:
        ans = sa // 2
    else:
        AAA = min((n - a), (a - 1))
        BBB = min((n - b), (b - 1))

        ans = min(AAA, BBB)  # 片方が端っこに来るまで。

        # 差を1減らす⇒差が偶数になる
        sa -= 1
        ans += 1

        # 差は偶数
        ans += sa // 2

    print(ans)

if __name__ == "__main__":
    main()  # End of Code
