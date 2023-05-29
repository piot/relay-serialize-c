/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef RELAY_SERIALIZE_SERVER_OUT_H
#define RELAY_SERIALIZE_SERVER_OUT_H

#include <relay-serialize/serialize.h>
#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

int relaySerializeServerOutChallenge(struct FldOutStream* outStream, RelaySerializeClientNonce forClient,
                                     RelaySerializeServerChallenge challenge);
int relaySerializeServerOutLogin(struct FldOutStream* outStream, RelaySerializeClientNonce forClient,
                                 RelaySerializeUserSessionId userSession);

int relaySerializeServerOutPacketHeader(struct FldOutStream* outStream);

int relaySerializeServerOutConnectRequestToListener(struct FldOutStream* outStream,
                                                    RelaySerializeConnectRequestFromServerToListener data);

int relaySerializeServerOutPacketToClientHeader(struct FldOutStream* outStream,
                                                RelaySerializeServerPacketFromServerToClient data);

int relaySerializeServerOutListenResponseToListener(struct FldOutStream* outStream,
                                                    RelaySerializeListenResponseFromServerToListener data);

int relaySerializeServerOutConnectResponseToInitiator(struct FldOutStream* outStream,
                                                      RelaySerializeConnectResponseFromServerToClient data);

#endif
