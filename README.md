# SSOO-tarea02

## AUTOR

Lukas Pinto <lukas.pinto@alumnos.uv.cl>

    
## Diseño de solución
### señales
Para la solucion de este problema primero en cuenta el manejo de las señales, las cuales se manejan mediante la funcion
signal, la cual recibe la señal y luego una funcion que le indica que hacer en el caso de recibir esa señal.
```c++
    std::signal(SIGINT, signal_handler);/*ctrl+c*/
    std::signal(SIGTSTP, signal_handler);/*ctrl+z*/
    std::signal(SIGQUIT, signal_handler);/*ctrl+\*/

```
#### signal_handler o manipulador de señal
dentro de esta función se le dice que hacer al programa en caso de resivir una señal.
```c++
 void signal_handler(int signal_num){
	std::cout<<"Detención no permitida"<<std::endl;
	/* función  que atrapa las señales*/
}

```
### Procesos
Para la creación del proceso hijo se utiliza la función fork() y el valor de esta función se le asigna a una variable llamada pid, la cual toma el valor 0 en el proceso hijo, y en el proceso padre toma el valor del hijo.
lo que quiere que con esta variable se identifica que proceso es cual, y asi se le asigna una tarea distinta en el ciclo while.
#### creación de proceso hijo
```c++
pid_t pid = fork();
```
#### asignación de tarea
```c++
if(pid == 0){
    /*calcular numero impar*/
}
else{
    /*calcular sucesion de fibonacci correspondiente*/
}
```
### Calculo
Para ambos casos se utiliza el mismo ciclo while para el calculo de fibonacci o el numero impar.
En el primer caso se utiliza un ciclo for que calcula el numero de fibonacci por cada ciclo del while.
En el segundo se calcula el modulo de 2 del numero actual y si es distin a 0 es impar y se hace lo que corresponda.
### sleep
en ambos casos se hace un sleep de 1 segundo para que el programa no se ejecute tan rapido y sean visible los numeros


```c++
    std::this_thread::sleep_for(std::chrono::seconds(1));
```


