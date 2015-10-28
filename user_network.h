#ifndef USER_NETWORK_H
#define USER_NETWORK_H
#include "doubly_linked_list.h"
#include "user.h"

class UserNetwork {
private:
	List<User> users;
public:
	UserNetwork() {}
	~UserNetwork() {}

	bool UserExists(string uname);	
	void AddUser(string uname, string pass, string rname, string bday);
	void DeleteUser(string uname);
	void WriteUsersToFile(string fname);
	void CreateUsersFromFile(string fname);
	User* AuthorizeUser(string uname, string pass);
};
#endif
