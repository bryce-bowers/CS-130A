#include "user.h"
#include "wall_post.h"
#include <string>
#include <iostream>
#include <sstream>
using namespaces std;

User::User(string uname, string pass, string rname, string bday, Wall* w) {
	wall = w;
	username = uname;
	password = pass;
	realname = rname;
	birthday = bday;
}

User::~User() {
	if (wall) delete wall; //This is done by destructor of Wall in part 4. 
}

void User::AddWallPost(string text) {
	if (wall) {
		WallPost post(username,text);
		wall.AddPost(post);
	} 
}	

void User::DeleteWallPost() {
//TODO
}

string User::RetriveInfo() {
	string userinfo;
	userinfo = "username:" + username + "\n";
	userinfo += "password" + password + "\n";
	userinfo += "realname" + realname + "\n";
	userinfo += "birthday" + birthday + "\n";
	userinfo += wall->WriteWallToString();
	return userinfo;
}

void ConstructUserFromString(string user_info) {
	istringstream ss(user_info);
	while (ss) {
		string s;
		if (!getline(ss, s)) break;
		size_t found = s.find(':');
		if (found == string::npos) continue;
		string keyword = s.substr(0, found);
		string value = s.substr(found+1);
		switch (keyword) {
			case "username":
				username = value;
				break;
			case "password":
				password = value;
				break;
			case "realname":
				realname = value;
				break;
			case "birthday":
				birthday = value;
				wall = new Wall;
				wall->CreateWallFromString(ss.str().substr(ss.tellg()));
				break;
			default:
				break;
		}
	} 
}
