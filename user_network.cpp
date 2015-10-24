#include "user_network.h"
#include "wall.h"
#include "user.h"
#include "doubly_linked_list.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool UserNetwork::UserExists(string uname) {
	Node<User> *head = users.GetHead();
	while (head) {
		if (head->GetVal().GetUserName() == uname) 
			return true;
		head = head->GetNext();
	}
	return false;
}

void UserNetwork::AddUser(string uname, string pass, string rname, string bday) {
	if (UserExists(uname)) {
		return;
	}
	Wall* wall = new Wall(uname);
	User* user = new User(uname, pass, rname, bday, wall);
	users.Add(*user);
}


void UserNetwork::DeleteUser(string uname) {
	Node<User>* head = users.GetHead();
	while (head) {
		if (head->GetVal().GetUserName() == uname) 
			users.Remove(head->GetVal());
		head = head->GetNext();
	}
}
	


void UserNetwork::WriteUsersToFile(string fname) {
	ofstream output_file(fname);
	Node<User>* head = users.GetHead();
	while (head) {
		User user = head->GetVal();
		output_file << user.RetrieveInfo();		
		head = head->GetNext();
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
		users.Add(*user);
		cur_pos = next_pos;
		next_pos = data.find("USERNAME", cur_pos + 1);
	}
	user_data = data.substr(cur_pos, data.length());
	User *user = new User;
	user->ConstructUserFromString(user_data);
	users.Add(*user);
}

User* UserNetwork::AuthorizeUser(string uname, string pass) {
	Node<User> *head = users.GetHead();
	while (head) {
		if (head->GetVal().GetUserName() == uname) {
			if (head->GetVal().GetPassword() == pass)	
				return &(head->GetVal());
		} 
		head = head->GetNext();
	}
	return NULL;
}

