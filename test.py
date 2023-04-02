def convert_to(x, syst=5):
    a = ""
    while x > 0:
        a += str(x % syst)
        x //= syst
    a = a[::-1]
    return int(a)


def calc(x, y, syst=5):
    x = str(x)
    y = str(y)
    if len(x) < len(y):
        x, y = y, x
    last = 0
    ans = ""
    for i in range(len(x)):
        if i < len(y):
            d = last + int(x[- i - 1]) + int(y[- i - 1])
            ans += str(d % syst)
            last = d // syst
        else:
            d = last + int(x[len(x) - i - 1])
            ans += str(d % syst)
            last = d // syst
    if last != 0:
        ans += str(last)
    ans = ans[::-1]
    return int(ans)


def mult(x, y, syst=5):
    ls = list()
    x = str(x)
    for i in range(len(x)):
        ls.append(convert_to(int(x[-i - 1]) * y * (10 ** i)))
    ans = 0
    for elm in ls:
        ans = calc(ans, elm)
    return ans


print(convert_to(14))
print(convert_to(17))
print(convert_to(14 * 17))
print(calc(1030, 343))
print(mult(14, 17))


# написать алгебру для разных систем счисления
# +, -, *, /
