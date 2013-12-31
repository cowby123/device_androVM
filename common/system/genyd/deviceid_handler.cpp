#include <cutils/properties.h>

#include "dispatcher.hpp"

////////////////////
// Helper methods //
////////////////////

static inline std::string getStdStringProperty(const char *key)
{
    char value[PROPERTY_VALUE_MAX];
    property_get(key, value, "");

    return value;
}

// Prepare Reply object with OK status
static void buildOkReply(Reply *reply)
{
    // Make a standard Ok reply
    reply->set_type(Reply::None);
    Status *status = reply->mutable_status();
    status->set_code(Status::Ok);
}

// Prepare Reply object with OK status and a string reply
static void buildStringReply(Reply *reply, const std::string &strValue)
{
    // Build an OK reply
    buildOkReply(reply);

    // Fill reply with given string
    reply->set_type(Reply::Value);
    Value *value = reply->mutable_value();
    value->set_type(Value::String);
    value->set_stringvalue(strValue);
}

/////////////////////////////
// Genymotion daemon verbs //
/////////////////////////////

void Dispatcher::getDeviceId(const Request &request, Reply *reply)
{
    // Read Device ID
    std::string deviceId = getStdStringProperty(DEVICE_ID);
    SLOGD("Getting DeviceID value: '%s'", deviceId.c_str());

    // Build reply
    buildStringReply(reply, deviceId);
}

void Dispatcher::setDeviceId(const Request &request, Reply *reply)
{
    // Read Device ID from request
    std::string deviceId = request.parameter().value().stringvalue();

    SLOGD("Setting DeviceID value to '%s'", deviceId.c_str());

    // Apply new DeviceID by setting property
    property_set(DEVICE_ID, deviceId.c_str());

    // Build standard OK reply;
    buildOkReply(reply);
}

void Dispatcher::getAndroidId(const Request &request, Reply *reply)
{
    SLOGE("Getting AndroidID");

    // Read android ID
    std::string androidId = getStdStringProperty(ANDROID_ID);

    SLOGD("Getting AndroidID value: '%s'", androidId.c_str());

    // Build reply
    buildStringReply(reply, androidId);
}

void Dispatcher::setAndroidId(const Request &request, Reply *reply)
{
    // Read Device ID from request
    std::string androidId = request.parameter().value().stringvalue();

    SLOGD("Setting AndroidID value to '%s'", androidId.c_str());

    // Apply new DeviceID by setting property
    property_set(ANDROID_ID, androidId.c_str());

    // Build standard OK reply;
    buildOkReply(reply);
}
