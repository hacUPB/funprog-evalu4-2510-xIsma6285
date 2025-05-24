Preguntas de comprensión
¿Qué se pasa realmente a la función cuando enviamos un arreglo como parámetro?
Respuesta: Se pasa la dirección del primer elemento del arreglo, es decir, un puntero.

¿Qué diferencia hay entre declarar el parámetro como int arr[] y int *arr?
Respuesta: Aunque ambos funcionan de forma similar, la diferencia está en la intención:

int arr[] se utiliza para dejar claro que se está trabajando con un arreglo.

int *arr enfatiza que se está utilizando una dirección de memoria (puntero).

¿Qué implicaciones tiene esto sobre la modificación del arreglo dentro de la función?
Respuesta: Como se pasa una referencia (puntero) al arreglo, cualquier modificación dentro de la función afecta directamente al arreglo original.

Preguntas finales para reforzar el aprendizaje
¿Cuál es exactamente la diferencia entre un arreglo y un puntero?
Respuesta:

Un arreglo es una colección de elementos contiguos en memoria con tamaño fijo.

Un puntero es una variable que almacena la dirección de memoria de otro dato (como un entero o el primer elemento de un arreglo).

¿Cómo están almacenados en la memoria los elementos de una matriz?
Respuesta:
Los elementos de una matriz se almacenan de forma lineal, ordenados por filas (en C).

¿Qué precauciones se deben tomar al usar punteros para recorrer arreglos?
Respuesta:

No acceder fuera de los límites del arreglo.

Asegurarse de que el puntero esté correctamente inicializado.