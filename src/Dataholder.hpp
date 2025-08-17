//
// Created by eal on 17/08-2025.
//

#ifndef DATAHOLDER_HPP
#define DATAHOLDER_HPP
#include <vector>

#include "LiFM-Datatypes/Club.hpp"
#include "LiFM-Datatypes/Match.hpp"

class Dataholder
{
public:
  static inline std::vector<std::shared_ptr<Club>> clubs_;
  static inline std::vector<std::shared_ptr<Match>> matches_;
};

#endif //DATAHOLDER_HPP
