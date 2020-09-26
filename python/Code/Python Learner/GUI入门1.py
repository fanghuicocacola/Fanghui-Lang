import easygui as eg
import sys
eg.msgbox('HELLO WORLD',ok_button='你好世界')
title = 'welcome'
msg = 'you have three choices'
choices = ['power', 'rich', 'love']
choice = eg.choicebox(msg,title,choices)
eg.msgbox('你的选择是'+str(choice), '结果')
if eg.ccbox('你确定？',choices = ('yes','no')):
    eg.msgbox('加油，看好你')
else:
    sys.exit(0)
eg.buttonbox(msg='你要跳舞吗',title='dancing', image='旋转.gif',choices=('1','2','3'))
eg.enterbox('你喜欢哪个水果','水果喜好调查')