#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

// FIXME 2: Create BirthdayParty and BirthdayPartyTicket to host birthday parties!
// FIXME 3: Update PartyFactory::factory() to allow it to be the ONLY method for creating a BirthdayParty
/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
private:
	std::list<std::string> room;  // Data structure for containing the party goers in this birthday party

	/**
	* Constructor for creating a BirthdayParty
	*/
	BirthdayParty() {}

	/**
	* because PartyFactory is a friend class, only 
	* PartyFactory can create a BirthdayParty
	* also, the constructor is private
	*/
	friend class PartyFactory;
public:
	/**
	* Add a person to the party
	* @param name the name of the party goer
	*/
	PartyTicket * add(std::string name) {
		room.push_front(name);
		std::list<std::string>::iterator i = room.begin();
		BirthdayPartyTicket *new_ticket = new BirthdayPartyTicket(this, i);
		return new_ticket;
	}

	/**
	* List all the persons currently in the party
	*/
	void list() {
		// iterate through all the persons here.
		for (auto i : room) {
			std::cout << i << std::endl;
		}
	}

	/**
	* Remove the person identified by the iterator from the party
	*/
	void remove(std::list<std::string>::iterator it) {
		// 1c: someone's getting out of hand. Let's ask them to leave.
		room.erase(it);
	}
};

#endif