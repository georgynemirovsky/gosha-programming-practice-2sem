import matplotlib.pyplot as plt

f = open('one-dimensional.txt', "r")
line = f.readlines()
x = []
y = []
for i in range(len(line)):
    x1, y1 = line[i].split()
    x.append(float(x1))
    y.append(float(y1))
fig, ax = plt.subplots()
ax.set_xlim(1, max(x))
ax.set_ylim(0, max(y) + 5)
ax.set_xlabel('Общая площадь дислокаций')
ax.set_ylabel('Время достижения конечного состояния')
ax.bar(x, y, width=1)
plt.title('Зависимость времени работы от полщади дислокации')
plt.show()