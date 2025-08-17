//
// Created by eal on 17/08-2025.
//

#ifndef CLUB_HPP
#define CLUB_HPP
#include <memory>
#include <string>
#include <vector>

#include "LiFM-Timeline/LiFMTimeline.hpp"


class Club
{
public:
  Club(const std::shared_ptr<LiFMTimeline>& timeline);
  int id_ = -1;
  std::string name_;
  int budget_ = -1;
  std::vector<int> players_;

private:
  void simulate();
  std::shared_ptr<LiFMTimeline> timeline_;
};


#endif //CLUB_HPP
