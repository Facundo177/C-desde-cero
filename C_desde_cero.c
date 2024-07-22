// Es un lenguaje compilado
// Multiplataforma

// Zinjai (IDE para C y C++)

// C no integra POO (solo es secuencial), C++ sí tiene Programación Orientada a Objetos


// En Zinjai - New - Empty C Program Skeleton

/*
Ejecución paso a paso
- Poner puntos de ruptura (punto rojo al lado del número de línea)
- Debug (step-over, step-in)


Diagrama de flujo
- Posicionarse arriba de todo  en el código
- Tools
- Draw flow chart

*/ 


#include <stdio.h >

int main(){
    // Programa principal
    printf("Hola Mundo desde C");
    return 0;
}

// Se devuelve el valor 0 si todo va bien
// Después se pueden agregar otros valores de retorno en caso de errores




/*

Memoria:

ROM (read only memory) -> no se puede modificar
RAM (random access memory) -> lectura/escritura


Variables:
Tienen
- nombre (identificador)
- valor (tipo de dato)
- dirección de memoria (en la RAM -> valor hexadecimal 0x333)

Es un puntero a un espacio en memoria
Sensible a mayúsculas y minúsculas (hola =/= Hola)


Pero, a diferencia de Python:
int a = 10;
int b = 15;
int c = a;      Se copia el valor.
c = 20;         Se modifica 'c', pero 'a' sigue valiendo 10. 
                La variable 'c' apunta a otro espacio en memoria al que se le copia el valor de 'a'.


Tipos de datos:
- int     -> 4 bytes
- float   -> 4 bytes
- double  -> 8 bytes (como float pero más preciso)
- char    -> 1 byte
- bool    -> 1 byte


Ej. de definición de variable:

[calificador] <tipo> <nombre> = <valor>;

int miVariable = 10;



Reglas de los nombres de variable:
- Sensible a mayúsculas/minúsculas
- No se pueden usar palabras reservadas (keywords)
- Usar notación de camello (camelCase)
- Iniciar con letras o _
- No puede iniciar con números o caracteres especiales
- No pueden contener espacios
- Se recomienda usar nombres descriptivos

*/


#include <stdio.h >

int main(){
    // Declarar variable
    int miNumero;
    printf("%d", miNumero);    // tomó un lugar en memoria con un valor basura
    // Inicializarla
    miNumero = 10;           
    // formato %d -> decimal o int
    printf("\n%d", miNumero);    // Solo se pueden imprimir strings, entonces miNumero reemplaza el %d. \n es un salto de línea.
    // Modificar valor (sobreescribir)
    miNumero = 20; 
    printf("\n%d", miNumero);

    return 0;
}




//--------------------------------------------------------------------------------------------------------




#include <stdio.h >

int main(){
    // Declarar varias variables
    int miNumero2 = 20, miNumero3 = 30;
    // Imprimir variables
    printf("miNumero2: %d, miNumero3: %d", miNumero2, miNumero3);

    return 0;
}




//--------------------------------------------------------------------------------------------------------




#include <stdio.h>
#include <stdbool.h>

int main(){
    // Tipo entero (formato %d o %i)
    int entero = 10;
    printf("%i\n", entero);

    // Tipo flotante (formato %f, se puede indicar antes de la f la cantidad de decimales)
    float flotante = 6.5;
    printf("%.2f\n", flotante);

    // Tipo double (formato %lf, long-float)
    double doble = 15.4;
    printf("%lf\n", doble);

    // Tipo char (formato %c) -> tienen equivalente es ASCII
    char caracter = 'A';
    printf("%c\n", caracter);
    printf("%d\n", caracter);  // 65
    char caracterASCII = 65;
    printf("%c\n", caracterASCII);  // A

    // Tipo bool (true / 1  o  false / 0)
    bool logico = true;
    printf("%d\n", logico);  // 1


    // Array (arreglo) -> conjunto de datos ubicados consecutivamente (termina en \0)
    // Tipo string / cadena (formato %s)
    char cadena[] = "Hola";
    printf("%s\n", cadena);

    char cadena2[10] = "Saludos"  // del indice 0 al 9, el 9 está reservado para \0. En total se pueden escribir 9 letras, del 0 al 8.
    printf("%s\n", cadena);       // si usamos más caracteres de los disponibles da error (no es este caso). Se imprimen datos basura hasta encontrar otro fin de cadena.


    // printf("%p", &miVariable);
    // %p -> formato para imprimir pointers o direcciones en memoria
    // & antes de la variable para indicar que se quiere obtener su dirección y no su valor


    return 0;
}




//--------------------------------------------------------------------------------------------------------




#include <stdio.h >

int main(){
    int miNumero = 10;

    printf("miNumero: %d", miNumero);
    printf("\nDireccion de miNumero: %p", &miNumero);

    return 0;
}




//--------------------------------------------------------------------------------------------------------




#include <stdio.h >

int main(){
    // Pedir información al usuario (con scanf)
    int miNumero;

    printf("Dame un numero: ");
    scanf("%d", &miNumero);      // Hay que darle el tipo de dato a recibir y la ubicación en memoria donde se va a guardar (en este caso es la que reservamos para la variable miNumero)

    // Imprimir valor dado por el usuario
    printf("\nTu numero es: %d", miNumero);

    // Lo anterior funciona así para cualquier tipo de dato simple


    // Con cadenas es diferente, ya que son arrays (compuestos)
    int tamanioCadena = 10;
    char nombre[tamanioCadena];
    printf("Dime un nombre: ");

    //scanf("%s", nombre);           
    // En arrays no se especifica la dirección de memoria, ya que se hace implícitamente
    // %s corta el string cuando hay un espacio, si queremos especificar cuando debe parar, hay que poner %[^'\n']s (para en \n)

    scanf("%[^'\n']s", nombre); 
    printf("\nEl nombre es: %s", nombre);

    return 0;
}




//--------------------------------------------------------------------------------------------------------




#include <stdio.h >

int main(){
    int tamanioCadena = 10;
    char nombre[tamanioCadena];

    // Pedir información al usuario (con fgets)
    printf("Dime un nombre: ");
    fgets(nombre, tamanioCadena, stdin);  // stdin -> standard input
    printf("\nEl nombre es: %s", nombre);


    // Pedir información al usuario (con gets)
    printf("Dime un nombre: ");
    gets(nombre);
    printf("\nEl nombre es: %s", nombre);

    return 0;
}




//--------------------------------------------------------------------------------------------------------



// Ejercicio 1 - Información de un empleado

#include <stdio.h>
#include <stdbool.h>

int main(){
    char nombre[50];
    int edad;
    float sueldo;
    bool empleadoConfianza;
    int empleadoConfianzaTemp;

    printf("Proporciona tu nombre: \n");
    gets(nombre);

    printf("\nProporciona tu edad: \n");
    scanf("%d", &edad);

    printf("\nProporciona tu sueldo (USD): \n");
    scanf("%f", &sueldo);

    printf("\nEres empleado de confianza? (1/0): \n");
    scanf("%d", &empleadoConfianzaTemp);

    empleadoConfianza = empleadoConfianzaTemp;

    printf("\nLa informacion proporcionada\nNombre: %s\nEdad: %d\nSueldo: $%.2f\nEmpleado de confianza: %d", nombre, edad, sueldo, empleadoConfianza);

    return 0;
}




//--------------------------------------------------------------------------------------------------------




/*

Constantes:

const <tipo> <nombre> = valor;

Ej:
const int MI_CONSTANTE = 100; 

Una vez creada, ya no se puede modificar.
Por convención se escribe su nombre en mayúsculas y se separan las palabras por _.

*/


#include <stdio.h >

#define PI 3.1416     // Otra forma de definir constantes

#include <math.h>     // Librería que trae varias constantes matemáticas. entre otras cosas

int main(){
    // Una forma de definir constantes es:
    const int MI_CONSTANTE = 10;
    // MI_CONSTANTE = 20;   *Error

    printf("Valor constante: %d", MI_CONSTANTE);

    printf("\nValor constante PI: %.4f", PI);

    printf("\nValor constante PI de math.h: %f", M_PI);

    return 0;
}




//--------------------------------------------------------------------------------------------------------




#include <stdio.h>
#include <stdbool.h>

int main(){
    // sizeof

    int entero;
    float flotante;
    double doble;
    char caracter;
    char cadena[] = "Hola Mundo";
    bool logico = false;

    // sizeof -> entero positivo (unsigned) long -> %lu
    // int -> signed

    printf("int: %lu", sizeof(entero));
    printf("\nfloat: %lu", sizeof(flotante));
    printf("\ndouble: %lu", sizeof(doble));
    printf("\nchar: %lu", sizeof(caracter));
    printf("\nchar array (string): %lu", sizeof(cadena));
    printf("\nbool: %lu", sizeof(logico));

    return 0;
}




//--------------------------------------------------------------------------------------------------------




/*

Operadores:
- Aritméticos
- Asignación
- Comparación
- Lógicos


Aritméticos:
+           x + y
-           x - y
*           x * y
/           x / y
%           x % y
++          ++x o x++
--          --x o x--

*/

#include <stdio.h>

int main(){
    int a, b, c, f;
    float d;

    a = 3 + 4;    // 7
    b = 6 - 2;    // 4
    c = a * 2;    // 14
    d = b / 2.5;  // 1.60
    f = 9 % 2;    // 1



    // Incrementos:
    a = 0;                  // 0

    // Pre-Incremento
    printf("%d", ++a);      // 1

    // Post-Incremento
    printf("%d", a++);      // 1    Se aplica el incremento después de operar con a, cuando termina de usarse en la función
    printf("%d", a);        // 2    Ya se aplicó el incremento pendiente

    // Ejemplos
    a = 5;                  
    b = 2;
    c = ++a * b++;          // 6 * 2 = 12
    
    printf("%d", a)         // 6
    printf("%d", b)         // 3
    printf("%d", c)         // 12


    a = 5;                  
    b = 2;
    c = --a * b--;          // 4 * 2 = 8
    
    printf("%d", a)         // 4
    printf("%d", b)         // 1
    printf("%d", c)         // 8

    return 0;
}




// Asignación:

#include <stdio.h>

int main(){
    int miNumero = 10;      // 10
    miNumero = 20;          // 20
    miNumero += 5;          // 25
    miNumero -= 3;          // 22
    miNumero *= 2;          // 44
    miNumero /= 7;          // 6    (sería 6,algo pero como es entero se corta toda la parte de la coma)
    miNumero %= 2;          // 0

    return 0;
}



// Comparación:

#include <stdio.h>
#include <stdbool.h>

int main(){
    int a = 5, b = 6;
    bool c = a == b;        // 0
    c = a != b;             // 1
    c = a > b;              // 0
    c = a >= b;             // 0
    c = a < b;              // 1
    c = a <= b;             // 1

    return 0;
}



// Lógicos:
/*

and -> &&
or -> ||
not -> !

*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    bool a = true, b = false;
    bool c = a && b;            // 0
    c = a || b;                 // 1
    c = !a;                     // 0

    return 0;
}




//--------------------------------------------------------------------------------------------------------




// Ejercicio - Valor dentro de un rango

#include <stdio.h>
#include <stdbool.h>

int main(){
    int minimo = 0, maximo = 5;
    int dato;

    printf("Proporciona un dato entre 0 y 5: \n");
    scanf("%d", &dato);

    bool dentroRango = dato >= minimo && dato <= maximo;
    printf("Dentro de rango?: %d", dentroRango)

    return 0;
}




//--------------------------------------------------------------------------------------------------------




/*

Prioridad:
1- Paréntesis y corchetes
2- Operadores unarios (-x, ++x, --x, !x)
3- Aritméticos (*, / y %)
4- Aritméticos (+ y -)
5- Relacionales (<, <=, > y >=)
6- Igualdad (== y !=)
7- Lógicos (&& y ||)
8- Asignación (=, +=, -=, *=, etc.)

*/




//--------------------------------------------------------------------------------------------------------




// Sentencias de Decision en C
/*

if/else:

if(condicion){
    ---------
}
else{
    ---------
}


Operador ternario:

(condicion) ? caso_verdadero : caso_falso

*/

#include <stdio.h>

int main(){
    printf("Proporciona un numero: ");
    int miNumero;
    scanf("%d", &miNumero);

    // if - else
    if(miNumero > 0){                       // Tanto en if como en else, si es una sola línea, se puede poner a su derecha el código a ejecutar ahorrandonos las llaves
        printf("\nValor positivo");
    }
    else if(miNumero < 0){                 // Simplemente es una nueva función if que se ejecuta al entrar en el else (nos ahorramos las llaves por estar en la misma línea).
        printf("\nValor negativo");
    }
    else{                                   // Son dos pares de if - else, que están anidados. El segundo condicional se ejecuta dentro del else del primero
        printf("\nValor cero");
    }


    // Operador ternario
    (miNumero > 0) ? printf("Positivo") : printf("Negativo o cero");        // Este no es el mejor ejemplo, ya que lo ideal es que solo hayan dos posibilidades como resultado


    return 0;
}




//--------------------------------------------------------------------------------------------------------




// Ejercicio - Mayor de edad

#include <stdio.h>

int main(){
    const int EDAD_ADULTO = 18;

    printf("Proporciona tu edad: ");
    int edadPersona;
    scanf("%d", &edadPersona);

    if(edadPersona >= EDAD_ADULTO){                       
        printf("\nMayor de edad");
    }
    else if(edadPersona < EDAD_ADULTO && edadPersona >= 0){                  
        printf("\nMenor de edad");
    }
    else{                                  
        printf("\nEdad no válida");
    }

    return 0;
}





// Ejercicio - Días de la semana

#include <stdio.h>

int main(){
    int diaSemana;
    printf("Proporciona el día: ");
    scanf("%d", &diaSemana);

    if(diaSemana == 1){                       
        printf("\nLunes");
    }
    else if(diaSemana == 2){                  
        printf("\nMartes");
    }
    else if(diaSemana == 3){                  
        printf("\nMiercoles");
    }
    else if(diaSemana == 4){                  
        printf("\nJueves");
    }
    else if(diaSemana == 5){                  
        printf("\nViernes");
    }
    else if(diaSemana == 6){                  
        printf("\nSabado");
    }
    else if(diaSemana == 7){                  
        printf("\nDomingo");
    }
    else{                  
        printf("\nDia invalido");
    }

    return 0;
}




//--------------------------------------------------------------------------------------------------------




/*

Switch:
Compara un valor dado con diferentes opciones (sólo valores numéricos)

switch(valor_a_evaluar){
    case 1:
        ------------------------;
        break;
    case 2: case 3:                             Se pueden juntar dos casos para un mismo resultado
        ------------------------;
        break;
    default:
        ------------------------;
}


*/


// Ejercicio - Días de la semana (ahora con switch)

#include <stdio.h>

int main(){
    int diaSemana;
    printf("Proporciona el día: ");
    scanf("%d", &diaSemana);

    switch(diaSemana){
        case 1:
            printf("\nLunes");
            break;
        case 2:
            printf("\nMartes");
            break;
        case 3:
            printf("\nMiercoles");
            break;
        case 4:
            printf("\nJueves");
            break;
        case 5:
            printf("\nViernes");
            break;
        case 6:
            printf("\nSabado");
            break;
        case 7:
            printf("\nDomingo");
            break;
        default:
            printf("\nDia invalido");
            break;
    }

    return 0;
}




//--------------------------------------------------------------------------------------------------------




/*

Ciclos:

- while
- do while
- for


While: Repetir un bloque de código mientras la condición sea verdadera.

while(condicion){
    ------------;
}


Do While:

do{
    ------------;
} while(condicion);


For:

for(declarar_contador; condición; incremento){
    ------------;
}




*/

#include <stdio.h>

int main(){
    // Del 0 al 4 (5 veces)
    /*
    int contador = 0, repeticiones = 5;

    while(contador < repeticiones){
        printf("\n%d", contador);
        contador++;
    }
    */

    // Del 1 al 5 (5 veces)
    int contador = 1, repeticiones = 5;

    while(contador <= repeticiones){
        printf("\n%d", contador);
        contador++;
    }

    return 0;
}




#include <stdio.h>
#include <stdbool.h>

int main(){
    int numero;

    do{
        printf("Proporcione un numero positivo: ");
        scanf("%d", &numero);
    } while(numero <= 0);

    bool condicion;
    do{
        printf("Proporcione un numero positivo: ");
        scanf("%d", &numero);
        condicion = numero > 0;
    } while(!condicion);

    printf("\nValor positivo: %d", numero);

    return 0;
}




#include <stdio.h>

int main(){
    const int REPETICIONES = 5;
    for(int contador = 1; contador <= REPETICIONES; contador++){
        printf("\n%d", contador);
    }

    return 0;
}




//--------------------------------------------------------------------------------------------------------




// Ejercicio - De 3 en 3

#include <stdio.h>

int main(){
    const int MAX = 10, MIN = -10;

    printf("Incremento: \n")
    for(int contador = 1; contador <= MAX; contador += 3){
        printf("%d ", contador);
    }

    printf("\nDecremento: \n")
    for(int contador = 1; contador >= MIN; contador -= 3){
        printf("%d ", contador);
    }

    return 0;
}




// Ejercicio - Acumulador suma

// For
#include <stdio.h>

int main(){
    const int MAX = 5;
    int acumuladorSuma = 0;

    for(int numero = 1; numero <= MAX; numero++){
        printf("(acumuladorSuma + numero) = (%d + %d) = ", acumuladorSuma, numero);
        acumuladorSuma += numero;
        printf("%d\n", acumuladorSuma);
    }

    printf("\nLa suma acumulativa total es: %d", acumuladorSuma);
    
    return 0;
}


// While
#include <stdio.h>

int main(){
    const int MAX = 5;
    int acumuladorSuma = 0, numero = 1;

    while(numero <= MAX){
        printf("(acumuladorSuma + numero) = (%d + %d) = ", acumuladorSuma, numero);
        acumuladorSuma += numero;
        printf("%d\n", acumuladorSuma);

        numero++;
    }

    printf("\nLa suma acumulativa total es: %d", acumuladorSuma);
    
    return 0;
}




//--------------------------------------------------------------------------------------------------------




/*

Arreglos (estructura de datos):

<tipo_dato> <nombre_arreglo>[tamaño_arreglo];

int numerosArreglo[5];

indices de 0 a 4 (5 elementos)

numerosArreglo[0] = 10;
numerosArreglo[4] = 50;

printf("%d", numerosArreglo[0]);


Sintaxis simplificada:

int numerosArreglo[] = {100, 200, 300, 400, 500};

*/

#include <stdio.h>

int main(){
    int numerosArreglo[5];

    numerosArreglo[0] = 13;
    numerosArreglo[1] = 21;
    numerosArreglo[4] = 62;

    printf("%d ", numerosArreglo[0]);
    printf("%d ", numerosArreglo[1]);
    
    return 0;
}




//--------------------------------------------------------------------------------------------------------



// Leer array

#include <stdio.h>

int main(){
    int numerosArreglo[] = {100, 200, 300, 400, 500};

    int largoArreglo;

    int tamanioArreglo = sizeof(numerosArreglo);            // 20 (son los bytes en memoria)
    int tamanioElemento = sizeof(numerosArreglo[0]);        // 4 (bytes de un numero entero en este caso)
    largoArreglo = tamanioArreglo / tamanioElemento;        // 5 elementos (20 bytes totales, 4 bytes por cada elemento)

    for(int i = 0; i < largoArreglo; i++){
        printf("\nArreglo[%d] = %d", i, numerosArreglo[i]);
    }
    
    return 0;
}



// Escribir array

#include <stdio.h>

int main(){
    int numeroElementos;
    printf("Proporciona la cantidad de elementos del arreglo: ")
    scanf("%d", &numeroElementos);

    int numeros[numeroElementos];

    for(int i = 0; i < numeroElementos; i++){
        int n = i+1;
        printf("Proporciona el valor %d de %d: ", n, numeroElementos);
        scanf("%d", &numeros[i]);
    }
    
    return 0;
}




//--------------------------------------------------------------------------------------------------------




/*

Matrices:

Arreglo de 2 dimensiones.

<tipo_dato> <nombre_matriz>[filas][columnas];

int matriz[2][3]        [00][01][02]
                        [10][11][12]


Sintaxis simplificada:

int matriz[2][3] = {
    {100, 200, 300},
    {400, 500, 600}
}



*/

#include <stdio.h>
#define FILAS 2
#define COLUMNAS 3

int main(){
    int matriz[2][3];

    matriz[0][0] = 100;
    matriz[0][1] = 200;
    matriz[0][2] = 300;
    matriz[1][0] = 400;
    matriz[1][1] = 500;
    matriz[1][2] = 600;

    // Se puede hacer más fácil:
    int matriz[2][3] = {
        {100, 200, 300},
        {400, 500, 600}
    };

    // o

    int matriz[FILAS][COLUMNAS] = {             // Para hacerlo de esta forma si o sí tiene que estar en #define, no se puede usar const porque daría error
        {100, 200, 300},
        {400, 500, 600}
    };

    
    return 0;
}




// Recorrer matriz

#include <stdio.h>
#define FILAS 2
#define COLUMNAS 3

int main(){
    int matriz[FILAS][COLUMNAS] = {
        {100, 200, 300},
        {400, 500, 600}
    };

    for(int fila = 0; fila < FILAS; fila++){
        for(int col = 0; col < COLUMNAS; col++){
            printf("%d ", matriz[fila][col]);
        }
        printf("\n");
    }
    
    return 0;
}



// Introducir datos en matriz

#include <stdio.h>

int main(){
    int filas, columnas;
    printf("Proporciona el numero de filas: ");
    scanf("%d", &filas);
    printf("Proporciona el numero de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];

    for(int fila = 0; fila < filas; fila++){
        for(int col = 0; col < columnas; col++){
            printf("Dame un número para [%d][%d]: ", fila, col);
            scanf("%d", &matriz[fila][col]);
        }
    }
    
    return 0;
}




//--------------------------------------------------------------------------------------------------------




/*

Funciones:

Bloque de código reutilizable, realiza una tarea en particular.

Se busca dividir el programa en funciones, para repartir las tareas.
Modularidad y reusabilidad.


<tipo_retorno> <nombre_funcion>(<parametros>){

    return <>;
}

*/

#include <stdio.h>

void imprimir(int parametro){
    printf("%d", parametro);
}

int sumar(int a, int b){
    int resultadoSuma = a + b;
    return resultadoSuma;
}

int main(){
    int argumento;
    printf("Proporciona un numero: ");
    scanf("%d", &argumento);

    imprimir(argumento);

    imprimir(sumar(8,5))

    return 0;
}




//--------------------------------------------------------------------------------------------------------




/*


Copia de valores:

Como habíamos visto, en los tipos de datos primitivos al igualar variables solo se copia su valor, es decir:
int a = 10;
int b = a;    se copia el 10
Ambas variables tienen lugares diferentes en memoria, por lo que al modificar b no le pasará nada a la variable a.


Apuntadores (pointers):
int a = 10;
int *b = &a;
En este caso b apunta a la dirección de a.

Para verlo mejor, los apuntadores funcionan así:
printf("%d", a);    // 10
printf("%d", *b);   // 10
printf("%p", b);    // 0x333 (%p de pointer)
La variable b es un apuntador, por lo que guarda la dirección de memoria. Con el * se accede a lo que esté guardado en esa dirección.

*b = 20;    // ahora a = 20
¡CUIDADO! si modificamos b directamente (b = 20), sin el *, cambiamos la dirección de memoria y hacemos que apunte a otro lado. 
Si tocamos memoria de otro programa se puede romper todo.
*b para acceder a donde apunta (desreferencia).

entonces:
a == *b
&a == b

pero &a =/= &b
b es su propia variable, tiene también un lugar en memoria.





Paso por valor:

En las funciones, los cambios hechos NO afectan a las variables externas, solo se crea una copia en una variable distinta.
Por eso hay que diferenciar parámetro de argumento.

void pasoPorValor(int parametro){       // parametro es una variable que SE CREA al ejecutar la función y COPIA el valor del argumento sin modificarlo. Se usa internamente por la función y se destruye cuando esta termina de ejecutarse.
    parametro = 20;
}

int argumento = 10;

pasoPorValor(argumento);                // argumento es el valor que se le pasa a la función, que va a ser copiado para hacer algo dentro de esa función. Puede ser una variable o un valor directo, pero solo se va a copiar su valor en el parametro.

printf("%d", argumento);                // 10 (sigue valiendo lo mismo aunque la funcion diga parametro = 20, porque son dos variables distintas en realidad)


*/

#include <stdio.h>

void cambiarValor(int parametro){
    parametro = 20;
}

int main(){
    int argumento = 10;
    printf("%d", argumento);    // 10

    cambiarValor(argumento);

    printf("%d", argumento);    // 10

    return 0;
}


/*

Paso por referencia:

Para poder modificar variables en nuestras funciones, se pueden usar apuntadores que modifiquen el espacio en memoria de estas.


void pasoReferencia(int *parametro){
    *parametro = 20;
}

int argumento = 10;                 // 10

pasoReferencia(&argumento);

printf("%d", argumento);            // 20

*/

#include <stdio.h>

void cambiarValor(int *parametro){
    *parametro = 20;
}

int main(){
    int argumento = 10;
    printf("%d", argumento);    // 10

    cambiarValor(&argumento);

    printf("%d", argumento);    // 20

    return 0;
}




//--------------------------------------------------------------------------------------------------------




/*

Copiar referencia en arreglos:

Los arreglos directamente guardan la dirección en memoria de su primer elemento, por lo que no hace falta &.


int arreglo1[] = {100, 200};

int *arreglo2 = arreglo1;

arreglo2[0] = 500;                  // También modifica arreglo1

printf("%d", arreglo1[0])           // 500
printf("%d", arreglo2[0])           // 500

Ambos arreglos son exactamente iguales, apuntan a los mismos espacios en memoria.


void pasoReferencia(int *parametro){
    parametro[0] = 500;
    parametro[1] = 600;
}

int argumento[] = {100, 200};

pasoReferencia(argumento);

printf("%d", argumento[0]);         // 500
printf("%d", argumento[1]);         // 600

*/

#include <stdio.h>

void cambiarValor(int *parametro){
    parametro[0] = 4;
    parametro[1] = 5;
    parametro[2] = 6;
}

int main(){
    int arreglo[] = {1, 2, 3};
    printf("%d %d %d", arreglo[0], arreglo[1], arreglo[2]);

    cambiarValor(arreglo);
    printf("\n%d %d %d", arreglo[0], arreglo[1], arreglo[2]);

    return 0;
}




#include <stdio.h>

void imprimirMensaje(char *mensaje){            // o también (char mensaje[])
    printf("Mensaje: %s", mensaje);
}

int main(){
    char cadena[5];
    printf("Proporciona el mensaje a mostrar: \n");
    gets(cadena);
    imprimirMensaje(cadena);

    return 0;
}




#include <stdio.h>

void imprimirMensaje(char *mensaje){
    //printf("Mensaje: %s", mensaje);           // Hola
    mensaje = "Adios";                          // No se modifica cadena[], pero el apuntador 'mensaje' ahora apunta a un nuevo espacio en memoria con "Adios"
    printf("Mensaje: %s", mensaje);             // Adios
}

int main(){
    char *cadena = "Hola";                      // No se puede modificar con [] una vez creado, daría error. Es de solo lectura.
    imprimirMensaje(cadena);                    // Adios

    printf("%s", cadena);                       // Hola

    return 0;
}

// Lo que pasa es que 'cadena' apunta a "Hola" y eso sigue siendo así, pero 'mensaje', que originalmente también apuntaría a "Hola", 
// al no poder sobreescribirlo por "Adios" ya que es solo lectura, apunta a un nuevo espacio en memoria que va a almacenar "Adios"




//--------------------------------------------------------------------------------------------------------




/*

Alcance de variables:

globales -> antes de main, se pueden usar en cualquier función y modificar

local -> una variable definida dentro de main() no se puede usar fuera de este

local a una función -> solo dura lo que dure la función


*/

#include <stdio.h>

int variableGlobal = 10;

void miFuncion(int variableLocalFuncion){
    variableLocalFuncion = 40;
    variableGlobal = 50;
}

int main(){
    int variableLocalMain = 20;

    miFuncion(30);

    variableGlobal = 60;

    return 0;
}




//--------------------------------------------------------------------------------------------------------




/*

Funciones recursivas:

mi_funcion(n){
    if(n==1){
        return n;
    }
    else{
        mi_funcion(n-1);
    }      
}



Reglas:
1- Una función que se llama a sí misma.
2- Debe avanzar hacia un caso base, para no caer en ciclos infinitos.

*/

#include <stdio.h>

int variableGlobal = 10;

void funcionRecursiva(int numero){
    if(numero == 1){
        printf("%d\n", numero);
    }
    else{
        printf("%d\n", numero);             // Se imprime de mayor a menor (antes de la llamada recursiva)
        funcionRecursiva(numero-1);         
        printf("%d\n", numero);             // Se imprime de menor a mayor (primero la llamada recursiva y después sigue con lo que quedó pendiente, llega al último caso primero y de ahí para atras)
    }
}

int main(){
    int valor = 5;

    funcionRecursiva(valor);

    return 0;
}




//--------------------------------------------------------------------------------------------------------




//Funciones básicas (con stdlib.h, string.h, math.h):

// Largo de strings

#include <stdio.h>
#include <string.h>

int main(){
    char cadena[] = "Hola";

    int largo = strlen(cadena);
    printf("Largo cadena: %d", largo);       // 4

    largo = sizeof(cadena);
    printf("Largo cadena: %d", largo);       // 5 (incluye el \0)

    char c;
    for(int i = 0; i < strlen(cadena); i++){        // Solo imprime letras, sin el \0
        c = cadena[i];
        printf("\n%c", c)
    }

    return 0;
}



// Subcadenas

#include <stdio.h>
#include <string.h>

int main(){
    char cadena[] = "Hola Mundo";
    char subcadena[10];

    int inicio = 0, nCaracteres = 4;
    strncpy(subcadena, &cadena[inicio], nCaracteres);   // No agrega \0, solo copia los caracteres indicados

    subcadena[nCaracteres] = '\0';

    printf("Original: %s", cadena);             // Hola Mundo
    printf("\nSubcadena: %s", subcadena);       // Hola


    inicio = 5; 
    nCaracteres = 5;
    strncpy(subcadena, &cadena[inicio], nCaracteres);   

    subcadena[nCaracteres] = '\0';

    printf("Original: %s", cadena);             // Hola Mundo
    printf("\nSubcadena: %s", subcadena);       // Mundo
    

    return 0;
}



// Convertir de texto a número y viceversa

#include <stdio.h>
#include <stdlib.h>

int main(){
    char cadena1[] = "10";
    char cadena2[] = "20";

    // atoi -> ASCII to int
    // atof -> ASCII to float
    // Si no es número regresa 0

    int resultado = atoi(cadena1) + atoi(cadena2);
    printf("Resultado suma: %d", resultado);



    int edad = 28;
    char edadTexto[5];

    // itoa -> int to ASCII
    // ftoa -> loat to ASCII
    // Se necesita proporcionar la base numérica (10 en este caso)

    itoa(edad, edadTexto, 10);
    printf("%s", edadTexto);

    return 0;
}



// Valor absoluto

#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero, numeroAbs;
    printf("Proporciona un número: ");
    scanf("%d", &numero);
    
    numeroAbs = abs(numero);
    printf("|%d| = %d", numero, numeroAbs);

    return 0;
}



// Redondeo y truncado

#include <stdio.h>
#include <math.h>

int main(){
    float numero;
    int redondeo, truncado;

    numero = 8.5;

    redondeo = round(numero);
    printf("%.2f -> %d", numero, redondeo);     // 9

    truncado = trunc(numero);
    printf("%.2f -> %d", numero, truncado);     // 8

    return 0;
}