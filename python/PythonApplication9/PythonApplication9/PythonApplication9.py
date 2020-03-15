def outer(a):
    x=5
    def inner(b):
        nonlocal x
        print(x)
        print(a+b)
    return inner
print(outer(5)(6))
g=lambda x,y:x+y
print(g(3,5))



