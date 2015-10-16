#include <ctime>
#include <string>
#include "wall_post.h"

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
  return this->text;
}
string WallPost::GetTimeCreated()
{
  return this->time_created;
}
string WallPost::GetAuthorUsername()
{
  return this->author_username;
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
bool WallPost::SetAuthorUsername(string author_username)
{
  this->author_username = author_username;
}
string WallPost::WallPostToString()
{
  string wall_post_as_string = "";
  wall_post_as_string += "author username: ";
  wall_post_as_string += this->GetAuthorUsername();
  wall_post_as_string += '\n';
  wall_post_as_string += "text: ";
  wall_post_as_string += this->GetText();
  wall_post_as_string += '\n';
  wall_post_as_string += "time created: ";
  wall_post_as_string += this->GetTimeCreated();
  return wall_post_as_string;
}
