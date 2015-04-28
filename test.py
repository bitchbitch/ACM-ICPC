def p(x):
    return x*x
fibs = [0,1]
for i in range(100):
    fibs.append(fibs[-2] + fibs[-1] + p(i))
print fibs
