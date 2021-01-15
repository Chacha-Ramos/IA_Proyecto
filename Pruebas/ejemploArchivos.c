#include<stdio.h>
#include<stdlib.h>


int main(){
	FILE *archivo=NULL;
	//Se abre un archivo ubicado en la misma localidad que el ejecutable y se abre en modo lectura.
	//w+ abre el archivo destruyendo el contenido anterior
	archivo=fopen("archivo.txt","w+");
	char *buffer=(char *)malloc(sizeof(char)*1024);
	if(archivo==NULL || buffer==NULL){
		puts("No es posible continuar por un error en el archivo o en la memoria dinamica");
		exit(1);
	}
	//Escribir contenido en el archivo:
	//Guardar una matriz(arreglo de dos dimensiones) de 10x10 que almacene el número de su posición 0...99   :  [0-9], [10-19], [20-29...]
	int fila, columna, contadorPos=0;
	for(columna=0; columna<10; columna++){
		for(fila=0; fila<10; fila++)
			fprintf(archivo, "%d\t",contadorPos++);
		fputc('\n',archivo);
	}
		
	rewind(archivo); //rebobinar al cursor para posicionarlo al inicio del archivo e inmediatamente leerlo
	puts("El archivo se abrio de manera exitosa y se reservo adecuadamente la memoria");
	//A través de un ciclo iterativo se recorren las lineas del archivo
	//!feof(archivo)
	//feof(archivo)==0
	//fgets(buffer,sizeof(char)*1024,archivo)!=NULL
	while(fgets(buffer,sizeof(char)*1024,archivo)!=NULL){
		//fgets(buffer,sizeof(char)*1024,archivo);  //Lee una linea y mueve el cursor a la siguiente.
		printf("La linea del archivo es: %s",buffer);
	}
	
	//Para asegurarnos la liberación de recursos cerramos los flujos de memoria y archivos
	fclose(archivo);
	free(buffer);
}

