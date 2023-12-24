REALIZACIÓN PRÁCTICA 9

Se trata de desarrollar un programa de multiplicación de matrices en paralelo. La forma de realizar el
reparto de trabajo entre los procesos es libre. Simplemente se pide que el tamaño de las matrices
(cuadradas) pueda ser definido mediante argumento en línea de comando o bien pidiendo su valor
por teclado, con el fin de poder realizar pruebas con matrices de diferentes tamaños. Asimismo se
debe procurar no limitar el tamaño de las matrices en la medida de lo posible, por lo que se
recomienda la reserva dinámica de memoria.
El proceso 0 inicializará las matrices con valores aleatorios de tipo float y repartirá la carga de
forma adecuada, según el criterio del programador. En una primera fase, se imprimirá el tiempo
Práctica 9: Ejemplo de aplicación práctica MANUAL DE PRÁCTICAS
38
empleado en la ejecución junto con el resultado en la salida estándar para comprobar que es
correcto. Posteriormente se eliminará para permitir que las matrices puedan crecer en tamaño sin
hacer esperar por una impresión de datos interminable.


NOTA:
Con el fin de realizar una reserva dinámica de memoria para matrices de un tamaño elevado
teniendo la posibilidad de doble indexación es necesario recurrir a los dobles punteros, es decir,
definir un array de punteros cada uno de los cuales apunta a una fila de la matriz.
