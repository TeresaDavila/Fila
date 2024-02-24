#include <iostream>

class Vertex {
public:
  float value;
  Vertex *next;
  Vertex() { next = nullptr; }
};

// Clase Queue
class Queue {
public:
  Queue();
  void enqueue(float value); // Insertar
  void dequeue(); // Eliminar
  void peekFront(); // Ver el primer elemento
  void peekBack(); // Ver el último elemento
  void print();

private:
  Vertex *head, *tail;
};

Queue::Queue() { head = nullptr; }

// Queue::enqueue()
void Queue::enqueue(float value){
  Vertex *vtx = new Vertex();
  vtx->value = value;
  if (head == nullptr){
    head = vtx;
    tail = vtx;
  }
  else{
    tail->next = vtx;
    tail = vtx;
  }   
}
// Queue::dequeue()
void Queue::dequeue(){
  Vertex *del = head;
  if (head == nullptr) {
    std::cout << "La fila está vacia" << std::endl;
  } else {
    head = head->next;
    delete del;
  }
}

// Queue::peekFront()
void Queue::peekFront(){
  if (head == nullptr){
    std::cout<< "La fila está vacia" << std::endl;
  }
  else{
    std::cout << "El valor del frente es: " << head->value << std::endl;
  }
}

// Queue::peekBack()
void Queue::peekBack(){
  if (head == nullptr){
    std::cout<< "La fila está vacia" << std::endl;
  }
  else{
    std::cout << "El valor del final es: " << tail->value << std::endl;
  }
}

// Queue::print()
void Queue::print() {
  Vertex *v = head;
  while (v != nullptr) {
    std::cout << v->value << "->";
    v = v->next;
  }
  std::cout << std::endl;
}

int main() {
  Queue fila;
  fila.enqueue(1);
  fila.enqueue(2);
  fila.enqueue(3);
  fila.enqueue(4);
  fila.dequeue();
  fila.print();
  fila.peekFront();
  fila.peekBack();
}