/****************************************************************************************************************************
  PingRespPacket.hpp
  
  AsyncMqttClient_Generic is a library for ESP32, ESP8266, Protenta_H7, STM32F7, etc. with current AsyncTCP support
  
  AsyncMqttClient_Generic is a library for ESP32, ESP8266, Protenta_H7, STM32F7, etc. with current AsyncTCP support
  
  Based on and modified from :
  
  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMqttClient_Generic
 
  Version: 1.0.0
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0    K Hoang     10/03/2022 Initial coding to support only ESP32 (with SSL) and ESP8266 (without SSL)
 *****************************************************************************************************************************/
 
#pragma once

#ifndef PING_RESP_PACKET_HPP
#define PING_RESP_PACKET_HPP

#include "Arduino.h"
#include "Packet.hpp"
#include "../ParsingInformation.hpp"
#include "../Callbacks.hpp"

namespace AsyncMqttClientInternals 
{
	class PingRespPacket : public Packet 
	{
	 public:
		explicit PingRespPacket(ParsingInformation* parsingInformation, OnPingRespInternalCallback callback);
		~PingRespPacket();

		void parseVariableHeader(char* data, size_t len, size_t* currentBytePosition);
		void parsePayload(char* data, size_t len, size_t* currentBytePosition);

	 private:
		ParsingInformation* _parsingInformation;
		OnPingRespInternalCallback _callback;
	};
}  // namespace AsyncMqttClientInternals

#endif		// PING_RESP_PACKET_HPP