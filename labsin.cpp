#include <iostream>
using namespace std;

char M[36][36];
int dr[] = {-1,1,0,0}; 
int dc[] = {0,0,-1,1}; 

void floodfill(int r,int c, int tam){
  if(r < 0 || r >= tam || c < 0 || c >= tam) return; 
  if(M[r][c] != '.') return;  
  M[r][c] = 'v';              
  for(int d = 0; d < 4;d++){
     floodfill(r + dr[d], c + dc[d],tam);
  }
  return;
}

void contarParedes(int tam){
  int cont = 0;
  for(int i = 0; i < tam;i++){  
    for(int j = 0; j < tam; j++){ 
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
      M[cont][i] = in[i];
    }
    
    cont++;
    
  }

  floodfill(0,0,tam);
  
  if(M[tam-1][tam-1] != 'v')
  floodfill(tam-1,tam-1,tam);
  
  contarParedes(tam);
  
  return 0;
}
