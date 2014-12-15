/*
 * This file is part of wysiwidi
 *
 * Copyright (C) 2014 Intel Corporation.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef RTSP_INPUT_HANDLER_H_
#define RTSP_INPUT_HANDLER_H_

#include <string>
#include "wfd/parser/driver.h"

namespace wfd {

// An aux class to handle input buffer.
class RTSPInputHandler {
 protected:
  virtual ~RTSPInputHandler() {}

  void InputReceived(const std::string& input);
  virtual void MessageParsed(std::unique_ptr<Message> message) = 0;

 private:
  bool GetHeader(std::string& header);
  bool GetPayload(std::string& payload, unsigned content_length);

  Driver driver_;
  std::string rtsp_recieve_buffer_;
};

}

#endif // RTSP_INPUT_HANDLER_H_
