# juego_nim
//UNNIVERSIDAD MESOAMERICANA
//PROGRAMACION I
//PROGRAMADOR: TOMÁS ALEXANDER OTZOY SIQUINÁ            No. CARNÉ 202307032
#include <iostream>
using namespace std;

int x = 3, y = 5, z = 7, ganador, seguir, puntos_1 = 0, puntos_2 = 0;
char jugador1[30], jugador2[30];
void filas(){
	switch(x){
		case 3: cout<<endl<<"		  ***  "; break;
		case 2: cout<<endl<<"		  **   "; break;
		case 1: cout<<endl<<"		  *    "; break;
		case 0: cout<<endl<<"		       "; break;
	default : cout<<endl<<"		  ***  ";
	}
	switch(y){
		case 5: cout<<endl<<"		 ***** "; break;
		case 4: cout<<endl<<"		 ****  "; break;
		case 3: cout<<endl<<"		 ***   "; break;
		case 2: cout<<endl<<"		 **    "; break;
		case 1: cout<<endl<<"		 *     "; break;
		case 0: cout<<endl<<"		       "; break;
	default : cout<<endl<<"		 ***** ";
	}
	switch(z){
		case 7: cout<<endl<<"		*******"; break;
		case 6: cout<<endl<<"		****** "; break;
		case 5: cout<<endl<<"		*****  "; break;
		case 4: cout<<endl<<"		****   "; break;
		case 3: cout<<endl<<"		***    "; break;
		case 2: cout<<endl<<"		**     "; break;
		case 1: cout<<endl<<"		*      "; break;
		case 0: cout<<endl<<"		       "; break;
	default : cout<<endl<<"		*******";
	}
}
void escoger_fila(){	
	int numero_fila = 0, cantidad_retirar;
	cout<<endl<<endl<<"Escoja el numero de fila:"<<endl<<"			   ";
	cin>>numero_fila;
		if(numero_fila > 3){
			cout<<endl<<"El numero de fila que ingreso no es valido, ingrese de nuevo el numero de fila"<<endl;
			escoger_fila();
		}
		else{
		cout<<endl<<"Ingrese la cantidad a retirar:"<<endl<<"				";
		cin>>cantidad_retirar;
	}
	switch(numero_fila){
		case 1: x = x - cantidad_retirar;
					if(x < 0){
						cout<<endl<<endl<<"No puede retirar mas de la cantidad existente"<<endl<<endl;
						x = x + cantidad_retirar;
						filas();
						escoger_fila();
					}
					else{
						ganador = x + y + z;
						if((ganador == 1)||(ganador == 0)){
							break;
						}filas();
					}
			break;
		case 2: y = y - cantidad_retirar;
					if(y < 0){
					 	cout<<endl<<endl<<"No puede retirar mas de la cantidad existente"<<endl<<endl;
						y = y + cantidad_retirar;
						filas();
						escoger_fila();
					}else{
						ganador = x + y + z;
						if((ganador == 1)||(ganador == 0)){
							break;
						}filas();
					}
			break;
		case 3: z = z - cantidad_retirar ;
					if(z < 0){
						cout<<endl<<endl<<"No puede retirar mas de la cantidad existente"<<endl<<endl;
						z = z + cantidad_retirar;
						filas();
						escoger_fila();
					}
					else{
						ganador = x + y + z;
						if((ganador == 1)||(ganador == 0)){
							break;
						}filas();
					}
			break;
	}	
}
bool turnos_jugadores(bool turnos){
	ganador = x + y + z;
	while(turnos == true){			//turno jugador 1
		if(ganador == 1){
			puntos_2 = puntos_2 + 3;
			cout<<endl<<"El ganador es:"<<endl<<"		"<<jugador2<<endl;
			cout<<endl<<" "<<jugador1<<" tiene "<<puntos_1<<" puntos"<<endl;
			cout<<endl<<" "<<jugador2<<" tiene "<<puntos_2<<" puntos"<<endl;
			turnos = false;
			break;
		}
		else if(ganador == 0){
			puntos_1 = puntos_1 + 1;
			puntos_2 = puntos_2 + 1;
			cout<<endl<<"El resultado es un empate cada jugador gana 1 punto"<<endl;
			cout<<endl<<" "<<jugador1<<" tiene "<<puntos_1<<" puntos"<<endl;
			cout<<endl<<" "<<jugador2<<" tiene "<<puntos_2<<" puntos"<<endl;
			turnos = false;
			break;
		}
		else{
			cout<<endl<<endl<<"Es turno es de:"<<endl<<"		"<<jugador1<<endl;
			escoger_fila();
		}							//turno jugador 2
		if(ganador == 1){
			puntos_1 = puntos_1 + 3;
			cout<<endl<<"El ganador es:"<<endl<<"		"<<jugador1<<endl;
			cout<<endl<<" "<<jugador1<<" tiene "<<puntos_1<<" puntos"<<endl;
			cout<<endl<<" "<<jugador2<<" tiene "<<puntos_2<<" puntos"<<endl;
			turnos = false;
			break;
		}
		else if(ganador == 0){
			puntos_1 = puntos_1 + 1;
			puntos_2 = puntos_2 + 1;
			cout<<endl<<"El resultado es un empate cada jugador gana 1 punto"<<endl;
			cout<<endl<<" "<<jugador1<<" tiene "<<puntos_1<<" puntos"<<endl;
			cout<<endl<<" "<<jugador2<<" tiene "<<puntos_2<<" puntos"<<endl;
			turnos = false;
			break;
		}
		else{
			cout<<endl<<endl<<"Es turno es de:"<<endl<<"		"<<jugador2<<endl;
			escoger_fila();
		}
	} return turnos;
}
void seguir_juego(){
		cout<<endl<<"Si desea seguir jugando ingrese 1, si desea acabar ingrese 2:"<<endl<<"								";
		cin>>seguir;
		switch(seguir){
			case 1: x = 3, y =5, z = 7;
					cout<<endl<<"		  ***  ";
					cout<<endl<<"		 ***** ";
					cout<<endl<<"		*******"<<endl;
					turnos_jugadores(true);
					seguir_juego();break;
			case 2: cout<<endl<<"GRACIAS POR JUGAR"; break;
		default: cout<<"El numero que ingreso no es valido"<<endl;
				 seguir_juego();	
	}
}
int main(){
	cout<<endl<<"Ingrese el nombre del primer jugador:"<<endl<<"					";
	cin>>jugador1;
	cout<<endl<<"Ingese el nombre del segundo jugador:"<<endl<<"					";
	cin>>jugador2;
	cout<<endl<<"		  ***  ";
	cout<<endl<<"		 ***** ";
	cout<<endl<<"		*******"<<endl;
	turnos_jugadores(true);
	seguir_juego();
	return 0;
}
