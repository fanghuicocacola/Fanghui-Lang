

import xlrd

"""读取并打印表格中的数据"""


# 定义读取并打印表格中数据的函数

def read_excel():

    data = xlrd.open_workbook('a.xlsx')

    print(data.sheet_names())

    table = data.sheet_by_index(0)

    print("打印工作表的名称、行数和列数:")

    print(table.name, table.nrows, table.ncols)

    row_4 = table.row_values(3)

    print("获取第4行的内容，以列表形式表示:")

    print(row_4)

    col_3 = table.col_values(2)

    print("获取第3列的内容，以列表形式表示:")

    print(col_3)

    # 注意输出结果中的空值！

    print("获取工作表中单元格的3种方法:")

    print(table.cell(1, 0).value)

    print(table.cell_value(1, 0))

    print(table.row(1)[0].value)

    print("获取单元格内容的数据类型：")

    print(type(table.cell_value(1, 2)))

    cols = table.col(0)

    for col in cols:
        print(col.value)


read_excel()


