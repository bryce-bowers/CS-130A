#ifndef WALL_POST_H
#define WALL_POST_H
#include <string>
#include <ctime>

class WallPost
{
 private:
  string author_username;
  string text;	
  time_t time_object;
  string time_created;

  void getTimeCreated(time_t);

 public:
  WallPost(author_username, text);
  ~WallPost();

  string getText();
  string getTime();
  string getUsername();
  string getWallPost();
}
#endif
