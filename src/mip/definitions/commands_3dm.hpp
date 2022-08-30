#pragma once

#include "descriptors.h"
#include "../mip_result.h"

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

namespace mip {
class Serializer;

namespace C {
struct mip_interface;
} // namespace C

namespace commands_3dm {

////////////////////////////////////////////////////////////////////////////////
///@addtogroup MipCommands_cpp  MIP Commands [CPP]
///@{
///@defgroup 3dm_commands_cpp  3dm Commands [CPP]
///
///@{

////////////////////////////////////////////////////////////////////////////////
// Descriptors
////////////////////////////////////////////////////////////////////////////////

enum 
{
    DESCRIPTOR_SET                      = 0x0C,
    
    CMD_POLL_IMU_MESSAGE                = 0x01,
    CMD_POLL_GNSS_MESSAGE               = 0x02,
    CMD_POLL_FILTER_MESSAGE             = 0x03,
    CMD_POLL_NMEA_MESSAGE               = 0x04,
    CMD_GET_IMU_BASE_RATE               = 0x06,
    CMD_GET_GNSS_BASE_RATE              = 0x07,
    CMD_IMU_MESSAGE_FORMAT              = 0x08,
    CMD_GNSS_MESSAGE_FORMAT             = 0x09,
    CMD_FILTER_MESSAGE_FORMAT           = 0x0A,
    CMD_GET_FILTER_BASE_RATE            = 0x0B,
    CMD_NMEA_MESSAGE_FORMAT             = 0x0C,
    CMD_POLL_DATA                       = 0x0D,
    CMD_GET_BASE_RATE                   = 0x0E,
    CMD_MESSAGE_FORMAT                  = 0x0F,
    CMD_CONFIGURE_FACTORY_STREAMING     = 0x10,
    CMD_CONTROL_DATA_STREAM             = 0x11,
    CMD_RAW_RTCM_2_3_MESSAGE            = 0x20,
    CMD_GNSS_CONSTELLATION_SETTINGS     = 0x21,
    CMD_GNSS_SBAS_SETTINGS              = 0x22,
    CMD_GNSS_ASSISTED_FIX_SETTINGS      = 0x23,
    CMD_GNSS_TIME_ASSISTANCE            = 0x24,
    CMD_PPS_SOURCE                      = 0x28,
    CMD_EVENT_SUPPORT                   = 0x2A,
    CMD_EVENT_CONTROL                   = 0x2B,
    CMD_EVENT_TRIGGER_STATUS            = 0x2C,
    CMD_EVENT_ACTION_STATUS             = 0x2D,
    CMD_EVENT_TRIGGER_CONFIG            = 0x2E,
    CMD_EVENT_ACTION_CONFIG             = 0x2F,
    CMD_DEVICE_STARTUP_SETTINGS         = 0x30,
    CMD_SENSOR2VEHICLE_TRANSFORM_EUL    = 0x31,
    CMD_SENSOR2VEHICLE_TRANSFORM_QUAT   = 0x32,
    CMD_SENSOR2VEHICLE_TRANSFORM_DCM    = 0x33,
    CMD_SET_GNSS_DYNAMICS_MODE          = 0x34,
    CMD_SET_IMU_SIGNAL_COND             = 0x35,
    CMD_SET_IMU_TIMESTAMP               = 0x36,
    CMD_ACCEL_BIAS                      = 0x37,
    CMD_GYRO_BIAS                       = 0x38,
    CMD_CAPTURE_GYRO_BIAS               = 0x39,
    CMD_HARD_IRON_OFFSET                = 0x3A,
    CMD_SOFT_IRON_MATRIX                = 0x3B,
    CMD_REALIGN_UP                      = 0x3C,
    CMD_REALIGN_NORTH                   = 0x3D,
    CMD_CONING_AND_SCULLING_ENABLE      = 0x3E,
    CMD_UART_BAUDRATE                   = 0x40,
    CMD_GPIO_CONFIG                     = 0x41,
    CMD_GPIO_STATE                      = 0x42,
    CMD_ODOMETER_CONFIG                 = 0x43,
    CMD_ADVANCED_DATA_FILTER            = 0x50,
    CMD_LEGACY_COMP_FILTER              = 0x51,
    CMD_SENSOR_RANGE                    = 0x52,
    CMD_CALIBRATED_RANGES               = 0x53,
    CMD_DATASTREAM_FORMAT               = 0x60,
    CMD_DEVICE_POWER_STATE              = 0x61,
    CMD_SAVE_RESTORE_GPS_SETTINGS       = 0x62,
    CMD_DEVICE_SETTINGS                 = 0x63,
    CMD_RAW_CLIP_SETTINGS               = 0x70,
    
    REPLY_IMU_MESSAGE_FORMAT            = 0x80,
    REPLY_GNSS_MESSAGE_FORMAT           = 0x81,
    REPLY_FILTER_MESSAGE_FORMAT         = 0x82,
    REPLY_IMU_BASE_RATE                 = 0x83,
    REPLY_GNSS_BASE_RATE                = 0x84,
    REPLY_DATASTREAM_ENABLE             = 0x85,
    REPLY_IMU_SIGNAL_SETTINGS           = 0x86,
    REPLY_UART_BAUDRATE                 = 0x87,
    REPLY_DATASTREAM_FORMAT             = 0x88,
    REPLY_POWER_STATE                   = 0x89,
    REPLY_FILTER_BASE_RATE              = 0x8A,
    REPLY_ADVANCED_DATA_FILTER          = 0x8B,
    REPLY_POLL_DATA                     = 0x8D,
    REPLY_BASE_RATE                     = 0x8E,
    REPLY_MESSAGE_FORMAT                = 0x8F,
    REPLY_COMMUNICATIONS_MODE           = 0x91,
    REPLY_GNSS_DYNAMICS_MODE            = 0x92,
    REPLY_IMU_TIMESTAMP_VALUE           = 0x93,
    REPLY_IMU_BASIC_STATUS              = 0x94,
    REPLY_IMU_ADVANCED_STATUS           = 0x95,
    REPLY_RAW_CLIP_SETTINGS             = 0x96,
    REPLY_LEGACY_COMP_FILTER            = 0x97,
    REPLY_ACCEL_BIAS_VECTOR             = 0x9A,
    REPLY_GYRO_BIAS_VECTOR              = 0x9B,
    REPLY_HARD_IRON_OFFSET_VECTOR       = 0x9C,
    REPLY_SOFT_IRON_COMP_MATRIX         = 0x9D,
    REPLY_CONING_AND_SCULLING_ENABLE    = 0x9E,
    REPLY_GNSS_CONSTELLATION_SETTINGS   = 0xA0,
    REPLY_GNSS_SBAS_SETTINGS            = 0xA1,
    REPLY_GNSS_ASSISTED_FIX_SETTINGS    = 0xA2,
    REPLY_GNSS_TIME_ASSISTANCE          = 0xA3,
    REPLY_SENSOR2VEHICLE_TRANSFORM_EUL  = 0xB1,
    REPLY_SENSOR2VEHICLE_TRANSFORM_QUAT = 0xB2,
    REPLY_SENSOR2VEHICLE_TRANSFORM_DCM  = 0xB3,
    REPLY_EVENT_SUPPORT                 = 0xB4,
    REPLY_EVENT_CONTROL                 = 0xB5,
    REPLY_EVENT_TRIGGER_STATUS          = 0xB6,
    REPLY_EVENT_ACTION_STATUS           = 0xB7,
    REPLY_EVENT_TRIGGER_CONFIG          = 0xB8,
    REPLY_EVENT_ACTION_CONFIG           = 0xB9,
    REPLY_NMEA_MESSAGE_FORMAT           = 0x8C,
    REPLY_PPS_SOURCE                    = 0xA8,
    REPLY_GPIO_CONFIG                   = 0xC1,
    REPLY_GPIO_STATE                    = 0xC2,
    REPLY_ODOMETER_CONFIG               = 0xC3,
    REPLY_SENSOR_RANGE                  = 0xD2,
    REPLY_CALIBRATED_RANGES             = 0xD3,
};

////////////////////////////////////////////////////////////////////////////////
// Shared Type Definitions
////////////////////////////////////////////////////////////////////////////////

struct NmeaMessage
{
    enum class MessageID : uint8_t
    {
        GGA  = 1,  ///<  GPS System Fix Data
        GLL  = 2,  ///<  Geographic Position Lat/Lon
        GSV  = 3,  ///<  GNSS Satellites in View
        RMC  = 4,  ///<  Recommended Minimum Specific GNSS Data
        VTG  = 5,  ///<  Course over Ground
        HDT  = 6,  ///<  Heading, True
        ZDA  = 7,  ///<  Time & Date
        PRKA = 100,  ///<  Parker proprietary Euler angles
        PRKR = 101,  ///<  Parker proprietary Angular Rate/Acceleration
    };
    
    enum class TalkerID : uint8_t
    {
        GNSS    = 1,  ///<  NMEA message will be produced with talker id "GN"
        GPS     = 2,  ///<  NMEA message will be produced with talker id "GP"
        GALILEO = 3,  ///<  NMEA message will be produced with talker id "GA"
        GLONASS = 4,  ///<  NMEA message will be produced with talker id "GL"
    };
    
    MessageID message_id = static_cast<MessageID>(0); ///< Message type (GGA, GLL, etc)
    TalkerID talker_id = static_cast<TalkerID>(0); ///< Talker ID (GN, GP, etc)
    uint8_t source_desc_set = 0; ///< Data source descriptor set (Filter, GNSS, etc)
    uint16_t decimation = 0; ///< Decimation from the base rate of the source descriptor set.
    
};
void insert(Serializer& serializer, const NmeaMessage& self);
void extract(Serializer& serializer, NmeaMessage& self);

enum class SensorRangeType : uint8_t
{
    ALL   = 0,  ///<  Only allowed for SAVE, LOAD, and DEFAULT function selectors.
    ACCEL = 1,  ///<  Accelerometer. Range is specified in g.
    GYRO  = 2,  ///<  Gyroscope. Range is specified in degrees/s.
    MAG   = 3,  ///<  Magnetometer. Range is specified in Gauss.
    PRESS = 4,  ///<  Pressure sensor. Range is specified in hPa.
};


////////////////////////////////////////////////////////////////////////////////
// Mip Fields
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_poll_imu_message  (0x0C,0x01) Poll Imu Message [CPP]
/// Poll the device for an IMU message with the specified format
/// 
/// This function polls for an IMU message using the provided format. The resulting message
/// will maintain the order of descriptors sent in the command and any unrecognized
/// descriptors are ignored. If the format is not provided, the device will attempt to use the
/// stored format (set with the Set IMU Message Format command.) If no format is provided
/// and there is no stored format, the device will respond with a NACK. The reply packet contains
/// an ACK/NACK field. The polled data packet is sent separately as an IMU Data packet.
///
///@{

struct PollImuMessage
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_POLL_IMU_MESSAGE;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    bool suppress_ack = 0; ///< Suppress the usual ACK/NACK reply.
    uint8_t num_descriptors = 0; ///< Number of descriptors in the descriptor list.
    DescriptorRate* descriptors = {nullptr}; ///< Descriptor list.
    
};
void insert(Serializer& serializer, const PollImuMessage& self);
void extract(Serializer& serializer, PollImuMessage& self);

CmdResult pollImuMessage(C::mip_interface& device, bool suppressAck, uint8_t numDescriptors, const DescriptorRate* descriptors);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_poll_gnss_message  (0x0C,0x02) Poll Gnss Message [CPP]
/// Poll the device for an GNSS message with the specified format
/// 
/// This function polls for a GNSS message using the provided format. The resulting message
/// will maintain the order of descriptors sent in the command and any unrecognized
/// descriptors are ignored. If the format is not provided, the device will attempt to use the
/// stored format (set with the Set GNSS Message Format command.) If no format is provided
/// and there is no stored format, the device will respond with a NACK. The reply packet contains
/// an ACK/NACK field. The polled data packet is sent separately as a GNSS Data packet.
///
///@{

struct PollGnssMessage
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_POLL_GNSS_MESSAGE;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    bool suppress_ack = 0; ///< Suppress the usual ACK/NACK reply.
    uint8_t num_descriptors = 0; ///< Number of descriptors in the descriptor list.
    DescriptorRate* descriptors = {nullptr}; ///< Descriptor list.
    
};
void insert(Serializer& serializer, const PollGnssMessage& self);
void extract(Serializer& serializer, PollGnssMessage& self);

CmdResult pollGnssMessage(C::mip_interface& device, bool suppressAck, uint8_t numDescriptors, const DescriptorRate* descriptors);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_poll_filter_message  (0x0C,0x03) Poll Filter Message [CPP]
/// Poll the device for an Estimation Filter message with the specified format
/// 
/// This function polls for an Estimation Filter message using the provided format. The resulting message
/// will maintain the order of descriptors sent in the command and any unrecognized
/// descriptors are ignored. If the format is not provided, the device will attempt to use the
/// stored format (set with the Set Estimation Filter Message Format command.) If no format is provided
/// and there is no stored format, the device will respond with a NACK. The reply packet contains
/// an ACK/NACK field. The polled data packet is sent separately as an Estimation Filter Data packet.
///
///@{

struct PollFilterMessage
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_POLL_FILTER_MESSAGE;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    bool suppress_ack = 0; ///< Suppress the usual ACK/NACK reply.
    uint8_t num_descriptors = 0; ///< Number of descriptors in the format list.
    DescriptorRate* descriptors = {nullptr}; ///< Descriptor format list.
    
};
void insert(Serializer& serializer, const PollFilterMessage& self);
void extract(Serializer& serializer, PollFilterMessage& self);

CmdResult pollFilterMessage(C::mip_interface& device, bool suppressAck, uint8_t numDescriptors, const DescriptorRate* descriptors);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_imu_message_format  (0x0C,0x08) Imu Message Format [CPP]
/// Set, read, or save the format of the IMU data packet.
/// 
/// The resulting data messages will maintain the order of descriptors sent in the command.
///
///@{

struct ImuMessageFormat
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_IMU_MESSAGE_FORMAT;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t num_descriptors = 0; ///< Number of descriptors
    DescriptorRate* descriptors = {nullptr}; ///< Descriptor format list.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_IMU_MESSAGE_FORMAT;
        
        uint8_t num_descriptors = 0; ///< Number of descriptors
        DescriptorRate* descriptors = {nullptr}; ///< Descriptor format list.
        
    };
};
void insert(Serializer& serializer, const ImuMessageFormat& self);
void extract(Serializer& serializer, ImuMessageFormat& self);

void insert(Serializer& serializer, const ImuMessageFormat::Response& self);
void extract(Serializer& serializer, ImuMessageFormat::Response& self);

CmdResult writeImuMessageFormat(C::mip_interface& device, uint8_t numDescriptors, const DescriptorRate* descriptors);
CmdResult readImuMessageFormat(C::mip_interface& device, uint8_t* numDescriptorsOut, uint8_t numDescriptorsOutMax, DescriptorRate* descriptorsOut);
CmdResult saveImuMessageFormat(C::mip_interface& device);
CmdResult loadImuMessageFormat(C::mip_interface& device);
CmdResult defaultImuMessageFormat(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_gps_message_format  (0x0C,0x09) Gps Message Format [CPP]
/// Set, read, or save the format of the GNSS data packet.
/// 
/// The resulting data messages will maintain the order of descriptors sent in the command.
///
///@{

struct GpsMessageFormat
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_GNSS_MESSAGE_FORMAT;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t num_descriptors = 0; ///< Number of descriptors
    DescriptorRate* descriptors = {nullptr}; ///< Descriptor format list.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_GNSS_MESSAGE_FORMAT;
        
        uint8_t num_descriptors = 0; ///< Number of descriptors
        DescriptorRate* descriptors = {nullptr}; ///< Descriptor format list.
        
    };
};
void insert(Serializer& serializer, const GpsMessageFormat& self);
void extract(Serializer& serializer, GpsMessageFormat& self);

void insert(Serializer& serializer, const GpsMessageFormat::Response& self);
void extract(Serializer& serializer, GpsMessageFormat::Response& self);

CmdResult writeGpsMessageFormat(C::mip_interface& device, uint8_t numDescriptors, const DescriptorRate* descriptors);
CmdResult readGpsMessageFormat(C::mip_interface& device, uint8_t* numDescriptorsOut, uint8_t numDescriptorsOutMax, DescriptorRate* descriptorsOut);
CmdResult saveGpsMessageFormat(C::mip_interface& device);
CmdResult loadGpsMessageFormat(C::mip_interface& device);
CmdResult defaultGpsMessageFormat(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_filter_message_format  (0x0C,0x0A) Filter Message Format [CPP]
/// Set, read, or save the format of the Estimation Filter data packet.
/// 
/// The resulting data messages will maintain the order of descriptors sent in the command.
///
///@{

struct FilterMessageFormat
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_FILTER_MESSAGE_FORMAT;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t num_descriptors = 0; ///< Number of descriptors (limited by payload size)
    DescriptorRate* descriptors = {nullptr};
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_FILTER_MESSAGE_FORMAT;
        
        uint8_t num_descriptors = 0; ///< Number of descriptors (limited by payload size)
        DescriptorRate* descriptors = {nullptr};
        
    };
};
void insert(Serializer& serializer, const FilterMessageFormat& self);
void extract(Serializer& serializer, FilterMessageFormat& self);

void insert(Serializer& serializer, const FilterMessageFormat::Response& self);
void extract(Serializer& serializer, FilterMessageFormat::Response& self);

CmdResult writeFilterMessageFormat(C::mip_interface& device, uint8_t numDescriptors, const DescriptorRate* descriptors);
CmdResult readFilterMessageFormat(C::mip_interface& device, uint8_t* numDescriptorsOut, uint8_t numDescriptorsOutMax, DescriptorRate* descriptorsOut);
CmdResult saveFilterMessageFormat(C::mip_interface& device);
CmdResult loadFilterMessageFormat(C::mip_interface& device);
CmdResult defaultFilterMessageFormat(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_imu_get_base_rate  (0x0C,0x06) Imu Get Base Rate [CPP]
/// Get the base rate for the IMU data in Hz
/// 
/// This is the fastest rate for this type of data available on the device.
/// This is used in conjunction with the IMU Message Format Command to set streaming data at a specified rate.
///
///@{

struct ImuGetBaseRate
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_GET_IMU_BASE_RATE;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_IMU_BASE_RATE;
        
        uint16_t rate = 0; ///< [hz]
        
    };
};
void insert(Serializer& serializer, const ImuGetBaseRate& self);
void extract(Serializer& serializer, ImuGetBaseRate& self);

void insert(Serializer& serializer, const ImuGetBaseRate::Response& self);
void extract(Serializer& serializer, ImuGetBaseRate::Response& self);

CmdResult imuGetBaseRate(C::mip_interface& device, uint16_t* rateOut);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_gps_get_base_rate  (0x0C,0x07) Gps Get Base Rate [CPP]
/// Get the base rate for the GNSS data in Hz
/// 
/// This is the fastest rate for this type of data available on the device.
/// This is used in conjunction with the GNSS Message Format Command to set streaming data at a specified rate.
///
///@{

struct GpsGetBaseRate
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_GET_GNSS_BASE_RATE;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_GNSS_BASE_RATE;
        
        uint16_t rate = 0; ///< [hz]
        
    };
};
void insert(Serializer& serializer, const GpsGetBaseRate& self);
void extract(Serializer& serializer, GpsGetBaseRate& self);

void insert(Serializer& serializer, const GpsGetBaseRate::Response& self);
void extract(Serializer& serializer, GpsGetBaseRate::Response& self);

CmdResult gpsGetBaseRate(C::mip_interface& device, uint16_t* rateOut);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_filter_get_base_rate  (0x0C,0x0B) Filter Get Base Rate [CPP]
/// Get the base rate for the Estimation Filter data in Hz
/// 
/// This is the fastest rate for this type of data available on the device.
/// This is used in conjunction with the Estimation Filter Message Format Command to set streaming data at a specified rate.
///
///@{

struct FilterGetBaseRate
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_GET_FILTER_BASE_RATE;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_FILTER_BASE_RATE;
        
        uint16_t rate = 0; ///< [hz]
        
    };
};
void insert(Serializer& serializer, const FilterGetBaseRate& self);
void extract(Serializer& serializer, FilterGetBaseRate& self);

void insert(Serializer& serializer, const FilterGetBaseRate::Response& self);
void extract(Serializer& serializer, FilterGetBaseRate::Response& self);

CmdResult filterGetBaseRate(C::mip_interface& device, uint16_t* rateOut);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_poll_data  (0x0C,0x0D) Poll Data [CPP]
/// Poll the device for a message with the specified descriptor set and format.
/// 
/// This function polls for a message using the provided format. The resulting message
/// will maintain the order of descriptors sent in the command and any unrecognized
/// descriptors are ignored. If the format is not provided, the device will attempt to use the
/// stored format (set with the Set Message Format command.) If no format is provided
/// and there is no stored format, the device will respond with a NACK. The reply packet contains
/// an ACK/NACK field. The polled data packet is sent separately as a normal Data packet.
///
///@{

struct PollData
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_POLL_DATA;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    uint8_t desc_set = 0; ///< Data descriptor set. Must be supported.
    bool suppress_ack = 0; ///< Suppress the usual ACK/NACK reply.
    uint8_t num_descriptors = 0; ///< Number of descriptors in the format list.
    uint8_t* descriptors = {nullptr}; ///< Descriptor format list.
    
};
void insert(Serializer& serializer, const PollData& self);
void extract(Serializer& serializer, PollData& self);

CmdResult pollData(C::mip_interface& device, uint8_t descSet, bool suppressAck, uint8_t numDescriptors, const uint8_t* descriptors);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_get_base_rate  (0x0C,0x0E) Get Base Rate [CPP]
/// Get the base rate for the specified descriptor set in Hz.
///
///@{

struct GetBaseRate
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_GET_BASE_RATE;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    uint8_t desc_set = 0; ///< This is the data descriptor set. It must be a supported descriptor.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_BASE_RATE;
        
        uint8_t desc_set = 0; ///< Echoes the parameter in the command.
        uint16_t rate = 0; ///< Base rate in Hz (0 = variable, unknown, or user-defined rate.  Data will be sent when received).
        
    };
};
void insert(Serializer& serializer, const GetBaseRate& self);
void extract(Serializer& serializer, GetBaseRate& self);

void insert(Serializer& serializer, const GetBaseRate::Response& self);
void extract(Serializer& serializer, GetBaseRate::Response& self);

CmdResult getBaseRate(C::mip_interface& device, uint8_t descSet, uint16_t* rateOut);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_message_format  (0x0C,0x0F) Message Format [CPP]
/// Set, read, or save the format for a given data packet.
/// 
/// The resulting data messages will maintain the order of descriptors sent in the command.
///
///@{

struct MessageFormat
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_MESSAGE_FORMAT;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t desc_set = 0; ///< Data descriptor set. Must be supported. When function is SAVE, LOAD, or DEFAULT, can be 0 to apply to all descriptor sets.
    uint8_t num_descriptors = 0; ///< Number of descriptors (limited by payload size)
    DescriptorRate* descriptors = {nullptr}; ///< List of descriptors and decimations.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_MESSAGE_FORMAT;
        
        uint8_t desc_set = 0; ///< Echoes the descriptor set from the command.
        uint8_t num_descriptors = 0; ///< Number of descriptors in the list.
        DescriptorRate* descriptors = {nullptr}; ///< List of descriptors and decimations.
        
    };
};
void insert(Serializer& serializer, const MessageFormat& self);
void extract(Serializer& serializer, MessageFormat& self);

void insert(Serializer& serializer, const MessageFormat::Response& self);
void extract(Serializer& serializer, MessageFormat::Response& self);

CmdResult writeMessageFormat(C::mip_interface& device, uint8_t descSet, uint8_t numDescriptors, const DescriptorRate* descriptors);
CmdResult readMessageFormat(C::mip_interface& device, uint8_t descSet, uint8_t* numDescriptorsOut, uint8_t numDescriptorsOutMax, DescriptorRate* descriptorsOut);
CmdResult saveMessageFormat(C::mip_interface& device, uint8_t descSet);
CmdResult loadMessageFormat(C::mip_interface& device, uint8_t descSet);
CmdResult defaultMessageFormat(C::mip_interface& device, uint8_t descSet);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_nmea_poll_data  (0x0C,0x04) Nmea Poll Data [CPP]
/// Poll the device for a NMEA message with the specified format.
/// 
/// This function polls for a NMEA message using the provided format.
/// If the format is not provided, the device will attempt to use the
/// stored format (set with the Set NMEA Message Format command.) If no format is provided
/// and there is no stored format, the device will respond with a NACK. The reply packet contains
/// an ACK/NACK field. The polled data packet is sent separately as normal NMEA messages.
///
///@{

struct NmeaPollData
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_POLL_NMEA_MESSAGE;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    bool suppress_ack = 0; ///< Suppress the usual ACK/NACK reply.
    uint8_t count = 0; ///< Number of format entries (limited by payload size)
    NmeaMessage* format_entries = {nullptr}; ///< List of format entries.
    
};
void insert(Serializer& serializer, const NmeaPollData& self);
void extract(Serializer& serializer, NmeaPollData& self);

CmdResult nmeaPollData(C::mip_interface& device, bool suppressAck, uint8_t count, const NmeaMessage* formatEntries);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_nmea_message_format  (0x0C,0x0C) Nmea Message Format [CPP]
/// Set, read, or save the NMEA message format.
///
///@{

struct NmeaMessageFormat
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_NMEA_MESSAGE_FORMAT;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t count = 0; ///< Number of format entries (limited by payload size)
    NmeaMessage* format_entries = {nullptr}; ///< List of format entries.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_NMEA_MESSAGE_FORMAT;
        
        uint8_t count = 0; ///< Number of format entries (limited by payload size)
        NmeaMessage* format_entries = {nullptr}; ///< List of format entries.
        
    };
};
void insert(Serializer& serializer, const NmeaMessageFormat& self);
void extract(Serializer& serializer, NmeaMessageFormat& self);

void insert(Serializer& serializer, const NmeaMessageFormat::Response& self);
void extract(Serializer& serializer, NmeaMessageFormat::Response& self);

CmdResult writeNmeaMessageFormat(C::mip_interface& device, uint8_t count, const NmeaMessage* formatEntries);
CmdResult readNmeaMessageFormat(C::mip_interface& device, uint8_t* countOut, uint8_t countOutMax, NmeaMessage* formatEntriesOut);
CmdResult saveNmeaMessageFormat(C::mip_interface& device);
CmdResult loadNmeaMessageFormat(C::mip_interface& device);
CmdResult defaultNmeaMessageFormat(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_device_settings  (0x0C,0x30) Device Settings [CPP]
/// Save, Load, or Reset to Default the values for all device settings.
/// 
/// When a save current settings command is issued, a brief data disturbance may occur while all settings are written to non-volatile memory.
/// 
/// This command should have a long timeout as it may take up to 1 second to complete.
///
///@{

struct DeviceSettings
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_DEVICE_STARTUP_SETTINGS;
    
    static const bool HAS_WRITE_FUNCTION = false;
    static const bool HAS_READ_FUNCTION = false;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    
};
void insert(Serializer& serializer, const DeviceSettings& self);
void extract(Serializer& serializer, DeviceSettings& self);

CmdResult saveDeviceSettings(C::mip_interface& device);
CmdResult loadDeviceSettings(C::mip_interface& device);
CmdResult defaultDeviceSettings(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_uart_baudrate  (0x0C,0x40) Uart Baudrate [CPP]
/// Read, Save, Load, or Reset to Default the baud rate of the main communication channel.
/// 
/// For all functions except 0x01 (use new settings), the new baud rate value is ignored.
/// Please see the device user manual for supported baud rates.
/// 
/// The device will wait until all incoming and outgoing data has been sent, up
/// to a maximum of 250 ms, before applying any change.
/// 
/// No guarantee is provided as to what happens to commands issued during this
/// delay period; They may or may not be processed and any responses aren't
/// guaranteed to be at one rate or the other. The same applies to data packets.
/// 
/// It is highly recommended that the device be idle before issuing this command
/// and that it be issued in its own packet. Users should wait 250 ms after
/// sending this command before further interaction.
///
///@{

struct UartBaudrate
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_UART_BAUDRATE;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint32_t baud = 0;
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_UART_BAUDRATE;
        
        uint32_t baud = 0;
        
    };
};
void insert(Serializer& serializer, const UartBaudrate& self);
void extract(Serializer& serializer, UartBaudrate& self);

void insert(Serializer& serializer, const UartBaudrate::Response& self);
void extract(Serializer& serializer, UartBaudrate::Response& self);

CmdResult writeUartBaudrate(C::mip_interface& device, uint32_t baud);
CmdResult readUartBaudrate(C::mip_interface& device, uint32_t* baudOut);
CmdResult saveUartBaudrate(C::mip_interface& device);
CmdResult loadUartBaudrate(C::mip_interface& device);
CmdResult defaultUartBaudrate(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_factory_streaming  (0x0C,0x10) Factory Streaming [CPP]
/// Configures the device for recording data for technical support.
/// 
/// This command will configure all available data streams to predefined
/// formats designed to be used with technical support.
///
///@{

struct FactoryStreaming
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_CONFIGURE_FACTORY_STREAMING;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    enum class Action : uint8_t
    {
        OVERWRITE = 0,  ///<  Replaces the message format(s), removing any existing descriptors.
        MERGE     = 1,  ///<  Merges support descriptors into existing format(s). May reorder descriptors.
        ADD       = 2,  ///<  Adds descriptors to the current message format(s) without changing existing descriptors. May result in duplicates.
    };
    
    Action action = static_cast<Action>(0);
    uint8_t reserved = 0; ///< Reserved. Set to 0x00.
    
};
void insert(Serializer& serializer, const FactoryStreaming& self);
void extract(Serializer& serializer, FactoryStreaming& self);

CmdResult factoryStreaming(C::mip_interface& device, FactoryStreaming::Action action, uint8_t reserved);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_datastream_control  (0x0C,0x11) Datastream Control [CPP]
/// Enable/disable the selected data stream.
/// 
/// Each data stream (descriptor set) can be enabled or disabled.
/// The default for the device is all streams enabled.
/// For all functions except 0x01 (use new setting),
/// the new enable flag value is ignored and can be omitted.
///
///@{

struct DatastreamControl
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_CONTROL_DATA_STREAM;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    static const uint8_t LEGACY_IMU_STREAM = 0x01;
    static const uint8_t LEGACY_GNSS_STREAM = 0x02;
    static const uint8_t LEGACY_FILTER_STREAM = 0x03;
    static const uint8_t ALL_STREAMS = 0x00;
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t desc_set = 0; ///< The descriptor set of the stream to control. When function is SAVE, LOAD, or DEFAULT, can be ALL_STREAMS(0) to apply to all descriptor sets. On Generation 5 products, this must be one of the above legacy constants.
    bool enable = 0; ///< True or false to enable or disable the stream.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_DATASTREAM_ENABLE;
        
        uint8_t desc_set = 0;
        bool enabled = 0;
        
    };
};
void insert(Serializer& serializer, const DatastreamControl& self);
void extract(Serializer& serializer, DatastreamControl& self);

void insert(Serializer& serializer, const DatastreamControl::Response& self);
void extract(Serializer& serializer, DatastreamControl::Response& self);

CmdResult writeDatastreamControl(C::mip_interface& device, uint8_t descSet, bool enable);
CmdResult readDatastreamControl(C::mip_interface& device, uint8_t descSet, bool* enabledOut);
CmdResult saveDatastreamControl(C::mip_interface& device, uint8_t descSet);
CmdResult loadDatastreamControl(C::mip_interface& device, uint8_t descSet);
CmdResult defaultDatastreamControl(C::mip_interface& device, uint8_t descSet);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_gnss_sbas_settings  (0x0C,0x22) Gnss Sbas Settings [CPP]
/// Configure the SBAS subsystem
/// 
/// 
/// 
///
///@{

struct GnssSbasSettings
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_GNSS_SBAS_SETTINGS;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    struct SBASOptions : Bitfield<SBASOptions>
    {
        enum _enumType : uint16_t
        {
            NONE               = 0x0000,
            ENABLE_RANGING     = 0x0001,
            ENABLE_CORRECTIONS = 0x0002,
            APPLY_INTEGRITY    = 0x0004,
        };
        uint16_t value = NONE;
        
        SBASOptions() : value(NONE) {}
        SBASOptions(int val) : value((uint16_t)val) {}
        operator uint16_t() const { return value; }
        SBASOptions& operator=(uint16_t val) { value = val; return *this; }
        SBASOptions& operator=(int val) { value = val; return *this; }
        SBASOptions& operator|=(uint16_t val) { return *this = value | val; }
        SBASOptions& operator&=(uint16_t val) { return *this = value & val; }
    };
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t enable_sbas = 0; ///< 0 - SBAS Disabled, 1 - SBAS enabled
    SBASOptions sbas_options; ///< SBAS options, see definition
    uint8_t num_included_prns = 0; ///< Number of SBAS PRNs to include in search (0 = include all)
    uint16_t* included_prns = {nullptr}; ///< List of specific SBAS PRNs to search for
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_GNSS_SBAS_SETTINGS;
        
        uint8_t enable_sbas = 0; ///< 0 - SBAS Disabled, 1 - SBAS enabled
        SBASOptions sbas_options; ///< SBAS options, see definition
        uint8_t num_included_prns = 0; ///< Number of SBAS PRNs to include in search (0 = include all)
        uint16_t* included_prns = {nullptr}; ///< List of specific SBAS PRNs to search for
        
    };
};
void insert(Serializer& serializer, const GnssSbasSettings& self);
void extract(Serializer& serializer, GnssSbasSettings& self);

void insert(Serializer& serializer, const GnssSbasSettings::Response& self);
void extract(Serializer& serializer, GnssSbasSettings::Response& self);

CmdResult writeGnssSbasSettings(C::mip_interface& device, uint8_t enableSbas, GnssSbasSettings::SBASOptions sbasOptions, uint8_t numIncludedPrns, const uint16_t* includedPrns);
CmdResult readGnssSbasSettings(C::mip_interface& device, uint8_t* enableSbasOut, GnssSbasSettings::SBASOptions* sbasOptionsOut, uint8_t* numIncludedPrnsOut, uint8_t numIncludedPrnsOutMax, uint16_t* includedPrnsOut);
CmdResult saveGnssSbasSettings(C::mip_interface& device);
CmdResult loadGnssSbasSettings(C::mip_interface& device);
CmdResult defaultGnssSbasSettings(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_gnss_time_assistance  (0x0C,0x24) Gnss Time Assistance [CPP]
/// Provide the GNSS subsystem with initial time information.
/// 
/// This message is required immediately after power up if GNSS Assist was enabled when the device was powered off.
/// This will initialize the subsystem clock to help reduce the time to first fix (TTFF).
///
///@{

struct GnssTimeAssistance
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_GNSS_TIME_ASSISTANCE;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = false;
    static const bool HAS_LOAD_FUNCTION = false;
    static const bool HAS_RESET_FUNCTION = false;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    double tow = 0; ///< GPS Time of week [seconds]
    uint16_t week_number = 0; ///< GPS Weeks since 1980 [weeks]
    float accuracy = 0; ///< Accuracy of time information [seconds]
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_GNSS_TIME_ASSISTANCE;
        
        double tow = 0; ///< GPS Time of week [seconds]
        uint16_t week_number = 0; ///< GPS Weeks since 1980 [weeks]
        float accuracy = 0; ///< Accuracy of time information [seconds]
        
    };
};
void insert(Serializer& serializer, const GnssTimeAssistance& self);
void extract(Serializer& serializer, GnssTimeAssistance& self);

void insert(Serializer& serializer, const GnssTimeAssistance::Response& self);
void extract(Serializer& serializer, GnssTimeAssistance::Response& self);

CmdResult writeGnssTimeAssistance(C::mip_interface& device, double tow, uint16_t weekNumber, float accuracy);
CmdResult readGnssTimeAssistance(C::mip_interface& device, double* towOut, uint16_t* weekNumberOut, float* accuracyOut);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_adv_lowpass_filter  (0x0C,0x50) Adv Lowpass Filter [CPP]
/// Advanced configuration for the IMU data quantity low-pass filters.
/// 
/// The scaled data quantities are by default filtered through a single-pole IIR low-pass filter
/// which is configured with a -3dB cutoff frequency of half the reporting frequency (set by
/// decimation factor in the IMU Message Format command) to prevent aliasing on a per data
/// quantity basis. This advanced configuration command allows for the cutoff frequency to
/// be configured independently of the data reporting frequency as well as allowing for a
/// complete bypass of the digital low-pass filter.
/// 
/// Possible data descriptors:
/// 0x04 – Scaled accelerometer data
/// 0x05 – Scaled gyro data
/// 0x06 – Scaled magnetometer data (if applicable)
/// 0x17 – Scaled pressure data (if applicable)
///
///@{

struct AdvLowpassFilter
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_ADVANCED_DATA_FILTER;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t target_descriptor = 0; ///< Field descriptor of filtered quantity within the Sensor data set. Supported values are accel (0x04), gyro (0x05), mag (0x06), and pressure (0x17), provided the data is supported by the device. Except with the READ function selector, this can be 0 to apply to all of the above quantities.
    bool enable = 0; ///< The target data will be filtered if this is true.
    bool manual = 0; ///< If false, the cutoff frequency is set to half of the streaming rate as configured by the message format command. Otherwise, the cutoff frequency is set according to the following 'frequency' parameter.
    uint16_t frequency = 0; ///< -3dB cutoff frequency in Hz. Will not affect filtering if 'manual' is false.
    uint8_t reserved = 0; ///< Reserved, set to 0x00.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_ADVANCED_DATA_FILTER;
        
        uint8_t target_descriptor = 0;
        bool enable = 0; ///< True if the filter is currently enabled.
        bool manual = 0; ///< True if the filter cutoff was manually configured.
        uint16_t frequency = 0; ///< The cutoff frequency of the filter. If the filter is in auto mode, this value is unspecified.
        uint8_t reserved = 0; ///< Reserved and must be ignored.
        
    };
};
void insert(Serializer& serializer, const AdvLowpassFilter& self);
void extract(Serializer& serializer, AdvLowpassFilter& self);

void insert(Serializer& serializer, const AdvLowpassFilter::Response& self);
void extract(Serializer& serializer, AdvLowpassFilter::Response& self);

CmdResult writeAdvLowpassFilter(C::mip_interface& device, uint8_t targetDescriptor, bool enable, bool manual, uint16_t frequency, uint8_t reserved);
CmdResult readAdvLowpassFilter(C::mip_interface& device, uint8_t targetDescriptor, bool* enableOut, bool* manualOut, uint16_t* frequencyOut, uint8_t* reservedOut);
CmdResult saveAdvLowpassFilter(C::mip_interface& device, uint8_t targetDescriptor);
CmdResult loadAdvLowpassFilter(C::mip_interface& device, uint8_t targetDescriptor);
CmdResult defaultAdvLowpassFilter(C::mip_interface& device, uint8_t targetDescriptor);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_pps_source  (0x0C,0x28) Pps Source [CPP]
/// Controls the Pulse Per Second (PPS) source.
///
///@{

struct PpsSource
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_PPS_SOURCE;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    enum class Source : uint8_t
    {
        DISABLED   = 0,  ///<  PPS output is disabled. Not valid for PPS source command.
        RECEIVER_1 = 1,  ///<  PPS is provided by GNSS receiver 1.
        RECEIVER_2 = 2,  ///<  PPS is provided by GNSS receiver 2.
        GPIO       = 3,  ///<  PPS is provided to an external GPIO pin. Use the GPIO Setup command to choose and configure the pin.
        GENERATED  = 4,  ///<  PPS is generated from the system oscillator.
    };
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    Source source = static_cast<Source>(0);
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_PPS_SOURCE;
        
        Source source = static_cast<Source>(0);
        
    };
};
void insert(Serializer& serializer, const PpsSource& self);
void extract(Serializer& serializer, PpsSource& self);

void insert(Serializer& serializer, const PpsSource::Response& self);
void extract(Serializer& serializer, PpsSource::Response& self);

CmdResult writePpsSource(C::mip_interface& device, PpsSource::Source source);
CmdResult readPpsSource(C::mip_interface& device, PpsSource::Source* sourceOut);
CmdResult savePpsSource(C::mip_interface& device);
CmdResult loadPpsSource(C::mip_interface& device);
CmdResult defaultPpsSource(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_gpio_config  (0x0C,0x41) Gpio Config [CPP]
/// Configures the user GPIO pins on the connector for use with several built-in functions or for general input or output.
/// 
/// GPIO pins are device-dependent. Some features are only available on
/// certain pins. Some behaviors require specific configurations.
/// Consult the device user manual for restrictions and default settings.
/// 
/// To avoid glitches on GPIOs configured as an output in a mode other than
/// GPIO, always configure the relevant function before setting up the pin
/// with this command. Otherwise, the pin state will be undefined between
/// this command and the one to set up the feature. For input pins, use
/// this command first so the state is well-defined when the feature is
/// initialized.
/// 
/// Some configurations can only be active on one pin at a time. If such
/// configuration is applied to a second pin, the second one will take
/// precedence and the original pin's configuration will be reset.
/// 
///
///@{

struct GpioConfig
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_GPIO_CONFIG;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    enum class Feature : uint8_t
    {
        UNUSED    = 0,  ///<  The pin is not used. It may be technically possible to read the pin state in this mode, but this is not guaranteed to be true of all devices or pins.
        GPIO      = 1,  ///<  General purpose input or output. Use this for direct control of pin output state or to stream the state of the pin.
        PPS       = 2,  ///<  Pulse per second input or output.
        ENCODER   = 3,  ///<  Motor encoder/odometer input.
        TIMESTAMP = 4,  ///<  Precision Timestamping. Use with Event Trigger Configuration (0x0C,0x2E).
        POWER     = 5,  ///<  Controls the device power state (e.g. enter low power mode).
    };
    
    enum class Behavior : uint8_t
    {
        UNUSED            = 0,  ///<  Use 0 unless otherwise specified.
        GPIO_INPUT        = 1,  ///<  Pin will be an input. This can be used to stream or poll the value and is the default setting.
        GPIO_OUTPUT_LOW   = 2,  ///<  Pin is an output initially in the LOW state. This state will be restored during system startup if the configuration is saved.
        GPIO_OUTPUT_HIGH  = 3,  ///<  Pin is an output initially in the HIGH state. This state will be restored during system startup if the configuration is saved.
        PPS_INPUT         = 1,  ///<  Pin will receive the pulse-per-second signal. Only one pin can have this behavior. This will only work if the PPS Source command is configured to GPIO.
        PPS_OUTPUT        = 2,  ///<  Pin will transmit the pulse-per-second signal from the device.
        ENCODER_A         = 1,  ///<  Encoder "A" quadrature input. Only one pin can have this behavior. The last command to set this behavior will take precedence.
        ENCODER_B         = 2,  ///<  Encoder "B" quadrature input. Only one pin can have this behavior. The last command to set this behavior will take precedence.
        TIMESTAMP_RISING  = 1,  ///<  Rising edges will be timestamped.
        TIMESTAMP_FALLING = 2,  ///<  Falling edges will be timestamped.
        TIMESTAMP_EITHER  = 3,  ///<  Both rising and falling edges will be timestamped.
        POWER_SHUTDOWN    = 1,  ///<  A logic 1 applied to the pin will place the device in low-power mode. A full restart is executed after the signal is removed.
    };
    
    struct PinMode : Bitfield<PinMode>
    {
        enum _enumType : uint8_t
        {
            NONE       = 0x00,
            OPEN_DRAIN = 0x01,
            PULLDOWN   = 0x02,
            PULLUP     = 0x04,
        };
        uint8_t value = NONE;
        
        PinMode() : value(NONE) {}
        PinMode(int val) : value((uint8_t)val) {}
        operator uint8_t() const { return value; }
        PinMode& operator=(uint8_t val) { value = val; return *this; }
        PinMode& operator=(int val) { value = val; return *this; }
        PinMode& operator|=(uint8_t val) { return *this = value | val; }
        PinMode& operator&=(uint8_t val) { return *this = value & val; }
    };
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t pin = 0; ///< GPIO pin number counting from 1. For save, load, and default function selectors, this can be 0 to select all pins.
    Feature feature = static_cast<Feature>(0); ///< Determines how the pin will be used.
    Behavior behavior = static_cast<Behavior>(0); ///< Select an appropriate value from the enumeration based on the selected feature (e.g. for PPS, select one of the values prefixed with PPS_.)
    PinMode pin_mode; ///< GPIO configuration. May be restricted depending on device, pin, feature, and behavior. See device user manual.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_GPIO_CONFIG;
        
        uint8_t pin = 0; ///< GPIO pin number counting from 1. For save, load, and default function selectors, this can be 0 to select all pins.
        Feature feature = static_cast<Feature>(0); ///< Determines how the pin will be used.
        Behavior behavior = static_cast<Behavior>(0); ///< Select an appropriate value from the enumeration based on the selected feature (e.g. for PPS, select one of the values prefixed with PPS_.)
        PinMode pin_mode; ///< GPIO configuration. May be restricted depending on device, pin, feature, and behavior. See device user manual.
        
    };
};
void insert(Serializer& serializer, const GpioConfig& self);
void extract(Serializer& serializer, GpioConfig& self);

void insert(Serializer& serializer, const GpioConfig::Response& self);
void extract(Serializer& serializer, GpioConfig::Response& self);

CmdResult writeGpioConfig(C::mip_interface& device, uint8_t pin, GpioConfig::Feature feature, GpioConfig::Behavior behavior, GpioConfig::PinMode pinMode);
CmdResult readGpioConfig(C::mip_interface& device, uint8_t pin, GpioConfig::Feature* featureOut, GpioConfig::Behavior* behaviorOut, GpioConfig::PinMode* pinModeOut);
CmdResult saveGpioConfig(C::mip_interface& device, uint8_t pin);
CmdResult loadGpioConfig(C::mip_interface& device, uint8_t pin);
CmdResult defaultGpioConfig(C::mip_interface& device, uint8_t pin);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_gpio_state  (0x0C,0x42) Gpio State [CPP]
/// Allows the state of the pin to be read or controlled.
/// 
/// This command serves two purposes: 1) To allow reading the state of a pin via command,
/// rather than polling a data quantity, and 2) to provide a way to set the output state
/// without also having to specify the operating mode.
/// 
/// The state read back from the pin is the physical state of the pin, rather than a
/// configuration value. The state can be read regardless of its configuration as long as
/// the device supports GPIO input on that pin. If the pin is set to an output, the read
/// value would match the output value.
/// 
/// While the state of a pin can always be set, it will only have an observable effect if
/// the pin is set to output mode.
/// 
/// This command does not support saving, loading, or reseting the state. Instead, use the
/// GPIO Configuration command, which allows the initial state to be configured.
///
///@{

struct GpioState
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_GPIO_STATE;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = false;
    static const bool HAS_LOAD_FUNCTION = false;
    static const bool HAS_RESET_FUNCTION = false;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t pin = 0; ///< GPIO pin number counting from 1. Cannot be 0.
    bool state = 0; ///< The pin state.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_GPIO_STATE;
        
        uint8_t pin = 0; ///< GPIO pin number counting from 1. Cannot be 0.
        bool state = 0; ///< The pin state.
        
    };
};
void insert(Serializer& serializer, const GpioState& self);
void extract(Serializer& serializer, GpioState& self);

void insert(Serializer& serializer, const GpioState::Response& self);
void extract(Serializer& serializer, GpioState::Response& self);

CmdResult writeGpioState(C::mip_interface& device, uint8_t pin, bool state);
CmdResult readGpioState(C::mip_interface& device, uint8_t pin, bool* stateOut);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_odometer  (0x0C,0x43) Odometer [CPP]
/// Configures the hardware odometer interface.
/// 
///
///@{

struct Odometer
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_ODOMETER_CONFIG;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    enum class Mode : uint8_t
    {
        DISABLED   = 0,  ///<  Encoder is disabled.
        QUADRATURE = 2,  ///<  Quadrature encoder mode.
    };
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    Mode mode = static_cast<Mode>(0); ///< Mode setting.
    float scaling = 0; ///< Encoder pulses per meter of distance traveled [pulses/m]. Distance traveled is computed using the formula d = p / N * 2R * pi, where d is distance, p is the number of pulses received, N is the encoder resolution, and R is the wheel radius. By simplifying all of the parameters into one, the formula d = p / S is obtained, where s is the odometer scaling factor passed to this command. S is equivalent to N / (2R * pi) and has units of pulses / meter. N is in units of "A" pulses per revolution and R is in meters. Make this value negative if the odometer is mounted so that it rotates backwards.
    float uncertainty = 0; ///< Uncertainty in encoder counts to distance translation (1-sigma value) [m/m].
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_ODOMETER_CONFIG;
        
        Mode mode = static_cast<Mode>(0); ///< Mode setting.
        float scaling = 0; ///< Encoder pulses per meter of distance traveled [pulses/m]. Distance traveled is computed using the formula d = p / N * 2R * pi, where d is distance, p is the number of pulses received, N is the encoder resolution, and R is the wheel radius. By simplifying all of the parameters into one, the formula d = p / S is obtained, where s is the odometer scaling factor passed to this command. S is equivalent to N / (2R * pi) and has units of pulses / meter. N is in units of "A" pulses per revolution and R is in meters. Make this value negative if the odometer is mounted so that it rotates backwards.
        float uncertainty = 0; ///< Uncertainty in encoder counts to distance translation (1-sigma value) [m/m].
        
    };
};
void insert(Serializer& serializer, const Odometer& self);
void extract(Serializer& serializer, Odometer& self);

void insert(Serializer& serializer, const Odometer::Response& self);
void extract(Serializer& serializer, Odometer::Response& self);

CmdResult writeOdometer(C::mip_interface& device, Odometer::Mode mode, float scaling, float uncertainty);
CmdResult readOdometer(C::mip_interface& device, Odometer::Mode* modeOut, float* scalingOut, float* uncertaintyOut);
CmdResult saveOdometer(C::mip_interface& device);
CmdResult loadOdometer(C::mip_interface& device);
CmdResult defaultOdometer(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_get_event_support  (0x0C,0x2A) Get Event Support [CPP]
/// Lists the available trigger or action types.
/// 
/// There are a limited number of trigger and action slots available
/// in the device. Up to M triggers and N actions can be configured at once
/// in slots 1..M and 1..N respectively. M and N are identified by the
/// max_instances field in the response with the appropriate query selector.
/// 
/// Each slot can be configured as one of a variety of different types of
/// triggers or actions. The supported types are enumerated in the response
/// to this command. Additionally, there is a limit on the number of a given
/// type. In other words, while the device may support M triggers in total,
/// only a few of them maybe usable as a given type. This limit helps optimize
/// device resources. The limit is identified in the count field.
/// 
/// All of the information in this command is available in the user manual.
/// This command provides a programmatic method for obtaining the information.
/// 
///
///@{

struct GetEventSupport
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_EVENT_SUPPORT;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    enum class Query : uint8_t
    {
        TRIGGER_TYPES = 1,  ///<  Query the supported trigger types and max count for each.
        ACTION_TYPES  = 2,  ///<  Query the supported action types and max count for each.
    };
    
    struct Info
    {
        uint8_t type = 0; ///< Trigger or action type, as defined in the respective setup command.
        uint8_t count = 0; ///< This is the maximum number of instances supported for this type.
        
    };
    Query query = static_cast<Query>(0); ///< What type of information to retrieve.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_EVENT_SUPPORT;
        
        Query query = static_cast<Query>(0); ///< Query type specified in the command.
        uint8_t max_instances = 0; ///< Number of slots available. The 'instance' number for the configuration or control commands must be between 1 and this value.
        uint8_t num_entries = 0; ///< Number of supported types.
        Info entries[126]; ///< List of supported types.
        
    };
};
void insert(Serializer& serializer, const GetEventSupport& self);
void extract(Serializer& serializer, GetEventSupport& self);

void insert(Serializer& serializer, const GetEventSupport::Info& self);
void extract(Serializer& serializer, GetEventSupport::Info& self);

void insert(Serializer& serializer, const GetEventSupport::Response& self);
void extract(Serializer& serializer, GetEventSupport::Response& self);

CmdResult getEventSupport(C::mip_interface& device, GetEventSupport::Query query, uint8_t* maxInstancesOut, uint8_t* numEntriesOut, uint8_t numEntriesOutMax, GetEventSupport::Info* entriesOut);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_event_control  (0x0C,0x2B) Event Control [CPP]
/// Enables or disables event triggers.
/// 
/// Triggers can be disabled, enabled, and tested. While disabled, a trigger will
/// not evaluate its logic and effective behave like no trigger is configured.
/// A disabled trigger will not activate any actions. Triggers are disabled by default.
/// 
/// Use this command to enable (or disable) a trigger, or to place it into a test mode.
/// When in test mode, the trigger logic is disabled but the output is forced to
/// the active state, meaning that it will behave as if the trigger logic is satisfied
/// and any associated actions will execute.
///
///@{

struct EventControl
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_EVENT_CONTROL;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    enum class Mode : uint8_t
    {
        DISABLED   = 0,  ///<  Trigger is disabled.
        ENABLED    = 1,  ///<  Trigger is enabled and will work normally.
        TEST       = 2,  ///<  Forces the trigger to the active state for testing purposes.
        TEST_PULSE = 3,  ///<  Trigger is forced to the active state for one event cycle only. After the test cycle, the mode reverts to the previous state (either enabled or disabled).
    };
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t instance = 0; ///< Trigger instance to affect. 0 can be used to apply the mode to all configured triggers, except when the function selector is READ.
    Mode mode = static_cast<Mode>(0); ///< How to change the trigger state. Except when instance is 0, the corresponding trigger must be configured, i.e. not have type 0.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_EVENT_CONTROL;
        
        uint8_t instance = 0; ///< Trigger instance to affect. 0 can be used to apply the mode to all configured triggers, except when the function selector is READ.
        Mode mode = static_cast<Mode>(0); ///< How to change the trigger state. Except when instance is 0, the corresponding trigger must be configured, i.e. not have type 0.
        
    };
};
void insert(Serializer& serializer, const EventControl& self);
void extract(Serializer& serializer, EventControl& self);

void insert(Serializer& serializer, const EventControl::Response& self);
void extract(Serializer& serializer, EventControl::Response& self);

CmdResult writeEventControl(C::mip_interface& device, uint8_t instance, EventControl::Mode mode);
CmdResult readEventControl(C::mip_interface& device, uint8_t instance, EventControl::Mode* modeOut);
CmdResult saveEventControl(C::mip_interface& device, uint8_t instance);
CmdResult loadEventControl(C::mip_interface& device, uint8_t instance);
CmdResult defaultEventControl(C::mip_interface& device, uint8_t instance);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_get_event_trigger_status  (0x0C,0x2C) Get Event Trigger Status [CPP]
///
///@{

struct GetEventTriggerStatus
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_EVENT_TRIGGER_STATUS;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    struct Status : Bitfield<Status>
    {
        enum _enumType : uint8_t
        {
            NONE    = 0x00,
            ACTIVE  = 0x01,
            ENABLED = 0x02,
            TEST    = 0x04,
        };
        uint8_t value = NONE;
        
        Status() : value(NONE) {}
        Status(int val) : value((uint8_t)val) {}
        operator uint8_t() const { return value; }
        Status& operator=(uint8_t val) { value = val; return *this; }
        Status& operator=(int val) { value = val; return *this; }
        Status& operator|=(uint8_t val) { return *this = value | val; }
        Status& operator&=(uint8_t val) { return *this = value & val; }
    };
    
    struct Entry
    {
        uint8_t type = 0; ///< Configured trigger type.
        Status status; ///< Trigger status.
        
    };
    uint8_t requested_count = 0; ///< Number of entries requested. If 0, requests all trigger slots.
    uint8_t requested_instances[20] = {0}; ///< List of trigger instances to query.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_EVENT_TRIGGER_STATUS;
        
        uint8_t count = 0; ///< Number of entries requested. If requested_count was 0, this is the number of supported trigger slots.
        Entry triggers[20]; ///< A list of the configured triggers. Entries are in the order requested, or in increasing order if count was 0.
        
    };
};
void insert(Serializer& serializer, const GetEventTriggerStatus& self);
void extract(Serializer& serializer, GetEventTriggerStatus& self);

void insert(Serializer& serializer, const GetEventTriggerStatus::Entry& self);
void extract(Serializer& serializer, GetEventTriggerStatus::Entry& self);

void insert(Serializer& serializer, const GetEventTriggerStatus::Response& self);
void extract(Serializer& serializer, GetEventTriggerStatus::Response& self);

CmdResult getEventTriggerStatus(C::mip_interface& device, uint8_t requestedCount, const uint8_t* requestedInstances, uint8_t* countOut, uint8_t countOutMax, GetEventTriggerStatus::Entry* triggersOut);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_get_event_action_status  (0x0C,0x2D) Get Event Action Status [CPP]
///
///@{

struct GetEventActionStatus
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_EVENT_ACTION_STATUS;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    struct Entry
    {
        uint8_t action_type = 0; ///< Configured action type.
        uint8_t trigger_id = 0; ///< Associated trigger instance.
        
    };
    uint8_t requested_count = 0; ///< Number of entries requested. If 0, requests all action slots.
    uint8_t requested_instances[20] = {0}; ///< List of action instances to query.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_EVENT_ACTION_STATUS;
        
        uint8_t count = 0; ///< Number of entries requested. If requested_count was 0, this is the number of supported action slots.
        Entry actions[20]; ///< A list of the configured actions. Entries are in the order requested, or in increasing order if count was 0.
        
    };
};
void insert(Serializer& serializer, const GetEventActionStatus& self);
void extract(Serializer& serializer, GetEventActionStatus& self);

void insert(Serializer& serializer, const GetEventActionStatus::Entry& self);
void extract(Serializer& serializer, GetEventActionStatus::Entry& self);

void insert(Serializer& serializer, const GetEventActionStatus::Response& self);
void extract(Serializer& serializer, GetEventActionStatus::Response& self);

CmdResult getEventActionStatus(C::mip_interface& device, uint8_t requestedCount, const uint8_t* requestedInstances, uint8_t* countOut, uint8_t countOutMax, GetEventActionStatus::Entry* actionsOut);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_event_trigger  (0x0C,0x2E) Event Trigger [CPP]
/// Configures various types of event triggers.
///
///@{

struct EventTrigger
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_EVENT_TRIGGER_CONFIG;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    struct GpioParams
    {
        enum class Mode : uint8_t
        {
            DISABLED   = 0,  ///<  The pin will have no effect and the trigger will never activate.
            WHILE_HIGH = 1,  ///<  The trigger will be active while the pin is high.
            WHILE_LOW  = 2,  ///<  The trigger will be active while the pin is low.
            EDGE       = 4,  ///<  Use if the pin is configured for timestamping via the 3DM Gpio Configuration command (0x0C41).
        };
        
        uint8_t pin = 0; ///< GPIO pin number.
        Mode mode = static_cast<Mode>(0); ///< How the pin state affects the trigger.
        
    };
    struct ThresholdParams
    {
        enum class Type : uint8_t
        {
            WINDOW   = 1,  ///<  Window comparison. Trigger is active if low_thres &lt;= value &lt;= high_thres. If the thresholds are reversed, the trigger is active when value &lt; high_thres or value &gt; low_thres.
            INTERVAL = 2,  ///<  Trigger at evenly-spaced intervals. Normally used with time fields to trigger periodically. Trigger is active when (value % interval) &lt;= int_thres. If the thresholds are reversed (high_thres &lt; low_thres) then the trigger is active when (value % low_thres) &gt; high_thres.
        };
        
        uint8_t desc_set = 0; ///< Descriptor set of target data quantity.
        uint8_t field_desc = 0; ///< Field descriptor of target data quantity.
        uint8_t param_id = 0; ///< 1-based index of the target parameter within the MIP field. E.g. for Scaled Accel (0x80,0x04) a value of 2 would represent the Y axis.
        Type type = static_cast<Type>(0); ///< Determines the type of comparison.
        union
        {
            double low_thres;
            double int_thres;
        };
        union
        {
            double high_thres;
            double interval;
        };
        
    };
    struct CombinationParams
    {
        static const uint16_t LOGIC_NEVER = 0x0000;
        static const uint16_t LOGIC_ALWAYS = 0xFFFF;
        static const uint16_t LOGIC_NONE = 0x0001;
        static const uint16_t LOGIC_OR = 0xFFFE;
        static const uint16_t LOGIC_NAND = 0x7FFF;
        static const uint16_t LOGIC_XOR_ONE = 0x0116;
        static const uint16_t LOGIC_ONLY_A = 0x0002;
        static const uint16_t LOGIC_ONLY_B = 0x0004;
        static const uint16_t LOGIC_ONLY_C = 0x0010;
        static const uint16_t LOGIC_ONLY_D = 0x0100;
        static const uint16_t LOGIC_AND_AB = 0x8888;
        static const uint16_t LOGIC_AB_OR_C = 0xF8F8;
        static const uint16_t LOGIC_AND = 0x8000;
        uint16_t logic_table = 0; ///< The last column of a truth table describing the output given the state of each input.
        uint8_t input_triggers[4] = {0}; ///< List of trigger IDs for inputs. Use 0 for unused inputs.
        
    };
    enum class Type : uint8_t
    {
        NONE        = 0,  ///<  No trigger selected. The state will always be inactive.
        GPIO        = 1,  ///<  Trigger based on the state of a GPIO pin. See GpioParams.
        THRESHOLD   = 2,  ///<  Compare a data quantity against a high and low threshold. See ThresholdParams.
        COMBINATION = 3,  ///<  Logical combination of two or more triggers. See CombinationParams.
    };
    
    union Parameters
    {
        Parameters() {}
        GpioParams gpio;
        ThresholdParams threshold;
        CombinationParams combination;
    };
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t instance = 0; ///< Trigger number. When function is SAVE, LOAD, or DEFAULT, this can be 0 to apply to all instances.
    Type type = static_cast<Type>(0); ///< Type of trigger to configure.
    Parameters parameters;
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_EVENT_TRIGGER_CONFIG;
        
        uint8_t instance = 0; ///< Trigger number. When function is SAVE, LOAD, or DEFAULT, this can be 0 to apply to all instances.
        Type type = static_cast<Type>(0); ///< Type of trigger to configure.
        Parameters parameters;
        
    };
};
void insert(Serializer& serializer, const EventTrigger& self);
void extract(Serializer& serializer, EventTrigger& self);

void insert(Serializer& serializer, const EventTrigger::GpioParams& self);
void extract(Serializer& serializer, EventTrigger::GpioParams& self);

void insert(Serializer& serializer, const EventTrigger::ThresholdParams& self);
void extract(Serializer& serializer, EventTrigger::ThresholdParams& self);

void insert(Serializer& serializer, const EventTrigger::CombinationParams& self);
void extract(Serializer& serializer, EventTrigger::CombinationParams& self);

void insert(Serializer& serializer, const EventTrigger::Response& self);
void extract(Serializer& serializer, EventTrigger::Response& self);

CmdResult writeEventTrigger(C::mip_interface& device, uint8_t instance, EventTrigger::Type type, const EventTrigger::Parameters& parameters);
CmdResult readEventTrigger(C::mip_interface& device, uint8_t instance, EventTrigger::Type* typeOut, EventTrigger::Parameters* parametersOut);
CmdResult saveEventTrigger(C::mip_interface& device, uint8_t instance);
CmdResult loadEventTrigger(C::mip_interface& device, uint8_t instance);
CmdResult defaultEventTrigger(C::mip_interface& device, uint8_t instance);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_event_action  (0x0C,0x2F) Event Action [CPP]
/// Configures various types of event actions.
///
///@{

struct EventAction
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_EVENT_ACTION_CONFIG;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    struct GpioParams
    {
        enum class Mode : uint8_t
        {
            DISABLED     = 0,  ///<  Pin state will not be changed.
            ACTIVE_HIGH  = 1,  ///<  Pin will be set high when the trigger is active and low otherwise.
            ACTIVE_LOW   = 2,  ///<  Pin will be set low when the trigger is active and high otherwise.
            ONESHOT_HIGH = 5,  ///<  Pin will be set high each time the trigger activates. It will not be set low.
            ONESHOT_LOW  = 6,  ///<  Pin will be set low each time the trigger activates. It will not be set high.
            TOGGLE       = 7,  ///<  Pin will change to the opposite state each time the trigger activates.
        };
        
        uint8_t pin = 0; ///< GPIO pin number.
        Mode mode = static_cast<Mode>(0); ///< Behavior of the pin.
        
    };
    struct MessageParams
    {
        uint8_t desc_set = 0; ///< MIP data descriptor set.
        uint16_t decimation = 0; ///< Decimation from the base rate. If 0, a packet is emitted each time the trigger activates. Otherwise, packets will be streamed while the trigger is active. The internal decimation counter is reset if the trigger deactivates.
        uint8_t num_fields = 0; ///< Number of mip fields in the packet. Limited to 12.
        uint8_t descriptors[20] = {0}; ///< List of field descriptors.
        
    };
    enum class Type : uint8_t
    {
        NONE    = 0,  ///<  No action. Parameters should be empty.
        GPIO    = 1,  ///<  Control the state of a GPIO pin. See GpioParameters.
        MESSAGE = 2,  ///<  Output a data packet. See MessageParameters.
    };
    
    union Parameters
    {
        Parameters() {}
        GpioParams gpio;
        MessageParams message;
    };
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    uint8_t instance = 0; ///< Action number. When function is SAVE, LOAD, or DEFAULT, this can be 0 to apply to all instances.
    uint8_t trigger = 0; ///< Trigger ID number.
    Type type = static_cast<Type>(0); ///< Type of action to configure.
    Parameters parameters;
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_EVENT_ACTION_CONFIG;
        
        uint8_t instance = 0; ///< Action number. When function is SAVE, LOAD, or DEFAULT, this can be 0 to apply to all instances.
        uint8_t trigger = 0; ///< Trigger ID number.
        Type type = static_cast<Type>(0); ///< Type of action to configure.
        Parameters parameters;
        
    };
};
void insert(Serializer& serializer, const EventAction& self);
void extract(Serializer& serializer, EventAction& self);

void insert(Serializer& serializer, const EventAction::GpioParams& self);
void extract(Serializer& serializer, EventAction::GpioParams& self);

void insert(Serializer& serializer, const EventAction::MessageParams& self);
void extract(Serializer& serializer, EventAction::MessageParams& self);

void insert(Serializer& serializer, const EventAction::Response& self);
void extract(Serializer& serializer, EventAction::Response& self);

CmdResult writeEventAction(C::mip_interface& device, uint8_t instance, uint8_t trigger, EventAction::Type type, const EventAction::Parameters& parameters);
CmdResult readEventAction(C::mip_interface& device, uint8_t instance, uint8_t* triggerOut, EventAction::Type* typeOut, EventAction::Parameters* parametersOut);
CmdResult saveEventAction(C::mip_interface& device, uint8_t instance);
CmdResult loadEventAction(C::mip_interface& device, uint8_t instance);
CmdResult defaultEventAction(C::mip_interface& device, uint8_t instance);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_accel_bias  (0x0C,0x37) Accel Bias [CPP]
/// Configures the user specified accelerometer bias
/// 
/// The user specified bias is subtracted from the calibrated accelerometer output.  Value is input in the sensor frame.
///
///@{

struct AccelBias
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_ACCEL_BIAS;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    float bias[3] = {0}; ///< accelerometer bias in the sensor frame (x,y,z) [g]
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_ACCEL_BIAS_VECTOR;
        
        float bias[3] = {0}; ///< accelerometer bias in the sensor frame (x,y,z) [g]
        
    };
};
void insert(Serializer& serializer, const AccelBias& self);
void extract(Serializer& serializer, AccelBias& self);

void insert(Serializer& serializer, const AccelBias::Response& self);
void extract(Serializer& serializer, AccelBias::Response& self);

CmdResult writeAccelBias(C::mip_interface& device, const float* bias);
CmdResult readAccelBias(C::mip_interface& device, float* biasOut);
CmdResult saveAccelBias(C::mip_interface& device);
CmdResult loadAccelBias(C::mip_interface& device);
CmdResult defaultAccelBias(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_gyro_bias  (0x0C,0x38) Gyro Bias [CPP]
/// Configures the user specified gyroscope bias
/// 
/// The user specified bias is subtracted from the calibrated angular rate output.  Value is input in the sensor frame.
///
///@{

struct GyroBias
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_GYRO_BIAS;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    float bias[3] = {0}; ///< gyro bias in the sensor frame (x,y,z) [radians/second]
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_GYRO_BIAS_VECTOR;
        
        float bias[3] = {0}; ///< gyro bias in the sensor frame (x,y,z) [radians/second]
        
    };
};
void insert(Serializer& serializer, const GyroBias& self);
void extract(Serializer& serializer, GyroBias& self);

void insert(Serializer& serializer, const GyroBias::Response& self);
void extract(Serializer& serializer, GyroBias::Response& self);

CmdResult writeGyroBias(C::mip_interface& device, const float* bias);
CmdResult readGyroBias(C::mip_interface& device, float* biasOut);
CmdResult saveGyroBias(C::mip_interface& device);
CmdResult loadGyroBias(C::mip_interface& device);
CmdResult defaultGyroBias(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_capture_gyro_bias  (0x0C,0x39) Capture Gyro Bias [CPP]
/// Samples gyro for a specified time range and writes the averaged result to the Gyro Bias vector in RAM
/// 
/// The device will average the gyro output for the duration of "averaging_time_ms." To store the resulting vector
/// in non-volatile memory, use the Set Gyro Bias command.
/// IMPORTANT: The device must be stationary and experiencing minimum vibration for the duration of "averaging_time_ms"
/// Averaging Time range: 1000 to 30,000
///
///@{

struct CaptureGyroBias
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_CAPTURE_GYRO_BIAS;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    uint16_t averaging_time_ms = 0; ///< Averaging time [milliseconds]
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_GYRO_BIAS_VECTOR;
        
        float bias[3] = {0}; ///< gyro bias in the sensor frame (x,y,z) [radians/second]
        
    };
};
void insert(Serializer& serializer, const CaptureGyroBias& self);
void extract(Serializer& serializer, CaptureGyroBias& self);

void insert(Serializer& serializer, const CaptureGyroBias::Response& self);
void extract(Serializer& serializer, CaptureGyroBias::Response& self);

CmdResult captureGyroBias(C::mip_interface& device, uint16_t averagingTimeMs, float* biasOut);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_mag_hard_iron_offset  (0x0C,0x3A) Mag Hard Iron Offset [CPP]
/// Configure the user specified magnetometer hard iron offset vector
/// 
/// The values for this offset are determined empirically by external software algorithms
/// based on calibration data taken after the device is installed in its application. These values
/// can be obtained and set by using the LORD "MIP Iron Calibration" application.
/// Alternatively, on some systems, the auto-mag calibration feature may be used to capture these values in-run.
/// The offset is applied to the scaled magnetometer vector prior to output.
///
///@{

struct MagHardIronOffset
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_HARD_IRON_OFFSET;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    float offset[3] = {0}; ///< hard iron offset in the sensor frame (x,y,z) [Gauss]
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_HARD_IRON_OFFSET_VECTOR;
        
        float offset[3] = {0}; ///< hard iron offset in the sensor frame (x,y,z) [Gauss]
        
    };
};
void insert(Serializer& serializer, const MagHardIronOffset& self);
void extract(Serializer& serializer, MagHardIronOffset& self);

void insert(Serializer& serializer, const MagHardIronOffset::Response& self);
void extract(Serializer& serializer, MagHardIronOffset::Response& self);

CmdResult writeMagHardIronOffset(C::mip_interface& device, const float* offset);
CmdResult readMagHardIronOffset(C::mip_interface& device, float* offsetOut);
CmdResult saveMagHardIronOffset(C::mip_interface& device);
CmdResult loadMagHardIronOffset(C::mip_interface& device);
CmdResult defaultMagHardIronOffset(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_mag_soft_iron_matrix  (0x0C,0x3B) Mag Soft Iron Matrix [CPP]
/// Configure the user specified magnetometer soft iron offset matrix
/// 
/// The values for this matrix are determined empirically by external software algorithms
/// based on calibration data taken after the device is installed in its application. These values
/// can be obtained and set by using the LORD "MIP Iron Calibration" application.
/// Alternatively, on some systems, the auto-mag calibration feature may be used to capture these values in-run.
/// The matrix is applied to the scaled magnetometer vector prior to output.
/// 
/// The matrix is in row major order:
/// EQSTART M = \begin{bmatrix} 0 &amp; 1 &amp; 2 \\ 3 &amp; 4 &amp; 5 \\ 6 &amp; 7 &amp; 8 \end{bmatrix} EQEND
/// 
///
///@{

struct MagSoftIronMatrix
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_SOFT_IRON_MATRIX;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    float offset[9] = {0}; ///< soft iron matrix [dimensionless]
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_SOFT_IRON_COMP_MATRIX;
        
        float offset[9] = {0}; ///< soft iron matrix [dimensionless]
        
    };
};
void insert(Serializer& serializer, const MagSoftIronMatrix& self);
void extract(Serializer& serializer, MagSoftIronMatrix& self);

void insert(Serializer& serializer, const MagSoftIronMatrix::Response& self);
void extract(Serializer& serializer, MagSoftIronMatrix::Response& self);

CmdResult writeMagSoftIronMatrix(C::mip_interface& device, const float* offset);
CmdResult readMagSoftIronMatrix(C::mip_interface& device, float* offsetOut);
CmdResult saveMagSoftIronMatrix(C::mip_interface& device);
CmdResult loadMagSoftIronMatrix(C::mip_interface& device);
CmdResult defaultMagSoftIronMatrix(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_sensor_2_vehicle_transform_euler  (0x0C,0x31) Sensor 2 Vehicle Transform Euler [CPP]
/// Sets the sensor-to-vehicle frame transformation using Yaw, Pitch, Roll Euler angles.
/// These are the Yaw, Pitch, and Roll mounting angles of the sensor with respect to vehicle frame of reference,
/// and describe the transformation of vectors from the sensor body frame to the vehicle frame.<br/>
/// Note: This is the transformation, the inverse of the rotation defined in our legacy products.<br/>
/// The transformation may be stored in the device as a matrix or quaternion.  When Euler angles are read back from the device, they may not
/// be exactly equal to the Euler angles used to set the transformation, but they are functionally equivalent, such that they result in the same transformation.<br/>
/// <br/><br/>
/// This transformation to the vehicle frame will be applied to the following output quantities:<br/><br/>
/// IMU:<br/>
/// Scaled Acceleration<br/>
/// Scaled Gyro<br/>
/// Scaled Magnetometer<br/>
/// Delta Theta<br/>
/// Delta Velocity<br/>
/// Complementary Filter Orientation<br/>
/// <br/><br/>
/// Estimation Filter:<br/>
/// Estimated Orientation, Quaternion<br/>
/// Estimated Orientation, Matrix<br/>
/// Estimated Orientation, Euler Angles<br/>
/// Estimated Linear Acceleration<br/>
/// Estimated Angular Rate<br/>
/// Estimated Gravity Vector<br/>
/// <br/>
/// Changing this setting will force all low-pass filters, the complementary filter, and the estimation filter to reset.
///
///@{

struct Sensor2VehicleTransformEuler
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_SENSOR2VEHICLE_TRANSFORM_EUL;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    float roll = 0; ///< [radians]
    float pitch = 0; ///< [radians]
    float yaw = 0; ///< [radians]
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_SENSOR2VEHICLE_TRANSFORM_EUL;
        
        float roll = 0; ///< [radians]
        float pitch = 0; ///< [radians]
        float yaw = 0; ///< [radians]
        
    };
};
void insert(Serializer& serializer, const Sensor2VehicleTransformEuler& self);
void extract(Serializer& serializer, Sensor2VehicleTransformEuler& self);

void insert(Serializer& serializer, const Sensor2VehicleTransformEuler::Response& self);
void extract(Serializer& serializer, Sensor2VehicleTransformEuler::Response& self);

CmdResult writeSensor2VehicleTransformEuler(C::mip_interface& device, float roll, float pitch, float yaw);
CmdResult readSensor2VehicleTransformEuler(C::mip_interface& device, float* rollOut, float* pitchOut, float* yawOut);
CmdResult saveSensor2VehicleTransformEuler(C::mip_interface& device);
CmdResult loadSensor2VehicleTransformEuler(C::mip_interface& device);
CmdResult defaultSensor2VehicleTransformEuler(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_sensor_2_vehicle_transform_quaternion  (0x0C,0x32) Sensor 2 Vehicle Transform Quaternion [CPP]
/// Set the sensor to vehicle frame transformation using unit length quaternion.
/// 
/// Note: This is the transformation, the inverse of the rotation.
/// 
/// This quaternion describes the transformation of vectors from the sensor body frame to the vehicle frame of reference, and satisfies the following relationship:<br/>
/// 
/// EQSTART p^{veh} = q^{-1} p^{sen} q EQEND<br/>
/// 
/// Where:<br/>
/// EQSTART q = (q_w, q_x, q_y, q_z) EQEND is the quaternion desrcribing the transformation. <br/>
/// EQSTART p^{sen} = (0, v^{sen}_x, v^{sen}_y, v^{sen}_z) EQEND and EQSTART v^{sen} EQEND is a 3-element vector expressed in the sensor body frame.<br/>
/// EQSTART p^{veh} = (0, v^{veh}_x, v^{veh}_y, v^{veh}_z) EQEND and EQSTART v^{veh} EQEND is a 3-element vector expressed in the vehicle frame.<br/>
/// 
/// The transformation may be stored in the device as a matrix or a quaternion.  When the quaternion is read back from the device, it may not
/// be exactly equal to the quaternion used to set the transformation, but it is functionally equivalent.<br/>
/// <br/><br/>
/// This transformation affects the following output quantities:<br/><br/>
/// IMU:<br/>
/// Scaled Acceleration<br/>
/// Scaled Gyro<br/>
/// Scaled Magnetometer<br/>
/// Delta Theta<br/>
/// Delta Velocity<br/>
/// <br/><br/>
/// Estimation Filter:<br/>
/// Estimated Orientation, Quaternion<br/>
/// Estimated Orientation, Matrix<br/>
/// Estimated Orientation, Euler Angles<br/>
/// Estimated Linear Acceleration<br/>
/// Estimated Angular Rate<br/>
/// Estimated Gravity Vector<br/>
/// <br/>
/// Changing this setting will force all low-pass filters, the complementary filter, and the estimation filter to reset.
///
///@{

struct Sensor2VehicleTransformQuaternion
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_SENSOR2VEHICLE_TRANSFORM_QUAT;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    float q[4] = {0}; ///< Unit length quaternion representing transform [w, i, j, k]
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_SENSOR2VEHICLE_TRANSFORM_QUAT;
        
        float q[4] = {0}; ///< Unit length quaternion representing transform [w, i, j, k]
        
    };
};
void insert(Serializer& serializer, const Sensor2VehicleTransformQuaternion& self);
void extract(Serializer& serializer, Sensor2VehicleTransformQuaternion& self);

void insert(Serializer& serializer, const Sensor2VehicleTransformQuaternion::Response& self);
void extract(Serializer& serializer, Sensor2VehicleTransformQuaternion::Response& self);

CmdResult writeSensor2VehicleTransformQuaternion(C::mip_interface& device, const float* q);
CmdResult readSensor2VehicleTransformQuaternion(C::mip_interface& device, float* qOut);
CmdResult saveSensor2VehicleTransformQuaternion(C::mip_interface& device);
CmdResult loadSensor2VehicleTransformQuaternion(C::mip_interface& device);
CmdResult defaultSensor2VehicleTransformQuaternion(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_sensor_2_vehicle_transform_dcm  (0x0C,0x33) Sensor 2 Vehicle Transform Dcm [CPP]
/// Set the sensor to vehicle frame transformation using a using a 3 x 3 direction cosine matrix EQSTART M_{ned}^{veh} EQEND, stored in row-major order in a 9-element array.
/// 
/// These angles define the transformation of vectors from the sensor body frame to the fixed vehicle frame, according to:<br/>
/// EQSTART v^{veh} = M_{sen}^{veh} v^{sen} EQEND<br/>
/// 
/// Where:<br/>
/// 
/// EQSTART v^{sen} EQEND is a 3-element vector expressed in the sensor body frame. <br/>
/// EQSTART v^{veh} EQEND is the same 3-element vector expressed in the vehicle frame.  <br/>
/// <br/>
/// The matrix elements are stored is row-major order: EQSTART M_{sen}^{veh} = \begin{bmatrix} M_{11}, M_{12}, M_{13}, M_{21}, M_{22}, M_{23}, M_{31}, M_{32}, M_{33} \end{bmatrix} EQEND
/// The transformation may be stored in the device as a matrix or a quaternion. When EQSTART M_{sen}^{veh} EQEND is read back from the device, it may not
/// be exactly equal to array used to set the transformation, but it is functionally equivalent.<br/>
/// <br/><br/>
/// This transformation affects the following output quantities:<br/><br/>
/// IMU:<br/>
/// Scaled Acceleration<br/>
/// Scaled Gyro<br/>
/// Scaled Magnetometer<br/>
/// Delta Theta<br/>
/// Delta Velocity<br/>
/// <br/><br/>
/// Estimation Filter:<br/>
/// Estimated Orientation, Quaternion<br/>
/// Estimated Orientation, Matrix<br/>
/// Estimated Orientation, Euler Angles<br/>
/// Estimated Linear Acceleration<br/>
/// Estimated Angular Rate<br/>
/// Estimated Gravity Vector<br/>
/// <br/>
/// Changing this setting will force all low-pass filters, the complementary filter, and the estimation filter to reset.
///
///@{

struct Sensor2VehicleTransformDcm
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_SENSOR2VEHICLE_TRANSFORM_DCM;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    float dcm[9] = {0}; ///< 3 x 3 direction cosine matrix, stored in row-major order
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_SENSOR2VEHICLE_TRANSFORM_DCM;
        
        float dcm[9] = {0}; ///< 3 x 3 direction cosine matrix, stored in row-major order
        
    };
};
void insert(Serializer& serializer, const Sensor2VehicleTransformDcm& self);
void extract(Serializer& serializer, Sensor2VehicleTransformDcm& self);

void insert(Serializer& serializer, const Sensor2VehicleTransformDcm::Response& self);
void extract(Serializer& serializer, Sensor2VehicleTransformDcm::Response& self);

CmdResult writeSensor2VehicleTransformDcm(C::mip_interface& device, const float* dcm);
CmdResult readSensor2VehicleTransformDcm(C::mip_interface& device, float* dcmOut);
CmdResult saveSensor2VehicleTransformDcm(C::mip_interface& device);
CmdResult loadSensor2VehicleTransformDcm(C::mip_interface& device);
CmdResult defaultSensor2VehicleTransformDcm(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_complementary_filter  (0x0C,0x51) Complementary Filter [CPP]
/// Configure the settings for the complementary filter which produces the following (0x80) descriptor set values: attitude matrix (0x80,09), quaternion (0x80,0A), and  Euler angle (0x80,0C) outputs.
/// 
/// The filter can be configured to correct for pitch and roll using the accelerometer (with the assumption that linear acceleration is minimal),
/// and to correct for heading using the magnetomer (with the assumption that the local magnetic field is dominated by the Earth's own magnetic field).
/// Pitch/roll and heading corrections each have their own configurable time constants, with a valid range of 1-1000 seconds. The default time constant is 10 seconds.
///
///@{

struct ComplementaryFilter
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_LEGACY_COMP_FILTER;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    bool pitch_roll_enable = 0; ///< Enable Pitch/Roll corrections
    bool heading_enable = 0; ///< Enable Heading corrections (only available on devices with magnetometer)
    float pitch_roll_time_constant = 0; ///< Time constant associated with the pitch/roll corrections [s]
    float heading_time_constant = 0; ///< Time constant associated with the heading corrections [s]
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_LEGACY_COMP_FILTER;
        
        bool pitch_roll_enable = 0; ///< Enable Pitch/Roll corrections
        bool heading_enable = 0; ///< Enable Heading corrections (only available on devices with magnetometer)
        float pitch_roll_time_constant = 0; ///< Time constant associated with the pitch/roll corrections [s]
        float heading_time_constant = 0; ///< Time constant associated with the heading corrections [s]
        
    };
};
void insert(Serializer& serializer, const ComplementaryFilter& self);
void extract(Serializer& serializer, ComplementaryFilter& self);

void insert(Serializer& serializer, const ComplementaryFilter::Response& self);
void extract(Serializer& serializer, ComplementaryFilter::Response& self);

CmdResult writeComplementaryFilter(C::mip_interface& device, bool pitchRollEnable, bool headingEnable, float pitchRollTimeConstant, float headingTimeConstant);
CmdResult readComplementaryFilter(C::mip_interface& device, bool* pitchRollEnableOut, bool* headingEnableOut, float* pitchRollTimeConstantOut, float* headingTimeConstantOut);
CmdResult saveComplementaryFilter(C::mip_interface& device);
CmdResult loadComplementaryFilter(C::mip_interface& device);
CmdResult defaultComplementaryFilter(C::mip_interface& device);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_sensor_range  (0x0C,0x52) Sensor Range [CPP]
/// Changes the IMU sensor gain.
/// 
/// This allows you to optimize the range to get the best accuracy and performance
/// while minimizing overrange events.
/// 
/// Use the 3DM Get Calibrated Sensor Ranges (0x0C,0x53) command to determine
/// the appropriate setting value for your application. Using values other than
/// those specified may result in a NACK or inaccurate measurement data.
///
///@{

struct SensorRange
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_SENSOR_RANGE;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    FunctionSelector function = static_cast<FunctionSelector>(0);
    SensorRangeType sensor = static_cast<SensorRangeType>(0); ///< Which type of sensor will get the new range value.
    uint8_t setting = 0; ///< Use the 3DM Get Calibrated Sensor Ranges (0x0C,0x53) command to determine this value.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_SENSOR_RANGE;
        
        SensorRangeType sensor = static_cast<SensorRangeType>(0); ///< Which type of sensor will get the new range value.
        uint8_t setting = 0; ///< Use the 3DM Get Calibrated Sensor Ranges (0x0C,0x53) command to determine this value.
        
    };
};
void insert(Serializer& serializer, const SensorRange& self);
void extract(Serializer& serializer, SensorRange& self);

void insert(Serializer& serializer, const SensorRange::Response& self);
void extract(Serializer& serializer, SensorRange::Response& self);

CmdResult writeSensorRange(C::mip_interface& device, SensorRangeType sensor, uint8_t setting);
CmdResult readSensorRange(C::mip_interface& device, SensorRangeType sensor, uint8_t* settingOut);
CmdResult saveSensorRange(C::mip_interface& device, SensorRangeType sensor);
CmdResult loadSensorRange(C::mip_interface& device, SensorRangeType sensor);
CmdResult defaultSensorRange(C::mip_interface& device, SensorRangeType sensor);
///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_3dm_calibrated_sensor_ranges  (0x0C,0x53) Calibrated Sensor Ranges [CPP]
/// Returns the supported sensor ranges which may be used with the 3DM Sensor Range (0x0C,0x52) command.
/// 
/// The response includes an array of (u8, float) pairs which map each allowed setting
/// to the corresponding maximum range in physical units. See SensorRangeType for units.
///
///@{

struct CalibratedSensorRanges
{
    static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::CMD_CALIBRATED_RANGES;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    struct Entry
    {
        uint8_t setting = 0; ///< The value used in the 3DM Sensor Range command and response.
        float range = 0; ///< The actual range value. Units depend on the sensor type.
        
    };
    SensorRangeType sensor = static_cast<SensorRangeType>(0); ///< The sensor to query. Cannot be ALL.
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mip::commands_3dm::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mip::commands_3dm::REPLY_CALIBRATED_RANGES;
        
        SensorRangeType sensor = static_cast<SensorRangeType>(0); ///< The sensor type from the command.
        uint8_t num_ranges = 0; ///< Number of supported ranges.
        Entry ranges[50]; ///< List of possible range settings.
        
    };
};
void insert(Serializer& serializer, const CalibratedSensorRanges& self);
void extract(Serializer& serializer, CalibratedSensorRanges& self);

void insert(Serializer& serializer, const CalibratedSensorRanges::Entry& self);
void extract(Serializer& serializer, CalibratedSensorRanges::Entry& self);

void insert(Serializer& serializer, const CalibratedSensorRanges::Response& self);
void extract(Serializer& serializer, CalibratedSensorRanges::Response& self);

CmdResult calibratedSensorRanges(C::mip_interface& device, SensorRangeType sensor, uint8_t* numRangesOut, uint8_t numRangesOutMax, CalibratedSensorRanges::Entry* rangesOut);
///@}
///

///@}
///@}
///
////////////////////////////////////////////////////////////////////////////////
} // namespace commands_3dm
} // namespace mip

