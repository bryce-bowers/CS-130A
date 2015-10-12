#include "user_network.h"
#include "wall.h"
#include "user.h"
#include "doubly_linked_list.h"
#include <iostream>
#include <string>
using namespace std;

void UserNetwork::AddUser(string uname, string pass, string rname, string bday) {
	Wall* wall = new Wall;
	User* user = new User(uname, pass, rname, bday, wall);
	users.Add(user);
}


void UserNetwork::DeleteUser(string uname) {
	Node<User>* head = users.GetHead();
	while (head) {
		if (head->GetVal()->GetUserName() == uname) 
			users.Remove(head->GetVal());
		head = head->GetNext();
	}
}
	


void UserNetwork::WriteUsersToFile(string fname) {
	ofstream output_file(fname);
	Node<User>* head = users.GetHead();
	while (head) {
		User* user = head->GetVal();
		output_file << user->RetrieveInfo();		
		head = head->GetNext();
	}
	output_file.close();
}


void UserNetwork::CreateUsersFromFile(string fname) {
	ifstream input_file(fname);
	// TODO
}


