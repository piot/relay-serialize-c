/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/out_stream.h>
#include <relay-serialize/client_out.h>
#include <relay-serialize/serialize.h>

#define DEBUG_PREFIX "ClientOut"

int relaySerializeClientOutRequestConnect(struct FldOutStream* outStream, RelaySerializeUserSessionId userSessionId,
                                          const RelaySerializeConnectRequestFromClientToServer* request)
{
    relaySerializeWriteCommand(outStream, relaySerializeCmdConnectRequestToServer, DEBUG_PREFIX);
    relaySerializeWriteUserSessionId(outStream, userSessionId);
    relaySerializeWriteApplicationId(outStream, request->appId);
    relaySerializeWriteChannelId(outStream, request->channelId);
    relaySerializeWriteRequestId(outStream, request->requestId);

    return 0;
}

int relaySerializeClientOutRequestListen(struct FldOutStream* outStream, RelaySerializeUserSessionId userSessionId,
                                         const RelaySerializeListenRequestFromClientToServer* request)
{
    relaySerializeWriteCommand(outStream, relaySerializeCmdListenRequestToServer, DEBUG_PREFIX);
    relaySerializeWriteUserSessionId(outStream, userSessionId);
    relaySerializeWriteApplicationId(outStream, request->appId);
    relaySerializeWriteChannelId(outStream, request->channelId);
    relaySerializeWriteRequestId(outStream, request->requestId);

    return 0;
}

int relaySerializeClientOutPacketToServerHeader(FldOutStream* outStream,  RelaySerializeUserSessionId userSessionId,
                                                RelaySerializeServerPacketFromClientToServer data)
{
    relaySerializeWriteCommand(outStream, relaySerializeCmdPacket, DEBUG_PREFIX);
    relaySerializeWriteUserSessionId(outStream, userSessionId);
    relaySerializeWriteConnectionId(outStream, data.connectionId);
    return fldOutStreamWriteUInt16(outStream, data.packetOctetCount);
}
