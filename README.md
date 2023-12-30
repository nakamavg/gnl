# gnl

## Índice

- [Abrir un fichero en c](#abrir-un-fichero-en-c)
- [Leer un fichero en c](#leer-un-fichero-en-c)
- [Main de ejemplo](#main-de-ejemplo)
- [Pruebas antes de entrar en batalla](#pruebas-antes-de-entrar-en-batalla)
- [Empezando por la cabeza](#empezando-por-la-cabeza)
	- [Que es una variable estatica](#que-es-una-variable-estatica)
- [Mas preambulos](#mas-preambulos)
	- [Madre get_next_line](#madre-get_next_line)
	- [`*read_line`](#read_line)


# Pruebas antes de entrar en batalla 

## Abrir un fichero en c 

```c
fd = open("test.txt", O_RDONLY);
```
nos devuelve un Numero >2 si todo ha ido bien 

ya que el 0 es el standar input

y el 1 es el standar output

y el 2 el standar error

## Leer un fichero en c 

```c

 read(fd, buf,5)
```
- Este trozo de codigo lee del fd previamente abierto 5 caracteres y los guarda en el buffer
- read es inteligente y cada llamada a read va a continuar donde lo dejamos 
- read nos devuelve el tamaño de lo leido

## Main de ejemplo

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
	int fd;
	char buf[255];
	int char_read;
	
	fd = open("test.txt", O_RDONLY);
	while(char_read = read(fd, buf,5))
	{
		
		buf[char_read] = '\0';
		printf("buffer-> %s \n", buf);
	}
	return (0);
}
```
- Este pequño main valida que read nos devuelva un tamaño > 0  y seguira iterando hasta no tengamos nada que leer

  salida del output:
  ![image](https://github.com/nakamavg/gnl/assets/7202262/2756bdb1-072a-43c1-9393-a0a764d2632d)

-[subir](#gnl)
# Empezando por la cabeza 

- Nuestras librerias que no deben faltar
	-`stdlib.h` que contiene `malloc` `free` `NULL` `size_t` 
	- `unistd.h` que contiene `write` `read` `close`

- Tambien Definos el tamaño de nuestro buffer 

```c
	# ifndef BUFFER_SIZE
	#  define BUFFER_SIZE 42
	# endif
```
- Con esta macro le decimos al programa que el tamaño que vamos a leer de los fd en cada pasada siempre va a ser 42

- En el la cabecera tambien declaro funciones hechas en libft y que van a estar dentro de el archivo [`get_next_line_utils.c`](get_next_line_utils.c) como `ft_strchr` para buscar el eol o en español salto de linea o `\n` `ft_strlen` para medir longitud de los strings, `ft_strlcpy` que copia caracteres de la cadena `src` en `dst` o `ft_strdup` que alloca memoria dinamicamente a una cadena o `ft_strjoin` que concatena dos cadenas y asigna memoria dinamicamente.

y tambien incluyo la funcion madre de `get_next_line` que se encuentra en el archivo [`get_next_line.c`](get_next_line.c)

-[subir](#gnl)
# Mas preambulos 
## Que es una variable estatica

- Mejor ver algo grafico que mil lineas explicativas antes
```c
#include <stdio.h>

void	prueba(void)
{
	int		cafes0 = 100;
	static int	cafes1 = 100;

	printf("QUEDAN cafes0 = %d, cafes1 = %d\n", cafes0, cafes1);
	cafes0--;
	cafes1--;
}
int main(void)
{
	prueba();
	prueba();
	prueba();
}
```
``` bash
nakama@DESKTOP-FIDJ5EI:~/github/gnl$ ./a.out 
QUEDAN cafes0 = 100, cafes1 = 100
QUEDAN cafes0 = 100, cafes1 = 99
QUEDAN cafes0 = 100, cafes1 = 98
```
- Como se puede ver mientras que la variable cafes0 se queda siempre en 100 en cada llamada a la funcion 
- cafes1 mantiene su valor entre llamadas a la funcion o memoria durante toda la ejecucion del programa

Esto va a ser nuestro buffer una variable de tipo static 

-[subir](#gnl)
# Al Turron 

- Madre get_next_line

```c
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, buf);
	if (!line || ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	prepare_buffer(buf, line, newline);
	return (line);
}
```
- Nuestro buffer vemos que tenemos un tamaño `Buffer_size + 1`
esto es por que aunque leamos siempre el tamaño del buffer tenemos que guardar uno para añadir el caracter `\0`

- Pequeña comprobacion para que nuestra funcion no pete por si nos pasan un fd no valido o un buffersize menor a 0

- guardamos en line lo que nos devuelve la funcion `read_line` 

## `*read_line`

 - Lee una linea de el fd y alloca memoria para el string 
 - fd el archivo de donde se lee la linea.
 - buf la variable donde se guarda lo leido.
 - retorna un puntero a la linea leida, O NULL si hay un error o se ha encontrado con el final del fichero.

- Comprobaciones de si no hay linea o si el tamaño de la linea es 0 

- newline guarda un puntero a la posicion de el salto de linea para preparar el buffer para la siguiente llamada a la funcion
-[subir](#gnl)

# Bonus

La unica diferencia en el aparatado bonus es que nuestro buffer pasara a ser bidimensional  y en la cabecera incluimos una macro para el la cantidad de fd maximos que podemos usar tambien validaremos la cantidad de fd que se le pasan a la funcion sean consecuentes con ese maximo.

```c 
# ifndef OPEN_MAX
#  define OPEN_MAX 512
# endif
```




