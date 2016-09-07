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
 int DisSur;
 int DisOeste;
 int DisNorte2;
 int DisEste2;
 int DisSur2;
 int DisOeste2;
 int Analisis[4];
 int DisPared;
 int Switch;
 int variable;
 Swith=1;
 
 DisPared=7;
 
 
/////////////////////////////////////////////////////////////////////
//Declaracion de funciones 
/////////////////////////////////////////////////////////////////////

void  GDerecha(){//90 grados a la derecha
  drive_speed(0,0);
	drive_goto(27,-26); //cambie -26 por -25 por que asi lo indica el manual 
    
}

void GIzquierda(){//90 grados a la izquierda
   drive_speed(0,0);
 drive_goto(-26,27);//cambie -26 por -25 por que asi lo indica el manual 
}

void Adelante(){
 Analizar();
 //if (Analisis[0]==7){
   if (Switch==0){
   
 if (DisNorte>6){
 drive_goto(21,21);// para 7(21) centrimetros 
}  
}

 if (Switch==1){
   
 if (DisNorte2>6){
 drive_goto(21,21);// para 7(21) centrimetros 
}  
}

}

void Adelante2(){
 Analizar();
 if (Analisis[0]==7){
 drive_goto(15,15);// para 7(21) centrimetros 
}  
}

void Paro(){
drive_speed(0,0);
}
  
void Paso(){
  
  Analizar();
  if(Switch==0){
 variable=DisEste2;
 if (Analisis[0]==7){
   drive_goto(variable+15,variable+15);//el bueno era 30
 }   
 
}
else{
 variable=DisEste;
 if (Analisis[0]==7){
   drive_goto(variable+15,variable+15);//el bueno era 30
 }   
  
}  
}
  
void PreAnalizar(){
if (Swith==1){
DisNorte=ping_cm(8);
DisOeste=ping_cm(10);
DisSur=20;
DisEste=ping_cm(2);
Switch=0;
}
else{
DisNorte2=ping_cm(8);
DisOeste2=ping_cm(10);
DisSur2=20;
DisEste2=ping_cm(2);
Switch=1;
}
}

void Centro()
{
  
  if (Switch==0){
    
if (DisEste>6){

if (DisNorte>4){
    drive_goto(6,0);
    drive_goto(8,8);
    drive_goto(0,6);
  }
} 
else if(DisEste<3){

  
   if (DisNorte>4){
    drive_goto(0,12);
    drive_goto(8,8);
    drive_goto(12,0);
  }
 }
}
 if (Switch==1){
if (DisEste2>6){

if (DisNorte2>4){
    drive_goto(12,0);
    drive_goto(8,8);
    drive_goto(0,12);
  }
} 
else if(DisEste2<3){
  
 
   if (DisNorte2>4){
    drive_goto(0,12);
    drive_goto(8,8);
    drive_goto(12,0);
  }
  } 
 }
}  

void Analizar(){
PreAnalizar();

if (Switch==0){
if(DisNorte<=DisPared){
    Analisis[0]=6;
  }
  else{
    Analisis[0]=7; 
  }
  
  if(DisOeste<=DisPared){
    Analisis[1]=6;
  }
  else{
    Analisis[1]=7; 
  }
  
  if(DisSur<=DisPared){
    Analisis[2]=6;
  }
  else{
    Analisis[2]=7; 
  }
  
  if(DisEste<=DisPared){
    Analisis[3]=6;
  }
  else{
    Analisis[3]=7; 
  }
}

//
if (Switch==1){
if(DisNorte2<=DisPared){
    Analisis[0]=6;
  }
  else{
    Analisis[0]=7; 
  }
  
  if(DisOeste2<=DisPared){
    Analisis[1]=6;
  }
  else{
    Analisis[1]=7; 
  }
  
  if(DisSur2<=DisPared){
    Analisis[2]=6;
  }
  else{
    Analisis[2]=7; 
  }
  
  if(DisEste2<=DisPared){
    Analisis[3]=6;
  }
  else{
    Analisis[3]=7; 
  }
}
//

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
      //Centro();
      	Adelante();
        }
      	else
       {
        	if (Analisis[1]==7)
         {
          //
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
   if (Analisis[3]==7){
     drive_speed(0,0);
      Paso();
    	GDerecha();
     Paso();
      if (Analisis[0]==7)
          {
           Adelante();
           
         }          
    }
   if (Analisis[3])
   }
}
 