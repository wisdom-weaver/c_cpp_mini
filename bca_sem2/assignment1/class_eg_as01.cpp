#include <iostream>
#include <stdio.h>
using namespace std;

class CricketTeam
{
public:
  string name;
  int score;
  int total_matches;

  void set_init_data();
  void show_data();
};

int main()
{
  CricketTeam player;
  getline(cin, player.name);
  return 0;
}