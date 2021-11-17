# SSOO-tarea02

## AUTOR

lukas Pinto <lukas.pinto@alumnos.uv.cl>

    
## Diseño de solución

En este caso la solución consta del uso de los comandos curl y jq.
En el caso del comando curl se utiliza este para descargar los datos y para luego para extraer lo solicitado se le entrega el resultado a traves de pipe line al comando jq.


### utilizacion del comando jq
Al comando jq se le entrega los parametos .[] el cual extrae los datos del arreglo json, luego se crea el objeto "payload" al igual que el archivo original y dentro de "payload", se crea otro objeto llamado "items" que contiene el array con los atributos requeridos.
dentro del objeto items, se introducen los atributos id e item_name a través del coamando map().
por ultimo una vez listo todo esto se le indica a la consola que rediriga al archivo items.json el resultado, y de no existir, se crea este archivo.

en el caso del pid este se obtiene a través de $$ el cual entrega el pid del proceso actual.
### verificacion
para verificacion se utiliza un if que evalua la variable $? el valor de ejecucion del ultimo comando del script
si este es igual a 0, el comando se ejecutó exitosamente.
