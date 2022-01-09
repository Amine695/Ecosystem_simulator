import matplotlib.pyplot as plt
import os.path

""" Ce script python va permettre de ploter le résultat de notre simulation """


data = []
time = []
sheeps = []
wolves = []


with open(os.path.dirname(__file__) + '/../data/data.txt') as file:
    for line in file:
        data.append(line.strip())

i = 0
j = 1
k = 2

while i < len(data):
    time.append(float(data[i]))
    wolves.append(int(data[j]))
    sheeps.append(int(data[k]))

    i += 3
    j += 3
    k += 3


plt.rcParams.update({'font.size': 14})
plt.figure(figsize=(12,6))
plt.title("Résultat de la simulation", fontdict = {'fontweight':'bold','fontsize':'15'})
plt.xlabel("Temps (secondes)")
plt.ylabel("Nombre d'animaux")
plt.plot(time,wolves,'b', label = "Loups", linewidth = 2)
plt.plot(time,sheeps,'r', label = "moutons", linewidth = 2)
plt.legend()
plt.savefig(os.path.dirname(__file__) + '/../plot/result.png')
plt.show()
