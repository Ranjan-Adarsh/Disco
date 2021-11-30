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
#include <stdbool.h>


const int total_websites_limit = 1e3, name_length_of_each_website_limit = 1e2;
//global variables
int** mat;
char** sites;
int** temp;
int length;
void export(char *filename, int **A);
void mainMenuOptions();
void menu5Options();
void menu4Options();
void menu2(int option);

// void plot(char * fname){
//     int pid;
//     if((pid = fork())==0){
//         if(execlp("python", "python","visualise.py",fname,(char*)NULL)==-1){
//         	execlp("python3", "python3","visualise.py",fname,(char*)NULL);
//         };
//     }
//     exit(0);
// }

void tempInitialise()
{
	temp=malloc(length*sizeof(int *));
	for(int i=0;i<length;i++)
	{
		*(temp+i)=malloc(sizeof(int));
	}
}
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
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			printf("%d\n",mat[i][j]);
			if(i==j)
				continue;
			else{
				if(mat[i][j]!=mat[j][i])
					{
						return false;
					}
			}
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
	//printf("run ref\n");
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
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			printf("%d ",temp[i][j]);
		}
		printf("\n");
	}
	char c[]="Output";
	char* ce=c;
	export(ce,temp);

	//make the respective calling
}

void makeSymmetric()
{
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==j)
			{
				temp[i][j]=mat[i][j];
				continue;
			}
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
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			printf("%d ",*(*(temp+i)+j));
		}
		printf("\n");
	}
	char c[]="Output";
	char* ce=c;
	export(ce,temp);

	//call the necessary function  for graph display
}

void makeTransitive()
{
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
	char c[]="Output";
	char* ce=c;
	export(ce,temp);
	//call necessary function for displaying graph
}

void makeHasseMatrix()
{
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
			if(i==j)
			{
				temp[i][j]=0;
				continue;
			}
			else if(temp[i][j]==1)
			{
			for(int k=0;k<length;k++)
			{
				if(temp[j][k]==1 && temp[i][k]==1)
					temp[i][k]=0;
			}
			}
		}
	}
	char c[]="Output";
	char* ce=c;
	export(ce,temp);
}
//Call necesaary funcyion to display hasse matrix


void import()
{
	FILE *stream = fopen("SampleInput.csv", "r");
    char line[1024];  //buffer
	char** labels=malloc(total_websites_limit*sizeof(char *));
	for(int a=0; a<total_websites_limit; ++a){
            *(labels + a) = malloc(name_length_of_each_website_limit*sizeof(char));
        }
    //char labels[total_websites_limit][name_length_of_each_website_limit]; 
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
    int** graph=malloc(label_count*sizeof(int *));
	for(int a=0; a<label_count; ++a){
            *(graph + a) = malloc(label_count*sizeof(int));
        }
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
//    for (int i = 0; i < label_count; i++) {
//       printf("%s\n", labels[i]);
//    }
   length=label_count;
	mat=graph;
	// for(int i=0;i<label_count;i++)
	// {
	// 	for(int j=0;j<label_count;j++)
	// 	{
	// 		printf("%d",mat[i][j]);
	// 	}
	// 	printf("\n");
	// }
	sites=labels;
 	for (int i = 0; i < label_count; i++) {
       printf("%s\n", sites[i]);
    }

	 //sites[i]=labels[i];
	//Data retrival ends here
}


//EXPORT FUNCTION   
void export (char *filename, int **A) {
   filename = strcat(filename, ".csv");
   printf("%s",filename);
   FILE *fp = fopen(filename, "w+");
   for (int i = 0; i < length; i++) {
      fprintf(fp, ",%s", sites[i]);
   }
   //fprintf(fp, "\n");
   for (int i = 0; i < length; i++) {
      fprintf(fp, "%s", sites[i]);
      for (int j = 0; j < length; j++) {
          fprintf(fp, ",%d", *(*(A+i)+j));
      }    
      fprintf(fp, "\n");
   }
   fclose(fp);
}

void menu2(int option)
{
	int choice;
	printf("Do you want to visualise how the network will look if we add minimum links to satisfy the property?Press 1 for yes and 2 for no\n");
	scanf(" %d",&choice);
	if(choice==1)
	{
	switch(option)
	{
		case 1:
		{
			makeReflexive();
			//mainMenuOptions();
			break;
		}
		case 2:
		{
			makeSymmetric();
			//mainMenuOptions();
			break;
		}
		case 3:
		{
			makeTransitive();
			//mainMenuOptions();
			break;
		}
		case 7:
		{
			break;

		}
		default:
		{
			printf("Invalid Choice");
		}
	}
}
mainMenuOptions();
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
			menu4Options();
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
		  menu4Options();
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
	  menu4Options();
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
	  menu4Options();
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
	  menu4Options();
			break;
		}
		case 6:{
			char index_string[2*length+5];
            int num,k=0;
            int index[length];
			printf("The list of indices are:\n");
			for(int i=0;i<length;i++)
			{
				printf("%d. %s",i,*(sites+i));
			}
			printf("Enter the number of indices: ");
			scanf("%d",&num);
			printf("Now enter the indexes separated by ',': ");
			scanf("%s",index_string);
			char* tokens=strtok(index_string,",");
			while(tokens != NULL){
                index[k] = atoi(tokens);
                tokens = strtok(NULL, ",");
                ++k;
            }
			int flag;
			for(int i=0;i<length;i++)
			{
				flag=1;
				for(int j=0;j<k;j++)
				{
					if(mat[j][i]==0)
					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					printf("%s ",sites[i]);
				}
			}
			menu4Options();
			break;
		}
		case 7:{
			char index_string[2*length+5];
            int num,k=0;
            int index[length];
			printf("The list of indices are:\n");
			for(int i=0;i<length;i++)
			{
				printf("%d. %s",i,*(sites+i));
			}
			printf("Enter the number of indices: ");
			scanf("%d",&num);
			printf("Now enter the indexes separated by ',': ");
			scanf("%s",index_string);
			char* tokens=strtok(index_string,",");
			while(tokens != NULL){
                index[k] = atoi(tokens);
                tokens = strtok(NULL, ",");
                ++k;
            }
			int flag;
			for(int i=0;i<length;i++)
			{
				flag=1;
				for(int j=0;j<k;j++)
				{
					if(mat[i][j]==0)
					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					printf("%s ",sites[i]);
				}
			}
			menu4Options();
			break;
		}
		case 8:{

			menu5Options();
			break;
		}
		case 9:{
			mainMenuOptions();
			break;
		}
	}
}
void menu5Options()
{
	int cO5;
	printf("1. Given 2 websites A and B, display the website which is reachable from both A and B and can also reach all such websites that A nad B can reach.\n");
	printf("2. Given 2 websites A and B display the website which can reach to both A and B and is also reachable from all such websites which can reach to both A and B\n");
	printf("3. Is the lattice distributive?\n");
	printf("4. Return to Menu 4\n");
	scanf("% d",&cO5);
	
	if(cO5==1)
	{
		int A,B;
		int indexes[length]; 
	for(int j=0;j<length;j++)
	{
		indexes[j]=0;
	}
		printf("Write the index number of website:\nA: ");
		scanf("%d",&A);
		printf("B: ");
		scanf("%d",&B);
		for(int i=0;i<length;i++)
		{
			if(mat[A][i]==1 && mat[B][i]==1)
			{
				indexes[i]=1;
			}
		}
		int flag;
		for(int k=0;k<length;k++)
		{
			flag=1;
			if(k==A || k==B)
			{
				continue;
			}
			else if(indexes[k]==1)
			{
				for(int l=0;l<length;l++)
				{
					if(indexes[l]==1 && mat[k][l]==0)
					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					printf("%s ",sites[k]);
				}
			}
		}
		menu5Options();

	}
	else if(cO5==2)
	{
		int A,B;
		int indexes[length]; 
	for(int j=0;j<length;j++)
	{
		indexes[j]=0;
	}
		printf("Write the index number of website:\nA: ");
		scanf("%d",&A);
		printf("B: ");
		scanf("%d",&B);
		for(int i=0;i<length;i++)
		{
			if(mat[i][A]==1 && mat[i][B]==1)
			{
				indexes[i]=1;
			}
		}
		int flag;
		for(int i=0;i<length;i++)
		{
			if(indexes[i]==1)
			{
				flag=1;
				for(int k=0;k<length;k++)
				{
					if(indexes[k]==1 && mat[k][i]==0)
					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					printf("%s ",sites[i]);
				}
			}
		}
		menu5Options();	
	}
	else if(cO5==3)
	{
			//Is the lattice distribute?
			printf("No");
			menu5Options();
	}
	else if(cO5==4)
	{
		menu4Options();
	}

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
				 mainMenuOptions();
			 }
			 else{
				 menu2(choice);
			 }
			 break;
		 }
	 	case 2:
		 {
			 if(isSymmetric()==true)
			 {
				 printf("Yes");
				 mainMenuOptions();
			 }
			 else{
				 printf("No\n");
				 menu2(choice);
			 }
			 break;
		 }
	 	case 3:
		 {
			 if(isTransitive())
			 {
				 printf("Yes");
				 mainMenuOptions();
			 }
			 else{
				 menu2(choice);
			 }
			 break;
		 }
	 	case 4:
		 {
			 if(hasAtleastOneReflexive()==true)
			 {
				 printf("Yes\n");
				 mainMenuOptions();
			 }
			 else{
				 printf("No\n");
				 mainMenuOptions();
			 }
			 break;
		 }
	 	case 5:
		 {
			  if(hasAtleastOneSymmetric()==true)
			 {
				 printf("Yes\n");
				 mainMenuOptions();
			 }
			 else{
				 printf("No\n");
				 mainMenuOptions();
			 }
			 break;
		 }
	 	case 6:
		 {
			  if(hasAtleastOneTransitive()==true)
			 {
				 printf("Yes\n");
				 mainMenuOptions();
			 }
			 else{
				 printf("No\n");
				 mainMenuOptions();
			 }
			 break;
		 }
	 	case 7:
		 {
			 break;
		 }
	 	case 8:
		 {
			 if(isPoset()==true)
			 {
				 printf("Yes\n");
				 menu4Options();
			 }
			 else{
				 printf("NO\n");
				 mainMenuOptions();
			 }
			 break;
		 }
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
	tempInitialise();
	mainMenuOptions();
	return 0;
}
