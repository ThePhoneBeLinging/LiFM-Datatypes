//
// Created by eal on 17/08-2025.
//

#include "LiFM-Datatypes/Match.hpp"

#include <iostream>

Match::Match(const int homeClub, const int awayClub, const std::chrono::system_clock::time_point matchTime,
             const std::shared_ptr<LiFMTimeline>& timeline) : homeClub_(homeClub), awayClub_(awayClub),
                                                              matchTime_(matchTime), timeline_(timeline)
{
  timeline_->registerUpdate(matchTime_, [&]()-> void { matchLogic(); });
  srand(time(nullptr));
}

int Match::getResult() const
{
  if (homeGoals_ == awayGoals_)
  {
    return 0;
  }
  return homeGoals_ > awayGoals_ ? 1 : 2;
}

std::pair<int, int> Match::getGoals()
{
  return std::make_pair(homeGoals_, awayGoals_);
}

void Match::matchLogic()
{
  if (isFinished_)
  {
    return;
  }
  int num = rand();
  if (num % 2 == 0)
  {
    homeGoals_++;
  }
  else
  {
    awayGoals_++;
  }
  constexpr int secondsPerFunctionCall = 15;
  timeSimulated_ += secondsPerFunctionCall;
  timeline_->registerUpdate(matchTime_ + std::chrono::seconds(timeSimulated_), [&]()-> void { matchLogic(); });

  if (timeSimulated_ >= 90 * 60)
  {
    isFinished_ = true;
  }
}
