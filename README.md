# sistemas-tiempo-real

https://netting.wordpress.com/2016/10/01/segmentacion-de-memoria-de-un-programa-y-el-stack/

.text : Es de tamaño fijo y de solo lectura. En esta parte se almacenan todas y cada una de las instrucciones en código máquina que componen el programa que se está ejecutando. Como curiosidad añadir que en caso de existir varias instancias en ejecución del mismo programa o binario el sistema operativo actúa de forma inteligente manteniendo una sola copia en memoria del código y permitiendo que los procesos puedan compartirla para ahorrar recursos.

.data [data segment]: Aquí se almacenan las variables globales inicializadas del programa. De tamaño fijo y permite la escritura, se puede escribir en él.

.bss [bss segment]: Aquí se almacenan las variables globales sin inicializar. De tamaño fijo y permite la escritura, se puede escribir en él.

Heap [heap segment]: Segmento de memoria reservado para la memoria dinámica del programa. El tamaño de este segmento no está predefinido, va variando. Crece hacia a arriba, en el mismo sentido que las direcciones de memoria. Para reservar memoria utilizamos, por ejemplo, las conocidas funciones de asignación malloc(), calloc(), o realloc() del lenguaje C.

STACK [stack segment]: Para lo que nos ocupa, lo más interesante. La pila o stack. Aquí se guardan los argumentos pasados al programa, las cadenas del entorno donde este es ejecutado (el comando env permite su visualización), argumentos pasados a las funciones, las variables locales que todavía no contienen ningún contenido, y además es donde se almacena el registro IP cuando una función es llamada (valores de retorno).
