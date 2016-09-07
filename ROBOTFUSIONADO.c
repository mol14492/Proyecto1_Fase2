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
//Funciones de movimiento
////////////////////////////////////////////////////////////////////
 
 void GDerecha(); 
 void GIzquierda();

 void Adelante();
  void Adelante2();
 void Paro();
 void Paso();
 void PreAnalizar();
 void Analizar();
 
 void Centro();
 
/////////////////////////////////////////////////////////////////////
//Declaracion de Variables
/////////////////////////////////////////////////////////////////////
 
 int DisNorte;
 int DisEste;
 int DisEste2;
 int Analisis[4];
 int DisPared;
 int variable;
 int chock;
 int chock2;
 chock=0;
 chock2=0;
 DisPared=7;
 
 
/////////////////////////////////////////////////////////////////////
//Declaracion de funciones 
/////////////////////////////////////////////////////////////////////

void  GDerecha()
{//90 grados a la derecha
  drive_speed(0,0);
	drive_goto(27,-26); //cambie -26 por -25 por que asi lo indica el manual    
}

void GIzquierda()
{//90 grados a la izquierda
   drive_speed(0,0);
   drive_goto(-26,27);//cambie -26 por -25 por que asi lo indica el manual 
}

void Adelante()
{
   Analizar();
 
   
  if (DisNorte>6)
   {
     drive_goto(21,21);// para 7(21) centrimetros 
    }  
}

void Paro()
  {
  drive_speed(0,0);
  }
  
void Paso()
  { 
    Analizar();
   variable=DisEste2;
   if (Analisis[0]==7)
   {
      drive_goto(variable+15,variable+15);//el bueno era 30
   }   
  }
  
void PreAnalizar()
{
  DisNorte=ping_cm(8);
  DisEste2=ping_cm(10);
  DisEste=ping_cm(2);
}

void Centro()
{
  chock=0;
  while(chock==0)
  {
   
     // adelante=ping_cm(8); 
        DisEste=ping_cm(2);
        DisEste2=ping_cm(10);
 
       if (DisEste2<DisEste)
       {
           drive_speed(0,0);
           drive_goto(1,0);  
        } 
        if (DisEste2>DisEste)
        {
          drive_speed(0,0);
          drive_goto(0,1);
          } 
        if (DisEste2==DisEste)
       {
           chock=1;
       }
  }  
   
}

void Analizar()
{
  PreAnalizar();

    if(DisNorte<=DisPared)
      {
        Analisis[0]=6;
      }
      else
      {
        Analisis[0]=7; 
      }  
       if(DisEste2<=DisPared)
       {
        Analisis[1]=6;
      }
      else
      {
        Analisis[1]=7; 
      } 
      if(DisEste<=DisPared)
      {
        Analisis[3]=6;
      }
      else
      {
        Analisis[3]=7; 
      }      
  }

void main()
{
  pause(6000);
  while(1)
  {
    Analizar();
    
    if (Analisis[3]==6)
    {  
      	if (Analisis[0]==7)
       {
        Centro();
      	Adelante();
        }
      	else
       {
        	if (Analisis[1]==7)
           { 
           Paso();
        	 GIzquierda();
           Paso();
           if (Analisis[0]==7)
             {
                 //  Centro();
                Adelante();
             }            
        	}
       } 
     }   
   
   
     if (Analisis[3]==7)
     {
        drive_speed(0,0);
        Paso();
    	  GDerecha();
       Paso();
       if (Analisis[0]==7)
       {
          Adelante();
       }          
    }
  }
}
