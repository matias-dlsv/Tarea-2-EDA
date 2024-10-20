## Descripcion

**make** -> compila

**make clean** -> borra archivos de compilación. 

**se ejecuta el codigo con **./imagepro**

Las funciones a utilizar son las siguientes: 




## read
se ingresa una imagen junto a un nombre para referenciarla. 
formato: {*NOMBRE*} = read {*PATH*}

## show: 
permite imprimir la imagen. Fue entregada por el profesor. 
formato: show {*NOMBRE*}

## getRegions: 
imprime la cantidad de regiones que tiene la imagen y 
el tamaño de cada una. 
formato: getRegions {**NOMBRE**}


## **ShowRegion**: 
luego de utilizar **getRegions** se obtendra las regiones siento identificadas
con un numero (1,2,3...). Para imprimir una region se debe usar 'ShowRegion', nombre de imagen el numero de region a imprimir. 

formato: ShowRegion {*NOMBRE*} {*NUMERO_DE_REGION*} 

## Exit
termina el programa. 



## ejemplo completo
 >im1 = read images/image_1.bmp
 
 *Imagen cargada exitosamente.*
 
 >show im1
 
 0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000111111000000000000000000000000000111110000000000000
0000000000011111111111000000000000000000000111111111100000000000
0000000001111111111111100000000000000000011111111111111000000000
0000000011111111111111111000000000000000111111111111111100000000
0000000111111111111111111000000000000001111111111111111110000000
0000001111111111111111111100000000000011111111110111111111000000
0000011111111111111111111110000000000111111111111111111111100000
0000011111111111111111111110000000000111111111111011111111100000
0000111111111111111111111111000000001111111111111111111111110000
0000111111111111111111111111000000001111111111111111111111110000
0000111111111111111111111111000000001111111111111111111111110000
0000111111111111111111111111000000001111111111111111111111110000
0000111111111111111111111111100000001111111111111111111111110000
0000111111111111111111111111000000001111111111111111111111110000
0000111111111111111111111111000000001111111111111111111111110000
0000111111111111110111111111000000001111111111111111111111110000
0000111111111111111111111111000000001111111111111111111111110000
0000011111111111111111111111000000000111111111111111111111111000
0000011111111111111111111110000000000110000001111111111111111000
0000001111111111111111111100000000000010000001111111111111100000
0000000111111111111111111100000000000010000101010010001111000000
0000000011111111111111111000000000000000000100001000001110000000
0000000001111111111111110000000000000000111111111111111000000000
0000000000111111111111000000000000000000001111111111110000000000
0000000000000111111100000000000000000000000011111110000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
 
 >getRegions im1

*Region 1 -> size 481*

*Region 2 -> size 446*
 
 
 >ShowRegion im1 1

0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000111111000000000000000000000000000000000000000000000
0000000000011111111111000000000000000000000000000000000000000000
0000000001111111111111100000000000000000000000000000000000000000
0000000011111111111111111000000000000000000000000000000000000000
0000000111111111111111111000000000000000000000000000000000000000
0000001111111111111111111100000000000000000000000000000000000000
0000011111111111111111111110000000000000000000000000000000000000
0000011111111111111111111110000000000000000000000000000000000000
0000111111111111111111111111000000000000000000000000000000000000
0000111111111111111111111111000000000000000000000000000000000000
0000111111111111111111111111000000000000000000000000000000000000
0000111111111111111111111111000000000000000000000000000000000000
0000111111111111111111111111100000000000000000000000000000000000
0000111111111111111111111111000000000000000000000000000000000000
0000111111111111111111111111000000000000000000000000000000000000
0000111111111111110111111111000000000000000000000000000000000000
0000111111111111111111111111000000000000000000000000000000000000
0000011111111111111111111111000000000000000000000000000000000000
0000011111111111111111111110000000000000000000000000000000000000
0000001111111111111111111100000000000000000000000000000000000000
0000000111111111111111111100000000000000000000000000000000000000
0000000011111111111111111000000000000000000000000000000000000000
0000000001111111111111110000000000000000000000000000000000000000
0000000000111111111111000000000000000000000000000000000000000000
0000000000000111111100000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000

>exit

