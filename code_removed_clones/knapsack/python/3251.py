# Solucion al problema de la mochila utilizando algortimos geneticos
# Problema de la mochila de geeksforgeeks
# http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/
import random

def valido(p,t,k):
    suma = 0
    for i in range (0, len(t)):
        suma += t[i]*p[i]

    return True if suma <= k else False

def poblacionInicial(t,v,k,tp):
    n = 0
    poblacion = []
    while (n < tp):
        c = []
        for i in range (0,len(t)): # se deben sacar poblaciones random del tamano de los objetos
            c.append(random.randint(0,1))
        if (valido(c,t,k)): # si no supera la capacidad de la mochila
            poblacion.append(c) # agrega una poblacion
            n += 1
    return poblacion


def f_desempeno(p,v): #funcion de desempeno (fitness)
    suma = 0
    for i in range (0, len(t)):
        suma += (p[i]*v[i])
    return suma

def desempeno(p,v): #elije el de mejor desempeno
    mejor = 0
    tmp = 0
    pi = 0 # posicion del mejor
    desempenos = []
    for i in range(0,len(p)):
        tmp = f_desempeno(p[i],v)
        desempenos.append(tmp)
        if (tmp > mejor):
            mejor = tmp
            pi = i
    return (desempenos,p[pi],pi)

def seleccion(p,d,n): # por ruleta
    #print ("d : ", d)
    #print ("n : ", n)
    # a cada cromosoma se le asigna una porcion de la ruleta dependiendo de su desempeno
    suma = sum(d) # suma de todos los desempenos
    fc = []
    acumulado = 0
    nueva_p = [] # nueva poblacion
    # asignacion de la proporcion
    for i in range (0, len(d)):
        #print ("i: ", i)
        fc.append(float(d[i])/float(suma) + acumulado) # normalizacion
        #print ("fc: ", fc[i])
        acumulado = fc[i]

    #print ("fc : ", fc)

    while (n): # hasta que tenga toda la poblacion
        r = random.uniform(0, 1)
        #print ("random : ", r)
        for i in range(0,len(d)):
            if (r <= fc[i]):
                nueva_p.append(p[i]) # agregados por la ruleta
                break

        n -= 1
    return poblacion

def cruzamientoPunto(cr1, cr2, pc): #cromosoma1, cromosoma2, punto de corte
    h1 = cr1[:pc] + cr2[pc:]
    h2 = cr2[:pc] + cr1[pc:]
    return h1,h2

# poblacion, cantidad de poblaciones nuevas necesarias, tamanos de cada objeto y capacidad mochila
def cruzamiento(p,c,t,k):
    #print ("c_o : ",c)
    nueva_p = [] # poblacion despues del cruzamiento
    while (c): # mientras que no tengamos toda nuestra poblacion
        #print ("c: ", c)
        r1 = random.randint(0,len(p)-1)
        r2 = random.randint(0,len(p)-1)
        while (r1 == r2) : # para no hacer cruzamiento con el mismo cromosoma
            r2 = random.randint(0,len(p)-1)

        p_corte = random.randint(0,len(p[r1]))
        h1,h2 = cruzamientoPunto(p[r1],p[r2],p_corte) # cruzamiento en un punto, salen dos hijos (aptos o no)
        if (valido(h1,t,k) and c):
            #print ("agrega")
            c -= 1
            nueva_p.append(h1)
        if (valido(h2,t,k) and c):
            #print ("agrega")
            c -= 1
            nueva_p.append(h2)

    return nueva_p

def mutacion(p):
    r = random.randint(0,len(p)-1)
    if (p[r] == 0):
        p[r] = 1
    else:
        p[r] = 0

def operadorMutacion(p):
    for i in range (0,len(p)): # posibilidades de mutar en toda la poblacion
        r = random.uniform(0, 1) # tasa de mutacion
        if (0.05 <= r <= 0.01): # porcentaje de mutacion de 5% a 10%
            mutacion(p[i])
    return p

if __name__ == '__main__':

    t = [10, 20, 30]#[15,10,20,10,5,12,8,16,25,12] # tamano de cada objeto
    v = [60, 100, 120]#[50,40,60,30,45,40,50,35,70,35] # valor de cada objeto
    k = 50#70 # capacidad de la mochila
    tp = 4 # tamano de la poblacion
    n = 100 # generaciones

    while (n):
        poblacion = poblacionInicial(t,v,k,tp) #lista de las poblaciones
        #print (poblacion)
        desempenos, mejor, pi = desempeno(poblacion,v) # desempeno de cada poblacion
        poblacion = seleccion(poblacion, desempenos, tp-1) # tp-1 por el elitismo
        poblacion[len(poblacion)-1] = mejor # elitismo
        #print (poblacion)
        poblacion = cruzamiento(poblacion, tp-1, t, k)
        poblacion.append(mejor) # elitismo
        #print (poblacion)
        poblacion = operadorMutacion(poblacion)
        #print (poblacion)
        n -= 1

    print ("poblacion final: ", poblacion)

    desempenos, mejor, pi = desempeno(poblacion,v)
    print ("Mejor solucion: ", mejor)
    print ("Valor maximizado: ", desempenos[pi])
