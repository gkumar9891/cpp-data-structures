  #include<iostream>
  #include<string>
  #define n 10

  using namespace std;
  

  class Stack {

     public:

     int *arr = new int[n];
     int top = -1;


     void push(int data) {
         top++;
         arr[top] = data;
     }

     void pop() {
         top--;
     } 

     int Top() {
        return arr[top]; 
     }
         
  };

  int infixEvaluation(string infix) {

     Stack disk;
     int operator1;
     int operator2;

    for(int i = infix.length() - 1; i >= 0; i--) {

        if(infix[i] >= '0' && infix[i] <= '9') {
            disk.push( int(infix[i]) - int('0'));      
        } else {
            operator1 = disk.Top();
            disk.pop();
            operator2 = disk.Top();
            disk.pop();

            switch(infix[i]) {
                case '+': disk.push(operator1 + operator2); break; 
                case '-': disk.push(operator1 - operator2); break;
                case '*': disk.push(operator1 * operator2); break;
                case '/': disk.push(operator1 / operator2); break;
            }
        }
    }

    return disk.Top();
  
  }


  int main() {

     string infix = "-+7*45+20";

     cout << infixEvaluation(infix);



      return 0;
  }