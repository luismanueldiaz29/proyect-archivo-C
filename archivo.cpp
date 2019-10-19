#include <iostream>
#include <fstream>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;
  char cod[10];
  char ape[20];
  char nom[20];
  char mat[20];
  char servicio[30];
  char costo[20];
  int suma=0;
  int promedio[100];
  int i=0;
char est[20];
void ingresar();
void eliminar();
void individual();
void general();
void modificar();
void salir();
void menu();
//Variables Globales

int auxcod=0;
long codi=atol(cod);
bool encontrado=false;

void ingresar(){
	char op='S';
	while(op=='S'){
    ofstream escritura;
    ifstream consulta;
    bool repetido=false;
    escritura.open("salon de bellesa.txt",ios::out|ios::app);
    consulta.open("salon de bellesa.txt",ios::in);
    if(escritura.is_open() && consulta.is_open()){
        system("cls");
     cout<<"\nDATOS DEL CLIENTE"<<endl;
     cout<<endl;
     fflush(stdin);
     cout<<"CEDULA: ";
        cin>>auxcod;
        consulta>>codi;
        while(!consulta.eof()){
            consulta>>ape>>nom>>servicio>>costo>>promedio[i];
          
            if(codi==auxcod){

                cout<<"LA CEDULA DIJITADA YA EXISTE, ASEGURECE DE ESCRIBIR BIEN"<<endl;
                repetido=true;
                break;
            }
            consulta>>codi;
        }
        if(repetido==false){
        	fflush(stdin);
cout<<"APELLIDO: ";
cin>>ape;
fflush(stdin);
cout<<"NOMBRE: ";
cin>>nom;
fflush(stdin);
cout<<"SERVICIO: ";
cin>>servicio;
fflush(stdin);
cout<<"COSTO: ";
cin>>costo;
suma=suma+atol(costo);
promedio[i]=(atol(costo)*100)/suma;
i++;
escritura<<auxcod<<" "<<ape<<" "<<nom<<" "<<" "<<servicio<<" "<<costo<<" "<<promedio[i]<<endl;
            cout<<"AGREGADO..."<<endl;
        }
    }else{
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }
    escritura.close();
    consulta.close();
    do{
cout<<endl;
cout<<"AGREGAR OTRO ARCHIVO (S) O (N)"<<endl;
op=getch();
op=toupper(op);
 
}while(op!='S'&& op!='N');
}
}//Fin funcion ingresar


void general(){
	char op='S';
        int a;
          while(op=='S')
          {
          	   system("CLS");
               cout<<"\n\n\t1.) Consulta general";
               cout<<"\n\n\t2.) Salir "<<endl;
               cout<<endl;
               cout<<"          Elija su opcion del 1 al 2: ";
               cin>>a;
               cout<<endl;
               switch(a)
            {
                  case 1:
                         while(op=='S')
                    {
    ifstream lectura;
    lectura.open("salon de bellesa.txt",ios::out|ios::in);
    if(lectura.is_open()){
        cout<<"SALON DE BELLESA.txt"<<endl;
        cout<<"________________________________"<<endl;
        lectura>>codi;
        while(!lectura.eof()){
            lectura>>ape>>nom>>servicio>>costo>>promedio[i];
            
            cout<<"CEDULA: "<<codi<<endl;
            cout<<"APELLIDO: "<<ape<<endl;
            cout<<"NOMBRE: "<<nom<<endl;
            cout<<"MATERIA: "<<mat<<endl;
            cout<<"COSTO: "<<costo<<endl;
            cout<<"EL PROMEDIO DE GANACIAS ES DE: "<<promedio[i]<<"%"<<endl;
            lectura>>codi;
            cout<<"________________________________"<<endl;
        }
    }else{
        cout<<"LO SIENTO, NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }
    lectura.close();
                                            cout<<endl;
                                           cout<<"\n\tPRESIONE UNA TECLA PARA SALIR ";
                                           system("PAUSE");
                                          
                                           do{
                                        system("CLS");
                                         cout<<"\n\tSEGUIR EN LA CONSULTA GENERAL (S) O (N): ";
                                        cin>>op;
                                        op=toupper(op);
                               }while((op!='S')&&(op!='N'));
                          
            break;
    }

        case 2:
        break;
        
        do{
           system("PAUSE");
           cout<<"SEGUIR EN EL SUBMENU... (S) O (N): ";
           op=getch();
           op=toupper(op);
           }while(op!='S'&&op!='N');
      }
  }
}//Fin funcion consultas

void individual(){
	char op='S';
        int a;
          while(op=='S')
          {
               system("CLS");
               cout<<"\n\n\t1.) Consulta individual";
               cout<<"\n\n\t2.) Salir "<<endl;
                cout<<endl;
               cout<<"          Elija su opcion del 1 al 2: ";
               cin>>a;
               switch(a){
case 1:
                long ced,codi;
                while(op=='S')
                     {
            system("CLS");
    ifstream lectura;//Creamos la variable de tipo lectura
    lectura.open("estudiante.txt",ios::out|ios::in);//Abrimos el archivo
    //validando la apertura del archivo
    encontrado=false;
    if(lectura.is_open()){
        cout<<"Ingresa el codigo del estudiante que deseas Buscar: ";
        cin>>auxcod;
        lectura>>cod;//lectura adelantada
 
               
        while(!lectura.eof()){
            lectura>>ape>>nom>>servicio>>costo>>promedio[i];//leyendo los campos del registro
            //Comparar cada registro para ver si es encontrado
            codi=atol(cod);
            if(auxcod==codi){
                cout<<"______________________________"<<endl;
               cout<<"CEDULA: "<<codi<<endl;
            cout<<"APELLIDO: "<<ape<<endl;
            cout<<"NOMBRE: "<<nom<<endl;
            cout<<"SERVICIO: "<<servicio<<endl;
            cout<<"COSTO: "<<costo<<endl;
            cout<<"EL PROMEDIO DE GANANCIAS ES DE: "<<promedio<<"%"<<endl;
                cout<<"______________________________"<<endl;
                encontrado=true;
            }

            lectura>>cod;//lectura adelantada
        }
        if(encontrado==false){
        	cout<<endl;
            cout<<"NO EXISTE EL REGISTRO DEL CLIENTE"<<auxcod<<endl;
        }
    }else{
    	cout<<endl;
        cout<<"NO SE A CREADO EL REGISTRO DEL CLIENTE"<<endl;
    }
    //cerrando el archivo
    lectura.close();

                           cout<<endl;
                           cout<<"PRESIONE UNA TECLA PARA CONTINUAR"<<endl;
                           system("PAUSE");
                           break;
}
               
                do{
                   system("CLS");
                   cout<<endl;
                   cout<<"\n\tSEGUIR EN LA CONSULTA INDIVIDUAL (S) O (N): "<<endl;
                   op=getch();
                   op=toupper(op);
                   }while(op!='S'&&op!='N');
                      
             break;
              case 2:
        break;
        }
        do{
           system("PAUSE");
           cout<<endl;
           cout<<"SEGUIR EN EL SUDMENU CONSULTA (S) O (N): ";
           op=getch();
           op=toupper(op);
           }while(op!='S'&&op!='N');
          }
}
void modificar(){
	  char auxcod[10];  
  char auxnom[10];
  char auxape[20];
  char auxser[20];
  char auxcos[20];
  float auxprom;  
  int auxsum;
  
  char auxcod_est[10];
           char op='S';
          while(op=='S')
          {
			    fstream aux;
			    ifstream lectura;
			    bool encontrado=false;
			    char auxcod_est[10];
			    char auxNombre[30];
			    
			    aux.open("auxiliar.txt",ios::out);
			    lectura.open("salon de bellesa.txt",ios::in);
			    
			    if(aux.is_open() && lectura.is_open()){
			    	system("CLS");
			    	cout<<endl;
			        cout<<"INGRESA LA CEDULA DEL CLIENTE AL CUAL QUIERE MODIFICAR SUS DATOS: ";
			        cin>>auxcod_est;
			        lectura>>cod;
			        
			        while(!lectura.eof()){
			            lectura>>ape>>nom>>servicio>>costo>>promedio[i];
			            
			            if (strcmp(cod,auxcod_est)==0){
			                encontrado=true;
			                strcpy(auxcod,cod);
			                strcpy(auxape,ape);
							strcpy(auxnom,nom);
							strcpy(auxser,servicio);
							strcpy(auxcos,costo);
							auxprom=promedio[i];
							
			               	cout<<endl;
			               	cout<<"CEDULA: "<<cod<<endl;
							cout<<"APELLIDOS: "<<ape<<endl;			                 
			               	cout<<"NOMBRE: "<<nom<<endl;
                           	cout<<"SERVICIO: "<<servicio<<endl;
                           	cout<<"COSTO:"<<costo<<endl;
                           	cout<<"PROMEDIO DE GANACIA ES DE"<<promedio<<"%";
			            	cout<<endl;	
			            	
			            	char a;
			            	cout<<endl;
			            	cout<<"\n(S) PARA MODIFICAR APELLIDOS";
			            	cout<<"\n(N) PARA PASAR A LA SIGUIENTE OPCION";
			            	a=toupper(getch());
			            	
							if(a=='S')	{
							        	cout<<"INGRESA EL NUEVO APELLIDO\n";
			                			cin>>auxape;
							}	            
                            cout<<endl;
			                cout<<"\n(S) PARA MODIFICAR EL NOMBRE DEL CLIENTE";
			            	cout<<"\n(N) PARA PASRA A LA SIGUIENTE OPCION";
			            	a=toupper(getch());
							if(a=='S')	{
							        	cout<<"INGRECE EL NUEVO NOMBRE DEL ESTUDIANTE\n";
			                			cin>>auxnom;
							}	            
                             cout<<endl;
			            	cout<<"\n(S) PARA MODIFICAR EL TIPO DE SERVICIO DEL CLIENTE";
			            	cout<<"\n(N) PARA PASAR A LA SIGUIENTE OPCION";
							if(a=='S')	{
							        	cout<<"INGRECE EL SERVICIO QUE SE LE OFRECIO\n";
			                			cin>>auxser;
							}	            
                            cout<<endl;
			            	cout<<"\n(S) PARA MODIFICAR EL COSTO";
			            	cout<<"\n(N) PARA PASAR A LA SIGUIENTE OPCION";
			            	a=toupper(getch());
							if(a=='S')	{
							        	cout<<"INGRESA EL COSTO VERDADERO";
			                			cin>>auxcos;
							}	            
                            auxprom=(atol(auxcos)*100)/suma;
                            
			                aux<<auxcod<<" "<<auxape<<" "<<auxnom<<" "<<auxser<<" "<<auxcos<<" "<<auxprom<<endl;
			                cout<<"Registro Modificado"<<endl;
			               }else{
			                aux<<cod<<" "<<ape<<" "<<nom<<" "<<servicio<<" "<<costo<<" "<<promedio<<endl;
			            }
			            lectura>>cod;	            			               
			            if (lectura.eof()) break;
			        }
			    }else{
			        cout<<"EL ARCHIVO AUN NO A SIDO CREADO..."<<endl;
			    }
			    
			    if(encontrado==false){
			        cout<<"NO SE ENCONTRO NINGUN REGISTRO QUE TENGA ESA CEDULA"<<auxcod_est<<endl;
			        system("pause");
			    }
			    
			    aux.close();
			    lectura.close();
			    remove("salon de bellesa.txt");
			    rename("auxiliar.txt","salon de bellesa.txt");
					
           		do{
                 system("CLS");
                  cout<<"\n\tDESEA MODIFICAR OTRO REGUISTRO (S) O (N) : ";
                 cin>>op;
                 op=toupper(op);
             	}while(op!='S'&&op!='N');
                       
          }  
  }

	
void eliminar(){
		char op='S';
       while(op=='S')
       {
       	system("CLS");
 ofstream aux;
    ifstream lectura;
    encontrado=false;
    int auxcod=0;
    char auxape[30];
    aux.open("auxiliar.txt",ios::out);
    lectura.open("salon de bellesa.txt",ios::in);
    if(aux.is_open() && lectura.is_open()){
        cout<<"INGRESA LA CEDULA DEL CLIENTE QUE QUIERE ELIMINAR: ";
        cin>>auxcod;
        lectura>>codi;  //hacemos una lectura adelantada
        while(!lectura.eof()){
            lectura>>ape>>nom>>servicio>>costo>>promedio[i];
            if(auxcod==codi){
                encontrado=true;
                cout<<"__________________________"<<endl;
                cout<<"CEDULA: "<<codi<<endl;
            cout<<"APELLIDO: "<<ape<<endl;
            cout<<"NOMBRE: "<<nom<<endl;
            cout<<"SERVICIO: "<<servicio<<endl;
            cout<<"COSTO: "<<costo<<endl;
            cout<<"EL COSTO REPRESENTA EL "<<promedio<<"%";
                cout<<"__________________________"<<endl;
                cout<<"**ELIMINADO"<<endl;
            }else{
                aux<<codi<<" "<<ape<<" "<<nom<<" "<<servicio<<" "<<costo<<" "<<promedio<<endl; //cuando no sea igual que lo vaya copiando
            }
            lectura>>codi;
        }
    }else{
        cout<<"EL ARCHIVO AUN NO A SIDO CREADO"<<endl;
    }
    if(encontrado==false){
        cout<<"NO SE ENCONTRO NINGUN REGUISTRO CON LA CLAVE "<<auxcod<<endl;
    }
    aux.close();
    lectura.close();
    remove("salon de bellesa.txt");
    rename("auxiliar.txt","salon de bellesa.txt"); 
               system("PAUSE");
        do
        {
        system("CLS");
         cout<<"\n\tELIMINAR OTRO REGUISTRO (S) O (N): ";
         cin>>op;
        op=toupper(op);
        }while(op!='S'&&op!='N');
       }
}//fin eliminar 

void salir(){
    cout<<"PROGRAMA FINALIZADO... GRACIAS"<<endl;
}

int main(){
    menu();
    return 0;
    system("PAUSE");
}

void menu_menu(){	
    cout<<"\n\tREGISTRO DE UN SALON DE BELLESA  "<<endl;
    cout<<"\n\n\t\t**MENU**";
    cout<<"\n\n\t1.) INGRESAR";
    cout<<"\n\t2.) CONSULTA GENERAL";
    cout<<"\n\t3.) CONSULTA INDIVIDUAL";
    cout<<"\n\t4.) MODIFICAR ALGUN DATO";
    cout<<"\n\t5.) ELIMINAR REGUISTRO";
    cout<<"\n\t6.) SALIR";
}

void menu(){
    int opcion=0;
    do{
    	system("cls");
    	cout<<endl;
    	menu_menu();
        cout<<endl;
        cout<<"\n\tDIGITE UNA OPCION... ";
        cin>>opcion;
        switch(opcion){
            case 1:
                ingresar();
            break;
            case 2:
                general();
            break;
            case 3:
                individual();
            break;
            case 4:
                modificar();
            break;
            case 5:
                eliminar();
            break;
            case 6:
                salir();
            break;
            default:
                cout<<"INCORRECTO...";
        }
    }while(opcion!=6);
}//Fin funcion menu

