#include <iostream>
#include <string>
#include <sstream>

struct node
{
	std::string name;	//Hold the node data (name in this case)
	node * next;		//Point to next node
	node * last;		//Point to last node
};

//Menu to display choices
int menu();

//Check to see if user made a valid selection in the menu
int decisionVerification(std::string decision);

//Initialize 32 nodes with "Free" nodes
void initialize(node *&head, node *&last);

//Create a new linked list - used only when initializing the 32 "Free" nodes
void newNode(node *&head, node *&last, std::string name);

//Insert a node at the end of list - used only when intializing the 32 "Free" nodes
void insert(node *&head, node *&last, std::string name);

//Check to see if inputted value is a number
bool isNumber(const std::string val);

//Remove the pages of a specified program
void remove(node *&head, std::string name);

//Checks to see if linked list is full
bool isFull(node *&head);

//Checks to see if linked list is empty
bool isEmpty(node *&head);

//Check how many fragments exist
void fragmentation(node *&head);

//Display linked list
void showList(node *head);

//Check if there are duplicates of a program
bool duplicateError(node *&head, std::string name);

//Check if there is enough space in the linked list
bool spaceError(node *&head, int pages);

//Worst-fit algorithm to allocate space for programs
void worstFit(node *&head, std::string name, int pages);

//Best-fit algorithm to allocate space for programs
void bestFit(node *&head, std::string name, int pages);

int main(int argc, char * argv[])
{
	//Check to see which algorithm to use
	std::string param = argv[1];
	
	if (argc == 2 && param == "worst")
		std::cout << "Using worst-fit algorithm \n";

	else if (argc == 2 && param == "best")
		std::cout << "Using best-fit algorithm \n";

	else
	{
		std::cout << "Invalid parameters entered. Program terminating. \n";
		return 0;
	}


	//Initialize nodes
	node * head = NULL;
	node * last = NULL;

	char choice;			//Hold the user's choice
	std::string name;		//Hold the name of the program
	std::string stringSize;
	int size;				//Hold the size of the program
	int pages;				//Hold the number of the pages the program will occupy
	bool rerun = true;		//Initialize boolean for while loops

	initialize(head, last);	//Initialize a linked list consisting of 32 nodes with "Free" spaces

	do
	{
		choice = menu();	

		switch (choice)
		{
		case 1: 
			
			std::cout << "Program name - ";
			while (rerun)
			{
				std::cin >> name;
				if (name == "Free")
				{
					std::cout << "Program cannot be called 'Free'. Enter another name." << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
				}

				else
				{
					break;
				}
			}

			std::cout << "Program size (KB) - ";
			std::cin >> stringSize;

			//Validate that input is a number
			if (isNumber(stringSize))
			{

                std::stringstream convert(stringSize);  //Conversion from string to int
                convert >> size;

				if (size <= 0)
				{
					std::cout << "Invalid program size. Returning to menu. \n";
					break;
				}
			}

			else
			{
				std::cout << "Invalid program size. Returning to menu. \n";
				break;
			}

			std::cout << std::endl;

			//Check to see if the program already exists
			if (duplicateError(head, name))		
				std::cout << "Error - Program " << name << " already running. \n";

			else
			{
				for (int i = 0; i < 64; i++)	//Determine how many pages will be occupied
				{
					size -= 4;
					if (size <= 0)
					{
						pages = i + 1;
						if (spaceError(head, pages))
							std::cout << "Error - not enough memory for Program " << name << std::endl;

						break;
					}
				}


				if (!spaceError(head, pages))
				{
					//Use worst-fit or best-fit depending on entered paramter

					if (param == "worst")
						worstFit(head, name, pages);

					else
						bestFit(head, name, pages);

					std::cout << "Program " << name << " added successfully: " << pages << " page(s) used. \n";
				}
			}

			break;
			
		case 2: 
			std::cout << "Program name - ";
			std::cin >> name;
			remove(head, name);
			break;

		case 3:
			fragmentation(head);
			break;

		case 4: 
			showList(head);
			break;

		}

	} while (choice != 5);		//Exit program if 5 is selected

    return 0;
}

//Menu to contain options
int menu()
{
	std::string decision;	//Hold decision of user
	int choice;				//Hold decision of user once it passes through the verification
	bool rerun = true;

	while (rerun)
	{
		std::cout << std::endl;
		std::cout << "1. Add program \n";
		std::cout << "2. Kill program \n";
		std::cout << "3. Fragmentation \n";
		std::cout << "4. Print memory \n";
		std::cout << "5. Exit \n\n";

		std::cout << "choice - ";
		std::cin >> decision;

		choice = decisionVerification(decision);	//Verify that input is valid: that it is between the values of one and five inclusively

		if (choice == 6)							//Verification returns 6 if input was valid
			std::cout << "Invalid selection. Try again. \n";

		else
			return choice;
	}
}

//Verify input
int decisionVerification(std::string decision)
{
	if (decision == "1")
		return 1;

	else if (decision == "2")
		return 2;

	else if (decision == "3")
		return 3;

	else if (decision == "4")
		return 4;

	else if (decision == "5")
		return 5;

	else
		return 6;	//Invalid input - return 6

}

//Initialize linked list with 32 nodes
void initialize(node *&head, node *&last)		
{
	for (int i = 0; i < 32; i++)
	{
		insert(head, last, "Free");
	}
}

//Create a new node at the end of the linked list
void newNode(node *&head, node *&last, std::string name)
{
	node *temp = new node;	//Create temporary node
	temp->name = name;		//Temp node holds the program name
	temp->next = NULL;		//Temp points to NULL 
	head = temp;			
	last = temp;			//Since there is only one node, the head and last node are the same node
}

//Add node to end of linked list
void insert(node *&head, node *&last, std::string name)
{
	if (head == NULL)				//If there is no linked list initially, create one
		newNode(head, last, name);

	else							//Else add on to end of the list
	{
		node *temp = new node;		//Create temporary node
		temp->name = name;			//Temp node holds the program name
		temp->next = NULL;			//Temp points to NULL because the new node will be added to the end
		last->next = temp;			
		last = temp;
	}

}

//Check to see if input is a number for the program size
bool isNumber(const std::string val)
{
	for (int i = 0; i < val.length(); i++)
	{
		if (!isdigit(val[i]))
			return false;

	}

	return true;
}

//Delete the pages of a specified program
void remove(node *&head, std::string name)
{
	int j = 0;	//Hold the number of pages that will be reclaimed

	node *temp = head;
	for (int i = 0; i < 64; i++)
	{
		if(temp->name != name)				//If the node does not contain the program
			temp = temp->next;				//Continue onto the next node

		else if (temp->name == name)		//If the node contains the program
		{
			j++;
			temp->name = "Free";			//Make it free
		}

		if (temp->next == NULL)				//If the loop reaches the end of the linked list
		{
			if (temp->name == name)			//If the last node contains the program
			{
				j++;
				temp->name = "Free";		//Make last node free
			}

			if (j == 0)
			{
				std::cout << "Program " << name << " does not exist. \n";
				break;
			}
			
			else
			{
				std::cout << "Program " << name << " successfully killed. " << j << " page(s) reclaimed. \n";
				break;
			}
		}
	}

}

//Check to see if linked list is empty (containing all "Free" spaces)
bool isEmpty(node *& head)
{
	node *temp = head;
	int i = 0;

	while (temp->next != NULL)				//If next node is not null (i.e. not at the end of the list)
	{
		if (temp->name == "Free")
			i++;

		temp = temp->next;
	}

	if (temp->next == NULL && temp->name == "Free")		//If next node is null and current node is free
		i++;

	if (i == 32)		//32 is the maximum number of pages that the program can hold 
		return true;

	else
		return false;

}

//Check to see if linked list is full
bool isFull(node *& head)
{
	node *temp = head;
	int i = 0;
	while (temp->next != NULL)
	{
		if (temp->name != "Free")
			i++;

		temp = temp->next;
	}

	if (temp->next == NULL && temp->name != "Free")
		i++;

		if (i == 32)
			return true;

		else 
			return false;
}

//Determine how many fragments exist
void fragmentation(node *& head)
{
	if (isEmpty(head) || isFull(head))		//Check in the beginning to see if the linked list is already empty or full
		std::cout << "There are zero fragments. \n";

	else
	{
		int i = 0;
		node *temp = head;

		while (temp->next != NULL)
		{
			/*if (temp->name != "Free")
			{
				while (temp->next->name != "Free")
				{
					temp = temp->next;
					//if (temp->name == "Free")
						//i++;
				}
			}

			temp = temp->next;*/
			while (temp->name != "Free")
			{
				temp = temp->next;
				if (temp->name == "Free")
					i++;

				if (temp->next == NULL && temp->name != "Free")
				{
					i++;
					break;
				}
			}

			//if (temp->name == "Free" && temp->next->name != "Free" && temp->next->next == NULL)
				//i++;

			temp = temp->next;

			if (temp == NULL)
				break;

			else if (temp->next == NULL && temp->name != "Free")
			{
				i++;
				break;
			}
		}

		std::cout << "There are " << i << " fragment(s). \n";
	}
}

//Display linked list
void showList(node *head)
{
	if (head == NULL)		//Current node is empty, then the list is empty -- but this condition will not be met in this program
		std::cout << "The list is empty." << std::endl;

	node *temp = head;
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (temp == NULL)
			{
				std::cout << "Free \t";
				break;
			}
			else
			{
				std::cout << temp->name << "\t";
				temp = temp->next;
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

//Check to see if user attempts to add a program that already exists
bool duplicateError(node *&head, std::string name)
{
	node *temp = head;

	while(temp->next != NULL) 
	{
		if (temp->name == name)
			return true;

		else
			temp = temp->next;
	}

	if (temp->next == NULL && temp->name == name)
		return true;

	return false;
}

//Check to see if there is enough space for the program
bool spaceError(node *&head, int pages)
{
	node *temp = head;
	int i = 0;			//Hold the number of free spaces available

	while (temp->next != NULL)
	{
		if (temp->name != "Free")
			temp = temp->next;

		else
		{
			if (i == pages)
				return false;

			i++;

			temp = temp->next;
		}

		if (i == pages)
			return false;
		
	}

	if (temp->next == NULL && temp->name == "Free")		//If position is at the last node and it is free
		i++;

	if (i == pages)
		return false;

	return true;
}

//Worst-fit algorithm to place programs in available space
void worstFit(node *&head, std::string name, int pages)
{
	node *temp = head;

	//Establish two other nodes to hold the possible starting positions of open nodes
	node *temp1 = head;
	node *temp2 = head;

	//Establish variables to hold how many free positions are available and compare the numbers later
	int i = 0;	//Corresponds to temp1
	int j = 0;	//Corresponds to temp2
	
	while (temp->next != NULL)
	{
		while (temp->next != NULL)
		{
			if (temp->name == "Free")
			{
				//If temp1 holder does not currently equal the current position and there has been no open position recorded yet
				//Record the starting position of the set of "Free" nodes
				if(temp1 != temp && i == 0)	
					temp1 = temp;

				i++;	//Record that one free space is available
			}

			temp = temp->next;	//Move to next node

			//If there are no more "Free" spaces available
			//The i != 0 part is in case at the beginning of the linked list there is already an occupied spot
			//While loop will stil continue until it finds the first open spot and record it
			if (temp->name != "Free" && i != 0)
			{
				i++;
				if (temp->next == NULL)
					temp1 = temp;
				break;
			}

			//Deal with extraneous problem of when there is an Free node at the end and no free spaces have been recorded yet (i.e. every other node is occupied)
			if (temp->name == "Free" && temp->next == NULL && i == 0)
			{
				i = 1;
				temp1 = temp;
			}
		}

		while (temp->next != NULL)
		{
			//Same format at the while loop prior

			if (temp->name == "Free")
			{	
				if(temp2 != temp && j==0)
					temp2 = temp;
				j++;
			}

			temp = temp->next;
			if (temp->name != "Free" && j != 0)
			{
				j++;
				if (temp->next == NULL)
					temp2 = temp;
				break;
			}

			if (temp->name == "Free" && temp->next == NULL && j == 0)
				temp2 = temp;
		}

		//Check to see which is greater - the smaller one is set to zero to record for later in case multiple free spaces need to be recorded
		if (j > i)	
			i = 0;
		else if (i > j)
			j = 0;
	}

	//Check to see which is greater again for extraneous cases
	if (j > i)
		i = 0;
	else if (i > j)
		j = 0;
	
	if (i == 0)	//If j recorded more available positions, use its starting position (temp2)
	{
		for (int k = 0; k < pages; k++)
		{
			temp2->name = name;
			temp2 = temp2->next;
		}
	}

	else if (j == 0)	//If i recorded more available positions, use its starting position (temp1)
	{
		for (int k = 0; k < pages; k++)
		{
			temp1->name = name;
			temp1 = temp1->next;
		}
	}
	
}

//Best-fit algorithm to place programs in available space
void bestFit(node *&head, std::string name, int pages)
{
	node *temp = head;

	//Establish two other nodes to hold the possible starting positions of open nodes
	node *temp1 = head;
	node *temp2 = head;

	//Establish variables to hold how many free positions are available and compare the numbers later
	int i = 0;	//Corresponds to temp1
	int j = 0;	//Corresponds to temp2

	while (temp->next != NULL)
	{
		while (temp->next != NULL)
		{
			if (temp->name == "Free")
			{
				//If temp1 holder does not currently equal the current position and there has been no open position recorded yet
				//Record the starting position of the set of "Free" nodes
				if (temp1 != temp && i == 0)
					temp1 = temp;

				i++;	//Record that one free space is available
			}

			temp = temp->next;	//Move to next node

								//If there are no more "Free" spaces available
								//The i != 0 part is in case at the beginning of the linked list there is already an occupied spot
								//While loop will stil continue until it finds the first open spot and record it
			if (temp->name != "Free" && i != 0)
			{
				i++;
				if (temp->next == NULL)
					temp1 = temp;
				break;
			}

			//Deal with extraneous problem of when there is an Free node at the end and no free spaces have been recorded yet (i.e. every other node is occupied)
			if (temp->name == "Free" && temp->next == NULL && i == 0)
			{
				i = 1;
				temp1 = temp;
			}
		}

		while (temp->next != NULL)
		{
			//Same format at the while loop prior

			if (temp->name == "Free")
			{
				if (temp2 != temp && j == 0)
					temp2 = temp;
				j++;
			}

			temp = temp->next;
			if (temp->name != "Free" && j != 0)
			{
				j++;
				if (temp->next == NULL)
					temp2 = temp;
				break;
			}

			if (temp->name == "Free" && temp->next == NULL && j == 0)
				temp2 = temp;
		}

		//Check to see which is smallest - the greater one is set to zero to record for later in case multiple free spaces need to be recorded
		if (j < i)
			i = 0;
		else if (i < j)
			j = 0;
	}

	//Check to see which is smallest again for extraneous cases
	//Also check to see which is the smallest and is able to hold the number of pages the program occupies
	if (j > i && j > pages)
		j = 0;
	else if (i > j && i > pages)
		i = 0;

	if (i == 0)	//If i recorded the most optimal space, use it's starting position (temp1)
	{
		for (int k = 0; k < pages; k++)
		{
			temp1->name = name;
			temp1 = temp1->next;
		}
	}

	else if (j == 0)	//If j recorded the most space, use its starting position (temp2)
	{
		for (int k = 0; k < pages; k++)
		{
			temp2->name = name;
			temp2 = temp2->next;
		}
	}

}


