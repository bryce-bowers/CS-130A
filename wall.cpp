#include "doubly_linked_list.h"
#include "basic.h"
#include "wall.h"
#include "wall_post.h"
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

Wall::Wall(string username)
{
  this->username = username;
}

void Wall::AddPost(WallPost wall_post)
{
  wall_posts.Add(wall_post);
}

void Wall::CreateWallFromString(string data) 
{
 	size_t cur_pos = data.find("POST_CONTENT", 0);
	if (cur_pos == string::npos) {
		cout << "No post data found." << endl;
		return;
	}
	size_t next_pos = data.find("POST_CONTENT", cur_pos+1);
	string post_data;
	while (next_pos != string::npos) {
		post_data = data.substr(cur_pos, next_pos - cur_pos);
		WallPost *post = new WallPost();
		post->SetAuthorUsername(username);
		post->ConstructFromString(post_data);
		AddPost(*post);
		cur_pos = next_pos;
		next_pos = data.find("POST_CONTENT", cur_pos + 1);
	}
	post_data = data.substr(cur_pos, data.length());
	WallPost *post  = new WallPost();
	post->SetAuthorUsername(username);
	post->ConstructFromString(post_data);
	AddPost(*post);
}


string Wall::GetUsername()
{
  return username;
}
void Wall::RemovePost()
{
  unordered_map<int,WallPost> posts;
  int post_index = 1;
  Node<WallPost> *head = wall_posts.GetHead();
  cout << "Here are all your posts: " << endl;
  while (head) {
    WallPost post = head->GetVal();
    cout << "Post Index: " << post_index << endl;
    cout << post.WallPostToString() << endl;
    head = head->GetNext();
    posts[post_index] = post;
    post_index ++;
  }
  if (post_index == 1) {
	  cout << "No wall post to delete." << endl;
	  return;
  }
  cout << "Input post index to delete: " << endl;
  int idx_del;
  while (!ReadInt(idx_del) || idx_del > post_index) {
  	cout << "Invalide post index. Enter again: " << endl;
  }
  wall_posts.Remove(posts[idx_del]);
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
        wall_as_string += pointer->GetVal().WallPostToString();
        wall_as_string += '\n';
        pointer = pointer->GetNext();
      } 
  return wall_as_string;
}
