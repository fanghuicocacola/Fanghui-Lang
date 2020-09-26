class Dog:
    def __init__(self, name):
        self.name = name
        self.show()

    def show(self):
        self.type = '哺乳动物'
        self.run()
        print(self.name + 'is' + self.type + '用' + self.runmethod + 'run')

    def run(self):
        self.runmethod = '四肢'


if __name__ == '__main__':
    Dog('狗')