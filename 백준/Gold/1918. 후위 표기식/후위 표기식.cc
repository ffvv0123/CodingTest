#include <iostream>

#include <stack>

#include <string>

using namespace std;

int main(){

	stack<char> op;	

	string str;

	string res;

	cin >> str;

	

	for(int i = 0; i < str.length(); i++){

		

		if (str[i] >= 'A' && str[i] <= 'Z'){

			res += str[i];

		}

		

		else{

		    switch(str[i])

    		{

	    		case '(':

	    		    op.push(str[i]);

	    		    break;

			    

	    		case '*':

	    		case '/':

	    		    while(!op.empty() && (op.top() == '*' || op.top() == '/')){

		    	    	res += op.top();

	    		    	op.pop();

	    		    }

    			    op.push(str[i]);

	    		    break;

			

	    		case '+':

	    		case '-':

    		    	while(!op.empty() && op.top() != '('){

    			    	res += op.top();

	    		    	op.pop();

    			    }

	    		    op.push(str[i]);

    			    break;

			

    			case ')':

    			    while(!op.empty() && op.top() != '('){

	    		    	res += op.top();

	    		    	op.pop();

    			    }

    			    op.pop();

    			    break;	

    	        }		    						

    		}

	}

		while(!op.empty()){

			res += op.top();

			op.pop();

		}		    

	cout << res;	

}