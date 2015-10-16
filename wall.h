#ifndef WALL_H
#define WALL_H
#include <string>
#include "doubly_linked_list.h"
#include "wall_post.h"

using namespace std;

class Wall
{
 private:
  string username;
  DoublyLinkedList<WallPost> wall_posts;

 public:
  Wall(string username);
  void AddPost(WallPost* wall_post);
  Wall CreateWallFromString(string); //Wall will only have WallPosts given by the string parameter
  
  string GetUsername();
  void RemovePost(WallPost* wall_post);
  void SetUsername(string username);
  string WriteWallToString();
};
#endif
