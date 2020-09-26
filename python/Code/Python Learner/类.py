class Student:
    def __init__(self,name,score,bj):
        self.name = name
        self.score = score
        self.bj = bj

    def report(self):
        print(f'{self.name} {self.score} {self.bj}')


st1 = Student('张三', 450, '计算机1')
st1.report()
st2 = Student('李四', 470, '计算机2')
st2.report()