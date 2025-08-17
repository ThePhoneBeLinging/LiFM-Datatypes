//
// Created by eal on 17/08-2025.
//

#include "LiFM-Datatypes/League.hpp"

#include "Dataholder.hpp"

std::shared_ptr<LeagueTable> League::generateLeagueTable() const
{
  auto leagueTable = std::make_shared<LeagueTable>();
  leagueTable->tableClubs.resize(clubs_.size());

  for (int i = 0; i < matches_.size(); i++)
  {
    auto matchID = matches_[i];
    auto match = Dataholder::matches_[matchID];
    auto homeClubID = match->homeClub_;
    auto awayClubID = match->awayClub_;
    auto homeClubIndex = std::find(clubs_.begin(), clubs_.end(), homeClubID) - clubs_.begin();
    auto awayClubIndex = std::find(clubs_.begin(), clubs_.end(), awayClubID) - clubs_.begin();

    leagueTable->tableClubs[homeClubIndex].goalsFor += match->homeGoals_;
    leagueTable->tableClubs[homeClubIndex].goalsAgainst += match->awayGoals_;

    leagueTable->tableClubs[awayClubIndex].goalsFor += match->awayGoals_;
    leagueTable->tableClubs[awayClubIndex].goalsAgainst += match->homeGoals_;

    if (match->homeGoals_ == match->awayGoals_)
    {
      leagueTable->tableClubs[homeClubIndex].draws++;
      leagueTable->tableClubs[awayClubIndex].draws++;
      leagueTable->tableClubs[homeClubIndex].points++;
      leagueTable->tableClubs[awayClubIndex].points++;
    }
    else if (match->homeGoals_ > match->awayGoals_)
    {
      leagueTable->tableClubs[homeClubIndex].wins++;
      leagueTable->tableClubs[awayClubIndex].losses++;
      leagueTable->tableClubs[homeClubIndex].points += 3;
    }
    else
    {
      leagueTable->tableClubs[awayClubIndex].wins++;
      leagueTable->tableClubs[homeClubIndex].losses++;
      leagueTable->tableClubs[awayClubIndex].points += 3;
    }
  }

  for (int i = 0; i < clubs_.size(); i++)
  {
    leagueTable->tableClubs[i].clubID = clubs_[i];
    leagueTable->tableClubs[i].name = Dataholder::clubs_[clubs_[i]]->name_;
    leagueTable->tableClubs[i].goalDifference = leagueTable->tableClubs[i].goalsFor - leagueTable->tableClubs[i].
      goalsAgainst;
  }

  return leagueTable;
}
