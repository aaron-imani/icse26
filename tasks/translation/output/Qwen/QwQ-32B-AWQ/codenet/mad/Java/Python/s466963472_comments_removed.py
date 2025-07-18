import sys

d = None
iterator = None

def get_integers():
    for line in sys.stdin:
        for number in map(int, line.split()):
            yield number

def read():
    global d, iterator
    if iterator is None:
        iterator = get_integers()
    try:
        d = next(iterator)
        return True
    except StopIteration:
        return False

def solve():
    global d
    ans = 0
    i = 1
    while i * d < 600:
        x = i * d
        y = x * x
        ans += y * d
        i += 1
    return ans


if __name__ == "__main__":
    while read():
        print(solve())
# End of Code
