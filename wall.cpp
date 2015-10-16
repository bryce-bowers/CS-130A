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

void Wall::AddPost(WallPost* wall_post)
{
  this->wall_posts.Add(wall_post);
}
bool Wall::CreateWallFromString(string wall_posts_as_string)
{
  string wall_post_strings[3]; //stores the attributes until the object is created
  const int wall_post_strings_size = 3;
  string delimiter_detector = ""; //gets the next delimiter value
  size_t delimiter_position;
  const string wall_username_delimiter=";wu&"; //username for Wall
  const string new_wall_post_delimiter=";nwp&"; //indicates start of new WallPost
  const string new_attribute_delimiter=";na&"; //indicates next attribute for WallPost

      delimiter_position = wall_posts_as_string.find(wall_username_delimiter);
      wall_post_strings[0] = wall_posts_as_string.substr(0, delimiter_position);      
      Wall* newPost = new Wall(wall_post_strings[0]);
      wall_posts_as_string.erase(0, delimiter_position + 4);
      cout << wall_post_strings[0] << endl;
      Wall newWall(wall_post_strings[0]);
  //while(wall_posts_as_string.find(new_wall_post_delimiter) > wall_posts_as_string.find(new_attribute_delimiter))
for(int i = 0; wall_posts_as_string.find(new_attribute_delimiter) < wall_posts_as_string.find(new_wall_post_delimiter) && i < wall_post_strings_size; i++)
    { 
      for(int j = 0; j < wall_post_strings_size; j++) //is there a way to find size of the array? this hurts me
        {
          wall_post_strings[j] = "";
        }

      //for(int i = 0; wall_posts_as_string.find(new_attribute_delimiter) < wall_posts_as_string.find(new_wall_post_delimiter) && i < wall_post_strings_size; i++)
        //{
  
          wall_post_strings[i] = wall_posts_as_string.substr(0, delimiter_position);
          wall_posts_as_string.erase(0, delimiter_position+4);
          cout << wall_post_strings[i] << " ";          
        //}
        wall_posts_as_string.erase(0, 5);
      //create new WallPost
      WallPost* newWallPost = new WallPost(wall_post_strings[0], wall_post_strings[1]);
        for(int i = 0; i < wall_post_strings_size; i++)
          {
            
            switch(i)
              {
            case 2:
              if (wall_post_strings[i] != "")
                {
                newWallPost->SetTimeCreated(wall_post_strings[i]);
                }
              }
          }
        newWall.AddPost(newWallPost);
  }
}


string Wall::GetUsername()
{
  return this->username;
}
void Wall::RemovePost(WallPost* wall_post)
{
  this->wall_posts.Remove(wall_post);
}
void Wall::SetUsername(string username)
{
  this->username = username;
}
string Wall::WriteWallToString()
{
  Node<WallPost>* pointer = wall_posts.GetHead();
    string wall_as_string = "";
    while(pointer)
      {
        wall_as_string += pointer->GetVal()->WallPostToString();
        wall_as_string += '\n';
        pointer = pointer->GetNext();
      } 
  return wall_as_string;

}
