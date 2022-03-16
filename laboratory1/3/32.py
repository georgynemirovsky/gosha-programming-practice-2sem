import matplotlib.pyplot as plt

f = open('n-time.txt', "r")
line = f.readlines()
x = []
y = []
for i in range(len(line)):
    x1, y1 = line[i].split()
    x.append(float(x1))
    y.append(float(y1))
fig, ax = plt.subplots(1, 2)
plt.suptitle('Зависимость среднего времени достижения конечного состояния, от стороны решётки')
ax[0].plot(x, y)
ax[1].plot(x[4::], y[4::])
ax[1].set_xscale('log')
ax[1].set_yscale('log')
ax[0].set_ylabel('n (число ходов)')
ax[0].set_xlabel('N (сторона решётки)')
ax[1].set_xlabel('ln(N)')
ax[1].set_ylabel('ln(n)')
fig.set_figheight(6)
fig.set_figwidth(12)
plt.show()