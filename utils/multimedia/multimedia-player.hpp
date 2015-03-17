/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
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

#ifndef DASH_MULTIMEDIA_PLAYER
#define DASH_MULTIMEDIA_PLAYER

#include "adaptation-logic.hpp"
#include "multimediabuffer.hpp"

#include <string>
#include <typeinfo>
#include <map>
#include <memory>

namespace dash
{
namespace player
{


class MultimediaPlayer
{
friend class AdaptationLogic;
public:
  //zMultimediaPlayer();
  MultimediaPlayer(std::string AdaptationLogicStr, unsigned int maxBufferedSeconds);
  ~MultimediaPlayer();

  bool AddToBuffer(unsigned int segmentNr, const dash::mpd::IRepresentation* usedRepresentation);
  bool EnoughSpaceInBuffer(unsigned int segmentNr, const dash::mpd::IRepresentation* usedRepresentation);

  double GetBufferLevel(std::string repId = std::string("NULL"));
  unsigned int getHighestBufferedSegmentNr(std::string repId);
  unsigned int nextSegmentNrToConsume();


  MultimediaBuffer::BufferRepresentationEntry
  ConsumeFromBuffer();

  void
  SetAvailableRepresentations(std::map<std::string, IRepresentation*>* availableRepresentations);

  std::shared_ptr<AdaptationLogic>&
  GetAdaptationLogic();

  void
  SetLastDownloadBitRate(double bitrate);

  double
  GetLastDownloadBitRate();

protected:
  MultimediaBuffer* m_buffer;
  double m_lastBitrate;
  std::shared_ptr<AdaptationLogic> m_adaptLogic;
  std::map<std::string, IRepresentation*>* m_availableRepresentations;
};
}
}

#endif // DASH_MULTIMEDIA_PLAYER