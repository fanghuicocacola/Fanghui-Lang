import os
os.system('calc')
try:
    with open('list.txt', encoding='utf-8') as f:
        print(f.read())
except OSError as reason:
    print('文件出错了'+str(reason))