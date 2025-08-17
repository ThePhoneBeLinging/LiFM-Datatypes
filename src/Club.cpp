//
// Created by eal on 17/08-2025.
//

#include "LiFM-Datatypes/Club.hpp"

#include <iostream>

#include "Utility/ConfigController.h"

Club::Club(const std::shared_ptr<LiFMTimeline>& timeline) : timeline_(timeline)
{
  auto timePoint = timeline_->getRawTimePoint();
  timeline_->registerUpdate(timePoint, [this]()-> void
  {
    this->simulate();
  });
}

void Club::simulate()
{
  std::cout << "Simulating club: " << name_ << "\n";
  int minutesBetweenSimulations = ConfigController::getConfigInt("ClubSimulationDelay");
  auto timePoint = timeline_->getRawTimePoint() + std::chrono::minutes(minutesBetweenSimulations);
  timeline_->registerUpdate(timePoint, [this]()-> void
  {
    this->simulate();
  });
}
