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

#ifndef NDN_FILECONSUMER_CBR_H
#define NDN_FILECONSUMER_CBR_H


#include "ndn-file-consumer.hpp"

namespace ns3 {
namespace ndn {




/**
 * @ingroup ndn-apps
 * @brief Ndn application for sending out Interest packets at a "constant" rate (Poisson process)
 */
class FileConsumerWdw : public FileConsumer {
public:
  static TypeId
  GetTypeId();

  /**
   * \brief Default constructor
   * Sets up randomizer function and packet sequence number
   */
  FileConsumerWdw();
  virtual ~FileConsumerWdw();


  virtual void
  StartApplication();


protected:
  virtual void
  OnFileData(uint32_t seq_nr, const uint8_t* data, unsigned length);

  virtual void
  OnFileReceived(unsigned status, unsigned length);

  virtual void
  ScheduleNextSendEvent(double miliseconds=0);

  virtual bool
  SendPacket();

  virtual void
  OnData(shared_ptr<const Data> data);

  virtual void
  OnTimeout(uint32_t seqNo);


  virtual void
  IncrementWindow();

  virtual void
  DecrementWindow();


  unsigned int m_windowSize;
  unsigned int m_maxWindowSize;
  unsigned int m_windowThreshold;
  unsigned int m_inFlight;


  uint32_t lastSeqNoRecv;
  bool m_wrongSeqOrder;


  unsigned int received_packets_during_this_window;
  unsigned int timeouts_during_this_window;

  unsigned int packets_sent;
  unsigned int packets_received;
  unsigned int packets_timeout;






};

} // namespace ndn
} // namespace ns3

#endif
