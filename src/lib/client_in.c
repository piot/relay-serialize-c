/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/relay-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <relay-serialize/client_in.h>
#include <relay-serialize/serialize.h>

int relaySerializeClientInConnectRequestToListener(struct FldInStream* inStream,
                                                   RelaySerializeConnectRequestFromServerToListener* data)
{
    relaySerializeReadListenerId(inStream, &data->listenerId);
    relaySerializeReadConnectionId(inStream, &data->connectionId);
    relaySerializeReadUserId(inStream, &data->fromUserId);
    return relaySerializeReadRequestId(inStream, &data->debugRequestId);
}

int relaySerializeClientInPacketFromServer(struct FldInStream* inStream,
                                           RelaySerializeServerPacketFromServerToClient* data)
{
    relaySerializeReadConnectionId(inStream, &data->connectionId);
    return fldInStreamReadUInt16(inStream, &data->packetOctetCount);
}

int relaySerializeClientInListenResponse(struct FldInStream* inStream,
                                         RelaySerializeListenResponseFromServerToListener* data)
{
    relaySerializeReadListenerId(inStream, &data->listenerId);
    relaySerializeReadApplicationId(inStream, &data->appId);
    relaySerializeReadChannelId(inStream, &data->channelId);
    return relaySerializeReadRequestId(inStream, &data->requestId);
}

int relaySerializeClientInConnectResponse(struct FldInStream* inStream,
                                          RelaySerializeConnectResponseFromServerToClient* data)
{
    relaySerializeReadConnectionId(inStream, &data->assignedConnectionId);
    return relaySerializeReadRequestId(inStream, &data->requestId);
}

int relaySerializeClientInPacketHeader(struct FldInStream* inStream, RelaySerializeServerPacketFromServerToClient* data)
{
    relaySerializeReadConnectionId(inStream, &data->connectionId);
    return fldInStreamReadUInt16(inStream, &data->packetOctetCount);
}
