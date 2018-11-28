import numpy as np
import matplotlib.pyplot as plt1
import matplotlib.pyplot as plt2


data= np.genfromtxt('test.txt',delimiter=',')
print(data)

sum=0
Subj =["Tri Rapide","Tri Select"]
l_Sum=[]

for i in data:
        print(i)
for i in range(len(data[0])):
    sum=0
    for j in range(len(data)):
        sum=sum+data[j][i]
    l_Sum.append(sum)
print(l_Sum)
plt1.yscale('log')
plt2.yscale('log')
plt1.plot(data)
plt2.xlabel("Nombre de tests")
plt1.ylabel("Moyenne de Temps pour un tri")
plt1.legend(Subj)
plt2.plot(l_Sum)

plt1.show()
plt2.show()
