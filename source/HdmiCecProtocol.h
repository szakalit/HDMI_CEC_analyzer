#ifndef HDMICEC_PROTOCOL
#define HDMICEC_PROTOCOL

//
// HDMI CIC Protocol enums and parameters
//
// Reference: HDMI CEC spec. version 1.3a

#include <LogicPublicTypes.h>

// Protocol-specific namespace to avoid namespace polution
namespace HdmiCec
{

const char* GetProtocolName();
const char* GetFullProtocolName();
const char* GetChannelName();

// The minimum pulse width is 0.4ms (for an "initiator asserted" logical 1).
// Reference: Section 5.2.2 "Data Bit Timing"
// Max frequency is 1000ms / 0.4ms= 2.5 kHz.
static const U32 MaxFrequency = 2500;

// Minimum recommended sample rate: mMaxBitRate * 4 = 10 kHz
static const U32 MinSampleRate = MaxFrequency * 4;

// Maximum number of operands in a message
static const U16 MaxMessageOperands = 14;
// Maximum number of frames in a message (header frame + op frame + 0..14 operand frames)
static const U16 MaxMessageFrames = 2 + MaxMessageOperands;

//
// Protocol enums
//

// 4-bit Logical device addresses (CEC 10.2)
enum DevAddress
{
    DevAddress_TV          = 0,
    DevAddress_Recorder1   = 1,
    DevAddress_Recorder2   = 2,
    DevAddress_Tuner1      = 3,
    DevAddress_Player1     = 4,
    DevAddress_AudioSystem = 5,
    DevAddress_Tuner2      = 6,
    DevAddress_Tuner3      = 7,
    DevAddress_Player2     = 8,
    DevAddress_Recorder3   = 9,
    DevAddress_Tuner4      = 10,
    DevAddress_Player3     = 11,
    DevAddress_Reserved1   = 12,
    DevAddress_Reserved2   = 13,
    DevAddress_FreeUse     = 14,
    DevAddress_UnregBcast  = 15
};
const char* GetDevAddressText(DevAddress devAddress);

// 8-bit opcodes
enum OpCode
{
    OpCode_ActiveSource              = 0x82,
    OpCode_ImageViewOn               = 0x04,
    OpCode_TextViewOn                = 0x0d,
    OpCode_InactiveSource            = 0x9d,
    OpCode_RequestActiveSource       = 0x85,
    OpCode_RoutingChange             = 0x80,
    OpCode_RoutingInformation        = 0x81,
    OpCode_SetStreamPath             = 0x86,
    OpCode_Standby                   = 0x36,
    OpCode_RecordOff                 = 0x0b,
    OpCode_RecordOn                  = 0x09,
    OpCode_RecordStatus              = 0x0a,
    OpCode_RecordTvScreen            = 0x0f,
    OpCode_ClearAnalogueTimer        = 0x33,
    OpCode_ClearDigitalTimer         = 0x99,
    OpCode_ClearExternalTimer        = 0xa1,
    OpCode_SetAnalogueTimer          = 0x34,
    OpCode_SetDigitalTimer           = 0x97,
    OpCode_SetExternalTimer          = 0xa2,
    OpCode_SetTimerProgramTitle      = 0x67,
    OpCode_TimerClearedStatus        = 0x43,
    OpCode_TimerStatus               = 0x35,
    OpCode_CecVersion                = 0x9e,
    OpCode_GetCecVersion             = 0x9f,
    OpCode_GivePhysicalAddress       = 0x83,
    OpCode_GetMenuLanguage           = 0x91,
    OpCode_ReportPhysicalAddress     = 0x84,
    OpCode_SetMenuLanguage           = 0x32,
    OpCode_DeckControl               = 0x42,
    OpCode_DeckStatus                = 0x1b,
    OpCode_GiveDeckStatus            = 0x1a,
    OpCode_Play                      = 0x41,
    OpCode_GiveTunerDeviceStatus     = 0x08,
    OpCode_SelectAnalogueService     = 0x92,
    OpCode_SelectDigitalService      = 0x93,
    OpCode_TunerDeviceStatus         = 0x07,
    OpCode_TunerStepDecrement        = 0x06,
    OpCode_TunerStepIncrement        = 0x05,
    OpCode_DeviceVendorId            = 0x87,
    OpCode_GiveDeviceVendorId        = 0x8c,
    OpCode_VendorCommand             = 0x89,
    OpCode_VendorCommandWithId       = 0xa0,
    OpCode_VendorRemoteButtonDown    = 0x8a,
    OpCode_VendorRemoteButtonUp      = 0x8b,
    OpCode_SetOsdString              = 0x64,
    OpCode_GiveOsdName               = 0x46,
    OpCode_SetOsdName                = 0x47,
    OpCode_MenuRequest               = 0x8d,
    OpCode_MenuStatus                = 0x8e,
    OpCode_UserControlPressed        = 0x44,
    OpCode_UserControlReleased       = 0x45,
    OpCode_GiveDevicePowerStatus     = 0x8f,
    OpCode_ReportPowerStatus         = 0x90,
    OpCode_FeatureAbort              = 0x00,
    OpCode_Abort                     = 0xff,
    OpCode_GiveAudioStatus           = 0x71,
    OpCode_GiveSystemAudioModeStatus = 0x7d,
    OpCode_ReportAudioStatus         = 0x7a,
    OpCode_SetSystemAudioMode        = 0x72,
    OpCode_SystemAudioModeRequest    = 0x70,
    OpCode_SystemAudioModeStatus     = 0x7e,
    OpCode_SetAudioRate              = 0x9a
};
const char* GetOpCodeText(OpCode opCode);

//
// Analyzer implementation
//

// Flags of the 10-bit CEC frame
enum FrameFlags
{
    FrameFlag_EOM = 0x1,
    FrameFlag_ACK = 0x2
};

// Frame types, this is not explicitly defined in the protocol
enum FrameType
{
    FrameType_StartSeq, // CEC start sequence
    FrameType_Header,   // Header frame containing SRC and DST addresses
    FrameType_OpCode,   // Frame containing an opcode
    FrameType_Operand   // Frame containing a single operand
};


} // namespace HdmiCec

#endif // HDMICEC_PROTOCOL
