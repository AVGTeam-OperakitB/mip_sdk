
#include "commands_base.h"

#include "utils/serialization.h"

#include <assert.h>



////////////////////////////////////////////////////////////////////////////////
// Shared Type Definitions
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Mip Fields
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
size_t insert_MipCmd_Base_Ping(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_Ping* self)
{
    return offset;
}

size_t extract_MipCmd_Base_Ping(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_Ping* self)
{
    return offset;
}


////////////////////////////////////////////////////////////////////////////////
size_t insert_MipCmd_Base_SetIdle(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_SetIdle* self)
{
    return offset;
}

size_t extract_MipCmd_Base_SetIdle(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_SetIdle* self)
{
    return offset;
}


////////////////////////////////////////////////////////////////////////////////
size_t insert_MipCmd_Base_GetDeviceInfo(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_GetDeviceInfo* self)
{
    return offset;
}

size_t extract_MipCmd_Base_GetDeviceInfo(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_GetDeviceInfo* self)
{
    return offset;
}


size_t insert_MipCmd_Base_GetDeviceInfo_Response(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_GetDeviceInfo_Response* self)
{
    offset = insert_Mipbase_device_info(buffer, bufferSize, offset, &self->device_info);
    
    return offset;
}

size_t extract_MipCmd_Base_GetDeviceInfo_Response(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_GetDeviceInfo_Response* self)
{
    offset = extract_Mipbase_device_info(buffer, bufferSize, offset, &self->device_info);
    
    return offset;
}


////////////////////////////////////////////////////////////////////////////////
size_t insert_MipCmd_Base_GetDeviceDescriptors(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_GetDeviceDescriptors* self)
{
    return offset;
}

size_t extract_MipCmd_Base_GetDeviceDescriptors(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_GetDeviceDescriptors* self)
{
    return offset;
}


size_t insert_MipCmd_Base_GetDeviceDescriptors_Response(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_GetDeviceDescriptors_Response* self)
{
    
    assert(self->descriptors_count <= 253);
    for(unsigned int i=0; i < self->descriptors_count; i++)
        offset = insert_u16(buffer, bufferSize, offset, self->descriptors[i]);
    offset = insert_u8(buffer, bufferSize, offset, self->descriptors_count);
    
    return offset;
}

size_t extract_MipCmd_Base_GetDeviceDescriptors_Response(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_GetDeviceDescriptors_Response* self)
{
    
    assert(self->descriptors_count <= 253);
    for(unsigned int i=0; i < self->descriptors_count; i++)
        offset = extract_u16(buffer, bufferSize, offset, &self->descriptors[i]);
    offset = extract_u8(buffer, bufferSize, offset, &self->descriptors_count);
    
    return offset;
}


////////////////////////////////////////////////////////////////////////////////
size_t insert_MipCmd_Base_BuiltInTest(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_BuiltInTest* self)
{
    return offset;
}

size_t extract_MipCmd_Base_BuiltInTest(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_BuiltInTest* self)
{
    return offset;
}


size_t insert_MipCmd_Base_BuiltInTest_Response(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_BuiltInTest_Response* self)
{
    offset = insert_u32(buffer, bufferSize, offset, self->result);
    
    return offset;
}

size_t extract_MipCmd_Base_BuiltInTest_Response(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_BuiltInTest_Response* self)
{
    offset = extract_u32(buffer, bufferSize, offset, &self->result);
    
    return offset;
}


////////////////////////////////////////////////////////////////////////////////
size_t insert_MipCmd_Base_Resume(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_Resume* self)
{
    return offset;
}

size_t extract_MipCmd_Base_Resume(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_Resume* self)
{
    return offset;
}


////////////////////////////////////////////////////////////////////////////////
size_t insert_MipCmd_Base_GetExtendedDescriptors(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_GetExtendedDescriptors* self)
{
    return offset;
}

size_t extract_MipCmd_Base_GetExtendedDescriptors(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_GetExtendedDescriptors* self)
{
    return offset;
}


size_t insert_MipCmd_Base_GetExtendedDescriptors_Response(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_GetExtendedDescriptors_Response* self)
{
    
    assert(self->descriptors_count <= 253);
    for(unsigned int i=0; i < self->descriptors_count; i++)
        offset = insert_u16(buffer, bufferSize, offset, self->descriptors[i]);
    offset = insert_u8(buffer, bufferSize, offset, self->descriptors_count);
    
    return offset;
}

size_t extract_MipCmd_Base_GetExtendedDescriptors_Response(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_GetExtendedDescriptors_Response* self)
{
    
    assert(self->descriptors_count <= 253);
    for(unsigned int i=0; i < self->descriptors_count; i++)
        offset = extract_u16(buffer, bufferSize, offset, &self->descriptors[i]);
    offset = extract_u8(buffer, bufferSize, offset, &self->descriptors_count);
    
    return offset;
}


////////////////////////////////////////////////////////////////////////////////
size_t insert_MipCmd_Base_ContinuousBit(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_ContinuousBit* self)
{
    return offset;
}

size_t extract_MipCmd_Base_ContinuousBit(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_ContinuousBit* self)
{
    return offset;
}


size_t insert_MipCmd_Base_ContinuousBit_Response(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_ContinuousBit_Response* self)
{
    
    assert(16 <= 16);
    for(unsigned int i=0; i < 16; i++)
        offset = insert_u8(buffer, bufferSize, offset, self->result[i]);
    
    return offset;
}

size_t extract_MipCmd_Base_ContinuousBit_Response(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_ContinuousBit_Response* self)
{
    
    assert(16 <= 16);
    for(unsigned int i=0; i < 16; i++)
        offset = extract_u8(buffer, bufferSize, offset, &self->result[i]);
    
    return offset;
}


////////////////////////////////////////////////////////////////////////////////
size_t insert_MipCmd_Base_CommSpeed(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_CommSpeed* self)
{
    offset = insert_MipFunctionSelector(buffer, bufferSize, offset, self->function);
    offset = insert_u8(buffer, bufferSize, offset, self->port);
    offset = insert_u32(buffer, bufferSize, offset, self->baud);
    
    return offset;
}

size_t extract_MipCmd_Base_CommSpeed(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_CommSpeed* self)
{
    offset = extract_MipFunctionSelector(buffer, bufferSize, offset, &self->function);
    offset = extract_u8(buffer, bufferSize, offset, &self->port);
    offset = extract_u32(buffer, bufferSize, offset, &self->baud);
    
    return offset;
}


size_t insert_MipCmd_Base_CommSpeed_Response(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_CommSpeed_Response* self)
{
    offset = insert_u8(buffer, bufferSize, offset, self->port);
    offset = insert_u32(buffer, bufferSize, offset, self->baud);
    
    return offset;
}

size_t extract_MipCmd_Base_CommSpeed_Response(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_CommSpeed_Response* self)
{
    offset = extract_u8(buffer, bufferSize, offset, &self->port);
    offset = extract_u32(buffer, bufferSize, offset, &self->baud);
    
    return offset;
}


////////////////////////////////////////////////////////////////////////////////
size_t insert_MipCmd_Base_GpsTimeUpdate(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_GpsTimeUpdate* self)
{
    offset = insert_MipFunctionSelector(buffer, bufferSize, offset, self->function);
    offset = insert_MipCmd_Base_GpsTimeUpdate_Fieldid(buffer, bufferSize, offset, self->field_id);
    offset = insert_u32(buffer, bufferSize, offset, self->value);
    
    return offset;
}

size_t extract_MipCmd_Base_GpsTimeUpdate(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_GpsTimeUpdate* self)
{
    offset = extract_MipFunctionSelector(buffer, bufferSize, offset, &self->function);
    offset = extract_MipCmd_Base_GpsTimeUpdate_Fieldid(buffer, bufferSize, offset, &self->field_id);
    offset = extract_u32(buffer, bufferSize, offset, &self->value);
    
    return offset;
}


////////////////////////////////////////////////////////////////////////////////
size_t insert_MipCmd_Base_SoftReset(uint8_t* buffer, size_t bufferSize, size_t offset, const struct MipCmd_Base_SoftReset* self)
{
    return offset;
}

size_t extract_MipCmd_Base_SoftReset(const uint8_t* buffer, size_t bufferSize, size_t offset, struct MipCmd_Base_SoftReset* self)
{
    return offset;
}


