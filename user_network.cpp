#include "user_network.h"
#include "wall.h"
#include "user.h"
#include "doubly_linked_list.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool UserNetwork::UserExists(string uname) {
        for(int i = 0; i < users.getLength(); i++)
  	  {
  	    if (users.get(i).GetUserName() == uname)
  	      return true;
  	  }
  	return false;
}

void UserNetwork::AddUser(string uname, string pass, string rname, string bday) {
	if (UserExists(uname)) {
		return;
	}
	Wall* wall = new Wall(uname);
	User* user = new User(uname, pass, rname, bday, wall);
	users.insert(0, *user);
}


void UserNetwork::DeleteUser(string uname) {
	for (int i = 0; i < users.getLength(); i++)
	  {
	    if (users.get(i).GetUserName() == uname)
	      users.remove(i);
	  }  
}
	


void UserNetwork::WriteUsersToFile(string fname) {
	ofstream output_file(fname);
	for (int i = 0; i < users.getLength(); i++)
	  {
	    output_file << users.get(i).RetrieveInfo();
	  }
	output_file.close();
}


void UserNetwork::CreateUsersFromFile(string fname) {
	ifstream input_file(fname);
	if (!input_file) {
		cout << "File doesn't exist." << endl;
		return;
	}
	cout << "Adding users from file: " << fname << endl;
	string data ((std::istreambuf_iterator<char>(input_file)),
		     (std::istreambuf_iterator<char>()));
	size_t cur_pos = data.find("USERNAME", 0);
	if (cur_pos == string::npos) {
		cout << "No user data found." << endl;
		return;
	}
	size_t next_pos = data.find("USERNAME", cur_pos+1);
	string user_data;
	while (next_pos != string::npos) {
		user_data = data.substr(cur_pos, next_pos - cur_pos);
		User *user = new User;
		user->ConstructUserFromString(user_data);
		users.insert(0, *user);
		cur_pos = next_pos;
		next_pos = data.find("USERNAME", cur_pos + 1);
	}
	user_data = data.substr(cur_pos, data.length());
	User *user = new User;
	user->ConstructUserFromString(user_data);
	users.insert(0, *user);
}

User* UserNetwork::AuthorizeUser(string uname, string pass) {
  	for (int i = 0; i < users.getLength(); i++)
  	  {
  	    if (users.get(i).GetUserName() == uname && users.get(i).GetPassword() == pass)
  	      return &(users.get(i));
  	  }
  	return NULL;
  
}

