str1='喜欢这世界，喜欢你，想见你'
print(str1[:5]+str1[5:])
print(str1[6])
print(str1[7])
print(str1[8])
str2='tO BE OR NOT TO BE'
str2=str2.capitalize()
print(str2)
str2=str2.casefold()
print(str2)
str2=str2.replace('not','never')
print(str2)
str3='forkkkkkkkkkkk'
str3=str3.translate(str.maketrans('or','uc'))
print(str3)
print("{0} love {b}.{c}".format("I",b="fishc",c="com"))


