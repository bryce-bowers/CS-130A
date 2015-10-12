#ifndef WALL_H
#include WALL_H
#include <string>

class Wall {
 private:
  string username;
  DoublyLinkedList<WallPost> wall_post;

 public:
  Wall(string post_text);
  Wall(string post_text, string username);
  ~Wall();
  bool AddPost(WallPost);
  bool CreateWallFromString(string); //Wall will only have WallPosts given by the string parameter
  string GetUsername();
  bool RemovePost(WallPost wall_post);
  void SetUsername(string username);
  string WriteWallToString();
}
#endif
