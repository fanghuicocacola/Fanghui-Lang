from tkinter import *

root = Tk()
root.title('选择题')
group = LabelFrame(root,text='最好的             语言                    是：', padx=5, pady=5)
group.pack(padx=10, pady=10)
v = IntVar()

LA = [('Python', 1), ('PHP', 2), ('C', 3), ('JAVA', 4)]
for lang,num in LA:
    b = Radiobutton(group, text=lang, variable=v, value=num)
    b.pack(anchor=W)

mainloop()

