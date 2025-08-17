//
// Created by eal on 17/08-2025.
//

#include "LiFM-Datatypes/LeagueTable.hpp"
#include <sstream>
#include <iomanip>

#include "Dataholder.hpp"

std::string LeagueTable::generateTableString()
{
    std::ostringstream oss;
    oss << "---------------------------------------------------------------\n";
    oss << "| Pos | " << std::left << std::setw(14) << "Club" << std::right
        << " | W  | D  | L  | GF | GA | GD | Pts |\n";
    oss << "---------------------------------------------------------------\n";

    size_t n = tableClubs.size();
    std::sort(tableClubs.begin(), tableClubs.end(), [](const TableClub& a, const TableClub& b)
    {
        return a.points > b.points || (a.points == b.points && a.goalDifference > b.goalDifference);
    });
    constexpr int maxClubNameLength = 15;
    for (size_t i = 0; i < n; ++i)
    {
        oss << "| "
            << std::setw(3) << (i + 1) << " "
            << "| " << std::left << std::setw(maxClubNameLength) << tableClubs[i].name << std::right
            << " "
            << "| " << std::setw(2) << tableClubs[i].wins << " "
            << "| " << std::setw(2) << tableClubs[i].draws << " "
            << "| " << std::setw(2) << tableClubs[i].losses << " "
            << "| " << std::setw(2) << tableClubs[i].goalsFor << " "
            << "| " << std::setw(2) << tableClubs[i].goalsAgainst << " "
            << "| " << std::setw(2) << tableClubs[i].goalDifference << " "
            << "| " << std::setw(3) << tableClubs[i].points << " |\n";
    }
    oss << "---------------------------------------------------------------\n";
    return oss.str();
}
