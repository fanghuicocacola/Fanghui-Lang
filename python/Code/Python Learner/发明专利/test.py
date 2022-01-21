import 发明专利
import re
from docx import Document
re1 = r"\d{1,4}-\w{1,10}"
re2 = r"\w{1,10}"
# 从文件创建文档对象
document = Document('t.docx')
# 显示每段的内容
for p in document.paragraphs:
    res = re.findall(re1, p.text)
    if res:
        print(res)
        print(p)
        break

for s in res:
    res2 = re.findall(re2, s)
    print(res2)
    for paragraph in document.paragraphs:
        tmp = ''
        runs = paragraph.runs
        for i, run in enumerate(runs):
            tmp += run.text  # 合并run字符串
            if res2[1] in tmp and res2[0]+'-'+res2[1] not in tmp:
                # 如果存在匹配得字符串，那么将当前得run替换成合并后得字符串
                run.text = run.text.replace(res2[1], res2[1] + res2[0])
                tmp = ''

document.save('result_test.docx')



