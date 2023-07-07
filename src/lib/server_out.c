/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/out_stream.h>
#include <relay-serialize/commands.h>
#include <relay-serialize/server_out.h>

#define DEBUG_PREFIX "ServerOut"

int relaySerializeServerOutConnectRequestToListener(FldOutStream* outStream,
                                                    RelaySerializeConnectRequestFromServerToListener data)
{
    relaySerializeWriteCommand(outStream, relaySerializeCmdConnectionRequestToClient, DEBUG_PREFIX);
    relaySerializeWriteListenerId(outStream, data.listenerId);
    relaySerializeWriteConnectionId(outStream, data.connectionId);
    relaySerializeWriteUserId(outStream, data.fromUserId);
    relaySerializeWriteRequestId(outStream, data.debugRequestId);

    return 0;
}

int relaySerializeServerOutListenResponseToListener(FldOutStream* outStream,
                                                    RelaySerializeListenResponseFromServerToListener data)
{
    relaySerializeWriteCommand(outStream, relaySerializeCmdListenResponseToClient, DEBUG_PREFIX);
    relaySerializeWriteListenerId(outStream, data.listenerId);
    relaySerializeWriteApplicationId(outStream, data.appId);
    relaySerializeWriteChannelId(outStream, data.channelId);
    relaySerializeWriteRequestId(outStream, data.requestId);

    return 0;
}

int relaySerializeServerOutConnectResponseToInitiator(FldOutStream* outStream,
                                                      RelaySerializeConnectResponseFromServerToClient data)
{
    relaySerializeWriteCommand(outStream, relaySerializeCmdConnectResponseToClient, DEBUG_PREFIX);
    relaySerializeWriteConnectionId(outStream, data.assignedConnectionId);
    relaySerializeWriteRequestId(outStream, data.requestId);

    return 0;
}

int relaySerializeServerOutPacketToClientHeader(FldOutStream* outStream,
                                                RelaySerializeServerPacketFromServerToClient data)
{
    relaySerializeWriteCommand(outStream, relaySerializeCmdPacketToClient, DEBUG_PREFIX);
    relaySerializeWriteConnectionId(outStream, data.connectionId);
    return fldOutStreamWriteUInt16(outStream, data.packetOctetCount);
}
