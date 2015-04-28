n,k = map(int,raw_input().split())
a = map(int,raw_input().split())
k -= 1
if a[k] == 0 :
    while k > 0 and  a[k] == 0 :
        k -= 1
    if a[k] > 0:
        print k + 1
    else :
        print 0
else:
    temp = a[k]
    while k < n  and a[k] == temp:
        k += 1
    print k
