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
 void Centro2();
 
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
 int Stack[200];
 int iStack;
 iStack=0;
 chock=0;
 chock2=0;
 DisPared=6;
 
 
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
 
   
  if (Analisis[0]==7)
   {
     drive_goto(21,21);// para 7(21) centrimetros 
    }  
}

//Funcion que detiene robot
void Paro()
  {
  drive_speed(0,0);
  }
  //Funion que da un paso de robot
void Paso()
  { 
    Analizar();
   variable=DisEste2;
   //if (Analisis[0]==7)
   if (DisNorte>8)
   {
      drive_goto(variable*3+10,variable*3+ 10);//el bueno era 30
   }   
  }
  
 //preAnalisis hace analisis de entorno necesario
void PreAnalizar()
{
  DisNorte=ping_cm(8);
  DisEste2=ping_cm(10);
  DisEste=ping_cm(2);
}

//funcion de centrado de robot
void Centro()
{
  chock=0;
  while(chock==0)
  {
   
        DisNorte=ping_cm(8); 
        DisEste=ping_cm(2);
        DisEste2=ping_cm(10);
   // if (DisEste2<15 && DisEste<15)
   // {
       if (DisEste2<DisEste)
       {
           drive_speed(0,0);
           drive_goto(2,0);  
        } 
        if (DisEste2>DisEste)
        {
          drive_speed(0,0);
          drive_goto(0,2);
          } 
        if (DisEste2==DisEste)
       {
           chock=1;
       }
   // }    
  }  
   
}

//otra funcion de centrado de robot
void Centro2()
{
 Analizar();
  if (DisEste2>6){

if (DisNorte>4){
    drive_goto(6,0);
    drive_goto(8,8);
    drive_goto(0,6);
    drive_goto(-8,-8);  
  }
} 
else if(DisEste<3){

  
   if (DisNorte>4){
    drive_goto(0,12);
    drive_goto(8,8);
    drive_goto(12,0);
    drive_goto(-8,-8);
  }
 }  
}

  
//Analisis determinar si existen o no paredes en el entorno
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


//Main es el cerebro de todo el programa
void main()
{
  
  pause(2000);
while(1)
{
	Analizar();
    
    	if (DisNorte<3)
	{
	 	drive_goto(-7,-7); 	
	}

	Analizar();

	if (Analisis[1]==7 && Analisis[3]==6)
	{
		
		if (DisNorte>6)
		{
			drive_goto(16,16);
        Stack[iStack]=1;
        iStack=iStack+1;
		}
	}
	
	else if (Analisis[1]==6 && Analisis[3]==6)
	{	
	 	
    if(DisEste2<8 && DisEste<8)
    {
    Centro();
    }    	
    
     //
     if(DisEste2<3 && DisEste<3)
    {
    Centro2();
    } 
    // 
    
    
    
    
 	if (DisNorte>6)
		{
			drive_goto(16,16);
         Stack[iStack]=1;
         iStack=iStack+1;
		}
	}

	else if (Analisis[1]==6 && Analisis[3]==7)
	{
		
		if (DisNorte>6)
		{
			drive_goto(16,16);
        Stack[iStack]=1;
        iStack=iStack+1;
		}
	}

	else if (Analisis[1]==7 && Analisis[3]==7)
	{
		
		if (DisNorte>5)
		{
			drive_goto(16,16);
        Stack[iStack]=1;
        iStack=iStack+1;
		}

		GDerecha();
  
        Stack[iStack]=3;
        iStack=iStack+1;
		if (DisNorte>5)
		{
			drive_goto(19,19);
         Stack[iStack]=1;
        iStack=iStack+1;
		}
  
    if (DisNorte>7)
		{
			drive_goto(23,23);
         Stack[iStack]=1;
        iStack=iStack+1;
		}
     
     
	 if(DisEste2<8 && DisEste<8)
    {
    Centro();
    } 
    
    //
     if(DisEste2<3 && DisEste<3)
    {
    Centro2();
    } 
    // 
    
    
    
	}
	Analizar();

	if (Analisis[0]==7 && Analisis[1]==7 && Analisis[3]==7)

	{
		GDerecha();
  
        Stack[iStack]=3;
        iStack=iStack+1;

		if (DisNorte>6)
		{
			drive_goto(19,19);
         Stack[iStack]=1;
        iStack=iStack+1;
		}
     if (DisNorte>7)
		{
			drive_goto(23,23);
         Stack[iStack]=1;
        iStack=iStack+1;
		}
	}


	else if (Analisis[0]==6 && Analisis[1]==6 && Analisis[3]==6)
	{
		if (DisNorte<3)
		{
	 		drive_goto(-7,-7); 	
		}	
		
		GIzquierda();
        Stack[iStack]=2;
        iStack=iStack+1;
	}
}

}
