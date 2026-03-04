
#ifndef stack_h
#define stack_h
#include "node.h"
class Stack {
	NodePtr top;
	int size;
public:
    void push(int);
    int pop();
    Stack(NodePtr t = NULL, int s = 0);
    ~Stack();
};


void Stack::push(int x){
  NodePtr new_node=new NODE(x);
  if(new_node){new_node->set_next(top);
                top = new_node;  
                size ++;  
                cout << "Pushed" << x << endl;
              } 
  else{top = new_node; new_node->set_next(NULL); size++;}
}

int Stack::pop(){
    if (top==NULL){cout<<"Empty Stack"<<endl; return 0;}
    else{
        
        NodePtr t=top;
        int value;

        value=t->get_value();
        top = t->get_next();

        delete t;
        size--;
        return value;

        }
    }

Stack::Stack(NodePtr t, int s){
    top = t;
    size = s;
}
Stack::~Stack(){
    while(size!=0){this->pop();}
}


#endif
