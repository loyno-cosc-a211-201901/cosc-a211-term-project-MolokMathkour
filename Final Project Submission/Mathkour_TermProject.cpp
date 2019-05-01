//Program Name: Final Project Tasks orgnizer(To do list and Calender Reminders)
//Purpose: The purpose of this program is to allow the user to orgnize the tasks as to do list
//or to mark days in the calender to make a reminder for certin task.
//Author: Molok A. Mathkour
//Date Last Modified: 4/30/2019

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

//write a function that will return total number of days
int  getNumberOfDays(int month, int year)
{
		 //write a statments that determin the leap year condition, if month is 2
		 if( month == 2)
		 {
		   if((year%400==0) || (year%4==0 && year%100!=0))
		     return 29;
		   else
		     return 28;
		 }
		 // write statments that included the months which have 31 days
		 else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		 ||month == 10 || month==12)
		   return 31;
		 else // write statments that included the months which have 30 days
		   return 30;
}
//write a function that print out the Calendar
void printCalendar(string weekDays[], int firstWeekDayOfMonth, int numberOfDays, int remiderDay)//declare necessary variables
{
 int week;
 int day;
 for( week=0; week < 7;week++){ // for statment that declare the days in the week
   cout << weekDays[week] << "    ";
	 }
		 cout << "\n-------------------------------------------------\n";
		 cout << "\n";
		 int tempBreak=1; // declare a variable

		 for(week=0 ; week < firstWeekDayOfMonth; week++) //for statments for the firstWeekDayOfMonth
{
		   cout << "       ";
		   tempBreak++;
	 }
 for(day=1 ;day<=numberOfDays; day++) // write a for statment for the numberOfDays
	 {
	   if(day == remiderDay) // write an if statment thst msrk the reminder day in the calender
			 {
		     cout << "*"<< day << "*"<<"   ";
			 }
			 else
				 {
			     cout << day <<"     ";
			   }

	 if(day < 10)
	   cout << " ";
	 if(tempBreak >= 7)
				 {
				   cout << "\n";
				   tempBreak=0; // tempBreak
				 }
	 tempBreak++;
	 }
}

//include the necessary function for the program
int getToDoAction (); // write function that include the choices menu
char addToList(string description, int priority, string dueDate); // write function that add new entries to the list


int getToDoAction () { // include a menu of the choices
int userChoice;

	cout << "               TO DO LIST !               " << endl;
	cout << "Please choose one of the following options" << endl;
	cout << "<><><><><><><><><><><><><><><><><><><><><><>"<<endl;
	cout << "1. Add to my to do list" << endl;
	cout << "2. Exit" << endl;
	cout << "<><><><><><><><><><><><><><><><><><><><><><>"<<endl;
	cin >> userChoice;

	return userChoice;
}
 char addToList(string description, int priority, string dueDate) // this function should be used to get the user inputs
{
  char userInput;
  char addAgain;

// write a code for the out put and inputs in the menu
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

return userInput; //return this function to the userInput
}

// this function display all the user's inputs

int main()
{
int userChoice;

		do // loop the menu
		{


		cout << endl;
		cout << "   Wolcome to the Your To do list and Calender Reminders!"<<endl;
		cout << "`` ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ``"<<endl;
		cout << "``                 1 - Calender Reminders                ``" <<endl;
		cout << "``                 2 - To do list                        ``" <<endl;
		cout << "``                 3 - Exit.                             ``" <<endl;
		cout << "`` ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ``"<<endl;
		cout << "   Enter your choice:  ";
		cin >> userChoice;


				if (userChoice == 1) // write if statment that prite the name of the current month and calender
		{
					int i, week, day, n, j, c = 1;
				  string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
				  string weekDays[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

				  time_t t = time(0);   // I use this to get the current time
				  struct tm * now = localtime( & t );
				  int currentDay=now->tm_mday;// current month day
				  int weekDay=now->tm_wday;//current week day
				  int currentYear=now->tm_year;//current year
				  int currentmonth=now->tm_mon;//current month
				  int numberOfDays=getNumberOfDays(now->tm_mon + 1, now->tm_year);//get the current numberOfDays

				  tm tFirst = { 0, 0, 0,1, currentmonth, currentYear };//current month & year
				  time_t time_temp = mktime(& tFirst);// call the function time
				  struct tm * firstTime = localtime(&time_temp); // use the structer tm to get the localtime

				  int firstWeekDayOfMonth=firstTime->tm_wday;// get the firstWeekDayOfMonth

				  cout << "Current Date: " << firstTime->tm_mday << "-"<< months[firstTime->tm_mon] << "-" << firstTime->tm_year + 1900<<"\n\n";// print out the curent date
				  cout << months[currentmonth] << "-" << currentYear + 1900<<"\n\n";

				  printCalendar(weekDays,firstWeekDayOfMonth,numberOfDays, numberOfDays);// function that print out the calender

				  cout << "  "<<endl;
				  cout << "Press enter key to add reminder"<<endl;

				  int dayReminder;
				  string remiderMessage;

				  cout <<endl;
				  cout << "Enter reminder day: ";// out put for the reminder day
				  cin >> dayReminder;// input for the reminder day
				  cin.ignore (50,'\n'); // include cin.ignore
				  cout << "Enter reminder messages:"; // out put for the reminder message
				  getline (cin, remiderMessage);


				  cout <<endl;

				  printCalendar(weekDays, firstWeekDayOfMonth, numberOfDays, dayReminder);
// calender menu
				  cout << "\n-^-^-^-^-^-^-^-^-^-^-^-^-Reminder-^-^-^-^-^-^-^-^-^-^-^-^-\n";
				  cout << "-^ " << endl;
				  cout << "-^       Reminder day:  " << dayReminder<< endl;
				  cout << "-^       Okay I will remide you to  " << remiderMessage<< endl;
				  cout <<"-^-^-^-^-^-^-^-^-^-^-^-^--^-^-^-^-^-^--^-^-^-^-^-^-^-^-^-^-" <<endl;

				  return 0;
				}
				else if (userChoice == 2)
				{
					// declare entries
					string description;
					int priority;
					string dueDate;
					char whatNext;
					int userChoice;
					// write a loop
					do{
					userChoice = getToDoAction();
					// write switch statment for the userChoice
							switch (userChoice)
								{
										case 1:
											 addToList( description, priority, dueDate ); // this show the addToList function
											 break;

										case 2:
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

				else if(userChoice == 3)
			{
				cout << "See You Again Soon, Goodbye!"<< endl; // quit message
				cout << endl;
			}
				else // unvalid choice
				{
					cout << "   Sorry, not a Valid Choice."<< endl;
					cout << "   Please Choose again (1-3)"<< endl;
				}

		}while (userChoice !=3);
return 0;
}
