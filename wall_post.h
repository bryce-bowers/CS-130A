#ifndef WALL_POST_H
#define WALL_POST_H
#include <string>
#include <ctime>

using namespace std;

class WallPost
{
 private:
  string author_username;
  string text;
  string time_created;

 public:
  WallPost(string author_username, string text);
  WallPost(string author_username, string text, string time_created);
  ~WallPost();

  string GetText();
  string GetTimeCreated();
  string GetAuthorUsername();

  void SetText(string text);
  bool SetTimeCreated(string time_created);
  bool SetAuthorUsername(string author_username);

  string WallPostToString();
};
#endif
