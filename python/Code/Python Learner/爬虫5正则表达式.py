import re
print(re.search(r"fich(c|d)","fichd"))
print(re.findall(r"[^a-z]", "FISHc.com"))
print(re.search(r"fishc{3}","fishccccmmmnnn"))
print(re.search(r"f...","fishcccc"))
s = '<jfsadop><09ik>'
print(re.search(r"<.+>",s))
print(re.search(r"<.+?>",s))
print(re.search(r"\W", "我爱鱼c（I love fish_c.com）"))
print(re.findall(r"\w", "我爱鱼c（I love fish_c.com）"))
p = re.compile(r'\w')
print(p.findall('Never give up _NIKE'))


