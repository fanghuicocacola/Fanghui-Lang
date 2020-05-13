import xlwt
import xlwt
import matplotlib.pyplot as plt
import numpy as np
wb = xlwt.Workbook()
ws = wb.add_sheet('sheet1')
ws2 = wb.add_sheet('sheet2')


def write99():
    for i in range(1, 10):
        for j in range(1, 10):
            ws.write(i-1, j-1, i*j)


write99()
wb.save('aca.xls')
