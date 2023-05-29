/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <relay-serialize/commands.h>
#include <relay-serialize/debug.h>
#include <stdio.h>

const char* relaySerializeCmdToString(uint8_t t)
{
    switch (t) {
        case relaySerializeCmdLogin:
            return "Login";
        case relaySerializeCmdPacket:
            return "Packet";
        case relaySerializeCmdLoginResponse:
            return "LoginResponse";
        case relaySerializeCmdPacketToClient:
            return "PacketToClient";
        default: {
            static char buf[128];
            tc_snprintf(buf, 128, "no idea %02X", t);
            return buf;
        }
    }
}
