"""
Created on Sat Feb 15 18:38:16 2020

@author: Dragos Chileban
"""
import pandas as pd
import numpy as np
import random
import matplotlib.pyplot as plt

data = pd.read_csv("data.csv")
A = data.to_numpy()
random.shuffle(A)

X = A[:, :1]
Y = A[:, 1:]
N = int(X.size / X[0].size)


X = np.append(X, np.ones((N, 1)), axis=1)
M = int(X[0].size)
"""
split = int(N * 8 / 10)
X_train = X[ : split]
X_test = X[split : ]

Y_train = Y[ : split]
Y_test = Y[split : ]

"""
theta = np.ones((M, 1))
learning_rate = .0000001

for i in range(100000):
    derivative = (1 / N) * np.transpose(X) @ (X @ theta - Y)
    theta = theta - learning_rate * derivative
    
#error = sum((X_test @ theta - Y_test)**2) / Y_test.size
#print(error)

plt.plot(X[:, :1], X @ theta)
plt.plot(X[:, :1], Y, 'ro')
