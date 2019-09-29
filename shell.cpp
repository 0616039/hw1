/*
Student No.: 0616039
Student Name: Lu Yi Wen
Email: ivy0621.cs06@g2.nctu.edu.tw
SE tag: xnxcxtxuxoxsx
Statement: I am fully aware that this program is not
supposed to be posted to a public server, such as a
public GitHub repository or a public web page.
*/
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
 
#define MAX_arg_SIZE 500
#define SHELLNAME ">"
using namespace std;
int main(){
	stringstream ss;
	string arg;
	int arglen;
	int and;
	int argstr;

    while (1){
    	char *argList[ MAX_arg_SIZE ];
    	for(int i = 0; i < MAX_arg_SIZE; i++)
			argList[i] = new char[500];
    	ss.clear();
        cout<<SHELLNAME; // 输出>
    	getline(cin, arg);
    	arglen = arg.length();
    	if(arg[arglen-1] == "&"){
    		and = 1;
    		arg[arglen-1] = "\0";
    	}
    	cout << and;
    	ss << arg;
    	argstr = 0;
		while (ss >> argList[argstr])
		{
		    argstr++;
		}
		if(and == 1)
			argList[argstr-1] = NULL;
		else
			argList[argstr] = NULL;
		/* fork another process */
		pid_t pid = fork();
		if (pid < 0) { /* error occurred */
			fprintf(stderr, "Fork Failed");
	  		exit(-1);
		}
		else if (pid == 0) { /* child process */
			execlp("/bin/ls", "ls", NULL);
		}
		else { /* parent process */
		/* parent will wait for the child to complete */
			wait (NULL);
		}
    }
    return 0;
}
