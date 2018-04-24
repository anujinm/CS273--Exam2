/**
* CS-273 Exam 2 Fall 2014
* Who doesn't like parties ?!
*
* @authors Everyone!
*/
#include <iostream>
#include <string>
#include "Party.h"
#include "PartyTicket.h"
#include "PartyFactory.h"

using std::cout;
using std::endl;

int main() // PLEASE DO NOT MODIFY THE MAIN FUNCTION
{
	Party *myparty = PartyFactory::factory("dinner"); // Create a dinner party with the party factory

	// Let's add a couple of people to the dinner party, and store their tickets in variables
	PartyTicket *ticket1 = myparty->add("Mike");
	PartyTicket *ticket2 = myparty->add("Jane");
	PartyTicket *ticket3 = myparty->add("Antonio");
	PartyTicket *ticket4 = myparty->add("Sue");

	cout << "Dinner Party before Jane leaves\n";
	myparty->list(); // List the people currently in the dinner party

	// Jane decides to leave the party. Darn!  She was really fun to have around!
	ticket2->leave();

	cout << "Dinner Party after Jane leaves:\n";
	myparty->list(); // List the people left in the dinner party

	/* Testing Birthday Party*/
	cout << "*********************************************" << endl;
	Party *myparty2 = PartyFactory::factory("birthday"); // Create a birthday party with the party factory
	PartyTicket *ticket_1 = myparty2->add("Anna");
	PartyTicket *ticket_2 = myparty2->add("Monica");
	PartyTicket *ticket_3 = myparty2->add("Michell");
	PartyTicket *ticket_4 = myparty2->add("Abebaye");

	cout << "Birthday Party before Monica and Michell leave\n";
	myparty2->list(); 

	ticket_2->leave();
	ticket_3->leave();

	cout << "Birthday Party after Monica and Michell left:\n";
	myparty2->list();

}