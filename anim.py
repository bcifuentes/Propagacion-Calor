from tkinter import Tk, Frame,Button,Label,ttk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

fhand=open("data.txt","r")
data=list()
tiempos=list()

for line in fhand:
    datos=line.split()
    data.append([float(i) for i in datos[1:]])
    tiempos.append(float(datos[0]))


fig, ax= plt.subplots(facecolor="white")
plt.title("Ecuación de difusión con fuente 20cos(t)",color='black',size=16)
plt.ylim(-22,22)
plt.grid()
plt.xlabel('Distancia (x)')  
plt.ylabel('Temperatura (T)')

x=np.arange(0,5,0.1)
line, = ax.plot(x, data[0],color='black',marker='.',linestyle='solid',
                linewidth=1,markersize=5,markeredgecolor='black')

def animate(i):
    line.set_ydata(data[(i)%len(data)])
    #print(tiempos)
    l='t={:} s'.format(tiempos[i])
    #line.set_label(None)
    
    line.set_label(l)
        
    legend = plt.legend(loc='lower left', shadow=True, fontsize='9')
    legend.get_frame().set_facecolor('white')
    
    return line,legend

def iniciar():
    global ani
    ani = animation.FuncAnimation(fig,animate,interval=5,blit=True,save_count=10)
    
    canvas.draw()

def pausar():
    ani.event_source.stop()

def reanudar():
    ani.event_source.start()

ventana = Tk()
ventana.geometry('642x535')
ventana.wm_title('Grafica Matplotlib Animacion')
ventana.minsize(width=642,height=535)

frame = Frame(ventana, bg='white',bd=3)
frame.pack(expand=1,fill='both')

canvas = FigureCanvasTkAgg(fig,master=frame)
canvas.get_tk_widget().pack(padx=5,pady=5,expand=1,fill='both')

Button(frame,text='Grafica Datos',width = 15,bg= 'black',fg='white',command=iniciar).pack(pady=5,side='left',expand=1)
Button(frame,text='Pausar',width = 15,bg= 'black',fg='white',command=pausar).pack(pady=5,side='left',expand=1)
Button(frame,text='Reanudar',width = 15,bg= 'black',fg='white',command=reanudar).pack(pady=5,side='left',expand=1)

ventana.mainloop()
