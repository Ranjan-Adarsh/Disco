/*
 ============================================================================
 Name        : Disco.c
 Author      : Adarsh_Ranjan_Yadav
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<stdbool.h>

const int total_websites_limit = 1e3, name_length_of_each_website_limit = 1e2;
//global variables
int** mat;
char** sites;
int length;



bool isReflexive()
{
	for(int i=0;i<length;i++)
	{
		if(mat[i][i]==0)
			return false;
	}
	return false;
}

bool isSymmetric()
{
	for(int i=1;i<length;i++)
	{
		for(int j=0;j<i-1;j++)
		{
			if(mat[i][j]!=mat[j][i])
				return false;
		}
	}
	return true;
}

bool isTransitive()
{
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(mat[i][j]==1)
			{
				for(int k=0;k<length;k++)
				{
					if(mat[j][k]==1)
					{
						if(mat[i][k]!=1)
							return false;
					}
				}
			}
		}
	}
	return true;
}
bool isAntiSymmetric()
{
	for(int i=1;i<length;i++)
	{
		for(int j=0;j<i-1;j++)
		{
			if(i==j)
				continue;
			else if(mat[i][j]==mat[j][i] && mat[i][j]==1)
				return false;
		}
	}
	return true;
}
bool isPoset()
{
	if(isAntiSymmetric()==true && isReflexive()==true && isTransitive()==true)
	{
		return true;
	}
	return false;
}
bool hasAtleastOneReflexive()
{
	for(int i=0;i<length;i++)
	{
		if(mat[i][i]==1)
			return true;
	}
	return false;
}
bool hasAtleastOneSymmetric()
{
	for(int i=1;i<length;i++)
	{
		for(int j=0;j<i-1;j++)
		{
			if(mat[i][j]==mat[j][i])
				return true;
		}
	}
	return false;
}
bool hasAtleastOneTransitive(){
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(mat[i][j]==1)
			{
				for(int k=0;k<length;k++)
				{
					if(mat[j][k]==1)
					{
						if(mat[i][k]==1)
							return true;
					}
				}
			}
		}
	}
	return false;
}
void makeReflexive()
{
	int temp[length][length];
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(i==j)
				temp[i][j]=1;
			else
				temp[i][j]=mat[i][j];
		}
	}

	//make the respective calling
}

void makeSymmetric()
{
	int temp[length][length];
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==j)
				continue;
			else if(mat[i][j]==1 || mat[j][i]==1)
			{
				temp[i][j]=1;
				temp[j][i]=1;
			}
			else
			{
				temp[i][j]=0;
				temp[j][i]=0;
			}
		}
	}
	//call the necessary function  for graph display
}

void makeTransitive()
{
	int temp[length][length];
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			temp[i][j]=mat[i][j];
		}
	}
	//Warshall Algo starts here
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			for(int k=0;k<length;k++)
			{
				if(temp[i][k]==1 && temp[k][j]==1)
					temp[i][j]=1;
			}
		}
	}
	//call necessary function for displaying graph
}

void makeHasseMatrix()
{
	int temp[length][length];
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			temp[i][j]=mat[i][j];
		}
	}
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(i==j && temp[i][j]==1)
			{
				temp[i][j]=0;
				continue;
			}
			else if(mat[i][j]==1)
			{
			for(int k=0;k<length;k++)
			{
				if(temp[j][k]==1 && temp[i][k]==1)
					temp[i][k]=0;
			}
			}
		}
	}
}
//Call necesaary funcyion to display hasse matrix


void import()
{
	FILE *stream = fopen("SampleInput.csv", "r");
    char line[1024];  //buffer
    char labels[total_websites_limit][name_length_of_each_website_limit]; 
    int label_count = 0;
    /* reading and counting labels/names of the websites */
    if (fgets(line, sizeof(line), stream)) {
      int i = 0;
      char *token;
      token = strtok(line, ",");
      while (token != NULL) {
         strcpy(labels[i], token);
         token = strtok(NULL, ",");
         i++;
         label_count++;
      }
    }
    /* filling the graph as a 2d-matrix */
    int graph[label_count][label_count];
    int row = 0;
    while (fgets(line, sizeof(line), stream)) {
       char* tmp = strdup(line);
       char *token;
       token = strtok(tmp, ",");
       int column = 0;
       while (token != NULL) {
          if (column != 0) {
             char c[100];
             strcpy(c, token);
             graph[row][column - 1] = (c[0] - '0');
          }   
          token = strtok(NULL, ",");
          column++;
        }
      free(tmp);
      row++;
   }
   fclose(stream);
   for (int i = 0; i < label_count; i++) {
      printf("%s\n", labels[i]);
	 //sites[i]=labels[i];
   }
      for(int i=0;i<length;i++)
   {
	   for(int j=0;j<length;j++)
	   {
		   printf("%d ",graph[i][j]);
	   }
   }
   length=label_count;
   for(int i=0;i<length;i++)
   {
	   for(int j=0;j<length;j++)
	   {
		   mat[i][j]=graph[i][j];
	   }
   }
	//Data retrival ends here
}


//LEARN ABOUT THE EXPORT FUNCTION   
void export (char *filename, int** A) {  
   filename = strcat(filename, ".csv");
   FILE *fp = fopen(filename, "w+");
   for (int i = 0; i < length; i++) {
      fprintf(fp,",%s", sites[i]);
   }
   fprintf(fp,"\n");
   for (int i = 0; i < length; i++) {
      fprintf(fp,"%s", sites[i]);
      for (int j = 0; j < length; j++) {
         fprintf(fp,",%d", A[i][j]);
      }    
      fprintf(fp,"\n");
   }
   fclose(fp);
}

void menu2(int option)
{
	char choice;
	printf("Do you want to visualise how the network will look if we add minimum links to satisfy the property?Press y for yes and any key for no");
	scanf("%c",&choice);
	if(choice=='y' || choice=='Y');
	{
	switch(option)
	{
		case 1:
		{
			makeReflexive();
			break;
		}
		case 2:
		{
			makeSymmetric();
			break;
		}
		case 3:
		{
			makeTransitive();
		}
		case 7:
		{

		}
		default:
		{
			printf("Invalid Choice");
		}
	}
}
return;
}


void menu3(int option)
{
	printf("Do you want to know the nodes in each piece?");
}
void menu4Options()
{
	printf("1. Display the hasse diagram\n");
	printf("2. Display the website whose link is availbe in every website\n");
	printf("3. Display the website which has links to every website\n");
	printf("4. Display the website that do not have links to any other websites except itself\n");
	printf("5. Display the websites that can't be reached from any other website except itself\n");
	printf("6. Given some websites display the websites which are reachable from all of them \n");
	printf("7. Given some websites, display the websites from which you can reach all those websites\n");
	printf("8. Is this relation an example of lattice?\n\n");
	printf("9. Return to Main Menu\n");
	int cM4;
	scanf("%d",&cM4);
	switch(cM4){
		case 1:
		{
			makeHasseMatrix();
			break;
		}
		case 2:
		{
		for (int i = 0; i < length; i++) {
         bool flag = true;
         for (int j = 0; j < length; j++) {
            flag &= (mat[j][i]);
         }
         if (flag) {
            printf("%s\n", sites[i]);
         }
      	}
			break;
		}
		case 3:{
			for (int i = 0; i < length; i++) {
         bool flag = true;
         for (int j = 0; j < length; j++) {
            flag &= (mat[i][j]);
         }
         if (flag) {
            printf("%s\n", sites[i]);
         }
      }
			break;
		}
		case 4:{
			for (int i = 0; i < length; i++) {
         bool flag = true;
         for (int j = 0; j < length; j++) {
         	if (i == j) continue;
            flag &= (!mat[i][j]);
         }
         if (flag) {
            printf("%s\n", sites[i]);
         }
      }
			break;
		}
		case 5:{
			for (int i = 0; i < length; i++) {
         bool flag = true;
         for (int j = 0; j < length; j++) {
         	if (i == j) continue;
            flag &= (!mat[j][i]);
         }
         if (flag) {
            printf("%s\n", sites[i]);
         }
      }
			break;
		}
		case 6:{
			break;
		}
		case 7:{
			break;
		}
		case 8:{
			break;
		}
		case 9:{
			break;
		}
	}
}
void menu5Options()
{
	printf("1. Given 2 websites A and B, display the website which is reachable from both A and B and can also reach all such websites that A nad B can reach.\n");
	printf("2. Given 2 websites A and B display the website which can reach to both A and B and is also reachable from all such websites which can reach to both A and B\n");
	printf("3. Is the lattice distributive?\n");
	printf("4. Return to Menu 4\n");
}
void mainMenuOptions()
{
	int choice;
	printf("\n\t\t\tMain menu\n");
	printf("1. Does every website has a link to itself?\n");
	printf("2. Is it always possible to return back to the previous website from the current website in one step?\n");
	printf("3. Does every website has all the links to the websites reachable from it?\n");
	printf("4. Does there exists any website that contains a link to itself?\n");
	printf("5. Is it impossible to return to the previous website from the current website in on step?\n");
	printf("6. Is it impossible to return to the previous website from the current website in on step(excluding the cases where the previous and current website is same)?\n");
	printf("7. Is it possible to divide the network into multiple pieces such that every website in a piece is reachable from every other website in that piece?\n");
	printf("8. Is this relation an example of poset?\n");
	printf("9. Exit\n");
	scanf("%d",&choice);
	 switch(choice)
	 {
	 	case 1:
		 {
			 if(isReflexive())
			 {
				 printf("Yes");
			 }
			 else{
				 menu2(choice);
			 }
		 }
	 	case 2:
		 {
			 if(isSymmetric())
			 {
				 printf("Yes");
			 }
			 else{
				 menu2(choice);
			 }
		 }
	 	case 3:
		 {
			 if(isTransitive())
			 {
				 printf("Yes");
			 }
			 else{
				 menu2(choice);
			 }
		 }
	 	case 4:
		 {
			 if(hasAtleastOneReflexive()==true)
			 {
				 printf("Yes\n");
			 }
			 else{
				 printf("No\n");
			 }
		 }
	 	case 5:
		 {
			  if(hasAtleastOneSymmetric()==true)
			 {
				 printf("Yes\n");
			 }
			 else{
				 printf("No\n");
			 }
		 }
	 	case 6:
		 {
			  if(hasAtleastOneTransitive()==true)
			 {
				 printf("Yes\n");
			 }
			 else{
				 printf("No\n");
			 }
		 }
	 	case 7:
	 	case 8:
	 	case 9:
	 	{
	 		exit(0);
	 		break;
	 	}
	 	default:
	 	{
	 		printf("Invalid Input");
	 		break;
	 	}
	 }

}



int main(void) {
	import();
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			printf("%d",mat[i][j]);
		}
	}
	mainMenuOptions();
	return 0;
}
