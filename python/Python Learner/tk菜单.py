from tkinter import *
root = Tk()
menu = Menu(root)
fmenu = Menu(menu)
for item in ['新建', '保存', '另存为', '关闭']:
    fmenu.add_command(label=item)
emenu = Menu(menu)
for item in ['复制', '粘贴', '全选', '清除']:
    emenu.add_cascade(label=item)
vmenu = Menu(menu)
for item in ['大纲','侧栏', '工具栏', '功能区']:
    vmenu.add_cascade(label=item)
gmenu = Menu(menu)
for item in ['字体','段落', '项目符号', '表格']:
    gmenu.add_command(label=item)


def pop(event):
    menu.post(event.x_root, event.y_root)


root.bind('<Button-3>', pop)
menu.add_cascade(label='文件', menu=fmenu)
menu.add_cascade(label='编辑', menu=emenu)
menu.add_cascade(label='视图', menu=vmenu)
menu.add_cascade(label='格式', menu=gmenu)

root['menu'] = menu
root.mainloop()