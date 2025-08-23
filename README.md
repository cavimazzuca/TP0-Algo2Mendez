# Consigna

Completar la implementación para que el programa funcione correctamente.
Se provee el archivo **main.c**

# Estructura del archivo

El archivo a leer tiene un formato como se muestra a continuación:

```csv
1,Pikachu,ELEC,55,40,90
2,Charmander,FUEG,52,43,65
3,Bulbasaur,PLAN,49,49,45
4,Squirtle,AGUA,48,65,43
5,Jigglypuff,NORM,45,20,20
```

Donde la primer columna es la ID, la segunda columna es el nombre del pokemon, luego le sigue el tipo y por último 3 números que representan ataque, defensa y velocidad del pokemon.

Los tipos válidos son los siguientes:

| Código | Tipo      |
|--------|-----------|
| ELEC   | Eléctrico |
| FUEG   | Fuego     |
| PLAN   | Planta    |
| AGUA   | Agua      |
| NORM   | Normal    |
| FANT   | Fantasma  |
| PSI    | Psíquico  |
| LUCH   | Lucha     |

# Restricciones

- No se permite el uso de strtok
- No se permite el uso de qsort
- No se permite suponer un largo máximo de línea, debe utilizarse memoria dinámica
- No se permite suponer una cantidad máxima de pokemones
- El programa no debe dejar memoria sin liberar al finalizar
- Se deben saltear las líneas erróneas (cantidad de columnas incorrectas por ejemplo)
- No se permite modificar **tp0.h**
