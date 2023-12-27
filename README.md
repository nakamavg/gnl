# gnl

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
