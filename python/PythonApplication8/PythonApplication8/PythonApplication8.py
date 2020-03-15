a="wula"
print(len(a))
print(max(1,2,3,2342,123,4324,35432,1232,1221,13))
numbers=[1,2,3,4,5,6,7,8,9,'0']
numbers.pop()
b=sum(numbers)
print(b);
def add(num1,num2):
    return(num1+num2)
print(add(1,2))
def test(*x):
    print("参数长度是：",len(x))
    print("第二个参数是：",x[2])
a=(1,3,4,'gula',33)
test(*a)