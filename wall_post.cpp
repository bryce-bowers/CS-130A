#include <ctime>
#include <ctime> //maybe <time.h>

class WallPost {
public:
  WallPost::WallPost(author_username, text)
  {
    this->author_username = author_username;
    this->text = text;
    time_t current_time;
    time(&current_time);
    time_created = ctime(&current_time);
  }
  WallPost::WallPost(author_username, text, time_created)
  {
    this->author_username = author_username;
    this->text = text;
    this->time_created = time_created;
  }
  string Wall::GetText()
  {
    return WallPost.text;
  }
  string Wall::GetTime()
  {
    return WallPost.time_created;
  }
  string Wall::GetUsername()
  {
    return WallPost.author_username;
  }
  bool Wall::SetText(text)
  {
    this->text = text;
  }
  bool Wall::SetTimeCreated(time_created)
  {
    this->time_created = time_created;
  }
  bool Wall::SetAuthorUsername(author_username)
  {
    this->author_username = author_username;
  }
  string Wall::WallPostToString()
  {
    const string NEW_WALL_POST_DELIMITER = ";nwp&";
    const string NEXT_ATTRIBUTE_DELIMITER = ";na&";
    
    string wall_post_as_string = NEW_WALL_POST_DELIMITER;
    wall_post_as_string += this.GetAuthorUsername();
    wall_post_as_string += NEXT_ATTRIBUTE_DELIMITER;
    wall_post_as_string += this.GetText();
    wall_post_as_string += NEXT_ATTRIBUTE_DELIMITER;
    wall_post_as_string += this.GetTimeCreated();
    return wall_post_as_string;
  }
