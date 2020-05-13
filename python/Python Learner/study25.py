import matplotlib.pyplot as plt
import numpy as np

x1 = np.arange(-10, 10, 0.25)
x2 = np.arange(-10, 10, 0.25)
y1 = np.cos(x2)
y2 = np.sin(x2)
y3 = 1/x1
plt.rcParams['axes.unicode_minus'] = False
plt.plot(x2, y1, 'b')
plt.plot(x2, y2, 'r')
plt.plot(x1, y3, 'r')
plt.show()
