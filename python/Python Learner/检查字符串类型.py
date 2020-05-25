str1 = input('请输入字符串：')
int_account = 0
str_account = 0
other_account = 0
for i in str1:
    if i.isdigit():
        int_account += 1
    elif i.isalpha():
        str_account += 1
    else:
        other_account += 1
print('数字 = %d，字母 = %d，其他 = %d'%(int_account, str_account, other_account))
