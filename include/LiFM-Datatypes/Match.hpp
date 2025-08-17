//
// Created by eal on 17/08-2025.
//

#ifndef MATCH_HPP
#define MATCH_HPP
#include <chrono>

#include "LiFM-Timeline/LiFMTimeline.hpp"


class Match
{
public:
  Match(int homeClub, int awayClub, std::chrono::system_clock::time_point matchTime,
        const std::shared_ptr<LiFMTimeline>& timeline);
  [[nodiscard]] int getResult() const;
  std::pair<int, int> getGoals();
  int homeClub_;
  int awayClub_;
  std::chrono::system_clock::time_point matchTime_;
  const std::shared_ptr<LiFMTimeline>& timeline_;
  bool isFinished_ = false;
  int timeSimulated_ = 0;
  int homeGoals_ = 0;
  int awayGoals_ = 0;

private:
  void matchLogic();
};


#endif //MATCH_HPP
