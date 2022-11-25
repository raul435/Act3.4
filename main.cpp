//Act 3.4
//A01742153 - José Raúl Arredondo López
//A01742439 - Ximena Aleciram Castañeda Cañedo

//complejidad 0(n)

#include "arbol.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "linkedlist.h"

using namespace std;

void conversionLong(dato &v){
  while(v.ip.length() < 3) v.ip = '0' + v.ip;
  while(v.ip2.length() < 2) v.ip2 = '0' + v.ip2;
  while(v.ip3.length() < 3) v.ip3 = '0' + v.ip3;
  while(v.ip4.length() < 2) v.ip4 = '0' + v.ip4;; 
  v.ipp = stoi(v.ip + v.ip2 + v.ip3);
  v.ipp = v.ipp*1000000 + stoi(v.ip4 + v.ip5);
}

long conversionString(string num, string num2, string num3, string num4, string num5){
  long nume;
  while(num.length()<3) num = '0' + num;
  while(num2.length()<2) num2= '0' + num2;
  while(num3.length()<3) num3 = '0' + num3;
  while(num4.length()<2) num4 = '0' + num4;
  nume = stoi(num + num2 + num3);
  return nume = (nume*1000000 + stoi(num4 + num5));
}


long convertir(string numero){
  string num, num2, num3, num4, num5;
  stringstream sx(numero);
  getline(sx, num, '.');//3
  getline(sx,num2,'.');//2
  getline(sx,num3,'.');//3
  getline(sx,num4,':');//2
  getline(sx,num5);//4
  return conversionString(num,num2,num3,num4,num5);
}


long ipToLong(string ip) {
  int idx = 0;
  long datoF = 0, dato = 0;
  while (idx < ip.size()) {
    if (ip[idx] != '.') {
      dato = dato * 10 + ip[idx] - '0';
    } else {
      datoF = datoF * 1000 + dato;
      dato = 0;
    }
    idx++;
  }
  datoF = datoF * 1000 + dato;
  return datoF;
}



int main() {
  long n, last, minimo, maximo;
  string mini, maxi, titulo, ssx;
  fstream finx;
  dato registrox;
  linkedlist lista;
  finx.open("bitacora3.txt",ios::in); 
  while(!finx.eof()){
    getline(finx,registrox.linea);
    stringstream sx(registrox.linea);
    getline(sx,ssx,' ');
    getline(sx,ssx,' ');
    getline(sx,ssx,' ');
    getline(sx,registrox.ip, '.');
    getline(sx,registrox.ip2,'.');
    getline(sx,registrox.ip3,'.');
    getline(sx,registrox.ip4,':');
    getline(sx,registrox.ip5,' ');
    conversionLong(registrox);
    lista.addFirst(registrox);
  }
  lista.burbuja();
  finx.close();
  n = convertir("0");
  last = convertir("9999");
  titulo = "bitacoraOrdenada.txt";
  lista.print(n,last,titulo); 


  int nps;
  cout << endl << "numero de IPs con mas busquedas a imprimir:" << endl;
  cin >> (nps);
  nps = nps + 1;
  int accesos = 1;
  queue<long> que;
  fstream fin;
  string registro, ss;
  long registroLong, registroAnterior;
  arbol arbols;
  fin.open("bitacoraOrdenada.txt", ios::in);
  while (!fin.eof()) {
    getline(fin, registro);
    stringstream s(registro);
    getline(s, ss, ' ');
    getline(s, ss, ' ');
    getline(s, ss, ' ');
    getline(s, registro, ':');
    registroLong = ipToLong(registro);
    if (registroLong == registroAnterior) {
      accesos++;
    } else {
      arbols.add(accesos, registroAnterior);
      registroAnterior = registroLong;
      accesos = 1;
    }
  }
  arbols.printn(nps);
  return 0;
}