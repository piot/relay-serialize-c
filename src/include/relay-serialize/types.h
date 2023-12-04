/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/relay-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef RELAY_SERIALIZE_TYPES_H
#define RELAY_SERIALIZE_TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef uint64_t RelaySerializeUserSessionId;
typedef uint64_t RelaySerializeUserId;
typedef uint64_t RelaySerializeApplicationId;
typedef uint64_t RelaySerializeListenerId;
typedef uint64_t RelaySerializeConnectionId;
typedef uint16_t RelaySerializeChannelId;
typedef uint8_t RelaySerializeRequestId;

typedef struct RelaySerializeConnectRequestFromClientToServer {
    RelaySerializeApplicationId appId;
    RelaySerializeChannelId channelId;
    RelaySerializeUserId connectToUserId;
    RelaySerializeRequestId requestId;
} RelaySerializeConnectRequestFromClientToServer;

typedef struct RelaySerializeConnectResponseFromServerToClient {
    RelaySerializeConnectionId assignedConnectionId;
    RelaySerializeRequestId requestId;
} RelaySerializeConnectResponseFromServerToClient;

typedef struct RelaySerializeListenRequestFromClientToServer {
    RelaySerializeApplicationId appId;
    RelaySerializeChannelId channelId;
    RelaySerializeRequestId requestId;
} RelaySerializeListenRequestFromClientToServer;

typedef struct RelaySerializeListenResponseFromServerToListener {
    RelaySerializeListenerId listenerId;
    RelaySerializeApplicationId appId;
    RelaySerializeChannelId channelId;
    RelaySerializeRequestId requestId;
} RelaySerializeListenResponseFromServerToListener;

typedef struct RelaySerializeConnectRequestFromServerToListener {
    RelaySerializeListenerId listenerId;
    RelaySerializeConnectionId connectionId;
    RelaySerializeUserId fromUserId;
    RelaySerializeRequestId debugRequestId;
} RelaySerializeConnectRequestFromServerToListener;

typedef struct RelaySerializeServerPacketFromServerToClient {
    RelaySerializeConnectionId connectionId;
    uint16_t packetOctetCount;
} RelaySerializeServerPacketFromServerToClient;

typedef struct RelaySerializeServerPacketFromClientToServer {
    RelaySerializeConnectionId connectionId;
    uint16_t packetOctetCount;
} RelaySerializeServerPacketFromClientToServer;

#endif
