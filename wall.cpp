#include "doubly_linked_list.h"
#include "wall.h"
#include "wall_post.h"
#include <string>
#include <iostream>
using namespace std;

Wall::Wall(string username)
{
  this->username = username;
  
}

Wall::~Wall()
{
  //intentionally left blank
}

void Wall::AddPost(WallPost* wall_post)
{
  this->wall_posts.Add(new Node<WallPost>(wall_post));
}
/*bool Wall::CreateWallFromString(string wall_posts_as_string)
{
  //string wall_post_strings[]; //stores the attributes until the object is created
  string delimiter_detector = ""; //gets the next delimiter value
  size_t delimiter_position = 0;
  const string wall_username_delimiter=";wu&"; //username for Wall
  const string new_wall_post_delimiter=";nwp&"; //indicates start of new WallPost
  const string new_attribute_delimiter=";na&"; //indicates next attribute for WallPost
  //delimiter_detector = next delimeter
  string token;
  while (delimiter_position == wall_posts_as_string.find(wall_username_delimiter))
    {
      cout << wall_posts_as_string << endl;
      wall_posts_as_string.erase(0, delimiter_position + wall_username_delimiter.length());
      delimiter_position = wall_posts_as_string.find(new_wall_post_delimiter);
      token = wall_posts_as_string.substr(0, delimiter_position);
      wall_posts_as_string.erase(0, wall_username_delimiter.length()+1);
      cout << wall_posts_as_string << endl;
      
    }
	/*while(delimiter_detector.compare(new_attribute_detector))
    {
      for(int i = 0; !delimiter_detector.compare(new_attribute_detector); i++)
      {
        wall_post_strings[i] = ;
        //delimiter_detector = next delimiter
      }
      //create new WallPost
      for(int i = 0; i <wall_post_strings.size(); i++)
      {
        wall_post_strings = null;
      }
      }
    }
*/
string Wall::GetUsername()
{
  return this->username;
}
void Wall::RemovePost(WallPost wall_post)
{
  this->wall_posts.Remove(new Node<WallPost>(wall_post));
}
void Wall::SetUsername(string username)
{
  this->username = username;
}
/*string Wall::WriteWallToString()
{
  //concatenate WallPost.GetWallPost() for all WallPosts
}*/
