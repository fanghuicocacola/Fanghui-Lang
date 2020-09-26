s = "Hello World"
it = iter(s)
while True:
    try:
        each = next(it)
    except StopIteration:
        break
    print(each,end=" ")

print(""
      "")
for each in s:
    print(each, end=" ")


class Fibs:
    def __init__(self):
        self.a = 0
        self.b = 1

    def __iter__(self):
        return self

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b
        return self.a


f = Fibs()
for cc in f:
    if cc < 20:
        print(cc)
    else:
        break
