from mpl_toolkits.mplot3d import Axes3D
import matplotlib
import numpy as np
import pandas as pd
from matplotlib import cm
from matplotlib import pyplot as plt

data = pd.read_csv('/Users/gosa/Downloads/Output.csv',sep = ' ', names = ['s','t','mv'])
s = np.array(data['s'])
t = np.array(data['t'])
mv = np.array(data['mv'])

N = 25
J = 25 

S = np.reshape(s, (N,J))
T = np.reshape(t, (N,J))
MV = np.reshape(mv, (N,J))


fig = plt.figure()
ax = fig.add_subplot(projection='3d')

ax.plot_surface(S, T, MV, rstride=1, cstride=1, cmap=cm.YlGnBu_r)
ax.set_zlim3d(auto=True)
ax.set_xlabel(r'$Strike$')
ax.set_ylabel(r'$Time$ $to$  $Maturity$')
ax.set_zlabel(r'$MV(S,t)$')
plt.show()