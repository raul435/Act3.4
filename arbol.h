#include <iostream>
#include <algorithm>
#include <queue>
#include "Node.h"

using namespace std; 

struct resultado{
  long ip;
  int acceso;
};

class arbol{
  public:
    arbol();
    ~arbol();
    void add(int acceso, long ip);
    void printn(int nprints);
  private:
    Node *raiz;
    void destruye(Node *r);
    void ordenar(Node *r,queue<resultado> &q);
};

arbol::arbol(){
  raiz = nullptr;
}

arbol::~arbol(){
  destruye(raiz);
}

void arbol::destruye(Node *r){
  if (r != nullptr){
    destruye(r->getDer());
    destruye(r->getIzq());
    delete r;
  }
}

void arbol::add(int acceso, long ip){
  Node *rais = raiz;
  Node *padre = nullptr;
  while(rais !=nullptr){
    padre = rais;
    if (rais->getAcceso() > acceso){
      rais = rais->getIzq();
    }
    else if(rais->getAcceso() < acceso){
      rais =  rais->getDer();
    }
    else{
      rais = (rais->getIp() < ip) ? rais->getDer() : rais->getIzq();
    }
  }
  if(padre == nullptr){
    raiz = new Node(acceso, ip);
  }
  else{
    if(padre->getAcceso() > acceso){
      padre->setIzq(new Node(acceso,ip));
    }
    else if(padre->getAcceso() < acceso){
      padre->setDer(new Node(acceso,ip));
    }
    else{
      if(padre->getIp() < ip){
        padre->setDer(new Node(acceso,ip));
      }
      else{
        padre->setIzq(new Node(acceso,ip));
      }
    }
  }
}

void arbol::ordenar(Node *r, queue<resultado> &q){
  if(r !=nullptr){
    ordenar(r->getDer(),q);
    resultado salida;
    salida.acceso = r->getAcceso();
    salida.ip = r->getIp();
    q.push(salida);
    ordenar(r->getIzq(), q);
  }
}

string conversion(long ip){
  string conv = "";
  for(int i = 0; i < 3; i++){
    conv = "." + to_string(ip%1000) + conv;
    ip = ip/1000;
  }
  return to_string(ip%1000) + conv;
}

void arbol::printn(int nprints){
  queue<resultado> que;
  ordenar(raiz, que);
  for(int cont = 1; cont < nprints; cont++){
    cout <<conversion(que.front().ip) << " " << que.front().acceso <<endl;
    que.pop(); 
  }
}