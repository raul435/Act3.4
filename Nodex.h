using namespace std;

struct dato{
  int key;
  string linea;
  string ip;
  string ip2;
  string ip3;
  string ip4;
  string ip5;
  long ipp;
}; 

class Nodex{
private:
  dato data;
  Nodex *prev; 
  Nodex *next;
public: 
  Nodex(dato data);
  Nodex(dato data, Nodex* prev, Nodex* next);
  dato getData();
  void setData(dato data);
  Nodex* getPrev();
  void setPrev(Nodex* data);
  Nodex* getNext();
  void setNext(Nodex* data);
};

Nodex::Nodex(dato data){
  this->data = data;
  this->next = nullptr;
  this->prev = nullptr;
}
Nodex::Nodex(dato data, Nodex* prev, Nodex* next){
  this->data = data;
  this->prev = prev;
  this->next = next;
}
dato Nodex::getData(){
  return data;
}

Nodex* Nodex::getPrev(){
  return prev;
}
Nodex* Nodex::getNext(){
  return next;
}
void Nodex::setData(dato data){
  this->data = data;
}
void Nodex::setPrev(Nodex* prev){
  this->prev = prev;
}
void Nodex::setNext(Nodex* next){
  this->next = next;
}
