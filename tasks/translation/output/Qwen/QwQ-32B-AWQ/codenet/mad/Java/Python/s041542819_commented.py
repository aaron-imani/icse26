class LightScanner:
    def __init__(self):
        self.tokens = []
        self.position = 0

    def next_token(self):
        if self.position == len(self.tokens):
            self.tokens = input().split()
            self.position = 0
        token = self.tokens[self.position]
        self.position += 1
        return token

    def next_int(self):
        return int(self.next_token())

    def next_long(self):
        return int(self.next_token())

def lower_bound(arr, target, min_idx=0):
    max_idx = len(arr)
    while min_idx < max_idx:
        mid = (min_idx + max_idx) // 2
        if target <= arr[mid]:
            max_idx = mid
        else:
            min_idx = mid + 1
    return min_idx

def main():
    scanner = LightScanner()
    a = scanner.next_int()
    b = scanner.next_int()
    q = scanner.next_int()

    s = [0] * (a + 2)
    s[0] = -10**10
    for i in range(a):
        s[i + 1] = scanner.next_long()
    s[a + 1] = 20000000000

    t = [0] * (b + 2)
    t[0] = -10**10
    for i in range(b):
        t[i + 1] = scanner.next_long()
    t[b + 1] = 20000000000

    for _ in range(q):
        x = scanner.next_long()
        idx_s = lower_bound(s, x + 1)
        prev_s_idx = max(0, idx_s - 1)
        sl = x - s[prev_s_idx]

        idx_t = lower_bound(t, x + 1)
        prev_t_idx = max(0, idx_t - 1)
        tl = x - t[prev_t_idx]

        next_s_idx = lower_bound(s, x)
        sr = s[next_s_idx] - x

        next_t_idx = lower_bound(t, x)
        tr = t[next_t_idx] - x

        case1 = max(sl, tl)
        case2 = max(sr, tr)
        case3 = 2 * sl + tr
        case4 = 2 * tl + sr
        case5 = sl + 2 * tr
        case6 = tl + 2 * sr

        ans = min(case1, case2, case3, case4, case5, case6)
        print(ans)

if __name__ == "__main__":
    main()
# End of Code
