from matplotlib.pyplot import cm
import matplotlib.pyplot as plt
import numpy as np

g=np.genfromtxt("potencial.txt", delimiter=' ')
M=int(np.genfromtxt("M.txt", delimiter=' '))

potencial=g[0:M,0:M]
campox=g[M:2*M,0:M]
campoy=g[2*M:3*M,0:M]
mag=np.sqrt(campox**2+campoy**2)

Y, X =np.mgrid[0:250:250j, 0:250:250j]
fig=plt.figure()
plt.streamplot(X, Y, campox, campoy, color='k', linewidth=1.0, arrowstyle='->',arrowsize=1.0, density=1.2)
plt.imshow(potencial)
plt.colorbar()
plt.title('Potencial y Campo Electrico')
plt.savefig("placas.pdf", format="pdf")
plt.close()
