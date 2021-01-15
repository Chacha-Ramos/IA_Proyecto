#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

 typedef struct 
   {
       int size;    //Tamaño de archivo
       uint16_t caracteristicaAdicional;
       uint16_t reservadoCopia;
       int offSet; //variable que almacena la posicion inicial de los datos
   } CabeceraImg;
   
   typedef struct 
   {
       int tamCabecera; //Tamaño de la estructura de informacion de la cabeceraImg
       int ancho;
       int alto;    //Se resguarda ancho y alto de la imagen
       uint16_t planos; //Cantidad de planos que contiene la imagen (planos de color)
       uint16_t bpp;    //Cantidad de bits por pixel
       int compresion;  //Informacion sobre la compresión 
       int imgSize; //Tamaño real de la imagen ancho*alto
       int resX;    //Resolución de la imagen en el eje horizontal
       int resY;    //Resolución de la imagen en el eje vertical
       int coloresR;    //Rango de colores posibles 2^bpp
       int imxColores;  //Rango inicial de colores
   } imagen;
   
unsigned char *cargaImagenFile(char *filename, imagen *matrizImagen)
{
    FILE *fileImagen;
    CabeceraImg infoImg;
    unsigned char *imgData;     //Los pixeles como arreglo de caracteres
    uint16_t type;

    //Apertura del archivo de imagen 
    fileImagen=fopen(filename, "r");
    if(!fileImagen)
    {
        return NULL;
    }

    fread(&type, sizeof(uint16_t),128, fileImagen);

    if(type!=0x4D42) 
    {
        fclose(fileImagen);
        return NULL;
    }
}

void main(){
    
}