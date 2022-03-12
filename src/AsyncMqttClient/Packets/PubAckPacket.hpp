/****************************************************************************************************************************
  PubAckPacket.hpp
  
  AsyncMqttClient_Generic is a library for ESP32, ESP8266, Protenta_H7, STM32F7, etc. with current AsyncTCP support
  
  Based on and modified from :
  
  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMqttClient_Generic
 
  Version: 1.0.1
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0    K Hoang     10/03/2022 Initial coding to support only ESP32 (with SSL) and ESP8266 (without SSL)
  1.0.1    K Hoang     10/03/2022 Fix Library Manager warnings
 *****************************************************************************************************************************/
 
#pragma once

#ifndef PUB_ACK_PACKET_HPP
#define PUB_ACK_PACKET_HPP

#include "Arduino.h"
#include "Packet.hpp"
#include "../ParsingInformation.hpp"
#include "../Callbacks.hpp"

namespace AsyncMqttClientInternals 
{
	class PubAckPacket : public Packet 
	{
	 public:
		explicit PubAckPacket(ParsingInformation* parsingInformation, OnPubAckInternalCallback callback);
		~PubAckPacket();

		void parseVariableHeader(char* data, size_t len, size_t* currentBytePosition);
		void parsePayload(char* data, size_t len, size_t* currentBytePosition);

	 private:
		ParsingInformation* _parsingInformation;
		OnPubAckInternalCallback _callback;

		uint8_t _bytePosition;
		char _packetIdMsb;
		uint16_t _packetId;
	};
}  // namespace AsyncMqttClientInternals

#endif		// PUB_ACK_PACKET_HPP
