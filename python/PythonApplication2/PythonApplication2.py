x=3
y=5
temp=x
x=y
y=temp
print(x,y)
阿里巴巴=1
恒大=2
阿里巴巴,恒大=恒大,阿里巴巴
print(阿里巴巴,恒大)
print("let\'s study python")
print("哈利路亚"*10)
print("alpha"+"go")
print(r"1321\243\123")
poem="""
君不见黄河之水天上来奔流到海不复回
君不见高堂明镜悲白发朝如青丝暮成雪
人生得意须尽欢莫使金樽空对月
天生我材必有用千金散尽还复来
烹羊宰牛且为乐会须一饮三百杯
岑夫子丹丘生将进酒杯莫停
"""
print(poem)
counts=3
while counts>0:
    x=input("请输入一个数字:")
    guess=int(x)
    print(x)
    if guess == 7:
        print("猜对啦")
    else:
        print("猜错啦")
        counts=counts-1
print("游戏结束")
