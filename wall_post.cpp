#include "wall_post.h"
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

WallPost::WallPost(string author_username, string text)
{
  this->author_username = author_username;
  this->text = text;
  //next version will extract hour:min:sec from time
  time_t current_time;
  time(&current_time);
  time_created = ctime(&current_time);
}
WallPost::WallPost(string author_username, string text, string time_created)
{
  this->author_username = author_username;
  this->text = text;
  this->time_created = time_created;
}
WallPost::~WallPost()
{
  //intentinally left blank
}
string WallPost::GetText()
{
  return text;
}
string WallPost::GetTimeCreated()
{
  return time_created;
}
string WallPost::GetAuthorUsername()
{
  return author_username;
}
void WallPost::SetText(string text)
{
  this->text = text;
}
bool WallPost::SetTimeCreated(string time_created)
{
  //next version will check if time is valid
  //and will return if not valid
  this->time_created = time_created;
  return true;
}
void WallPost::SetAuthorUsername(string author_username)
{
  this->author_username = author_username;
}
string WallPost::WallPostToString()
{
  string wall_post_as_string = "";
  wall_post_as_string += "POST_CONTENT:";
  wall_post_as_string += this->GetText();
  wall_post_as_string += '\n';
  wall_post_as_string += "CREATION_TIME:";
  wall_post_as_string += this->GetTimeCreated();
  return wall_post_as_string;
}
void WallPost::ConstructFromString(string data) {
	istringstream ss(data);
	while (ss) {
		string s;
		if (!getline(ss, s)) break;
		size_t found = s.find(':');
		if (found == string::npos) continue;
		const string keyword = s.substr(0, found);
		string value = s.substr(found+1);
		if (keyword == "POST_CONTENT")
			text = value;
		else if (keyword == "CREATION_TIME")
			time_created = value;
	} 
}

