/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef RELAY_SERIALIZE_TYPES_H
#define RELAY_SERIALIZE_TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef uint64_t RelaySerializeUserSessionId;
typedef uint64_t RelaySerializeUserId;
typedef uint64_t RelaySerializeApplicationId;
typedef uint64_t RelaySerializeClientNonce;
typedef uint64_t RelaySerializeServerChallenge;
typedef uint64_t RelaySerializeListenerId;
typedef uint64_t RelaySerializeConnectionId;
typedef uint16_t RelaySerializeChannelId;
typedef uint8_t RelaySerializeRequestId;

typedef struct RelaySerializeConnectRequestFromClientToServer {
    RelaySerializeApplicationId appId;
    RelaySerializeChannelId channelId;
    RelaySerializeUserId userId;
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
    RelaySerializeConnectionId assignedConnectionId;
    RelaySerializeApplicationId appId;
    RelaySerializeUserId fromUserId;
    RelaySerializeChannelId channelId;
    RelaySerializeRequestId debugRequestId;
} RelaySerializeConnectRequestFromServerToListener;

typedef struct RelaySerializeServerPacketFromServerToClient {
    RelaySerializeConnectionId connectionId;
    uint16_t packetOctetCount;
} RelaySerializeServerPacketFromServerToClient;

#endif
