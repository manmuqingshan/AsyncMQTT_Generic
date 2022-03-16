/****************************************************************************************************************************
  PubRecPacket.hpp
  
  AsyncMqttClient_Generic is a library for ESP32, ESP8266, Protenta_H7, STM32F7, etc. with current AsyncTCP support
  
  Based on and modified from :
  
  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMqttClient_Generic
 
  Version: 1.2.0
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0    K Hoang     10/03/2022 Initial coding to support only ESP32 (with SSL) and ESP8266 (without SSL)
  1.0.1    K Hoang     10/03/2022 Fix Library Manager warnings
  1.1.0    K Hoang     11/03/2022 Add support to WT32_ETH01 (with or without TLS/SSL)
  1.2.0    K Hoang     15/03/2022 Add support to STM32 using LAN8742A or LAN8720 (without TLS/SSL)
 *****************************************************************************************************************************/
 
#pragma once

#ifndef PUB_REC_PACKET_HPP
#define PUB_REC_PACKET_HPP

#include "Arduino.h"
#include "Packet.hpp"
#include "../ParsingInformation.hpp"
#include "../Callbacks.hpp"

namespace AsyncMqttClientInternals 
{
	class PubRecPacket : public Packet 
	{
	 public:
		explicit PubRecPacket(ParsingInformation* parsingInformation, OnPubRecInternalCallback callback);
		~PubRecPacket();

		void parseVariableHeader(char* data, size_t len, size_t* currentBytePosition);
		void parsePayload(char* data, size_t len, size_t* currentBytePosition);

	 private:
		ParsingInformation* _parsingInformation;
		OnPubRecInternalCallback _callback;

		uint8_t _bytePosition;
		char _packetIdMsb;
		uint16_t _packetId;
	};
}  // namespace AsyncMqttClientInternals

#endif		// PUB_REC_PACKET_HPP
