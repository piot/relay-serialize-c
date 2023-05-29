/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/out_stream.h>
#include <relay-serialize/commands.h>
#include <relay-serialize/server_out.h>

#define DEBUG_PREFIX "ServerOut"

int relaySerializeServerOutChallenge(FldOutStream* outStream, RelaySerializeClientNonce forClient,
                                     RelaySerializeServerChallenge challenge)
{
    relaySerializeWriteCommand(outStream, relaySerializeCmdChallengeResponse, DEBUG_PREFIX);
    relaySerializeWriteClientNonce(outStream, forClient);
    relaySerializeWriteServerChallenge(outStream, challenge);

    return 0;
}

int relaySerializeServerOutLogin(FldOutStream* outStream, RelaySerializeClientNonce forClient,
                                 RelaySerializeUserSessionId userSessionId)
{
    relaySerializeWriteCommand(outStream, relaySerializeCmdLoginResponse, DEBUG_PREFIX);
    relaySerializeWriteClientNonce(outStream, forClient);
    relaySerializeWriteUserSessionId(outStream, userSessionId);

    return 0;
}

int relaySerializeServerOutPacketHeader(FldOutStream* outStream)
{
    relaySerializeWriteCommand(outStream, relaySerializeCmdPacketToClient, DEBUG_PREFIX);

    return 0;
}

int relaySerializeServerOutConnectRequestToListener(FldOutStream* outStream,
                                                    RelaySerializeConnectRequestFromServerToListener data)
{
    relaySerializeWriteCommand(outStream, relaySerializeCmdConnectionRequestToClient, DEBUG_PREFIX);
    relaySerializeWriteConnectionId(outStream, data.assignedConnectionId);
    relaySerializeWriteApplicationId(outStream, data.appId);
    relaySerializeWriteChannelId(outStream, data.channelId);
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
}

int relaySerializeServerOutPacketToClientHeader(FldOutStream* outStream,
                                                RelaySerializeServerPacketFromServerToClient data)
{
    relaySerializeWriteConnectionId(outStream, data.connectionId);
    return fldOutStreamWriteUInt16(outStream, data.packetOctetCount);
}
