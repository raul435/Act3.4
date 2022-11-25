using namespace std;

class Node{
private:
  Node *izq; 
  Node *der;
  long ip;
  int acceso;
public: 
  Node(int acceso, long ip, Node *izq, Node *der);
  Node(int acceso, long ip);
  void setIp(long ip);
  void setAcceso(int acceso);
  void setIzq(Node *izq);
  void setDer(Node *der);
  int getAcceso();
  long getIp();
  Node* getIzq();
  Node* getDer();
};

Node::Node(int acceso, long ip){
  this->acceso = acceso;
  this->ip = ip;
  this->izq = nullptr;
  this->der = nullptr;
}

Node::Node(int acceso, long ip, Node* izq, Node* der){
  this->acceso = acceso;
  this->ip = ip;
  this->izq = izq;
  this->der = der;
}

int Node::getAcceso(){
  return acceso;
}

void Node::setAcceso(int acceso){
  this->acceso = acceso;
}

long Node::getIp(){
  return ip;
}

void Node::setIp(long ip){
  this->ip = ip;
}

Node* Node::getIzq(){
  return izq;
}

void Node::setIzq(Node *izq){
  this->izq=izq;
}

Node* Node::getDer(){
  return der;
}

void Node::setDer(Node *der){
  this->der=der;
}