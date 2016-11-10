import numpy as np
import matplotlib.pyplot as plt
import imageio #Para hacer el gif
import os #Para crear directorio temporal
import shutil #Para eliminar directorio temporal

g=np.genfromtxt("cuerda.txt", delimiter=" ")

tfin=200.0
N_time=1000
L=100.0

posicion=np.linspace(0, 100, len(g[0,:]))
amp=np.max(np.abs(g))

os.mkdir('temp')
with imageio.get_writer('./cuerda.gif', mode='I') as writer:
    for i in range(N_time):
        if i%20==0:
            fig=plt.figure()
            ax=plt.axes()
            plt.xlabel('Posicion')
            plt.ylabel('Altura')
            plt.title('Movimiento de una cuerda con extremos fijos')
            plt.plot(posicion, g[i,:], 'b-', ms=7)
            plt.xlim((0,L))
            plt.ylim((-amp,amp))
            plt.grid()
            plt.savefig('./temp/'+str(i)+'cuerda.png', format='png')
            plt.close()

            image=imageio.imread('./temp/'+str(i)+'cuerda.png')
            writer.append_data(image)
#borra directorio temporal
shutil.rmtree('temp')
