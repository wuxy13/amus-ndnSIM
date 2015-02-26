/**
 * Copyright (c) 2015 - Christian Kreuzberger - based on ndnSIM
 *
 * This file is part of amus-ndnSIM. See AUTHORS for complete list of ndnSIM authors and
 * contributors.
 *
 * ndnSIM is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * ndnSIM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * ndnSIM, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include "adaptation-logic.hpp"
#include "multimedia-player.hpp"


namespace dash
{
namespace player
{
ENSURE_ADAPTATION_LOGIC_INITIALIZED(AdaptationLogic);



AdaptationLogic::AdaptationLogic(MultimediaPlayer* mPlayer)
{
  this->m_multimediaPlayer = mPlayer;
}



AdaptationLogic::~AdaptationLogic()
{
#if defined(DEBUG) || defined(NS3_LOG_ENABLE)
  std::cerr << "Adaptation Logic deconstructing..." << std::endl;
#endif
}


void
AdaptationLogic::SetAvailableRepresentations(std::map<std::string, IRepresentation*>* availableRepresentations)
{
  this->m_availableRepresentations = availableRepresentations;
}


}

}
