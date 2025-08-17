//
// Created by eal on 17/08-2025.
//

#ifndef LEAGUETABLE_HPP
#define LEAGUETABLE_HPP
#include <string>
#include <vector>

struct TableClub
{
  int clubID;
  std::string name;
  int wins;
  int draws;
  int losses;
  int goalsFor;
  int goalsAgainst;
  int goalDifference;
  int points;
};

class LeagueTable
{
public:
  LeagueTable() = default;
  std::string generateTableString();
  std::vector<TableClub> tableClubs;
};


#endif //LEAGUETABLE_HPP
