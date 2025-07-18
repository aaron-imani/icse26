import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    def next():
        nonlocal index
        val = data[index]
        index += 1
        return val
    
    def next_int():
        return int(next())
    
    def next_long():
        return int(next())
    
    def next_double():
        return float(next())
    
    def split_string(s):
        return list(s)
    
    def split_char(s):
        return list(s)
    
    def char_to_int(aaa):
        return ord(aaa) - 48
    
    def max_int(a):
        return max(a)
    
    def min_int(a):
        return min(a)
    
    def max_long(a):
        return max(a)
    
    def min_long(a):
        return min(a)
    
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
