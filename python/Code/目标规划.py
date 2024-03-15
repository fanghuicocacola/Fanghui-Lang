from scipy import optimize
import numpy as np
import pulp

c = np.array([2,3,-5])
A = np.array([[-2,5,-1],[1,3,1]])
B = np.array([-10,12])
Aeq = np.array([[1,1,1]])
Beq = np.array([7])
res = optimize.linprog(-c,A,B,Aeq,Beq)
print(res)
z = [2,3,-5]
A = [[-2,5,-1],[1,3,1]]
B = [-10,12]
m = pulp.LpProblem(sense=pulp.LpMinimize)
for i in range(0,3):
    x = pulp.LpVariable(f'x{i}', lowBound=0)
m.solve()
for i in range(len(A)):
    m += (pulp.lpDot(A[i], x) >= B[i])
print('m', m)
