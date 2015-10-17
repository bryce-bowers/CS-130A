#include "user.h"
#include "wall_post.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

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
		WallPost *post = new WallPost(username,text);
		wall->AddPost(post);
	} 
}	

void User::DeleteWallPost() {
	wall->RemovePost();
}

void User::DisplayWallPosts() {
	cout << "Wall posts for user: " << username << "." << endl;
	cout << wall->WriteWallToString();
}

string User::RetrieveInfo() {
	string userinfo;
	userinfo = "USERNAME:" + username + "\n";
	userinfo += "PASSWORD:" + password + "\n";
	userinfo += "REALNAME:" + realname + "\n";
	userinfo += "BIRTHDAY:" + birthday + "\n";
	userinfo += wall->WriteWallToString();
	return userinfo;
}

void User::ConstructUserFromString(string user_info) {
	istringstream ss(user_info);
	while (ss) {
		string s;
		if (!getline(ss, s)) break;
		size_t found = s.find(':');
		if (found == string::npos) continue;
		const string keyword = s.substr(0, found);
		string value = s.substr(found+1);
		if (keyword == "USERNAME")
			username = value;
		else if (keyword == "PASSWORD")
			password = value;
		else if (keyword == "REALNAME")	
			realname = value;
		else if (keyword == "BIRTHDAY") {
			birthday = value;
			wall = new Wall(username);
			string wall_data = ss.str().substr(ss.tellg());
			cout << "Adding user: " << username << endl;
			wall->CreateWallFromString(wall_data);
		}
	} 
}
