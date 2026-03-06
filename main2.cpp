#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#include "stack.h"

bool check_char(char paren, Stack* s);

int main(int argc, char **argv){
vector<bool> check(argc-1);
cout << "Checking the parentheses in argv arguments\n";

for(int i = 1; i < argc; i++)
    {
     Stack* s = new Stack;
     bool this_str = false;
     for(int j=0;j<strlen(argv[i]);j++)
     {
         bool char_flag = check_char(argv[i][j], s);

         if (argv[i][j]=='{' || argv[i][j] == '[') s->push(argv[i][j]);

         else if (!char_flag) {this_str=false; break;}
         else if ( char_flag) {if (!s->get_size()){this_str=true;}}
         else {cout<<"No Condition met\n"; break;}
     }
     if (this_str) check[i-1] = true; 
     else if (!this_str) check[i-1] = false;
     delete s;
    }

    for (int i = 0; i < argc-1 ; i++)
    {if (check[i]) cout << "argv " << i+1 << " correct\n";
     else cout << "argv " << i+1 << " incorrect\n";}
    
   return 0;
}

bool check_char(char paren, Stack* s)
{
  if (!s->get_size()) return false;
  switch(paren)
         {
          case '}' : if (s->pop()=='{'){return true;} else return false; break;
          case ']' : if (s->pop()=='['){return true;} else return false; break;
          default: return true;
         }
}