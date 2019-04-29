#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//include the necessary function for the program
int getToDoAction (); // write function that include the choices menu
char addToList(string description, int priority, string dueDate);// write function that add new entries to the list
void printToDo(); // write function that that print out the user inputs

int getToDoAction () { // include a menu of the choices
int userChoice;

	cout << " TO DO LIST !" << endl;
	cout << "Please choose one of the following options" << endl;
	cout << "<><><><><><><><><><><><><><><><><><><><><><>"<<endl;
	cout << "1. Add to my to do list" << endl;
	cout << "2. Print out my whole list" << endl;
	cout << "3. Exit" << endl;
	cout << "<><><><><><><><><><><><><><><><><><><><><><>"<<endl;
	cin >> userChoice;

	return userChoice;
}

 char addToList(string description, int priority, string dueDate) // this function should be used to get the user inputs
{
char userInput;

      cout << "What would you like to add to your to do list?"<<endl;
			cin.ignore();
			cout << "what is the description of the activity?" << endl;
			getline(cin, description);
			cout << "Is this urgent? Enter a number between 1-5. 1 for not really important, 5 for very important" << endl;
			cin >> priority;
			cout << "when is the due date of this task?" << " Enter in a day/month format" << endl;
			cin >> dueDate;
			cout << "you entered  "<< description << " you marked this activity as  "<< priority << "in priority"<< "the due date is "<<dueDate<<endl;
      cout << "No problem! I will add your new entries to your to do list"<<endl;
return userInput;
}

// this function display all the user's inputs
void printToDo(){


}
// main function
int main()
{
  // declare entries
	string description;
	int priority;
	string dueDate;
	char whatNext;
  int userChoice;
// write a loop
	do{
	getToDoAction ();
// write switch statment for the userChoice
		switch (userChoice)
		{
	    case 1:
	     	 addToList(description, priority,dueDate); // this show the addToList function
	    	 break;

    	case 2:

         printToDo(); // this should show printToDo function
		  	 break;

	   	case 3:
         cout << " Thank you for using the To Do List Orgnizer. see you again soon!"<<endl; // exsiting choice
			   break;

	    default:
		    	cout << "That was an incorrect choice!" << endl;// default message
		}

		cout << "would you like to keep going? ‘y’ for YES or ’n’ for NO" << endl; // ask the user if thery want to view the choices again
		cin >> whatNext;

} while (whatNext == 'Y' || whatNext == 'y'); // end of the do loop
	return 0;
}
