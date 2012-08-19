#include <iostream>
using namespace std;


class test
{
public:
  //printer is a regular function that takes a const char and prints it
  void printer(const char * printme){
    cout << printme << endl;
  }
  //funcptr is a function pointer with a signature that should match printer
  void (test::*funcptr)(const char * printme);
  
  //caller is a function that takes a const char and a callback
  void caller(const char * printme, void (test::*funcptr)(const char * printex)){
    cout << printme << endl;
    //((this->*fp))(printme); preserve
    ((this->*funcptr))(printme);
  }
};


int main(){
  test m;
  m.printer("Some text");
  m.funcptr = &test::printer;
  (m.*(m.funcptr))("Something");
  return 0;
}
