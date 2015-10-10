#ifndef WALL_H
#include WALL_H
#include <string>

class Wall {
 public:
  Wall();
  ~Wall();
  bool addPost(string, string);
  bool createWallFromString(string); //Wall will only have WallPosts given by the string parameter
  string getWall();
  string getUsername();
  bool removePost(WallPost);
  string setUsername();
  string writeWallToString();

 private:
  string username;
  DoublyLinkedList wall_posts;
}
#endif
