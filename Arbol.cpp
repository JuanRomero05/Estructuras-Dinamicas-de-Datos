/*	URU - Juan Romero - Estructuras Dinámicas de Datos - Sección: A
	Problema sobre Arbol Binario
	Ejemplo:   		8
			3				10	
		1      6				 14
			4     7          13  
*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//Estructura de un nodo de un arbol binario
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

//Prototipos de funciones
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
void preOrden(Nodo *); //Funciones para recorrer el arbol
void inOrden(Nodo *);
void postOrden(Nodo *);

Nodo *arbol = NULL;	//Puntero del arbol

int main(){
	menu();
	
	getch();
	return 0;
}

//Funcion del menu switch
void menu(){
	int dato, opcion, contador = 0;
	
	do{
		cout<<"\t\t\t\t\t|------------------------------------------------------|\n"<<endl;
		cout<<"\t\t\t\t\t|                     ARBOL BINARIO                    |\n"<<endl;
		cout<<"\t\t\t\t\t|---------------------------|--------------------------|\n"<<endl;
		cout<<"\t\t\t\t\t| 1. Insertar               | 4. Recorrer en InOrden   |\n"<<endl;
		cout<<"\t\t\t\t\t| 2. Mostrar                | 5. Recorrer en PostOrden |\n"<<endl;
		cout<<"\t\t\t\t\t| 3. Recorrer en PreOrden   | 6. Salir                 |\n"<<endl;
		cout<<"\t\t\t\t\t|---------------------------|--------------------------|\n"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
		
			case 1: cout<<"\n Digite un numero: ";
					cin>>dato;
					insertarNodo(arbol, dato);	
					cout<<"\n";
					system("pause");
			break;
			
			case 2: cout<<"\n Mostrando el arbol completo: \n\n";
					mostrarArbol(arbol, contador);
					cout<<"\n";
					system("pause");
			break;
			
			case 3: cout<<"\nMostrando el arbol: \n\n";
					mostrarArbol(arbol, contador);
					cout<<"\n";
					cout<<"\n\n Recorrido en PreOrden: ";
					preOrden(arbol);
					cout<<"\n\n";
					system("pause");
			break;
			
			case 4: cout<<"\nMostrando el arbol: \n\n";
					mostrarArbol(arbol, contador);
					cout<<"\n";
					cout<<"\n Recorrido en InOrden: ";
					inOrden(arbol);
					cout<<"\n\n";
					system("pause");
			break;
			
			case 5: cout<<"\nMostrando el arbol: \n\n";
					mostrarArbol(arbol, contador);
					cout<<"\n";
					cout<<"\n Recorrido en PostOrden: ";
					postOrden(arbol);
					cout<<"\n\n";
					system("pause");
			break;	
			
			case 6: cout<<"\n\n PROGRAMA FINALIZADO...\n\n"<<endl;
					system("pause");
			break; 
			
			default: cout<<"\nOpcion no valida\n\n";
					 system("pause");		
		}
		system("cls");			
	}while(opcion != 6);
}

//Funcion para crear un nuevo nodo 
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo(); //Reservando espacio en memoria
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}

//Función para insertar nodos en el árbol
void insertarNodo(Nodo *&arbol, int n){
	
	if(arbol == NULL){ //Si el arbol está vacio
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}
	else{	//Si el arbol tiene uno o mas nodos
		int valorRaiz = arbol->dato; //Obtenemos el valor de la raiz
		if(n < valorRaiz){	//Si el elemento es menor a la raiz, insertamos en izq
			insertarNodo(arbol->izq, n);
		}
		else{	//Si el elemento es mayor a la raiz, insertamos en der
			insertarNodo(arbol->der, n);
		}
	}
}

//Función para mostrar el arbol completo
void mostrarArbol(Nodo *arbol, int cont){
	
	if(arbol == NULL){	//Si el arbol esta vacio
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

/*	Para recorrer el arbol en la forma de PreOrden, lo recorre así: primero la raíz, 
	luego el sub-árbol izquierdo y por último el sub-árbol derecho
	Secuencia (usando el ejemplo de arriba): 8-3-1-6-4-7-10-14-13
*/
//Funcion para recorrer el árbol en forma de PreOrden
void preOrden(Nodo *arbol){
	
	if(arbol == NULL){	//Si el arbol esta vacio
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

/*	Para recorrer el arbol en la forma de InOrden, lo recorre así: primero el sub-árbol izquierdo, 
	luego la raíz y por último el sub-árbol derecho
	Secuencia (usando el ejemplo de arriba): 1-3-4-6-7-8-10-13-14
*/
//Funcion para recorrer el árbol en forma de InOrden
void inOrden(Nodo *arbol){
	
	if(arbol == NULL){	//Si el arbol esta vacio
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}
}

/*	Para recorrer el arbol en la forma de PostOrden, lo recorre así: primero el sub-árbol izquierdo, 
	luego el sub-árbol derecho y por último la raíz.
	Secuencia(usando el ejemplo de arriba: 1-4-7-6-3-13-14-10-8
*/
//Funcion para recorrer el árbol en forma de PostOrden
void postOrden(Nodo *arbol){
	
	if(arbol == NULL){	//Si el arbol esta vacio
		return;
	}
	else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}
