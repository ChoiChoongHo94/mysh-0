#include "utils.h"
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  int count,temp=0, start = -1;  
  *argc = 0;
  while (1){
 	 if(command[count]==' '||command[count]=='\t'||command[count]=='\n')
		count++;
	 else if(command[count] == '\0'){
		(*argc)++;
		*argv = (char**)malloc(sizeof(char*));
		(*argv)[0] = (char*)malloc(sizeof(char));
		(*argv)[0][0] = '\0';
		 break;}
	 else {start = 1; temp=count; break;}
  }

  while(start==1){
	  if(command[count] == ' '|| command[count] == '\0'||
		command[count]=='\t'||command[count]=='\n'){
	     count= temp; *argv=(char**)malloc((*argc)*sizeof(char*)); break;}

 	  else{ 
		if(command[count+1] == ' ') {(*argc)++; count += 2;}
		else if(command[count+1] == '\0'){ (*argc)++; count ++;}
		else if(command[count+1] != ' ') count++;
	      }
  }
 int i =0; 

  while(start==1){
	if(command[count] == ' ') count++;
	else if (command[count] == '\0'||
		command[count]=='\t'||command[count]=='\n') break;

	else{
		if(command[count+1] == ' ' || command[count+1] == '\0'){
	  	  (*argv)[i] = (char*)malloc((count-temp+2) * sizeof(char));
		  for(int j=0; j < count-temp+1; j++) 
			(*argv)[i][j]=command[temp+j];
		  (*argv)[i][count-temp+1] = '\0';
		  count ++; temp = count+1; i++;}
		else if (command[count+1] != ' ') count++;}
  }
}
