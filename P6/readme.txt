REALIZACIÓN PRÁCTICA 6 

Vamos a suponer el siguiente escenario para calcular el factorial de un número: el proceso 0 se
encarga de recibir los números que le va introduciendo el usuario. El cálculo se lo encarga al proceso
1 que se supone que reside en una máquina con mayor potencia de cálculo. Para evitar el colapso de
las peticiones, deberá hacer esperar al usuario para que no introduzca otro dato hasta que se haya
completado el envío anterior. Para ello mostrará un mensaje de espera. Esta situación es poco
probable con un hardware de una mínima potencia, pero la incluimos como ejemplo para aprovechar
la potencia de las nuevas funciones. También será necesario incorporar una condición de salida. En
este caso, el envío del dato 0 indicará que se desea terminar la operación.
