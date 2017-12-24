import random
import time
global comparacion
comparacion = 0
global logicas
logicas = 0
global asignacion
asignacion = 0
global aritmeticas
aritmeticas =0


def QuickSort(arreglo,primer,ultimo):
  if primer < ultimo:
    global comparacion
    comparacion = comparacion + 1
    global asignacion
    asignacion = asignacion + 1
    q = particionRandomizada(arreglo,primer,ultimo)

    QuickSort(arreglo,primer,q - 1)
    QuickSort(arreglo,q + 1,ultimo)


def particionRandomizada(arreglo,primer,ultimo):
  global asignacion

  asignacion = asignacion + 1 
  i = random.randrange(primer,ultimo)
  asignacion = asignacion + 1
  arreglo[i],arreglo[ultimo] = arreglo[ultimo],arreglo[i]
  q = particion(arreglo,primer,ultimo)

  return q

def particion(arreglo,primer,ultimo):
  global asignacion
  global comparacion
  global logicas

  asignacion = asignacion + 1
  x = arreglo[primer]
  asignacion = asignacion + 2
  izquierdo = primer + 1
  derecho = ultimo

  while True:
 
    comparacion = comparacion + 1
    logicas = logicas + 1 
    while izquierdo <= derecho and arreglo[izquierdo] <= x:
      
      asignacion = asignacion + 1
      izquierdo = izquierdo + 1

    comparacion = comparacion + 1
    logicas = logicas + 1 
    while arreglo[derecho] >= x and derecho >= izquierdo:
      derecho = derecho - 1
      asignacion = asignacion + 1

    if derecho < izquierdo:
      break

    else:
      arreglo[izquierdo],arreglo[derecho] = arreglo[derecho],arreglo[izquierdo]
      asignacion = asignacion +  1

  arreglo[primer],arreglo[derecho] = arreglo[derecho],arreglo[primer]
  asignacion = asignacion + 1

  return derecho