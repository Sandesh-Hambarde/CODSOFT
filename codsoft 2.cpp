 # include<iostream>
 using namespace std;
 
 int main(){
 	float  num1 , num2 , result ;
 	 char  operation ;
 	 cout<< "   In this format  number 1   'operation'   number 2 "<< endl;
 	
 	 
 	 cin >> num1 >> operation  >> num2 ;
 	 if ( operation == '+'){
	  
 	
 		result = num1+ num2;
 		cout<< " result = " << result;
		 }
 	else if (operation == '-'){
	 
     result = num1 -num2;
     cout<< " result = " << result;}
    else if (operation == '*'){
	
      result = num1* num2;
      cout<< " result = " << result;}
    else if (operation == '/'){
	
       result = num1/num2;
       cout<< " result = " << result; }
    else {
        cout << "Error! Operator is not correct";
       result =  00;
 } return 0;
 }
