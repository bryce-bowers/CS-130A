#ifndef USER_H
#define USER_H
#include <string>
#include "doubly_linked_list.h"
#include "wall.h"

class User
{
private:
	Wall* wall;
	string username;
	string password;
	string realname;
	string birthday;
public:
	User(string uname, string pass, string rname, string bday, Wall* w);
	~User();
	string GetUserName() {
		return username;
	}
	void SetUserName(string name) {
		username = name;
	}
	string GetPassword() {
		return password;
	}
	void SetPassword(string pass) {
		password = pass;
	}
	string GetRealName() {
		return realname;
	}
	void SetRealName(string r_name) {
		realname = r_name;
	}
	string GetBirthday() {
		return birthday;
	}
	void SetBirthday(string bday) {
		birthday = bday;
	}
	void AddWallPost(string text);
	void DeleteWallPost(); //TODO
	string RetriveInfo();
	void ConstructUserFromString(string user_info);
	
};
#endif

