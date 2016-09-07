//////////////////////////////////////
//Univerisidad del Valle de Guatemala
//ALgortimos y estructura de Datos
//Proyeccto Semestral
//Erick Bautista 15192
//Gerardo Molina 14492
//Diego Lopez 141222
//////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Librerias a Utilizar
////////////////////////////////////////////////////////////////////
#include "abdrive.h"
#include "simpletools.h"
#include "ping.h"                      

////////////////////////////////////////////////////////////////////
//Variables a Utilizar
////////////////////////////////////////////////////////////////////

int adelante;
int derecha;
int derecha2;
int Stack[100];
int chock;
int chock2;
chock=0;
chock2=0;


////////////////////////////////////////////////////////////////////
//Funciones de movimiento
////////////////////////////////////////////////////////////////////
 

void Centro();

////////////////////////////////////////////////////////////////////
//Inicio del Main
////////////////////////////////////////////////////////////////////



void Centro()
{   
chock=0;
  while(chock==0)
{
   
  // adelante=ping_cm(8); 
    derecha=ping_cm(2);
    derecha2=ping_cm(10);
 
  if (derecha2<derecha)
  {
    drive_speed(0,0);
    drive_goto(1,0);
    
  } 
  
  if (derecha2>derecha)
  {
    drive_speed(0,0);
    drive_goto(0,1);
    
  } 
  if (derecha2==derecha)
  {
  chock=1;
  }
}  
}


void main(){
  pause(2000);
  while(1)
  {
    
    //analisis
    adelante=ping_cm(8); 
    derecha=ping_cm(2);
    derecha2=ping_cm(10);
    
    //condicional derecha
   // if (derecha2<4 && derecha<4)
    if (derecha<4)
    {
      if (adelante>5)
        {
          Centro();
          drive_speed(64,64);
        }
        
      else if (adelante<5)
      {
      
      drive_speed(0,0);
      Centro();
      drive_goto(-26,27);
      
      }           
    }
    
    
    //condicional antes de giro
    if (derecha2<4 && derecha>4)
    {
      chock2=0;
      while(chock2==0)
      {
          drive_goto(5,5);
          derecha=ping_cm(2);
          derecha2=ping_cm(10);
          if (derecha2>4)
          {   
             drive_speed(0,0);
             drive_goto(8,8);  
             chock2=1;   
          }        
      }    |
      
    }        
    //Giro
    if (chock2==1)
    {
       drive_speed(0,0);
       drive_goto(6,6);
       drive_goto(27,-26);                                                                                                                                                                                               
       drive_goto(20,20);      
    }      
    
    
 }   

}

  