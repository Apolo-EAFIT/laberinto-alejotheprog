#include <iostream>
using namespace std;

char M[36][36];
int dr[] = {-1,1,0,0}; // estos dos arreglos se encargan de recorreme la matriz arriba, abajo, derecha e izquerda, ya que se supone que
int dc[] = {0,0,-1,1}; // no puedo atravezar paredes en diagonal, y no tener que estar poniendo M[i-1]M[j+1] ... lo saque del libro

void floodfill(int r,int c, int tam){
  if(r < 0 || r >= tam || c < 0 || c >= tam) return; 
  if(M[r][c] != '.') return;  // se encarga pintarme los nodos alcanzables desde la raiz; 
  M[r][c] = 'v';              //sacado del libro pag  125
  for(int d = 0; d < 4;d++){
     floodfill(r + dr[d], c + dc[d],tam);
  }
  return;
}

void contarParedes(int tam){
  int cont = 0;
  for(int i = 0; i < tam;i++){   // se encarga de revisar si es una 'v' y en caso de que lo sea, cuenta 4 lados, y si hay una pared
    for(int j = 0; j < tam; j++){ // aumenta uno al contador
      if(M[i][j] == 'v'){
	
	for(int k = 0; k < 4; k++){
	  if(M[i+dr[k]][j+dc[k]] != 'v'){
	    cont++;
	  }
	}
	
      }
    }
  }
  cout << (cont - 4) * 9;
}

int main (){
  
  int tam, cont = 0;
  string in;
  
  cin >> tam;
  getline(cin,in);
  
  for(int k = 0; k < tam;k++ ){
    getline(cin,in);
    for(int i = 0; i < in.size();i++){
      M[cont][i] = in[i];  // guarda la matriz desde M[0][0]
    }
    
    cont++;
    
  }

  floodfill(0,0,tam);
  if(M[tam-1][tam-1] != 'v') // si desde el inicio no llegue a la salida
    floodfill(tam-1,tam-1,tam); // corro el algoritmo desde el mismo
  
  contarParedes(tam);
  
  return 0;
}
