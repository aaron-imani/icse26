import sys

def main():
    n = int(sys.stdin.readline())
    s = sys.stdin.readline().strip()
    flaged = [False] * n
    pop1st = 0
    for i in range(n):
        if s[i] == '1':
            flaged[i] = True
            pop1st += 1

    surp1 = 0
    mod_s1 = pop1st + 1
    for i in range(n):
        surp1 *= 2
        if flaged[i]:
            surp1 += 1
        surp1 %= mod_s1

    surp9 = 0
    mod_s9 = None
    if pop1st > 1:
        mod_s9 = pop1st - 1
        surp9 = 0
        for i in range(n):
            surp9 *= 2
            if flaged[i]:
                surp9 += 1
            surp9 %= mod_s9
    else:
        mod_s9 = 0  # dummy value

    for p in range(n):
        if flaged[p]:
            if pop1st == 1:
                print(0)
                continue
            else:
                mod_val = pop1st - 1
                exponent = n - p - 1
                dif = pow(2, exponent, mod_val)
                dw = (surp9 - dif) % mod_val
                ans = 1
                while dw != 把自己想象成一个Java程序员，现在需要将一段Java代码转换为Python。首先，我需要仔细阅读Java代码，理解其结构和逻辑。

首先，注意到Java代码中的类和静态方法，但主函数main()似乎没有使用这些类，可能它们是其他功能的辅助类。因此，在Python中，可以忽略这些类，只关注main()中的逻辑。

接下来，分析Java主函数的步骤：
1. 读取输入：整数n和字符串s。
2. 初始化一个布尔数组flaged，标记每个字符是否为'1'，并计算pop1st（'1'的数量）。
3. 计算surp1：通过遍历字符串，每次将当前值乘以2，加上当前位是否为'1'，然后模pop1st+1。
4. 如果pop1st >1，计算surp9：类似surp1的计算，模pop1st-1。
5. 对于每个位置p：
   - 如果当前字符是'1'：
     - 如果pop1st为1，直接输出0。
     - 否则，计算dif（2的（n-p-1）次方模pop1st-1），调整dw后计算答案。
   - 如果当前字符是'0'：
     - 计算dif（2的（n-p-1）次方模pop1st+1），调整dw后计算答案。
6. 答案计算部分通过不断模当前1的数量，直到dw为0，记录步数。

转换为Python时需要注意以下几点：
- **布尔数组**：用列表代替，初始化为False，然后根据字符设置为True。
- **模运算**：在Python中直接使用%运算符。
- **位计数**：用bin().count('1')替代Java的countFlaged方法。
- **快速幂运算**：Python的pow函数支持三参数（base, exp, mod），直接使用。

可能遇到的问题：
- **变量作用域**：确保在Python中变量正确声明和使用。
- **循环结构**：Python的循环语法与Java不同，但结构类似。
- **类型转换**：Java的long在Python中是int，无需特别处理。

最终代码结构：
- 读取输入。
- 计算flaged和pop1st。
- 计算surp1和surp9。
- 遍历每个位置，根据情况计算答案。

转换后的Python代码如下：

import sys

def main():
    n = int(sys.stdin.readline())
    s = sys.stdin.readline().strip()
    flaged = [False] * n
    pop1st = 0
    for i in range(n):
        if s[i] == '1':
            flaged[i] = True
            pop1st += 1

    surp1 = 0
    mod_s1 = pop1st + 1
    for i in range(n):
        surp1 *= 2
        if flaged[i]:
            surp1 += 1
        surp1 %= mod_s1

    surp9 = 0
    mod_s9 = None
    if pop1st > 1:
        mod_s9 = pop1st - 1
        surp9 = 0
        for i in range(n):
            surp9 *= 2
            if flaged[i]:
                surp9 += 1
            surp9 %= mod_s9
    else:
        mod_s9 = 0  # dummy value

    for p in range(n):
        if flaged[p]:
            if pop1st == 1:
                print(0)
                continue
            else:
                mod_val = pop1st - 1
                exponent = n - p - 1
                dif = pow(2, exponent, mod_val)
                dw = (surp9 - dif) % mod_val
                ans = 1
                while dw != 0:
                    cnt = bin(dw).count('1')
                    dw %= cnt
                    ans += 1
                print(ans)
        else:
            mod_val = pop1st + 1
            exponent = n - p - 1
            dif = pow(2, exponent, mod_val)
            dw = (surp1 + dif) % mod_val
            ans = 1
            while dw != 0:
                cnt = bin(dw).count('1')
                dw %= cnt
                ans += 1
            print(ans)

if __name__ == '__main__':
    main()
# End of Code
