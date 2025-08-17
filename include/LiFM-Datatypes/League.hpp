//
// Created by eal on 17/08-2025.
//

#ifndef LEAGUE_HPP
#define LEAGUE_HPP
#include <memory>
#include <vector>

#include "LeagueTable.hpp"


class League
{
public:
  League() = default;
  std::shared_ptr<LeagueTable> generateLeagueTable() const;
  std::vector<int> clubs_;
  std::vector<int> matches_;
};


#endif //LEAGUE_HPP
