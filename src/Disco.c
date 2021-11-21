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
void mainMenuOptions()
{
	printf("1. Does every website has a link to itself?\n");
	printf("2. Is it always possible to return back to the previous website from the current website in one step?\n");
	printf("3. Does every website has all the links to the websites reachable from it?");
	printf("4. Does there exists any website that contains a link to itself?");
	printf("5. Is it impossible to return to the previous website from the current website in on step?\n");
	printf("6. Is it impossible to return to the previous website from the current website in on step(excluding the cases where the previous and current website is same)?\n");
	printf("7. Is it possible to divide the network into multiple pieces such that every website in a piece is reachable from every other website in that piece?\n");
	printf("8. Is this relation an example of poset?");
	printf("9. Exit");

}
void menu2(int option)
{
	printf("Do you want to visualise how the network will look if we add minimum links to satisfy the property?");
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
	printf("8. Is this relation an example of lattice?\n");
	printf("9. Return to Main Menu\n");
}
void menu5Options()
{
	printf("1. Given 2 websites A and B, display the website which is reachable from both A and B and can also reach all such websites that A nad B can reach.\n");
	printf("2. Given 2 websites A and B display the website which can reach to both A and B and is also reachable from all such websites which can reach to both A and B\n");
	printf("3. Is the lattice distributive?\n");
	printf("4. Return to Menu 4\n");
}
int main(void) {
	 int choice;
	 printf("\\nMain menu\\n");
	 mainMenuOptions();
	 scanf("%d",&choice);
	 switch(choice)
	 {
	 	case 1:
	 	case 2:
	 	case 3:
	 	case 4:
	 	case 5:
	 	case 6:
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
