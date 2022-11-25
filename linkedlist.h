#include "Nodex.h"
#include <iostream>
#include <fstream>

class linkedlist{
  private:
    Nodex *head, *tail; 
    int size = 0;
  public:
    linkedlist();
    ~linkedlist();
    void addFirst(dato data);
    void print(long, long, string);
    void burbuja();
};

linkedlist::linkedlist(){
  size = 0;
  head = nullptr;
  tail = nullptr;
}
linkedlist::~linkedlist(){
  Nodex *curr = head;
  while (head != nullptr){
    head = head->getNext();
    delete curr;
    curr = head;
  }
  size = 0;
}

void linkedlist::addFirst(dato data){
  if(size == 0){
      head = new Nodex(data, nullptr, nullptr); 
      tail = new Nodex(data, nullptr, nullptr);
  }
  else if(size == 1){
    head = new Nodex(data, nullptr, head);
    tail -> setPrev(head);
    }
  else{
    Nodex *curr = new Nodex(data, nullptr, head);
    head -> setPrev(curr);
    head = curr;
  }
  size++;
}


void linkedlist::print(long min, long max, string titulo){
  ofstream archivo;
  archivo.open(titulo, ios::trunc); 
  Nodex *curr = head;
  while(curr != nullptr){
    if(curr->getData().ipp >= min && curr->getData().ipp <= max){
      cout << (curr->getData()).linea << endl;
      archivo << (curr->getData()).linea << endl;
    }
    curr = curr->getNext();
  }
  archivo.close();
}


void linkedlist::burbuja(){
  bool interruptor = true;
  dato tmp;
  Nodex *curr = head;
  for (int i=0; i<size-1 && interruptor; i++) {
    interruptor = false; 
    curr = head;
    for (int j=0; j<size-1-i; j++){
      if ((curr->getNext())->getData().ipp < curr->getData().ipp){
        tmp = curr->getData();
        curr -> setData((curr->getNext())->getData());
        (curr->getNext()) -> setData(tmp);
        interruptor = true;
      }
      curr = curr->getNext();
    }
  }
}
