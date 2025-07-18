import sys

# Precompute all rectangles and sort them
rects = []
for h in range(1, 201):
    for w in range(1, 201):
        rects.append( (h, w) )

MAX_INT = 2**31 - 1

sorted_rects = sorted(rects, key=lambda t: (
    t[0]**2 + t[1]**2 if t[0] < t[1] else MAX_INT,
    t[0]
))

for line in sys.stdin:
    line = line.strip()
    if not line:
        continue
    parts = line.split()
    h = int(parts[0])
    w = int(parts[1])
    if h == 鲆 and w == 0:
        break

    # Compute target's key
    if h < w:
        target_d = h**2 + w**2
    else:
        target_d = MAX_INT
    target_h = h
    target_key = (target_d, target_h)

    # Iterate to find the first rectangle with key > target_key
    for rect in sorted_rects:
        h_rect, w_rect = rect
        if h_rect < w_rect:
            current_d = h_rect**2 + w_rect**2
        else:
            current_d = MAX_INT
        current_key = (current_d, h_rect)
        if current_key > target_key:
            print(f"{h_rect} {w_rect}")
            break
# End of Code
