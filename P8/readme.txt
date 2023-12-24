REALIZACIÓN PRÁCTICA 8

Para la puesta en práctica de los conceptos que acabamos de ver haremos que un proceso “padre”
arranque un determinado número de procesos “hijo”. Habrá que elaborar dos ficheros ejecutables
donde uno de ellos, el “padre” se lanzará desde MPI, mientras que el otro, el “hijo”, se lanzará desde
el código del “padre”. Para comprobar el funcionamiento se mandarán mensajes de saludo: del
padre a los hijos y del hijo de menor rango al resto. Cada hijo imprimirá un mensaje de saludo al ser
creados, el mensaje de saludo enviado por el padre y el mensaje enviado por el hijo de menor rango.
