#include "RoveCommWifiUDP.h"

#if ROVECOMM_ESP32

//////////////////////////////////////////////////////////////////////////////////////////////////////
WifiUDP RoveCommWifiUDP::_UDPServer;
IPAddress RoveCommWifiUDP::_subscriberIps[ROVECOMM_WIFI_MAX_SUBSCRIBERS];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommWifiUDP::begin(const uint16_t port) {
  // Make sure subscriber list is empty
  for (int i = 0; i < ROVECOMM_WIFI_MAX_SUBSCRIBERS; i++) {
    _subscriberIps[i] = INADDR_NONE;
  }
  // Set up Ethernet UDP
  _UDPServer.begin(port);
  delay(1);
}

/////////////////////////////////////////////////////////////////////////////////
bool RoveCommWifiUDP::read(RoveCommPacket &dest) {
  // default to empty packet
  dest.dataId = RC_ROVECOMM_NO_DATA_DATA_ID;
  dest.dataCount = 0;

  // Read the most recent UDP packet from the input buffer
  // RoveCommPackets always fit inside single UDP packet so, unlike with TCP, we know how much
  // data we have to parse.
  int packetSize = _UDPServer.parsePacket();
  if (packetSize == 0 || packetSize > ROVECOMM_PACKET_HEADER_SIZE + ROVECOMM_PACKET_MAX_DATA_SIZE) return false;

  // Get incoming IP
  IPAddress readIp = _UDPServer.remoteIP();
  uint8_t readBuf[ROVECOMM_PACKET_MAX_DATA_SIZE];
  _UDPServer.read(readBuf, packetSize);

  // Read data from buffer into RoveCommPacket
  if (!rovecomm::unpackPacket(dest, readBuf)) return false;

  // Parse special data_ids/////////////////////////////////////////////////////////
  // Subscribe Request
  if (dest.dataId == RC_ROVECOMM_SUBSCRIBE_DATA_ID) {
    for (int i = 0; i < ROVECOMM_WIFI_MAX_SUBSCRIBERS; i++) {
      // Break if already subscribed
      if (_subscriberIps[i] == readIp) {
        break;
      }
      // Add if not subscribed
      else if (_subscriberIps[i] == INADDR_NONE) {
        _subscriberIps[i] = readIp;
        break;
      }
    }
  }
  // Unsubscribe Request
  else if (dest.dataId == RC_ROVECOMM_UNSUBSCRIBE_DATA_ID) {
    for (int i = 0; i < ROVECOMM_WIFI_MAX_SUBSCRIBERS; i++) {
      // Remove from subscriber list 
      if (_subscriberIps[i] == readIp) {
        _subscriberIps[i] = INADDR_NONE; // remove subscriber
      }
    }
  }
  else if (dest.dataId == RC_ROVECOMM_PING_DATA_ID) {
    uint8_t pData[1] = {1};
    this->_writeTo(rovecomm::UINT8_T, RC_ROVECOMM_PING_REPLY_DATA_ID, 1, pData, readIp, RC_ROVECOMM_WIFI_UDP_PORT);
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommWifiUDP::_write(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data) {
  
  // Pack data into a buffer for writing
  uint8_t writeBuf[ROVECOMM_PACKET_MAX_DATA_SIZE];
  size_t sendBytes = rovecomm::packPacket(writeBuf, dataId, dataCount, dataType, reinterpret_cast<const uint8_t*>(data));
  if (sendBytes == 0) return;

  // Send packet to everyone in subscribers
  for (int i = 0; i < ROVECOMM_WIFI_MAX_SUBSCRIBERS; i++) {
    if (_subscriberIps[i] != INADDR_NONE) {
      _UDPServer.beginPacket(_subscriberIps[i], RC_ROVECOMM_WIFI_UDP_PORT);
      _UDPServer.write(writeBuf, sendBytes);
      _UDPServer.endPacket();
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommWifiUDP::_writeTo(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data, const IPAddress ip, const uint16_t port) {
  
  // Pack data into a buffer for writing
  uint8_t writeBuf[ROVECOMM_PACKET_MAX_DATA_SIZE];
  size_t sendBytes = rovecomm::packPacket(writeBuf, dataId, dataCount, dataType, reinterpret_cast<const uint8_t*>(data));
  if (sendBytes == 0) return;

  // Write to that IP
  _UDPServer.beginPacket(ip, port);
  _UDPServer.write(writeBuf, sendBytes);
  _UDPServer.endPacket();
}

#else
#warning "This platform does not support WifiUdp!"
#endif
