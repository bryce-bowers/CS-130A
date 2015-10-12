#ifndef USER_NETWORK_H
#define USER_NETWORK_H
#include "doubly_linked_list.h"
#include "user.h"

class UserNetwork {
private:
	DoublyLinkedList<User> users;
public:
	UserNetwork() {}
	~UserNetwork() {}
	
	void AddUser(string uname, string pass, string rname, string bday);
	void DeleteUser(string uname);
	void WriteUsersToFile(string fname);
	void CreateUsersFromFile(string fname);
};
#endif
