﻿/*
   Copyright (c) 2017 TOSHIBA Digital Solutions Corporation

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
/*!
	@file
	@brief Definition of Client Internal Module
*/
#ifndef CLIENT_H_
#define CLIENT_H_

#ifdef GS_DLL_INSIDE
#define gsGetCollection gsGetCollection_Static
#define gsGetContainerInfo gsGetContainerInfo_Static
#define gsGetTimeSeries gsGetTimeSeries_Static
#define gsPutTimeSeries gsPutTimeSeries_Static
#define gsPutContainer gsPutContainer_Static
#define gsPutCollection gsPutCollection_Static
#define gsPutContainerGeneral gsPutContainerGeneral_Static
#define gsPutCollectionGeneral gsPutCollectionGeneral_Static
#define gsPutTimeSeriesGeneral gsPutTimeSeriesGeneral_Static
#define gsCreateRowByStore gsCreateRowByStore_Static
#define gsCreateIndexDetail gsCreateIndexDetail_Static
#define gsDropIndexDetail gsDropIndexDetail_Static
#define gsGetRowSchema gsGetRowSchema_Static
#define gsAddTime gsAddTime_Static
#endif 

#ifdef GS_CLIENT_UNIT_TEST
#define gsGetCollectionV4_3 gsGetCollectionV4_3_Stub
#define gsGetContainerInfoV1_5 gsGetContainerInfoV1_5_Stub
#define gsGetContainerInfoV2_1 gsGetContainerInfoV2_1_Stub
#define gsGetContainerInfoV3_3 gsGetContainerInfoV3_3_Stub
#define gsGetContainerInfoV4_3 gsGetContainerInfoV4_3_Stub
#define gsGetTimeSeriesV4_3 gsGetTimeSeriesV4_3_Stub
#define gsPutContainerV4_3 gsPutContainerV4_3_Stub
#define gsPutCollectionV4_3 gsPutCollectionV4_3_Stub
#define gsPutTimeSeriesV2_0 gsPutTimeSeriesV2_0_Stub
#define gsPutTimeSeriesV4_3 gsPutTimeSeriesV4_3_Stub
#define gsPutContainerGeneralV2_0 gsPutContainerGeneralV2_0_Stub
#define gsPutContainerGeneralV2_1 gsPutContainerGeneralV2_1_Stub
#define gsPutContainerGeneralV3_3 gsPutContainerGeneralV3_3_Stub
#define gsPutCollectionGeneralV2_1 gsPutCollectionGeneralV2_1_Stub
#define gsPutCollectionGeneralV3_3 gsPutCollectionGeneralV3_3_Stub
#define gsPutCollectionGeneralV4_3 gsPutCollectionGeneralV4_3_Stub
#define gsPutTimeSeriesGeneralV2_0 gsPutTimeSeriesGeneralV2_0_Stub
#define gsPutTimeSeriesGeneralV2_1 gsPutTimeSeriesGeneralV2_1_Stub
#define gsPutTimeSeriesGeneralV3_3 gsPutTimeSeriesGeneralV3_3_Stub
#define gsPutTimeSeriesGeneralV4_3 gsPutTimeSeriesGeneralV4_3_Stub
#define gsCreateRowByStoreV3_3 gsCreateRowByStoreV3_3_Stub
#define gsCreateRowByStoreV4_3 gsCreateRowByStoreV4_3_Stub
#define gsCreateIndexDetailV4_3 gsCreateIndexDetailV4_3_Stub
#define gsDropIndexDetailV4_3 gsDropIndexDetailV4_3_Stub
#define gsGetRowSchemaV2_1 gsGetRowSchemaV2_1_Stub
#define gsGetRowSchemaV3_3 gsGetRowSchemaV3_3_Stub
#define gsGetRowSchemaV4_3 gsGetRowSchemaV4_3_Stub
#define gsAddTimeV4_3 gsAddTimeV4_3_Stub
#endif 

#if !defined(GS_DEPRECATION_IGNORABLE) && defined(GS_CLIENT_UNIT_TEST)
#define GS_DEPRECATION_IGNORABLE 1
#endif

#ifndef GS_CLIENT_LOGGING_ENABLED
#define GS_CLIENT_LOGGING_ENABLED 0
#endif

#include "util/container.h"
#include "socket_wrapper.h"
#include "client_ext.h"
#include "authentication.h"
#include "service_address.h"
#include "container_key_utils.h"
#include "geometry_coder.h"
#include "gs_error_common.h"
#include "uuid/uuid.h"

#if GS_CLIENT_LOGGING_ENABLED
#include "util/trace.h"
#endif


#ifdef GS_DLL_INSIDE
#undef gsGetCollection
#undef gsGetContainerInfo
#undef gsGetTimeSeries
#undef gsPutContainer
#undef gsPutCollection
#undef gsPutTimeSeries
#undef gsPutContainerGeneral
#undef gsPutCollectionGeneral
#undef gsPutTimeSeriesGeneral
#undef gsCreateRowByStore
#undef gsCreateIndexDetail
#undef gsDropIndexDetail
#undef gsGetRowSchema
#undef gsAddTime

#ifdef __cplusplus
extern "C" {
#endif

GS_DLL_PUBLIC GSResult GS_API_CALL gsGetCollection(
		GSGridStore *store, const GSChar *name,
		const GSBinding *binding, GSCollection **collection);
GS_DLL_PUBLIC GSResult GS_API_CALL gsGetContainerInfo(
		GSGridStore *store, const GSChar *name, GSContainerInfo *info,
		GSBool *exists);
GS_DLL_PUBLIC GSResult GS_API_CALL gsGetContainerInfoV1_5(
		GSGridStore *store, const GSChar *name, GSContainerInfo *info,
		GSBool *exists);
GS_DLL_PUBLIC GSResult GS_API_CALL gsGetContainerInfoV2_1(
		GSGridStore *store, const GSChar *name, GSContainerInfo *info,
		GSBool *exists);
GS_DLL_PUBLIC GSResult GS_API_CALL gsGetContainerInfoV3_3(
		GSGridStore *store, const GSChar *name, GSContainerInfo *info,
		GSBool *exists);
GS_DLL_PUBLIC GSResult GS_API_CALL gsGetTimeSeries(
		GSGridStore *store, const GSChar *name,
		const GSBinding *binding, GSTimeSeries **timeSeries);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutContainer(
		GSGridStore *store, const GSChar *name,
		const GSBinding *binding, const GSContainerInfo *info,
		GSBool modifiable, GSContainer **container);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutCollection(
		GSGridStore *store, const GSChar *name,
		const GSBinding *binding, const GSCollectionProperties *properties,
		GSBool modifiable, GSCollection **collection);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutTimeSeries(
		GSGridStore *store, const GSChar *name,
		const GSBinding *binding, const GSTimeSeriesProperties *properties,
		GSBool modifiable, GSTimeSeries **timeSeries);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutContainerGeneral(
		GSGridStore *store, const GSChar *name,
		const GSContainerInfo *info,
		GSBool modifiable, GSContainer **container);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutContainerGeneralV2_0(
		GSGridStore *store, const GSChar *name,
		const GSContainerInfo *info,
		GSBool modifiable, GSContainer **container);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutContainerGeneralV2_1(
		GSGridStore *store, const GSChar *name,
		const GSContainerInfo *info,
		GSBool modifiable, GSContainer **container);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutContainerGeneralV3_3(
		GSGridStore *store, const GSChar *name,
		const GSContainerInfo *info,
		GSBool modifiable, GSContainer **container);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutCollectionGeneral(
		GSGridStore *store, const GSChar *name,
		const GSContainerInfo *info,
		GSBool modifiable, GSCollection **collection);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutCollectionGeneralV2_1(
		GSGridStore *store, const GSChar *name,
		const GSContainerInfo *info,
		GSBool modifiable, GSCollection **collection);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutCollectionGeneralV3_3(
		GSGridStore *store, const GSChar *name,
		const GSContainerInfo *info,
		GSBool modifiable, GSCollection **collection);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutTimeSeriesGeneral(
		GSGridStore *store, const GSChar *name,
		const GSContainerInfo *info,
		GSBool modifiable, GSTimeSeries **timeSeries);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutTimeSeriesGeneralV2_0(
		GSGridStore *store, const GSChar *name,
		const GSContainerInfo *info,
		GSBool modifiable, GSTimeSeries **timeSeries);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutTimeSeriesGeneralV2_1(
		GSGridStore *store, const GSChar *name,
		const GSContainerInfo *info,
		GSBool modifiable, GSTimeSeries **timeSeries);
GS_DLL_PUBLIC GSResult GS_API_CALL gsPutTimeSeriesGeneralV3_3(
		GSGridStore *store, const GSChar *name,
		const GSContainerInfo *info,
		GSBool modifiable, GSTimeSeries **timeSeries);
GS_DLL_PUBLIC GSResult GS_API_CALL gsCreateIndexDetail(
		GSContainer *container, const GSIndexInfo *info);
GS_DLL_PUBLIC GSResult GS_API_CALL gsDropIndexDetail(
		GSContainer *container, const GSIndexInfo *info);
GS_DLL_PUBLIC GSResult GS_API_CALL gsCreateRowByStore(
		GSGridStore *store, const GSContainerInfo *info, GSRow **row);
GS_DLL_PUBLIC GSResult GS_API_CALL gsCreateRowByStoreV3_3(
		GSGridStore *store, const GSContainerInfo *info, GSRow **row);
GS_DLL_PUBLIC GSResult GS_API_CALL gsGetRowSchema(
		GSRow *row, GSContainerInfo *schemaInfo);
GS_DLL_PUBLIC GSResult GS_API_CALL gsGetRowSchemaV2_1(
		GSRow *row, GSContainerInfo *schemaInfo);
GS_DLL_PUBLIC GSResult GS_API_CALL gsGetRowSchemaV3_3(
		GSRow *row, GSContainerInfo *schemaInfo);
GS_DLL_PUBLIC GSTimestamp GS_API_CALL gsAddTime(
		GSTimestamp timestamp, int32_t amount, GSTimeUnit timeUnit);

#ifdef __cplusplus
}
#endif

#endif	


typedef util::ByteStream<util::ArrayInStream> ArrayByteInStream;
typedef util::XArrayOutStream< std::allocator<uint8_t> > NormalXArrayOutStream;
typedef util::ByteStream<NormalXArrayOutStream> XArrayByteOutStream;

class ClientUtil {
public:
	static bool toBool(GSBool value);
	static GSBool toGSBool(bool value);
	static size_t toSizeValue(int64_t value);
	static size_t toSizeValue(int32_t value);
	static int32_t sizeValueToInt32(size_t value);
	static int64_t sizeValueToInt64(size_t value);
	template<typename T> static bool parseValue(
			const GSChar *strValue, T &resultValue);
	template<typename T> static T parseValue(const GSChar *strValue);

	static size_t copyString(
			const std::string &src, GSChar *dest, size_t destLenWithNull);
	static size_t copyString(
			const GSChar *src, size_t srcLenWithNull,
			GSChar *dest, size_t destLenWithNull) throw();

	static std::string normalizeSymbol(
			const GSChar *symbol, const GSChar *typeName);
	static std::string normalizeSymbolUnchecked(const GSChar *symbol);
	static void checkSymbol(const GSChar *symbol, const GSChar *typeName);
	static void checkBasicSymbol(const GSChar *symbol, const GSChar *typeName);
	static int32_t toASCIILower(int32_t ch);

	static bool isIPV6Address(const util::SocketAddress &address);
	static GSTimeUnit checkTimeUnit(GSTimeUnit timeUnit);
	template<typename T> static T getNonAlignedValue(const void *ptr);
	template<typename T> static void setNonAlignedValue(
			void *ptr, const T &value);

	template<typename T>
	static const T* findFromArray(
			const T *target, size_t totalByteSize, const T& value);

	template<typename C>
	static ArrayByteInStream subStream(
			const C &buf, const ArrayByteInStream &in, size_t size);


	static const uint32_t VAR_SIZE_1BYTE_THRESHOLD = 128;
	static const uint32_t VAR_SIZE_4BYTE_THRESHOLD = UINT32_C(1) << 30;
	static const uint64_t VAR_SIZE_8BYTE_THRESHOLD = UINT64_C(1) << 62;

	static inline bool varSizeIs1Byte(uint8_t val);
	static inline bool varSizeIs4Byte(uint8_t val);
	static inline bool varSizeIs8Byte(uint8_t val);

	static inline uint32_t decode1ByteVarSize(uint8_t val);
	static inline uint32_t decode4ByteVarSize(uint32_t val);
	static inline uint64_t decode8ByteVarSize(uint64_t val);

	static inline uint8_t encode1ByteVarSize(uint8_t val);
	static inline uint32_t encode4ByteVarSize(uint32_t val);
	static inline uint64_t encode8ByteVarSize(uint64_t val);


	static inline uint32_t getEncodedVarSize(size_t val);

	static void writeVarSize(XArrayByteOutStream &out, size_t val);

	static void writeVarDataString(XArrayByteOutStream &out, const GSChar* elem);

	static uint32_t readVarSize(ArrayByteInStream &in);


	inline static size_t calcNullsByteSize(size_t columnNum);

private:
	ClientUtil();
};

struct ClientVersion {
	ClientVersion() throw();
	ClientVersion(int32_t majorVersion, int32_t minorVersion) throw();

	bool since(int32_t majorVersion, int32_t minorVersion) const throw();
	bool since(const ClientVersion &another) const throw();

	int32_t majorVersion_;
	int32_t minorVersion_;
};

struct SocketAddressLess :
		public std::binary_function<util::SocketAddress, util::SocketAddress, bool> {
	bool operator()(
			const util::SocketAddress &left,
			const util::SocketAddress &right) const;
};

struct SocketAddressEqual :
		public std::binary_function<util::SocketAddress, util::SocketAddress, bool> {
	bool operator()(
			const util::SocketAddress &left,
			const util::SocketAddress &right) const;
};

template<typename L>
class DynamicLockGuard {
public:
	explicit DynamicLockGuard(L *lockObject);
	~DynamicLockGuard();

private:
	DynamicLockGuard(const DynamicLockGuard&);
	DynamicLockGuard& operator=(const DynamicLockGuard&);

	L *lockObject_;
};

class TimestampUtils {
public:
	struct RawMicroTimestamp;
	struct RawNanoTimestamp;

	static GSTimestamp current();

	static GSPreciseTimestamp getInitialPreciseTimestamp();

	static GSTimestamp getComponents(
			const GSPreciseTimestamp &timestamp, uint32_t *nanoSeconds);
	static GSPreciseTimestamp compose(
			GSTimestamp timestamp, uint32_t nanoSeconds);

	static RawMicroTimestamp microTimestampToRaw(const GSPreciseTimestamp &src);
	static GSPreciseTimestamp rawToMicroTimestamp(const RawMicroTimestamp &src);

	static RawNanoTimestamp nanoTimestampToRaw(const GSPreciseTimestamp &src);
	static GSPreciseTimestamp rawToNanoTimestamp(const RawNanoTimestamp &src);

	static int64_t getField(
			GSTimestamp timestamp, GSTimeUnit timeUnit,
			const GSTimeZone *zone);
	static int64_t getField(
			const GSPreciseTimestamp &timestamp, GSTimeUnit timeUnit,
			const GSTimeZone *zone);

	static void setField(
			GSTimestamp &timestamp, int64_t amount, GSTimeUnit timeUnit,
			const GSTimeZone *zone);
	static void setField(
			GSPreciseTimestamp &timestamp, int64_t amount, GSTimeUnit timeUnit,
			const GSTimeZone *zone);
	static void setField(
			util::PreciseDateTime &dateTime, int64_t amount, GSTimeUnit timeUnit,
			const GSTimeZone *zone);

	static GSTimestamp add(
			GSTimestamp timestamp, int64_t amount, GSTimeUnit timeUnit,
			const GSTimeZone *zone);
	static int64_t diff(
			GSTimestamp timestamp1, GSTimestamp timestamp2,
			GSTimeUnit timeUnit, const GSTimeZone *zone);

	static size_t format(
			GSTimestamp timestamp, GSChar *strBuf, size_t bufSize,
			const GSTimeZone *zone);
	static size_t format(
			const GSPreciseTimestamp &timestamp, GSChar *strBuf, size_t bufSize,
			const GSTimeZone *zone);

	static bool parse(const GSChar *str, GSTimestamp &timestamp);
	static bool parse(const GSChar *str, GSPreciseTimestamp &timestamp);

	static int64_t getZoneOffset(
			const GSTimeZone &zone, GSTimeUnit timeUnit);
	static void setZoneOffset(
			GSTimeZone &zone, int64_t offset, GSTimeUnit timeUnit);

	static size_t formatZone(
			const GSTimeZone &zone, GSChar *strBuf, size_t bufSize);
	static bool parseZone(const GSChar *str, GSTimeZone &zone);

	static GSTimestamp add(
			GSTimestamp timestamp, int64_t amount, GSTimeUnit timeUnit);
	static size_t format(
			GSTimestamp timestamp, GSChar *strBuf, size_t bufSize);

	static int32_t compare(
			const GSPreciseTimestamp &ts1, const GSPreciseTimestamp &ts2);

private:
	struct ZonedOptionSource {
		util::DateTime::FieldData fields_;
	};

	TimestampUtils();

	static util::PreciseDateTime toDateTime(
			const GSPreciseTimestamp &timestamp);
	static GSPreciseTimestamp toTimestamp(
			const util::PreciseDateTime &dateTime);

	static util::DateTime::FieldType resolveFieldType(GSTimeUnit timeUnit);

	static util::DateTime::Option resolveOption();
	static util::DateTime::ZonedOption resolveZonedOption(
			ZonedOptionSource &optionSrc, const GSTimeZone *zone);

	static util::DateTime::FieldData resolveTimestampMaxFields();
	static int64_t resolveTimestampMaxUnixTime();

	static GSTimeZone toGSZone(const util::TimeZone &src);

	static util::TimeZone resolveZone(const GSTimeZone &zone);
	static util::TimeZone resolveZone(const int64_t &offsetMillis);
};

struct TimestampUtils::RawMicroTimestamp {
	int64_t value_;
};

struct TimestampUtils::RawNanoTimestamp {
	typedef uint8_t Low;

	struct High {
		uint8_t value_[8];
	};

	union LocalHigh {
		High high_;
		int64_t longValue_;
	};

	static const int64_t HIGH_MICRO_UNIT = 4;

	void assign(int64_t high, uint8_t low) {
		LocalHigh local;
		local.longValue_ = high;
		high_ = local.high_;
		low_ = low;
	}

	int64_t getHigh() const {
		LocalHigh local;
		local.high_ = high_;
		return local.longValue_;
	}

	uint8_t getLow() const {
		return low_;
	}

	High high_;
	Low low_;
};

typedef TimestampUtils TimestampUtil;

struct Properties {
	typedef std::vector<GSPropertyEntry> EntryList;

	Properties();
	Properties(const Properties &properties);
	Properties(const GSPropertyEntry *properties, const size_t *propertyCount);

	bool containsKey(const GSChar *name) const;

	bool getInteger(const GSChar *name, int32_t &value) const;
	bool getDouble(const GSChar *name, double &value) const;
	bool getBool(const GSChar *name, bool &value) const;
	bool getString(const GSChar *name, std::string &value) const;
	const GSChar* getString(const GSChar *name) const;

	bool getTimeoutMillis(
			const GSChar *name, int64_t &value, int64_t defaultValue) const;

	void checkExclusiveProperties(
			const GSChar *name1, const GSChar *name2,
			const GSChar *name3 = NULL) const;

	void checkExclusiveProperties(
			const GSChar *const *nameList, size_t nameCount) const;

	static int32_t timeoutToInt32Seconds(int64_t value);
	static int32_t timeoutToInt32Millis(int64_t value);

	const GSPropertyEntry* toEntryList(EntryList &list) const;

	typedef std::map<std::string, std::string> PropertyMap;
	PropertyMap propertyMap_;
};


class ClientException : public GSCommonException {
public:
	typedef ClientException ParametersBuilder;

	ClientException(UTIL_EXCEPTION_CONSTRUCTOR_ARGS_DECL) throw();
	virtual ~ClientException() throw();

	void appendParameter(const char8_t *name, const char8_t *value) throw();

	size_t getParameterCount() const throw();
	const char8_t* getParameterName(size_t index) const throw();
	const char8_t* getParameterValue(size_t index) const throw();

	void inheritParameters(const std::exception *causeInHandling) throw();
	void inheritParameters(const ClientException &cause) throw();

	static void formatMessageWithParameter(
			std::ostream &os, const util::Exception &e,
			const ClientException &params);

	template<typename T> static T generateWithParameter(
			const T &base, const std::exception *causeInHandling) throw() {
		T exception = base;
		exception.inheritParameters(causeInHandling);
		return exception;
	}

private:
	typedef std::pair<u8string, u8string> Parameter;
	typedef std::vector<Parameter> ParameterList;

	ParameterList parameterList_;
};

#define GS_CLIENT_EXCEPTION_CONVERT_CUSTOM(type, errorCode, cause, message) \
		ClientException::generateWithParameter( \
				GS_COMMON_EXCEPTION_CONVERT_CUSTOM( \
						type, errorCode, cause, message), &(cause))
#define GS_CLIENT_EXCEPTION_CONVERT(errorCode, cause, message) \
		GS_CLIENT_EXCEPTION_CONVERT_CUSTOM( \
				ClientException, errorCode, cause, message)

#define GS_CLIENT_THROW_CUSTOM_ERROR(type, errorCode, message) \
		throw GS_COMMON_EXCEPTION_CREATE_DETAIL(type, errorCode, NULL, message)
#define GS_CLIENT_RETHROW_CUSTOM_ERROR(type, defaultCode, cause, message) \
		throw GS_CLIENT_EXCEPTION_CONVERT_CUSTOM( \
				type, defaultCode, cause, message)

#define GS_CLIENT_THROW_ERROR(errorCode, message) \
		GS_CLIENT_THROW_CUSTOM_ERROR(ClientException, errorCode, message)
#define GS_CLIENT_RETHROW_ERROR(cause, message) \
		GS_CLIENT_RETHROW_CUSTOM_ERROR(ClientException, 0, cause, message)
#define GS_CLIENT_RETHROW_ERROR_CODED(errorCode, cause, message) \
		GS_CLIENT_RETHROW_CUSTOM_ERROR( \
				ClientException, errorCode, cause, message)

struct ErrorStack {
public:
	size_t getSize() const throw();

	GSResult getErrorCode(size_t index) const throw();
	size_t formatErrorName(
			size_t index, GSChar *strBuf, size_t bufSize) const throw();

	size_t formatErrorDescription(
			size_t index, GSChar *strBuf, size_t bufSize) const throw();
	size_t formatErrorMessage(
			size_t index, GSChar *strBuf, size_t bufSize) const throw();
	static void formatErrorMessage(
			std::ostream &os, const util::Exception &e, size_t index,
			bool withCode);

	size_t formatErrorLocation(
			size_t index, GSChar *strBuf, size_t bufSize,
			bool detail = false) const throw();

	size_t getErrorParameterCount(size_t stackIndex) const throw();
	size_t formatErrorParameterName(
			size_t stackIndex, size_t parameterIndex,
			GSChar *strBuf, size_t bufSize) const throw();
	size_t formatErrorParameterValue(
			size_t stackIndex, size_t parameterIndex,
			GSChar *strBuf, size_t bufSize) const throw();

	void clear() throw();
	GSResult setFromCurrentException() throw();
	static ErrorStack tryRead(
			ArrayByteInStream &in,
			const util::Exception::NamedErrorCode &defaultCode) throw();

	ClientException& getException() throw();

	static void setDetailErrorMessageEnabled(bool enabled);

private:
	typedef ClientException BaseException;

	static volatile bool detailErrorMessageEnabled_;

	BaseException exception_;
};

class RemoteException : public ClientException {
protected:
	RemoteException(UTIL_EXCEPTION_CONSTRUCTOR_ARGS_DECL) throw();
	virtual ~RemoteException() throw();
};

class StatementException : public RemoteException {
public:
	StatementException(UTIL_EXCEPTION_CONSTRUCTOR_ARGS_DECL) throw();
	virtual ~StatementException() throw();
};

#define GS_CLIENT_RETHROW_STATEMENT(cause, message) \
		GS_CLIENT_RETHROW_CUSTOM_ERROR(StatementException, 0, cause, message)

class ConnectionException : public RemoteException {
public:
	ConnectionException(UTIL_EXCEPTION_CONSTRUCTOR_ARGS_DECL) throw();
	virtual ~ConnectionException() throw();
};

#define GS_CLIENT_THROW_CONNECTION(errorCode, message) \
		GS_CLIENT_THROW_CUSTOM_ERROR(ConnectionException, errorCode, message)
#define GS_CLIENT_RETHROW_CONNECTION(cause, message) \
		GS_CLIENT_RETHROW_CUSTOM_ERROR(ConnectionException, 0, cause, message)
#define GS_CLIENT_RETHROW_CONNECTION_CODED(errorCode, cause, message) \
		GS_CLIENT_RETHROW_CUSTOM_ERROR( \
				ConnectionException, errorCode, cause, message)

class WrongNodeException : public ConnectionException {
public:
	WrongNodeException(UTIL_EXCEPTION_CONSTRUCTOR_ARGS_DECL) throw();
	virtual ~WrongNodeException() throw();
};

#define GS_CLIENT_THROW_WRONG_NODE(errorCode, message) \
		GS_CLIENT_THROW_CUSTOM_ERROR(WrongNodeException, errorCode, message)
#define GS_CLIENT_RETHROW_WRONG_NODE(cause, message) \
		GS_CLIENT_RETHROW_CUSTOM_ERROR(WrongNodeException, 0, cause, message)

class ErrorReasonFormatter {
public:
	explicit ErrorReasonFormatter(const std::exception &exception);

	std::ostream& format(std::ostream &stream) const;

private:
	const std::exception &exception_;
};

std::ostream& operator<<(
		std::ostream &stream, const ErrorReasonFormatter &formatter);

enum ClientErrorCode {
	GS_ERROR_CC_INTERNAL_ERROR = 140000,
	GS_ERROR_CC_EMPTY_PARAMETER,
	GS_ERROR_CC_ILLEGAL_PARAMETER,
	GS_ERROR_CC_UNSUPPORTED_OPERATION,
	GS_ERROR_CC_SIZE_VALUE_OUT_OF_RANGE,
	GS_ERROR_CC_ILLEGAL_PROPERTY_ENTRY,
	GS_ERROR_CC_ILLEGAL_VALUE_FORMAT,
	GS_ERROR_CC_ILLEGAL_SYMBOL_CHARACTER,
	GS_ERROR_CC_UNKNOWN_COLUMN_NAME,
	GS_ERROR_CC_UNSUPPORTED_KEY_TYPE,
	GS_ERROR_CC_UNSUPPORTED_FIELD_TYPE,
	GS_ERROR_CC_UNSUPPORTED_ROW_MAPPING,
	GS_ERROR_CC_UNKNOWN_ELEMENT_TYPE_OPTION,
	GS_ERROR_CC_UNKNOWN_GEOMETRY_OPERATOR,
	GS_ERROR_CC_UNKNOWN_AGGREGATION,
	GS_ERROR_CC_UNKNOWN_TIME_OPERATOR,
	GS_ERROR_CC_UNKNOWN_INDEX_FLAG,
	GS_ERROR_CC_UNKNOWN_FETCH_OPTION,
	GS_ERROR_CC_UNKNOWN_TIME_UNIT,
	GS_ERROR_CC_UNSUPPORTED_DEFAULT_INDEX,
	GS_ERROR_CC_BINDING_ENTRY_NOT_FOUND,
	GS_ERROR_CC_MULTIPLE_KEYS_FOUND,
	GS_ERROR_CC_COLUMN_NAME_CONFLICTED,
	GS_ERROR_CC_ILLEGAL_SCHEMA,
	GS_ERROR_CC_KEY_NOT_FOUND,
	GS_ERROR_CC_KEY_NOT_ACCEPTED,
	GS_ERROR_CC_EMPTY_ROW_FIELD,
	GS_ERROR_CC_BAD_STATEMENT,
	GS_ERROR_CC_BAD_CONNECTION,
	GS_ERROR_CC_CONNECTION_TIMEOUT,
	GS_ERROR_CC_WRONG_NODE,
	GS_ERROR_CC_MESSAGE_CORRUPTED,
	GS_ERROR_CC_PARTITION_NOT_FOUND,
	GS_ERROR_CC_ILLEGAL_PARTITION_COUNT,
	GS_ERROR_CC_CONTAINER_NOT_OPENED,
	GS_ERROR_CC_ILLEGAL_COMMIT_MODE,
	GS_ERROR_CC_TRANSACTION_CLOSED,
	GS_ERROR_CC_NO_SUCH_ELEMENT,
	GS_ERROR_CC_CONTAINER_CLOSED,
	GS_ERROR_CC_NOT_LOCKED,
	GS_ERROR_CC_RESOURCE_CLOSED,
	GS_ERROR_CC_ALLOCATION_FAILED,
	GS_ERROR_CC_RECOVERABLE_CONNECTION_PROBLEM,
	GS_ERROR_CC_RECOVERABLE_ROW_SET_LOST,
	GS_ERROR_CC_ILLEGAL_CONFIG,
	GS_ERROR_CC_DATABASE_NOT_EMPTY, 
	GS_ERROR_CC_PLATFORM_ERROR
};


class RowMapper {
	friend class Cache;

public:
	enum RowTypeCategory {
		CATEGORY_COLLECTION,
		CATEGORY_TIME_SERIES,
		CATEGORY_AGGREGATION_RESULT
	};

	enum ElementType {
		ELEM_TYPE_STRING,
		ELEM_TYPE_BOOL,
		ELEM_TYPE_BYTE,
		ELEM_TYPE_SHORT,
		ELEM_TYPE_INTEGER,
		ELEM_TYPE_LONG,
		ELEM_TYPE_FLOAT,
		ELEM_TYPE_DOUBLE,
		ELEM_TYPE_TIMESTAMP,
		ELEM_TYPE_GEOMETRY,
		ELEM_TYPE_BLOB,
		ELEM_TYPE_MICRO_TIMESTAMP,
		ELEM_TYPE_NANO_TIMESTAMP,

		ELEM_TYPE_END_NORMAL,
		ELEM_TYPE_ANY_NULL = -1
	};

	enum KeyCategory {
		KEY_CATEGORY_NONE,
		KEY_CATEGORY_SINGLE,
		KEY_CATEGORY_COMPOSITE
	};

	enum MappingMode {
		MODE_NORMAL,
		MODE_ROWWISE_SEPARATED,
		MODE_ROWWISE_SEPARATED_V2, 
		MODE_COLUMNWISE_SEPARATED,
		MODE_AGGREGATED
	};

	enum SchemaFeatureLevel {

		FEATURE_LEVEL1,

		FEATURE_LEVEL2,

		FEATURE_LEVEL_NONE
	};

	struct TypeOptionMask {
		static const GSTypeOption MASK_NULLABLE =
				GS_TYPE_OPTION_NULLABLE | GS_TYPE_OPTION_NOT_NULL;
		static const GSTypeOption MASK_DEFAULT_VALUE =
				GS_TYPE_OPTION_DEFAULT_VALUE_NULL |
				GS_TYPE_OPTION_DEFAULT_VALUE_NOT_NULL;
		static const GSTypeOption MASK_PRECISION =
				GS_TYPE_OPTION_TIME_MILLI |
				GS_TYPE_OPTION_TIME_MICRO |
				GS_TYPE_OPTION_TIME_NANO;

		static const GSTypeOption MASK_GENERAL_SUPPORTED =
				MASK_NULLABLE | MASK_DEFAULT_VALUE | MASK_PRECISION;
		static const GSTypeOption MASK_BINDING_SUPPORTED =
				GS_TYPE_OPTION_KEY | MASK_GENERAL_SUPPORTED;
	};

	struct Tool;
	struct RowTool;
	struct GeneralRowHolder;
	struct Config;

	class DetailElementType;
	class Entry;

	class InputCursor;
	class OutputCursor;
	class VarDataPool;
	class Cache;
	class Reference;
	class MovableReference;

	template<ElementType ElemType, bool ArrayType> struct ObjectTypeTraits;
	template<ElementType ElemType, bool ArrayType> struct TypeTraits;

	template<bool A>
	struct ObjectTypeTraits<ELEM_TYPE_ANY_NULL, A> {
		typedef GSValue Field;
		typedef GSValue Object;
		static const GSType FULL_FIELD_TYPE = GS_TYPE_NULL;
		static Object& as(GSValue &v) { return v; }
		static const Object& as(const GSValue &v) { return v; }
	};
	typedef TypeTraits<ELEM_TYPE_ANY_NULL, false> AnyNullTraits;

	template<int> struct BindingEntryTraits;
	template<int> struct ColumnInfoTraits;
	template<int> struct IndexInfoTraits;
	class BindingRef;
	template<bool Const = false> class ContainerInfoRef;

	class BindingCursor;
	class ObjectBindingCursor;
	class StreamBindingCursor;
	class SchemaBindingCursor;
	class MapperBindingCursor;
	class ReorderedBindingCursor;

	class BindingBuilder;
	class ObjectBindingBuilder;
	class SchemaBindingBuilder;

public:
	RowMapper(
			RowTypeCategory category, const GSBinding *binding,
			const Config &config);
	RowMapper(
			const RowMapper &srcMapper, ArrayByteInStream &schemaIn,
			const Config &config, bool columnOrderIgnorable);

	static UTIL_UNIQUE_PTR<RowMapper> getInstance(
			ArrayByteInStream &in, const Config &config,
			RowTypeCategory category);

	static Cache& getDefaultCache();

	static const RowMapper& getAggregationResultMapper();
	static const RowMapper& getQueryAnalysisMapper();

	void checkSchemaMatched(const RowMapper &mapper, bool full) const;
	void checkKeySchemaMatched(const RowMapper &mapper) const;

	bool matches(
			BindingCursor &cursor, bool schemaOnly, bool schemaFull,
			bool throwOnUnmatch) const;
	bool matchBindingHead(
			RowTypeCategory category, bool general, bool nullableAllowed,
			bool throwOnUnmatch) const;

	static size_t getDigest(BindingCursor &cursor);

	GSContainerType getContainerType() const;

	void getContainerSchema(
			ContainerInfoRef<> &containerInfoRef,
			VarDataPool &varDataPool) const;
	void getKeyContainerSchema(
			ContainerInfoRef<> &containerInfoRef,
			VarDataPool &varDataPool) const;
	void peekNextRowSchema(
			InputCursor &cursor,
			UTIL_UNIQUE_PTR<RowMapper> &schemaMapper) const;

	static GSColumnInfo getColumnSchema(
			const Entry &entry, VarDataPool &varDataPool);

	RowTypeCategory getCategory() const;
	bool isGeneral() const;
	bool isNullableAllowed() const;

	size_t getEntryCount() const;
	const Entry& getEntry(size_t columnId) const;

	bool hasKey() const;
	KeyCategory getKeyCategory() const;

	GSType getElementType(int32_t columnId) const;
	bool isArray(int32_t columnId) const;
	bool hasAnyTypeColumn() const;
	bool isDefaultValueSpecified() const;

	SchemaFeatureLevel getFeatureLevel() const;
	static SchemaFeatureLevel mergeFeatureLevel(
			SchemaFeatureLevel level1, SchemaFeatureLevel level2);

	static GSBinding importSchema(
			ArrayByteInStream &in, VarDataPool *varDataPool,
			std::vector<GSBindingEntry> *entryList,
			GSContainerType *containerType, bool anyTypeAllowed);
	void exportSchema(XArrayByteOutStream &out, const Config &config) const;

	void exportKeySchemaSingle(XArrayByteOutStream &out) const;
	void exportKeySchemaComposite(XArrayByteOutStream &out) const;

	static size_t importColumnCount(ArrayByteInStream &in);
	static void exportColumnCount(
			XArrayByteOutStream &out, size_t columnCount);

	static void importKeyListBegin(
			ArrayByteInStream &in, const Config &config, size_t columnCount,
			std::vector<int32_t> &keyColumnList);
	static void importKeyListEnd(
			ArrayByteInStream &in, const Config &config, size_t columnCount,
			std::vector<int32_t> &keyColumnList,
			std::vector<GSColumnInfo> *columnInfoList);

	static void exportKeyListBegin(
			XArrayByteOutStream &out, const Config &config,
			const RowMapper *keyMapper);
	static void exportKeyListEnd(
			XArrayByteOutStream &out, const Config &config,
			const RowMapper *keyMapper);

	static GSColumnInfo importColumnSchema(
			ArrayByteInStream &in, const Config &config,
			VarDataPool &varDataPool);

	static void exportColumnSchema(
			XArrayByteOutStream &out, const Entry &entry);
	static Entry importColumnSchema(
			ArrayByteInStream &in, const bool *forKey, const Config &config);

	int32_t resolveColumnId(const GSChar *name) const;

	void encodeKeyGeneral(
			XArrayByteOutStream &out, MappingMode mode, bool keyGeneral,
			const GSType *keyType, const void *keyObj) const;
	template<typename It>
	void encodeKeyGeneral(
			XArrayByteOutStream &out, MappingMode mode, bool keyGeneral,
			const GSType *keyType, It begin, It end, size_t keyCount,
			bool withEncodedSize, bool withKeyCount) const;

	static void encodeKeyField(
			XArrayByteOutStream &out, MappingMode mode,
			const DetailElementType &keyType, const void *keyObj);

	void encodeKeyByObj(
			XArrayByteOutStream &out, MappingMode mode, const GSType *keyType,
			const void *keyObj) const;
	void encodeKeyByString(
			XArrayByteOutStream &out, MappingMode mode,
			const GSChar *keyString, OutputCursor *cursor) const;

	void encode(
			XArrayByteOutStream &out, MappingMode mode, const GSType *keyType,
			const void *keyObj, const void *rowObj) const;
	void encode(
			OutputCursor &cursor, const GSType *keyType, const void *keyObj,
			const void *rowObj) const;

	void encode(
			XArrayByteOutStream &out, MappingMode mode,
			bool keyGeneral, const GSType *keyType, const void *keyObj,
			bool rowGeneral, const void *rowObj) const;
	void encode(
			OutputCursor &cursor, bool keyGeneral, const GSType *keyType,
			const void *keyObj, bool rowGeneral, const void *rowObj) const;

	void encodeWithKeyString(
			XArrayByteOutStream &out, MappingMode mode,
			const GSChar *keyString, const void *rowObj) const;
	void encodeWithKeyString(
			XArrayByteOutStream &out, MappingMode mode,
			const GSChar *keyString, bool rowGeneral,
			const void *rowObj) const;

	void decode(
			ArrayByteInStream &in, MappingMode mode,
			VarDataPool *varDataPool, void *rowObj) const;
	void decode(InputCursor &cursor, void *rowObj) const;

	void decode(
			ArrayByteInStream &in, MappingMode mode,
			VarDataPool *varDataPool, bool rowGeneral, void *rowObj) const;
	void decode(InputCursor &cursor, bool rowGeneral, void *rowObj) const;

	void resolveKey(const void *rowObj, GSRowKey &keyObj) const;

	size_t getGeneralRowSize() const;
	size_t getGeneralRowKeySize() const;

	static void encodeGeometry(
			XArrayByteOutStream &out, const char8_t *text, MappingMode mode);

	template<typename Alloc>
	static const GSChar* findEmptyString(Alloc &alloc);
	static const GSChar* findEmptyString(VarDataPool &pool);

	template<typename Alloc>
	static const GSChar* decodeString(ArrayByteInStream &in, Alloc &alloc);
	const GSChar* decodeString(
			ArrayByteInStream &in, VarDataPool *pool, void *rowObj) const;

	template<typename Alloc>
	static const GSChar* decodeStringV2(ArrayByteInStream &in, Alloc &alloc);
	const GSChar* decodeStringV2(
			ArrayByteInStream &in, VarDataPool *pool, void *rowObj) const;

	template<typename Alloc>
	static const GSChar* readStringWithSize(
			ArrayByteInStream &in, size_t inSize, Alloc &alloc);
	template<typename Alloc>
	static const GSChar* copyString(const GSChar *src, Alloc &alloc);
	template<typename Alloc>
	static const GSChar* copyString(
			const GSChar *src, size_t srcSize, Alloc &alloc);

	static GSType toFullType(GSType type, bool arrayUsed);
	static GSType toElementType(GSType type, bool &arrayUsed);

	static bool isArrayColumn(const GSBindingEntry &entry);
	static bool isKeyColumn(const GSBindingEntry &entry);

	static Entry getEntryGeneral(
			const Entry &src, const DetailElementType &type);

	template<typename Caller, typename Operator>
	static void invokeTypedOperation(
			Caller &caller, Operator &op, const Entry &entry);

	template<typename Alloc, typename Mask>
	static GSValue copyValue(
			const GSValue &src, const DetailElementType &type, Alloc *alloc,
			const Mask&);

	template<typename Traits, typename Alloc, typename Mask, typename T>
	static GSValue copyValue(
			const GSValue &src, const Traits&, Alloc*, const Mask&, T);

	template<typename Traits, typename Alloc, typename Mask, typename E>
	static GSValue copyValue(
			const GSValue &src, const Traits&, Alloc *alloc, const Mask&,
			const E*);

	template<typename Traits, typename Alloc, typename Mask>
	static GSValue copyValue(
			const GSValue &src, const Traits&, Alloc *alloc, const Mask&,
			const GSChar *const*);

	template<typename Traits, typename Alloc, typename Mask>
	static GSValue copyValue(
			const GSValue &src, const Traits&, Alloc *alloc, const Mask&,
			GSBlob);

	static GSContainerType checkContainerType(GSContainerType type);
	static RowTypeCategory containerTypeToCategory(GSContainerType type);

	static bool isKeyType(GSType type);
	static bool isKeyColumn(GSTypeOption options);

	static bool isOptionNullable(GSTypeOption options);
	static bool isOptionInitialValueNull(GSTypeOption options);

	static GSTypeOption applyKeyOption(GSTypeOption srcOptions, bool forKey);
	static GSTypeOption applyNullableOption(
			GSTypeOption srcOptions, bool nullable, bool nullableAllowed,
			const bool *forKey);
	static GSTypeOption applyPrecisionOption(
			GSTypeOption srcOptions, const DetailElementType &type);

	static GSTypeOption filterTypeOptions(
			GSTypeOption srcOptions, const DetailElementType &type,
			const char8_t *name, const bool *forKey, bool anyTypeAllowed,
			bool nullableAllowed);
	static GSTypeOption filterColumnSchemaOptions(
			GSTypeOption srcOptions, const bool *forKey);

	static GSTypeOption filterKeyOption(
			GSTypeOption options, const bool *forKey);
	static GSTypeOption filterNullable(
			GSTypeOption options, GSTypeOption nullableDefault,
			bool nullableAllowed, bool forKey, const GSChar *columnName);
	static GSTypeOption filterInitialValueNull(
			GSTypeOption options, bool nullable,
			const GSChar *columnName);
	static GSTypeOption filterPrecision(
			GSTypeOption options, const DetailElementType &type,
			const GSChar *columnName);

	static BindingRef toBindingRef(
			const GSBinding *binding, const ClientVersion &version) throw();
	static ContainerInfoRef<true> toInfoRef(
			const GSContainerInfo *info, const ClientVersion &version) throw();

	struct Initializer {
	public:
		Initializer() throw();
		~Initializer();
	private:
		static size_t counter_;
	};

private:
	class GeometryEncoderHandler : public GeometryCoder::BinaryHandler {
	public:
		explicit GeometryEncoderHandler(XArrayByteOutStream &out);
		virtual void accept(const void *data, size_t size, uint32_t mode);

		XArrayByteOutStream &out_;
	};

	class GeometryDecoderHandler : public GeometryCoder::TextHandler {
	public:
		GeometryDecoderHandler(InputCursor &cursor, void *rowObj);
		virtual void accept(const char8_t *text);

		InputCursor &cursor_;
		void *const rowObj_;
		const char8_t *text_;
	};

	struct BaseCursor;

	class FieldLayoutBuilder {
	public:
		explicit FieldLayoutBuilder(size_t entryCount);

		Entry build(const DetailElementType &type, const Entry &src);

	private:
		size_t lastOffset_;
	};

	struct ReferenceHead {
		explicit ReferenceHead(size_t digest);

		const size_t digest_;
		size_t refCount_;
	};

	struct BindingHead {
		BindingHead(
				RowTypeCategory category, bool general, bool nullableAllowed);

		RowTypeCategory rowTypeCategory_;
		bool general_;
		bool nullableAllowed_;
	};

	struct ObjectLayout {
		ObjectLayout();

		uint32_t varColumnCount_;
		size_t nullsByteSize_;
		uint32_t nullsOffset_;
	};

	struct MapperConstants {
		static const bool ACCEPT_AGGREGATION_RESULT_COLUMN_ID;
		static const bool RESTRICT_KEY_ORDER_FIRST = true;

		static const Config BASIC_CONFIG;
		static const Config AGGREGATION_SCHEMA_CONFIG;
		static const RowMapper AGGREGATION_RESULT_MAPPER;
		static const RowMapper QUERY_ANALYSIS_MAPPER;
	};

	enum ColumnFlag {
		COLUMN_FLAG_ARRAY = 1 << 0,
		COLUMN_FLAG_NOT_NULL = 1 << 2
	};

	typedef std::map<u8string, uint32_t> ColumnIdMap;
	typedef std::vector<Entry> EntryList;
	typedef EntryList::const_iterator EntryIterator;

	static Cache *cache_;

	RowMapper(
			size_t digest, BindingCursor &cursor,
			UTIL_UNIQUE_PTR<RowMapper> *srcKeyMapper, const Config &config);

	RowMapper(const RowMapper&);
	RowMapper& operator=(const RowMapper&);

	template<typename C>
	static BindingHead setUp(
			const C &cursor, const Config &config, EntryList &entryList,
			ColumnIdMap &columnIdMap, UTIL_UNIQUE_PTR<RowMapper> &keyMapper,
			ObjectLayout &objectLayout);
	static BindingHead setUpDetail(
			BindingCursor &cursor, const Config &config, EntryList &entryList,
			ColumnIdMap &columnIdMap, UTIL_UNIQUE_PTR<RowMapper> *srcKeyMapper,
			UTIL_UNIQUE_PTR<RowMapper> &keyMapper, ObjectLayout &objectLayout);

	static bool matchEntryCount(
			size_t count1, size_t count2, bool throwOnUnmatch);
	static bool matchBindingHeadDetail(
			const BindingHead &head1, const BindingHead &head2,
			bool throwOnUnmatch);
	static bool matchEntry(
			const Entry &entry1, const Entry &entry2, bool schemaOnly,
			bool schemaFull, bool throwOnUnmatch);

	static bool matchEntryType(
			const Entry &entry1, const Entry &entry2, bool throwOnUnmatch);
	static bool matchEntryName(
			const Entry &entry1, const Entry &entry2, bool exact,
			bool throwOnUnmatch);
	static bool matchEntryBasicOptions(
			const Entry &entry1, const Entry &entry2, bool throwOnUnmatch);
	static bool matchEntryFullOptions(
			const Entry &entry1, const Entry &entry2, bool throwOnUnmatch);

	static size_t getDigest(const BindingHead &head);
	static size_t getDigest(const Entry &entry);
	static size_t getDigest(const DetailElementType &type);
	static size_t getDigest(const GSChar *str);

	static size_t checkNestedBindingEntryCount(
			const GSBinding &binding, const GSBinding *&keyBinding);
	static const GSBindingEntry& getNestedBindingEntry(
			const GSBinding &binding, const GSBinding *keyBinding,
			size_t totalPos, size_t &subPos, bool *nested,
			size_t *upperOffset);
	static bool isKeyBindingFound(const GSBindingEntry &entry);

	static BindingHead makeEntries(
			BindingCursor &cursor, const Config &config, EntryList &entryList);
	static void makeColumnIdMap(
			const EntryList &entryList, const Config &config,
			ColumnIdMap &columnIdMap);

	static void makeKeyMapper(
			const BindingHead &head, const EntryList &entryList,
			const Config &config, UTIL_UNIQUE_PTR<RowMapper> *srcKeyMapper,
			UTIL_UNIQUE_PTR<RowMapper> &keyMapper);
	static void checkKeyEntries(
			const BindingHead &head, const EntryList &entryList,
			const Config &config);

	static ObjectLayout makeObjectLayout(const EntryList &entryList);

	template<GSType T, typename M>
	static const GSChar *maskNullString(const GSChar *src);

	static void* getField(const Entry &entry, void *rowObj);
	static const void* getField(const Entry &entry, const void *rowObj);

	static void* getArrayFieldSizeAddr(const Entry &entry, void *rowObj);
	static size_t getArrayFieldSize(const Entry &entry, const void *rowObj);

	size_t toKeyList(
			const int32_t *&list, VarDataPool &varDataPool) const;

	const RowMapper& resolveCodingMapper(
			bool rowGeneral, const void *rowObj) const;
	const RowMapper& resolveKeyCodingMapper(
			bool keyGeneral, const GSType *keyType, const void *keyObj) const;

	const RowMapper& resolveKeyMapper() const;
	const RowMapper* findKeyMapper() const;

	bool isNull(const void *rowObj, int32_t columnId) const;
	void setNull(void *rowObj, int32_t columnId, bool nullValue) const;

	uint8_t* findNulls(void *rowObj) const;
	const uint8_t* findNulls(const void *rowObj) const;

	size_t getFixedRowPartSize(bool rowIdIncluded, MappingMode mode) const;
	size_t getFixedFieldPartSize(int32_t columnId, MappingMode mode) const;

	void peekAggregationSchema(
			InputCursor &baseCursor,
			UTIL_UNIQUE_PTR<RowMapper> &schemaMapper) const;
	void decodeAggregation(InputCursor &cursor, void *rowObj) const;
	const DetailElementType& decodeAggregationHead(
			InputCursor &cursor, const Entry *&entry) const;

	static void putArraySizeInfo(
			XArrayByteOutStream &out, MappingMode mode,
			size_t elementSize, size_t elementCount);

	void encodeField(
			OutputCursor &cursor, size_t columnId,
			const DetailElementType *keyType, const void *keyObj,
			const void *rowObj, const Entry *generalEntry = NULL) const;

	void decodeField(
			InputCursor &cursor, size_t columnId, void *rowObj,
			void *&pendingVarData, size_t &pendingPtrArraySize,
			const Entry *generalEntry = NULL) const;

	template<ElementType ElemType, bool ArrayType>
	void clearField(const Entry &entry, void *rowObj) const;
	void clearFieldGeneral(const Entry &entry, void *rowObj) const;

	size_t checkEntryIndex(int32_t columnId) const;

	uint32_t getVarColumnCount() const;
	size_t getNullsByteSize() const;
	uint32_t getNullsOffset() const;

	static void putMicroTimestamp(
			XArrayByteOutStream &out, const GSPreciseTimestamp &ts);
	static GSPreciseTimestamp getMicroTimestamp(ArrayByteInStream &in);
	static GSPreciseTimestamp getMicroTimestamp(const GSValue &rawValue);

	static void putNanoTimestamp(
			OutputCursor &cursor, const GSPreciseTimestamp &ts, bool onAnyData);
	static GSPreciseTimestamp getNanoTimestamp(
			InputCursor &cursor, bool onAnyData);

	static void putFixedNanoTimestamp(
			XArrayByteOutStream &out, const GSPreciseTimestamp &ts);
	static GSPreciseTimestamp getFixedNanoTimestamp(ArrayByteInStream &in);
	static GSPreciseTimestamp getFixedNanoTimestamp(const GSValue &rawValue);

	template<typename Alloc>
	static void deallocateStringArray(
			Alloc* alloc, GSChar **strArray, size_t arraySize) throw();
	void deallocatePtrArray(
			VarDataPool *pool, void *rowObj, void **ptrArray,
			size_t arraySize) const throw();

	void* allocate(VarDataPool *pool, void *rowObj, size_t size) const;
	void deallocate(VarDataPool *pool, void *rowObj, void *ptr) const;

	template<typename Alloc, typename Mask>
	struct ValueCopier {
		ValueCopier(Alloc *alloc, const GSValue &src);

		template<typename Traits>
		void operator()(GSValue &dest, const Entry &entry, const Traits&);

		Alloc *alloc_;
		const GSValue &src_;
	};

	template<typename Traits, typename Alloc, typename Mask,
	bool StringOrArray = Traits::FOR_SINGLE_VAR>
	struct StringOrArrayCopier {
		GSValue operator()(const GSValue &src, Alloc *alloc);
	};

	ReferenceHead refHead_;
	EntryList entryList_;
	ColumnIdMap columnIdMap_;
	UTIL_UNIQUE_PTR<RowMapper> keyMapper_;
	ObjectLayout objectLayout_;
	const BindingHead bindingHead_;
};

namespace {
RowMapper::Initializer g_rowMapperInitializer;
}

struct RowMapper::RowTool {
private:
	friend struct GSRowTag;
	friend struct GSRowKeyPredicateTag;

	static const RowMapper& resolveKeyMapper(const RowMapper &mapper);
};

struct RowMapper::GeneralRowHolder {
public:
	GeneralRowHolder();
	~GeneralRowHolder();

	void reset(GSRow *row) throw();
	GSRow* get() const  throw();

private:
	GSRow *row_;
};

struct RowMapper::BaseCursor {
	BaseCursor(const RowMapper &mapper, MappingMode mode, int32_t rowCount,
			bool rowIdIncluded, size_t topPos);

	void reset();

	template<typename StreamBase>
	void beginField(StreamBase &s);

	static size_t getVarDataTop(
			const RowMapper &mapper, MappingMode mode, int32_t rowCount,
			bool rowIdIncluded, size_t topPos);

	const RowMapper *mapper_;
	const MappingMode mode_;
	const int32_t rowCount_;
	const bool rowIdIncluded_;
	int32_t rowIndex_;
	int32_t fieldIndex_;
	const size_t topPos_;
	const size_t varDataTop_;
	size_t varDataLast_;
	size_t partialVarDataOffset_;
	const bool varDataSeparated_;
	size_t pendingPos_;
	int64_t lastRowID_;
	int64_t varDataOffset_;
};

struct RowMapper::Config {
	Config(
			bool anyTypeAllowed, bool nullableAllowed, bool keyExtensible,
			bool keyComposable = false);

	bool anyTypeAllowed_;
	bool nullableAllowed_;
	bool keyExtensible_;
	bool keyComposable_;
};

class RowMapper::DetailElementType {
public:
	static const DetailElementType& getAny();

	static const DetailElementType& of(ElementType base, bool forArray);

	static const DetailElementType& ofField(
			GSType base, bool forArray, GSTypeOption options);
	static const DetailElementType& ofFullField(GSType base, GSTypeOption options);
	static const DetailElementType& ofFullObject(GSType base);

	static const DetailElementType& ofRaw(int8_t rawType);

	template<typename Traits>
	static const DetailElementType& ofKeyTraits(const Traits&) {
		UTIL_STATIC_ASSERT(Traits::KEY_TYPE);
		return ofTraits(Traits());
	}

	template<typename Traits>
	static const DetailElementType& ofTraits(const Traits&) {
		return of(Traits::ELEMENT_TYPE, Traits::ARRAY_TYPE);
	}

	static const DetailElementType& get(ArrayByteInStream &in);
	void put(XArrayByteOutStream &out) const;

	ElementType getBase() const;

	bool isForArray() const;
	bool isForKey() const;
	bool isAny() const;

	GSType toFullFieldType() const;
	GSType toFullObjectType() const;
	const GSType* toFullObjectTypeRef() const;

	int8_t toRawType() const;
	GSTypeOption toOptions() const;

	size_t getFixedFieldPartSize(MappingMode mode) const;
	size_t getBaseFixedFieldSize() const;
	size_t getBaseFixedObjectSize() const;
	bool hasVarDataPart() const;

	SchemaFeatureLevel getFeatureLevel() const;

	bool equals(ElementType base, bool forArray) const;
	bool equals(const DetailElementType &another) const;

	bool matchAsObject(const DetailElementType &another) const;

private:
	template<ElementType ElemType, bool ArrayType>
	struct InvalidTypeTraits {
		static const ElementType ELEMENT_TYPE = ElemType;
		static const bool ARRAY_TYPE = ArrayType;
		static const bool KEY_TYPE = false;
		static const bool FOR_SIZE_VAR = false;
		static const bool TYPE_VALID = false;
		static const GSType FULL_FIELD_TYPE = GS_TYPE_NULL;
		static const size_t BASE_FIXED_FIELD_SIZE = 0;
		static const size_t BASE_FIXED_OBJECT_SIZE = 0;
	};

	DetailElementType(const DetailElementType&);
	DetailElementType& operator=(const DetailElementType&);

	template<typename Traits>
	explicit DetailElementType(const Traits&);

	static const DetailElementType& applyPrecision(
			const DetailElementType &src, GSTypeOption options);

	static GSTypeOption resolvePrecision(ElementType base, bool forArray);
	static GSType resolveFullObjectType(
			ElementType base, bool forArray, GSType fullFieldType);

	static SchemaFeatureLevel resolveFeatureLevel(
			ElementType base, bool forArray);

	static const DetailElementType LIST_BY_ELEM[];
	static const DetailElementType *LIST_BY_FULL[];

	ElementType base_;
	bool forArray_;
	bool valid_;

	GSTypeOption precision_;
	GSType fullFieldType_;
	GSType fullObjectType_;
	bool forKey_;
	bool forSizeVar_;
	size_t baseFixedFieldSize_;
	size_t baseFixedObjectSize_;
	SchemaFeatureLevel featureLevel_;
};

class RowMapper::Entry {
public:
	Entry();

	Entry withSchema(
			const DetailElementType &type, const char8_t *name,
			GSTypeOption filteredOptions) const;
	Entry withLayout(
			size_t offset, size_t arraySizeOffset,
			size_t compositeKeyOffset) const;

	const DetailElementType& getType() const;
	const u8string& getName() const;

	bool isForKey() const;
	bool isNullable() const;

	bool isInitialValueNull() const;
	bool isDefaultValueSpecified() const;

	GSTypeOption getOptions() const;

	size_t getOffset() const;
	size_t getArraySizeOffset() const;
	size_t getCompositeKeyOffset() const;

private:
	const DetailElementType *type_;
	u8string name_;
	GSTypeOption filteredOptions_;

	size_t offset_;
	size_t arraySizeOffset_;
	size_t compositeKeyOffset_;
};

class RowMapper::InputCursor {
public:
	friend class RowMapper;
	friend struct RowMapper::Tool;

	InputCursor(
			ArrayByteInStream &in, const RowMapper &mapper,
			MappingMode mode, int32_t rowCount, bool rowIdIncluded,
			VarDataPool *varDataPool);

	InputCursor& asReadOnly(
			util::LocalUniquePtr<InputCursor> &localCursor,
			ArrayByteInStream &localIn) const;

	void setVarDataBaseOffset(int64_t varDataBaseOffset);

	MappingMode getMode() const;
	int32_t getRowCount() const;
	int64_t getLastRowID() const;
	bool isRowIdIncluded() const;
	bool hasNext() const;
	bool isInRange() const;
	int32_t getRowIndex() const;

	void reset();

	void getRowFixedPartAll(
			GSRowSetType resultType,
			const util::NormalXArray<uint8_t> &resultData,
			const uint8_t *&data, size_t &size) const;
	void getRowVariablePartAll(
			GSRowSetType resultType,
			const util::NormalXArray<uint8_t> &resultData,
			const uint8_t *&data, size_t &size) const;

private:
	void beginRow(const RowMapper &mapper, uint8_t *nulls);
	void endRow();
	void beginField();
	void beginVarData();
	void endVarData();

	BaseCursor base_;
	ArrayByteInStream &in_;
	VarDataPool *varDataPool_;
	int64_t varDataBaseOffset_;
};

class RowMapper::OutputCursor {
public:
	friend class RowMapper;
	friend struct RowMapper::Tool;

	OutputCursor(XArrayByteOutStream &out, const RowMapper &mapper,
			MappingMode mode, int32_t rowCount, bool rowIdIncluded = false);

	void reset();

private:
	void beginRow(
			const RowMapper &mapper, int64_t rowID, const uint8_t *nulls);
	void endRow();
	void beginField();
	void beginVarData();
	void endVarData();

	BaseCursor base_;
	XArrayByteOutStream &out_;
};

class RowMapper::VarDataPool {
public:
	VarDataPool();
	~VarDataPool();

	void* allocate(size_t size);
	void deallocate(void*);
	void clear();
	size_t getUsageSize();

private:
	static const size_t NORMAL_BLOCK_SIZE;
	struct BlockHead {
		BlockHead *prev_;
		size_t bodySize_;
	};

	union AlignmentUnit {
		void *u1_;
		int64_t u2_;
		double u3_;
	};

	VarDataPool(const VarDataPool&);
	VarDataPool& operator=(const VarDataPool&);

	BlockHead *block_;
	uint8_t *tail_;
	uint8_t *end_;
};

class RowMapper::Cache {
public:
	Cache();

	const RowMapper* resolve(
			RowTypeCategory category, const GSBinding *binding,
			bool general, const Config &config);
	const RowMapper* resolve(
			const RowMapper &baseMapper, ArrayByteInStream &schemaIn,
			const Config &config, bool columnOrderIgnorable);
	const RowMapper* resolve(
			const RowMapper::ContainerInfoRef<true> &infoRef,
			const Config &config, bool forKey = false,
			const RowTypeCategory *category = NULL);

	const RowMapper* duplicate(const RowMapper &mapper);

	void release(const RowMapper **mapper);

private:
	Cache(const Cache&);
	Cache& operator=(const Cache&);

	const RowMapper* resolveDetail(
			BindingCursor &cursor, const Config &config);

	typedef std::multimap<size_t, RowMapper*> EntryMap;
	typedef EntryMap::iterator EntryMapIterator;
	EntryMap entryMap_;
	util::Mutex mutex_;
};

class RowMapper::Reference {
public:
	Reference();
	Reference(Cache &cache, const RowMapper *mapper);
	explicit Reference(UTIL_UNIQUE_PTR<RowMapper> &mapper);
	explicit Reference(const MovableReference &ref);
	~Reference();

	MovableReference move();
	void swap(Reference &another);

	const RowMapper* operator->() const;
	const RowMapper& operator*() const;

	const RowMapper* get() const;
	const RowMapper* release();
	Cache* getCache() const;
	void reset() throw();

private:
	Reference(const Reference &another);
	Reference& operator=(const Reference &another);

	Cache *cache_;
	const RowMapper *mapper_;
};

class RowMapper::MovableReference {
public:
	explicit MovableReference(Reference &ref);
	Reference& getReference() const;

private:
	Reference &ref_;
};

#define CLIENT_TYPE_TRAITS_PRIMITIVE_CUSTOM( \
		upperSymbol, upperSymbolFull, camelSymbol, objectType, fieldType) \
		template<> \
		struct RowMapper::ObjectTypeTraits< \
		RowMapper::ELEM_TYPE_##upperSymbol, false> { \
			typedef fieldType Field; \
			typedef objectType Object; \
			static const size_t zero = 0; \
			static const GSType FULL_FIELD_TYPE = GS_TYPE_##upperSymbolFull; \
			static Object& as(GSValue &v) { \
					return v.as##camelSymbol; } \
			static const Object& as(const GSValue &v) { \
					return v.as##camelSymbol; } \
			template<typename Value> \
			static size_t& arraySizeOf(Value &v) { \
					UTIL_STATIC_ASSERT(sizeof(Value) == 0); \
					return *const_cast<size_t*>(&zero); } \
			template<typename Value> \
			static const size_t& arraySizeOf(const Value &v) { \
					UTIL_STATIC_ASSERT(sizeof(Value) == 0); \
					return zero; } \
		}

#define CLIENT_TYPE_TRAITS_PRIMITIVE( \
		upperSymbol, camelSymbol, type) \
		CLIENT_TYPE_TRAITS_PRIMITIVE_CUSTOM( \
				upperSymbol, upperSymbol, camelSymbol, type, type)

#define CLIENT_TYPE_TRAITS_ARRAY( \
		upperSymbol, camelSymbol, type) \
		template<> \
		struct RowMapper::ObjectTypeTraits< \
		RowMapper::ELEM_TYPE_##upperSymbol, true> { \
			typedef type Field; \
			typedef type Object; \
			static const GSType FULL_FIELD_TYPE = \
					GS_TYPE_##upperSymbol##_ARRAY; \
			static Object& as(GSValue &v) { \
					return v.asArray.elements.as##camelSymbol; } \
			static const Object& as(const GSValue &v) { \
					return v.asArray.elements.as##camelSymbol; } \
			template<typename Value> \
			static size_t& arraySizeOf(Value &v) { \
					return v.asArray.length; } \
			template<typename Value> \
			static const size_t& arraySizeOf(const Value &v) { \
					return v.asArray.length; } \
		}

CLIENT_TYPE_TRAITS_PRIMITIVE(STRING, String, const GSChar*);
CLIENT_TYPE_TRAITS_PRIMITIVE(BOOL, Bool, GSBool);
CLIENT_TYPE_TRAITS_PRIMITIVE(BYTE, Byte, int8_t);
CLIENT_TYPE_TRAITS_PRIMITIVE(SHORT, Short, int16_t);
CLIENT_TYPE_TRAITS_PRIMITIVE(INTEGER, Integer, int32_t);
CLIENT_TYPE_TRAITS_PRIMITIVE(LONG, Long, int64_t);
CLIENT_TYPE_TRAITS_PRIMITIVE(FLOAT, Float, float);
CLIENT_TYPE_TRAITS_PRIMITIVE(DOUBLE, Double, double);
CLIENT_TYPE_TRAITS_PRIMITIVE(TIMESTAMP, Timestamp, GSTimestamp);
CLIENT_TYPE_TRAITS_PRIMITIVE(GEOMETRY, Geometry, const GSChar*);
CLIENT_TYPE_TRAITS_PRIMITIVE(BLOB, Blob, GSBlob);

CLIENT_TYPE_TRAITS_PRIMITIVE_CUSTOM(
		MICRO_TIMESTAMP, TIMESTAMP, PreciseTimestamp, GSPreciseTimestamp,
		TimestampUtils::RawMicroTimestamp);
CLIENT_TYPE_TRAITS_PRIMITIVE_CUSTOM(
		NANO_TIMESTAMP, TIMESTAMP, PreciseTimestamp, GSPreciseTimestamp,
		TimestampUtils::RawNanoTimestamp);

CLIENT_TYPE_TRAITS_ARRAY(STRING, String, const GSChar *const*);
CLIENT_TYPE_TRAITS_ARRAY(BOOL, Bool, const GSBool*);
CLIENT_TYPE_TRAITS_ARRAY(BYTE, Byte, const int8_t*);
CLIENT_TYPE_TRAITS_ARRAY(SHORT, Short, const int16_t*);
CLIENT_TYPE_TRAITS_ARRAY(INTEGER, Integer, const int32_t*);
CLIENT_TYPE_TRAITS_ARRAY(LONG, Long, const int64_t*);
CLIENT_TYPE_TRAITS_ARRAY(FLOAT, Float, const float*);
CLIENT_TYPE_TRAITS_ARRAY(DOUBLE, Double, const double*);
CLIENT_TYPE_TRAITS_ARRAY(TIMESTAMP, Timestamp, const GSTimestamp*);

template<RowMapper::ElementType ElemType, bool ArrayType>
struct RowMapper::TypeTraits {

	static const ElementType ELEMENT_TYPE = ElemType;

	static const bool ARRAY_TYPE = ArrayType;

	static const bool KEY_TYPE = !ARRAY_TYPE && (
			ELEMENT_TYPE == ELEM_TYPE_STRING ||
			ELEMENT_TYPE == ELEM_TYPE_INTEGER ||
			ELEMENT_TYPE == ELEM_TYPE_LONG ||
			ELEMENT_TYPE == ELEM_TYPE_TIMESTAMP ||
			ELEMENT_TYPE == ELEM_TYPE_MICRO_TIMESTAMP ||
			ELEMENT_TYPE == ELEM_TYPE_NANO_TIMESTAMP);

	static const bool FOR_SINGLE_VAR = (
			ELEMENT_TYPE == ELEM_TYPE_STRING ||
			ELEMENT_TYPE == ELEM_TYPE_GEOMETRY);

	static const bool FOR_SIZE_VAR = (
			ARRAY_TYPE ||
			FOR_SINGLE_VAR ||
			ELEMENT_TYPE == ELEM_TYPE_ANY_NULL ||
			ELEMENT_TYPE == ELEM_TYPE_BLOB);

	static const bool GENERAL_KEY = false;
	static const bool TYPE_VALID = true;

	static const ElementType SECONDARY_TYPE =
			(ELEMENT_TYPE == ELEM_TYPE_NANO_TIMESTAMP ?
					ELEM_TYPE_MICRO_TIMESTAMP : ELEM_TYPE_ANY_NULL);

	typedef ObjectTypeTraits<ElemType, ArrayType> ObjectTraits;

	typedef typename ObjectTraits::Field Field;
	typedef typename ObjectTraits::Object Object;

	static const GSType FULL_FIELD_TYPE = ObjectTraits::FULL_FIELD_TYPE;

	static const size_t BASE_FIXED_FIELD_SIZE =
			(FOR_SIZE_VAR ? 0 : sizeof(Field));
	static const size_t BASE_FIXED_OBJECT_SIZE =
			(ARRAY_TYPE ? sizeof(void*) + sizeof(size_t) :
			ELEMENT_TYPE == ELEM_TYPE_ANY_NULL ?
					sizeof(int8_t) + sizeof(GSValue) :
			sizeof(Object));

	static Object& as(GSValue &v) { return ObjectTraits::as(v); }
	static const Object& as(const GSValue &v) { return ObjectTraits::as(v); }

	template<typename Value>
	static size_t& arraySizeOf(Value &v) {
		return ObjectTraits::arraySizeOf(v);
	}

	template<typename Value>
	static const size_t& arraySizeOf(const Value &v) {
		return ObjectTraits::arraySizeOf(v);
	}

	static const GSType* findKeyFullObjectType() {
		return (KEY_TYPE ? getDetailType().toFullObjectTypeRef() : NULL);
	}

	static const DetailElementType& getDetailType() {
		return DetailElementType::of(ELEMENT_TYPE, ARRAY_TYPE);
	}

};

template<> struct RowMapper::BindingEntryTraits<0> {
	struct Type {
		const GSChar *columnName;
		GSType elementType;
		size_t offset;
		size_t arraySizeOffset;
		GSTypeOption options;
	};
};

template<> struct RowMapper::BindingEntryTraits<1> {
	typedef GSBindingEntry Type;
};

template<> struct RowMapper::ColumnInfoTraits<0> {
	struct Type {
		const GSChar *name;
		GSType type;
	};
};

template<> struct RowMapper::ColumnInfoTraits<1> {
	struct Type {
		const GSChar *name;
		GSType type;
		GSIndexTypeFlags indexTypeFlags;
	};
};

template<> struct RowMapper::ColumnInfoTraits<2> {
	typedef GSColumnInfo Type;
};

template<> struct RowMapper::IndexInfoTraits<0> {
	struct Type {
		const GSChar *name;
		GSIndexTypeFlags type;
		int32_t column;
		const GSChar *columnName;
	};
};

template<> struct RowMapper::IndexInfoTraits<1> {
	typedef GSIndexInfo Type;
};

class RowMapper::BindingRef {
public:
	typedef const GSBinding *RefType;
	typedef std::vector<GSBindingEntry> RefStorage;

	BindingRef(RefType ref, const ClientVersion &version) throw();

	GSBinding get(RefStorage &storage) const;

private:
	typedef const void *RawPtrType;
	typedef const uint8_t *BytePtrType;

	RawPtrType getEntryRef(size_t index) const;
	size_t getEntrySize() const;

	RefType ref_;
	ClientVersion version_;
};

template<bool Const> class RowMapper::ContainerInfoRef {
public:
	typedef typename util::Conditional<
			Const, const GSContainerInfo*, GSContainerInfo*>::Type RefType;

	ContainerInfoRef(RefType ref, const ClientVersion &version) throw();

	ContainerInfoRef(const ContainerInfoRef &another) throw();
	ContainerInfoRef& operator=(const ContainerInfoRef &another) throw();

	static void clear(RefType ref, const ClientVersion &version) throw();
	void clear() throw();

	bool hasRef() const;
	ContainerInfoRef<true> toConst() const;

	void get(GSContainerInfo &info) const;
	void set(const GSContainerInfo &info);

	GSContainerType getType() const;
	bool isRowKeyAssigned() const;

	size_t getRowKeyColumnCount() const;
	const int32_t* getRowKeyColumnList() const;

	size_t getColumnCount() const;
	GSColumnInfo getColumnInfo(size_t column) const;
	void setColumnInfo(size_t column, const GSColumnInfo &columnInfo);
	void createColumnInfoList(size_t columnCount, VarDataPool &pool);

	const void* getRawColumnInfoList() const;

	size_t getIndexCount() const;
	GSIndexInfo getIndexInfo(size_t pos) const;
	void setIndexInfo(size_t pos, const GSIndexInfo &indexInfo);
	void createIndexInfoList(size_t count, VarDataPool &pool);

	static void copyVersionedIndexInfo(
			const ClientVersion &version, const GSIndexInfo &src,
			GSIndexInfo &dest);

private:
	friend class ContainerInfoRef<true>;
	friend class ContainerInfoRef<false>;

	struct Constants {
		static const int32_t SINGLE_ROW_KEY_COLUMN_LIST[1];
	};

	typedef typename util::Conditional<
			Const, const GSColumnInfo*, GSColumnInfo*>::Type ColumnInfoRefType;

	typedef typename util::Conditional<
			Const, const void*, void*>::Type RawPtrType;
	typedef typename util::Conditional<
			Const, const uint8_t*, uint8_t*>::Type BytePtrType;

	template<bool RefConst>
	static RawPtrType getColumnInfoRef(
			const ContainerInfoRef<RefConst> &infoRef, RawPtrType columnInfoList,
			size_t column);
	size_t getColumnInfoSize() const;

	template<bool RefConst>
	static RawPtrType getIndexInfoRef(
			const ContainerInfoRef<RefConst> &infoRef, RawPtrType indexInfoList,
			size_t pos);
	size_t getIndexInfoSize() const;

	void clearColumnInfoList() throw();
	void clearIndexInfoList() throw();

	const GSTimeSeriesProperties* getTimeSeriesProperties() const;

	RefType ref_;
	ClientVersion version_;

	RawPtrType columnInfoList_;
	RawPtrType indexInfoList_;
	mutable GSTimeSeriesProperties tsProps_;
};

template<> void RowMapper::ContainerInfoRef<false>::clear() throw();

template<> void RowMapper::ContainerInfoRef<false>::set(
		const GSContainerInfo &info);

template<> void RowMapper::ContainerInfoRef<false>::setColumnInfo(
		size_t column, const GSColumnInfo &columnInfo);

template<> void RowMapper::ContainerInfoRef<false>::createColumnInfoList(
		size_t columnCount, VarDataPool &pool);

template<>
void RowMapper::ContainerInfoRef<false>::clearColumnInfoList() throw();

template<>
void RowMapper::ContainerInfoRef<false>::clearIndexInfoList() throw();

class RowMapper::BindingCursor {
public:
	BindingHead readHead(size_t *entryCount);
	bool readEntry(Entry &entry);

protected:
	explicit BindingCursor(const BindingHead &head);
	virtual ~BindingCursor();

	virtual size_t onHead() = 0;
	virtual Entry onEntry(size_t columnId) = 0;

private:
	BindingHead head_;
	bool entryAcceptable_;
	size_t nextColumnId_;
	size_t entryCount_;
};

class RowMapper::ObjectBindingCursor : public RowMapper::BindingCursor {
public:
	ObjectBindingCursor(
			RowTypeCategory category, const GSBinding *binding,
			bool general, const Config &config);
	virtual ~ObjectBindingCursor();

	static ObjectBindingCursor create(
			RowTypeCategory category, const GSBinding *binding,
			const Config &config);

protected:
	virtual size_t onHead();
	virtual Entry onEntry(size_t columnId);

private:
	const GSBinding *binding_;
	const GSBinding *keyBinding_;
	Config config_;

	size_t subPos_;
};

class RowMapper::StreamBindingCursor : public RowMapper::BindingCursor {
public:
	StreamBindingCursor(
			ArrayByteInStream &schemaIn, RowTypeCategory category,
			bool general, const Config &config);
	virtual ~StreamBindingCursor();

protected:
	virtual size_t onHead();
	virtual Entry onEntry(size_t columnId);

private:
	static size_t resolveKeyEntryCount(
			const ArrayByteInStream &orgSchemaIn, const Config &config);

	ArrayByteInStream &schemaIn_;
	ArrayByteInStream orgSchemaIn_;
	Config config_;

	size_t entryRemaining_;
	size_t keyEntryCount_;
	std::vector<int32_t> keyColumnList_;
	FieldLayoutBuilder layoutBuilder_;
};

class RowMapper::SchemaBindingCursor : public RowMapper::BindingCursor {
public:
	SchemaBindingCursor(
			const ContainerInfoRef<true> &infoRef,
			bool general, const Config &config, bool forKey,
			const RowTypeCategory *category);
	virtual ~SchemaBindingCursor();

private:
	virtual size_t onHead();
	virtual Entry onEntry(size_t columnId);

private:
	static RowTypeCategory resolveCategory(
			const ContainerInfoRef<true> &infoRef,
			const RowTypeCategory *category);
	static size_t checkInfo(
			const ContainerInfoRef<true> &infoRef, const Config &config,
			bool forKey, size_t keyEntryCount);

	ContainerInfoRef<true> infoRef_;
	Config config_;

	size_t keyEntryCount_;
	size_t entryCount_;
	FieldLayoutBuilder layoutBuilder_;
};

class RowMapper::MapperBindingCursor : public RowMapper::BindingCursor {
public:
	MapperBindingCursor(const BindingHead &head, const EntryList *entryList);
	virtual ~MapperBindingCursor();

	static MapperBindingCursor create(const RowMapper &mapper);

private:
	virtual size_t onHead();
	virtual Entry onEntry(size_t columnId);

private:
	const EntryList *entryList_;
};

class RowMapper::ReorderedBindingCursor : public RowMapper::BindingCursor {
public:
	class WithStream;

	ReorderedBindingCursor(
			BindingCursor &base, const RowMapper &mapper,
			bool columnOrderIgnorable);
	virtual ~ReorderedBindingCursor();

protected:
	virtual size_t onHead();
	virtual Entry onEntry(size_t columnId);

private:
	BindingCursor &base_;
	const RowMapper &mapper_;
	bool columnOrderIgnorable_;
};

class RowMapper::ReorderedBindingCursor::WithStream :
	public RowMapper::BindingCursor {
public:
	WithStream(
			ArrayByteInStream &schemaIn, const RowMapper &mapper,
			bool columnOrderIgnorable, const Config &config);
	virtual ~WithStream();

protected:
	virtual size_t onHead();
	virtual Entry onEntry(size_t columnId);

private:
	StreamBindingCursor streamCursor_;
	ReorderedBindingCursor reorderedCursor_;
};

class RowMapper::BindingBuilder {
public:
	virtual BindingCursor& toCursor(
			RowTypeCategory category, bool general, const Config &config) = 0;

protected:
	virtual ~BindingBuilder();
};

class RowMapper::ObjectBindingBuilder : public RowMapper::BindingBuilder {
public:
	explicit ObjectBindingBuilder(const GSBinding *binding);
	virtual ~ObjectBindingBuilder();

	virtual BindingCursor& toCursor(
			RowTypeCategory category, bool general, const Config &config);

private:
	const GSBinding *binding_;
	util::LocalUniquePtr<ObjectBindingCursor> cursor_;
};

class RowMapper::SchemaBindingBuilder : public RowMapper::BindingBuilder {
public:
	explicit SchemaBindingBuilder(const ContainerInfoRef<true> &infoRef);
	virtual ~SchemaBindingBuilder();

	virtual BindingCursor& toCursor(
			RowTypeCategory category, bool general, const Config &config);

private:
	ContainerInfoRef<true> infoRef_;
	util::LocalUniquePtr<SchemaBindingCursor> cursor_;
};


struct ContainerKey {
	ContainerKey();
	ContainerKey toCaseSensitive(bool caseSensitive) const;

	std::vector<uint8_t> bytes_;
	bool caseSensitive_;
	bool compatible_;
};

bool operator<(const ContainerKey &key1, const ContainerKey &key2);
bool operator==(const ContainerKey &key1, const ContainerKey &key2);
std::ostream& operator<<(std::ostream &out, const ContainerKey &key);

class ContainerKeyConverter {
public:
	typedef ContainerKeyUtils::Components Components;

	ContainerKeyConverter(bool compatible, bool internalMode);

	static int64_t getPublicDatabaseId();

	bool isCompatible() const;

	ContainerKey get(
			ArrayByteInStream &in, bool caseSensitive) const;
	void put(
			XArrayByteOutStream &out,
			const ContainerKey &key, int64_t databaseId) const;

	ContainerKey compose(
			const Components &components, bool caseSensitive) const;
	void decompose(
			const ContainerKey &key, Components &components) const;

	std::string format(const ContainerKey &key) const;
	std::ostream& format(std::ostream &os, const ContainerKey &key) const;
	ContainerKey parse(const char8_t *str, bool caseSensitive) const;

	int32_t compare(
			const ContainerKey &key1, const ContainerKey &key2) const;

private:
	static const int64_t PUBLIC_DATABASE_ID;

	bool compatible_;
	bool internalMode_;
};


struct Statement {
	enum Id {
		CONNECT,
		DISCONNECT,
		LOGIN,
		LOGOUT,
		GET_PARTITION_ADDRESS,
		GET_CONTAINER,
		GET_TIME_SERIES,		
		PUT_CONTAINER,
		PUT_TIME_SERIES,		
		DROP_COLLECTION,		
		DROP_TIME_SERIES,		
		CREATE_SESSION,
		CLOSE_SESSION,
		CREATE_INDEX,
		DROP_INDEX,
		CREATE_EVENT_NOTIFICATION,
		DROP_EVENT_NOTIFICATION,
		FLUSH_LOG,
		COMMIT_TRANSACTION,
		ABORT_TRANSACTION,
		GET_ROW,
		QUERY_TQL,
		QUERY_COLLECTION_GEOMETRY_RELATED,
		QUERY_COLLECTION_GEOMETRY_WITH_EXCLUSION,
		PUT_ROW,
		PUT_MULTIPLE_ROWS,
		UPDATE_ROW_BY_ID,
		DELETE_ROW,
		DELETE_ROW_BY_ID,
		APPEND_TIME_SERIES_ROW,
		GET_TIME_SERIES_ROW,		
		GET_TIME_SERIES_ROW_RELATED,
		INTERPOLATE_TIME_SERIES_ROW,
		AGGREGATE_TIME_SERIES,
		QUERY_TIME_SERIES_TQL,		
		QUERY_TIME_SERIES_RANGE,
		QUERY_TIME_SERIES_SAMPLING,
		PUT_TIME_SERIES_ROW,		
		PUT_TIME_SERIES_MULTIPLE_ROWS,		
		DELETE_TIME_SERIES_ROW,		
		GET_CONTAINER_PROPERTIES,
		GET_MULTIPLE_ROWS,
		GET_TIME_SERIES_MULTIPLE_ROWS,		

		GET_PARTITION_CONTAINER_NAMES,
		DROP_CONTAINER,
		CREATE_MULTIPLE_SESSIONS,
		CLOSE_MULTIPLE_SESSIONS,
		EXECUTE_MULTIPLE_QUERIES,
		GET_MULTIPLE_CONTAINER_ROWS,
		PUT_MULTIPLE_CONTAINER_ROWS,
		CLOSE_ROW_SET,
		FETCH_ROW_SET,
		CREATE_TRIGGER,
		DROP_TRIGGER,

		GET_USERS,
		PUT_USER,
		DROP_USER,
		GET_DATABASES,
		PUT_DATABASE,
		DROP_DATABASE,
		PUT_PRIVILEGE,
		DROP_PRIVILEGE,

		CREATE_INDEX_DETAIL,
		DROP_INDEX_DETAIL,

		STATEMENT_ID_MAX
	};
};

struct StatementResult {
	enum Id {
		SUCCESS,
		STATEMENT_ERROR,
		NODE_ERROR,
		DENY
	};
};

class NodeConnection {
public:
	struct ClientId;
	struct Config;
	struct LoginInfo;
	struct UserTypeUtils;
	struct OptionalRequest;
	class OptionalRequestSource;
	struct Heartbeat;
	struct SocketFactoryMap;
	static const int32_t EE_MAGIC_NUMBER;

	enum SocketType {
		SOCKET_TYPE_PLAIN,
		SOCKET_TYPE_SECURE,

		END_SOCKET_TYPE
	};
	struct SocketFactoryRefMap {
		SocketFactoryRefMap();
		bool isEmpty() const;

		typedef SocketFactory* (Factories)[END_SOCKET_TYPE];
		Factories factories_;
	};
	typedef uint32_t SocketTypeFlags;

	enum AuthType {
		AUTH_TYPE_INTERNAL,
		AUTH_TYPE_EXTERNAL_LDAP,

		END_AUTH_TYPE
	};

	enum ConnectionRoute {
		CONNECTION_ROUTE_DEFAULT,
		CONNECTION_ROUTE_PUBLIC,

		END_CONNECTION_ROUTE
	};

	NodeConnection(const util::SocketAddress &address, const Config &config);
	~NodeConnection();

	static int32_t getProtocolVersion();
	int32_t getRemoteProtocolVersion() const;
	static bool isSupportedProtocolVersion(int32_t protocolVersion);
	static void setProtocolVersion(int32_t protocolVersion);
	const util::SocketAddress& getRemoteAddress() const;

	static size_t getEEHeadLength(bool ipv6Enabled);
	static size_t getRequestHeadLength(
			bool ipv6Enabled, bool firstStatement = false);
	static void fillRequestHead(
			bool ipv6Enabled, util::NormalXArray<uint8_t> &req,
			bool firstStatement = false);

	static void putStatementId(XArrayByteOutStream &reqOut, int64_t statementId,
			bool firstStatement = false);
	static bool isOptionalRequestEnabled();
	static bool isClientIdOnLoginEnabled();
	static bool isDatabaseIdEnabled();
	static void tryPutEmptyOptionalRequest(XArrayByteOutStream &reqOut);

	ArrayByteInStream executeStatement(
			Statement::Id statement, int32_t partitionId, int64_t statementId,
			util::NormalXArray<uint8_t> &req, util::NormalXArray<uint8_t> *resp,
			Heartbeat *heartbeat = NULL);

	ArrayByteInStream executeStatementDirect(
			int32_t statementTypeNumber, int32_t partitionId, int64_t statementId,
			util::NormalXArray<uint8_t> &req, util::NormalXArray<uint8_t> *resp,
			Heartbeat *heartbeat = NULL);

	void connect(
			util::NormalXArray<uint8_t> &req, util::NormalXArray<uint8_t> &resp);
	void disconnect(
			util::NormalXArray<uint8_t> &req, util::NormalXArray<uint8_t> &resp);

	void login(
			util::NormalXArray<uint8_t> &req, util::NormalXArray<uint8_t> &resp,
			const LoginInfo &loginInfo, int64_t *databaseId);
	bool loginInternal(
			util::NormalXArray<uint8_t> &req, util::NormalXArray<uint8_t> &resp,
			const LoginInfo &loginInfo, Auth::Challenge &challenge,
			size_t &lastInPos);

	void logout(
			util::NormalXArray<uint8_t> &req, util::NormalXArray<uint8_t> &resp);

	void reuse(
			util::NormalXArray<uint8_t> &req, util::NormalXArray<uint8_t> &resp,
			const LoginInfo &loginInfo, int64_t *databaseId);

	int64_t getHeartbeatReceiveCount() const;

	static std::string getDigest(const char8_t *password);

	static int32_t statementToNumber(Statement::Id statement);

	static int32_t getStatementNumberOffset();

	static bool isDatabaseEnabled();

private:
	static const int32_t DEFAULT_PROTOCOL_VERSION;
	static const int32_t STATEMENT_TYPE_NUMBER_V2_OFFSET;

	static const char8_t ERROR_PARAM_ADDRESS[];
	static const char8_t ERROR_PARAM_PARTITION[];

	static volatile int32_t protocolVersion_;
	static bool tcpNoDelayEnabled_;

	NodeConnection(const NodeConnection&);
	NodeConnection& operator=(const NodeConnection&);

	bool isIPV6Enabled() const;
	void readFully(void *buf, size_t length);
	util::NormalXArray<uint8_t>* processHeartbeat(
			int32_t partitionId, util::NormalXArray<uint8_t> &resp,
			util::NormalXArray<uint8_t> &heartbeatBuf, Heartbeat &heartbeat);

	void putConnectRequest(XArrayByteOutStream &reqOut);
	void acceptConnectResponse(ArrayByteInStream &respIn);

	void putControlInfo(XArrayByteOutStream &reqOut);
	void acceptControlInfo(ArrayByteInStream &respIn);

	AuthType resolveAuthType(AuthType specifiedType, const std::string &user);
	ConnectionRoute resolveConnectionRoute(ConnectionRoute specifiedRoute, const std::string &user);

	void changeTransportMethod(SocketTypeFlags nextTypes);
	static void createSocket(
			const SocketFactoryRefMap &factoryMap, SocketType type,
			AbstractSocket &socket);

	static bool isStatementIdLarge(bool firstStatement);
	static int64_t getStatementId(
			ArrayByteInStream &respIn, bool firstStatement);

	AbstractSocket socket_;
	util::SocketAddress address_;
	const int64_t statementTimeoutMillis_;
	const int64_t heartbeatTimeoutMillis_;
	int32_t alternativeVersion_;
	bool alternativeVersionEnabled_;
	SocketTypeFlags acceptableSocketTypes_;
	SocketFactoryRefMap socketFactories_;
	Auth::Mode authMode_;
	int32_t remoteProtocolVersion_;
	int64_t statementId_;
	int64_t heartbeatReceiveCount_;
	std::string authenticatedUser_;
	std::string authenticatedPasswordDigest_;
	std::string authenticatedDatabase_;
	AuthType authType_;
	ConnectionRoute connectionRoute_;
	bool responseUnacceptable_;
	bool authenticated_;
	bool ownerMode_;
	int32_t transactionTimeoutSecs_;
};

struct NodeConnection::ClientId {
public:
	ClientId();
	ClientId(const uuid_t &uuid, int64_t sessionId);

	ClientId(const ClientId &another);
	ClientId& operator=(const ClientId &another);

	void generate(int64_t sessionId);

	bool isEmpty() const;

	int64_t getSessionId() const;
	const uuid_t& getUUID() const;

private:
	uuid_t uuid_;
	int64_t sessionId_;
	bool generated_;
};

struct NodeConnection::Config {
	static const int32_t CONNECT_TIMEOUT_DEFAULT;
	static const int32_t STATEMENT_TIMEOUT_DEFAULT;
	static const int32_t HEARTBEAT_TIMEOUT_DEFAULT;

	Config();
	void set(const Config &config, bool withSocketConfig);
	bool set(const Properties &properties);
	void setAlternativeVersion(int32_t alternativeVersion);

	int64_t connectTimeoutMillis_;
	int64_t statementTimeoutMillis_;
	int64_t heartbeatTimeoutMillis_;
	bool statementTimeoutEnabled_;
	int32_t alternativeVersion_;
	bool alternativeVersionEnabled_;
	SocketTypeFlags acceptableSocketTypes_;
	SocketFactoryRefMap socketFactories_;
};

struct NodeConnection::LoginInfo {
public:
	LoginInfo(
			const GSChar *user, const GSChar *password, bool ownerMode,
			const GSChar *clusterName, const GSChar *dbName,
			int64_t transactionTimeoutMillis, const GSChar *applicationName,
			double storeMemoryAgingSwapRate,
			const util::TimeZone &timeZoneOffset,
			AuthType authType = AUTH_TYPE_INTERNAL,
			ConnectionRoute connectionRoute = CONNECTION_ROUTE_DEFAULT);
	void setPassword(const GSChar *password);

	bool isPublicConnection() {
		return (connectionRoute_ == CONNECTION_ROUTE_PUBLIC);
	}

	static AuthType parseAuthType(const GSChar *typeStr);
	static const GSChar* formatAuthType(AuthType type);

	static ConnectionRoute parseConnectionRoute(const GSChar *typeStr);
	static const GSChar* formatConnectionRoute(ConnectionRoute type);
	void putConnectionOption(XArrayByteOutStream& req);

	std::allocator<uint8_t> alloc_;
	std::string user_;
	Auth::PasswordDigest passwordDigest_;
	std::string password_;
	std::string database_;
	bool ownerMode_;
	std::string clusterName_;
	int32_t transactionTimeoutSecs_;
	ClientId clientId_;
	std::string applicationName_;
	double storeMemoryAgingSwapRate_;
	util::TimeZone timeZoneOffset_;
	AuthType authType_;
	ConnectionRoute connectionRoute_;

private:
	struct AuthTypeList {
		static const GSChar *PROPERTY_STRING_LIST[END_AUTH_TYPE];
	};
	struct ConnectionRouteList {
		static const GSChar *PROPERTY_STRING_LIST[END_CONNECTION_ROUTE];
	};
};

struct NodeConnection::UserTypeUtils {
	static const GSChar ADMIN_USER[];
	static const GSChar SYSTEM_USER[];
	static const GSChar SPECIAL_USER_SYMBOL[];

	static bool checkAdmin(const std::string &user);
};

struct NodeConnection::OptionalRequest {
	enum Type {
		LEGACY_VERSION_BLOCK = 0,
		TYPE_TRANSACTION_TIMEOUT = 1,
		FOR_UPDATE = 2,
		CONTAINER_LOCK_REQUIRED = 3,
		SYSTEM_MODE = 4,
		DB_NAME = 5,
		CONTAINER_ATTRIBUTE = 6,
		ROW_INSERT_UPDATE = 7,
		STATEMENT_TIMEOUT = 10001,
		FETCH_LIMIT = 10002,
		FETCH_SIZE = 10003,
		CLIENT_ID = 11001,
		FETCH_BYTES_SIZE = 11002,
		FEATURE_VERSION = 11004,
		ACCEPTABLE_FEATURE_VERSION = 11005,
		APPLICATION_NAME = 11009,
		STORE_MEMORY_AGING_SWAP_RATE = 11010,
		TIME_ZONE_OFFSET = 11011,
		AUTHENTICATION_TYPE = 11012,
		CONNECTION_ROUTE = 11013
	};

	enum FeatureVersion {
		FEATURE_V4_3 = 3,
		FEATURE_V5_3 = 5,

		FEATURE_LATEST = FEATURE_V5_3
	};

	typedef std::vector<uint8_t> ExtValue;
	typedef std::map<int32_t, ExtValue> ExtMap;

	OptionalRequest();
	OptionalRequest(
			int32_t statementTimeout, int64_t fetchLimit, int64_t fetchSize,
			const std::string &dbName);

	void putExt(int32_t type, const void *value, size_t valueSize);
	void format(XArrayByteOutStream &reqOut) const;

	int32_t transactionTimeout_;
	bool forUpdate_;
	bool containerLockRequired_;
	bool systemMode_;
	std::string dbName_;
	int32_t containerAttribute_;
	int32_t rowInsertUpdate_;
	int32_t statementTimeout_;
	int64_t fetchLimit_;
	int64_t fetchSize_;
	ClientId clientId_;
	int32_t fetchBytesSize_;
	int32_t featureVersion_;
	int32_t acceptableFeatureVersion_;
	UTIL_UNIQUE_PTR<ExtMap> extRequestMap_;
	std::string applicationName_;
	double storeMemoryAgingSwapRate_;
	util::TimeZone timeZoneOffset_;
	AuthType authType_;
	ConnectionRoute connectionRoute_;

private:
	struct Formatter;
};

struct NodeConnection::OptionalRequest::Formatter {
	static const int32_t RANGE_SIZE;
	static const int32_t RANGE_START_ID;

	explicit Formatter(XArrayByteOutStream &reqOut);
	void putType(int32_t type);
	void close();

	static void putBodySize(
			XArrayByteOutStream &reqOut, size_t headPos, size_t bodyPos);

	XArrayByteOutStream &reqOut_;

	int32_t lastRangeId_;
	size_t headPos_;
	size_t bodyPos_;
	size_t rangeHeadPos_;
	size_t rangeBodyPos_;
};

class NodeConnection::OptionalRequestSource {
public:
	virtual bool hasOptions() const = 0;
	virtual void putOptions(OptionalRequest &optionalRequest) const = 0;
};

struct NodeConnection::Heartbeat {
	int32_t orgStatementTypeNumber_;
	int64_t orgStatementId_;
	bool orgStatementFound_;
	UTIL_UNIQUE_PTR<StatementException> orgException_;
	size_t orgRespPos_;
	size_t orgRespSize_;
};

struct NodeConnection::SocketFactoryMap {
	SocketFactory factories_[END_SOCKET_TYPE];
};

class NodeConnectionPool {
public:
	NodeConnectionPool();
	~NodeConnectionPool();

	size_t getMaxSize();
	void setMaxSize(size_t maxSize);

	void add(UTIL_UNIQUE_PTR<NodeConnection> &connection);
	UTIL_UNIQUE_PTR<NodeConnection> pull(const util::SocketAddress &address);

	UTIL_UNIQUE_PTR<NodeConnection> resolve(
			const util::SocketAddress &address,
			util::NormalXArray<uint8_t> &req,
			util::NormalXArray<uint8_t> &resp,
			const NodeConnection::Config &config,
			const NodeConnection::LoginInfo &loginInfo,
			int64_t *databaseId,
			bool preferCache);

	void clear();

private:
	static const size_t DEFAULT_MAX_SIZE;

	typedef std::map<util::SocketAddress, std::vector<NodeConnection*>,
			SocketAddressLess> ConnectionMap;
	typedef std::deque<util::SocketAddress> AddressQueue;

	NodeConnectionPool(const NodeConnectionPool&);
	NodeConnectionPool& operator=(const NodeConnectionPool&);

	void adjustSize(size_t maxSize);
	void closeExceededConnections();

	ConnectionMap connectionMap_;
	std::deque<util::SocketAddress> addressQueue_;
	std::vector<NodeConnection*> exceededConnectionList_;
	size_t maxSize_;
	util::Mutex mutex_;
};

class ContainerHashMode {
public:
	enum Id {
		COMPATIBLE1,
		MD5
	};
};

class NodeResolver {
public:
	static const int32_t NOTIFICATION_RECEIVE_TIMEOUT;
	static const int32_t PROVIDER_UPDATE_TIMEOUT;

	class ProtocolConfig;
	class DefaultProtocolConfig;
	struct AddressConfig;

	template<typename T> class ClusterInfoEntry;
	struct ClusterInfo;

	NodeResolver(
			NodeConnectionPool &pool, bool passive,
			const util::SocketAddress &address,
			const NodeConnection::Config &connectionConfig,
			const ServiceAddressResolver::Config &sarConfig,
			const std::vector<util::SocketAddress> &memberList,
			const AddressConfig &addressConfig,
			const util::SocketAddress &notificationInterfaceAddress =
					util::SocketAddress());

	void setConnectionConfig(const NodeConnection::Config &connectionConfig);
	void setNotificationReceiveTimeoutMillis(int64_t timeout);
	void setProviderTimeoutMillis(int64_t timeout);
	void setPreferableConnectionPoolSize(int32_t size);

	int32_t getPartitionCount(ClusterInfo &clusterInfo);
	ContainerHashMode::Id getContainerHashMode(ClusterInfo &clusterInfo);
	int64_t getDatabaseId(ClusterInfo &clusterInfo);
	void acceptDatabaseId(
			ClusterInfo &clusterInfo, int64_t databaseId,
			const util::SocketAddress &address);

	util::SocketAddress getMasterAddress(ClusterInfo &clusterInfo);
	util::SocketAddress getNodeAddress(
			ClusterInfo &clusterInfo, int32_t partitionId, bool backupPreferred,
			const util::SocketAddress *preferableHost = NULL);
	void getNodeAddressList(
			ClusterInfo &clusterInfo, int32_t partitionId,
			std::vector<util::SocketAddress> &addressList);

	void invalidateMaster(ClusterInfo &clusterInfo);

	void setProtocolConfig(ProtocolConfig *protocolConfig);

	void close();

	void setServiceType(GSChar* type);

	static const GSChar* resolveServiceType(const NodeConnection::LoginInfo &loginInfo) {
		return (const_cast<NodeConnection::LoginInfo*>(&loginInfo)->isPublicConnection() ?
			DEFAULT_PUBLIC_SERVICE_TYPE : DEFAULT_SERVICE_TYPE);
	}

	static util::SocketAddress getAddressProperties(
			const Properties &props, bool *passive,
			ServiceAddressResolver::Config &sarConfig,
			std::vector<util::SocketAddress> &memberList,
			const AddressConfig *addressConfig,
			util::SocketAddress *notificationInterfaceAddress);

	static util::SocketAddress getNotificationProperties(
			const Properties &props, const GSChar *host,
			const bool *ipv6Expected,
			ServiceAddressResolver::Config &sarConfig,
			std::vector<util::SocketAddress> &memberList,
			const AddressConfig &addressConfig,
			util::SocketAddress *notificationInterfaceAddress);

	static util::SocketAddress getNotificationAddress(
			const GSChar *host, const bool *ipv6Expected,
			const AddressConfig &config, const GSChar *key);

	static void parseNotificationMember(
			const GSChar *value, const bool *ipv6Expected,
			std::vector<util::SocketAddress> &memberList);

	static util::SocketAddress resolveAddress(
			const GSChar *host, const bool *ipv6Expected, const GSChar *key);

	static int getAddressFamily(const bool *ipv6Expected);

	static void makeServiceAddressResolver(
			ServiceAddressResolver &resolver,
			const std::vector<util::SocketAddress> &memberList,
			const AddressConfig &addressConfig);

	static ServiceAddressResolver::Config makeServiceAddressResolverConfig(
			const ServiceAddressResolver::Config &src,
			const NodeConnection::Config &connectionConfig);

private:
	static const bool IPV6_ENABLED_DEFAULT;

	static const int32_t NOTIFICATION_STATEMENT_TYPE_V1;
	static const int32_t NOTIFICATION_STATEMENT_TYPE;

	static const int32_t DEFAULT_NOTIFICATION_PORT;
	static const GSChar *const DEFAULT_NOTIFICATION_ADDRESS;
	static const GSChar *const DEFAULT_NOTIFICATION_ADDRESS_V6;
	static const GSChar *const DEFAULT_SERVICE_TYPE;
	static const GSChar* const DEFAULT_PUBLIC_SERVICE_TYPE;

	static AddressConfig DEFAULT_ADDRESS_CONFIG;
	static DefaultProtocolConfig DEFAULT_PROTOCOL_CONFIG;

	typedef std::vector<util::SocketAddress> NodeAddressList;
	typedef std::set<util::SocketAddress, SocketAddressLess> NodeAddressSet;
	typedef std::map<int32_t, NodeAddressList> NodeAddressMap;

	NodeResolver(const NodeResolver&);
	NodeResolver& operator=(const NodeResolver&);

	void prepareConnectionAndClusterInfo(
			ClusterInfo &clusterInfo, size_t startTrialCount);
	void updateNotificationMember();
	bool updateConnectionAndClusterInfo(ClusterInfo &clusterInfo);
	void updateMasterInfo(ClusterInfo &clusterInfo);
	void invalidateMasterInternal(ClusterInfo &clusterInfo, bool inside);
	void releaseMasterCache(bool forceClose);
	void applyMasterCacheCounter(ClusterInfo &clusterInfo);

	void acceptClusterInfo(
			ClusterInfo &clusterInfo, const int32_t *partitionCount,
			const ContainerHashMode::Id *hashMode, const int64_t *databaseId,
			const util::SocketAddress &address, bool byConnection);
	template<typename T> void acceptClusterInfoEntry(
			ClusterInfo &clusterInfo, ClusterInfoEntry<T> &entry,
			const char8_t *name, const T *value,
			const util::SocketAddress &address,
			bool byConnection, bool checkOnly);

	const std::vector<util::SocketAddress>* getNodeAddressList(
			ClusterInfo &clusterInfo, int32_t partitionId, bool backupPreferred,
			size_t startTrialCount, bool allowEmpty);
	size_t getInetAddressSize() const;
	static ContainerHashMode::Id decodeContainerHashMode(
			ArrayByteInStream &in);
	void decodeSocketAddress(
			ArrayByteInStream &in, util::SocketAddress &socketAddress);

	void updateConnectionPoolSize();

	const util::SocketAddress* findNotificationInterfaceAddress() const;

	static const GSChar* findLastChar(
			const GSChar *begin, const GSChar *end, int32_t ch);

	NodeConnectionPool &pool_;
	bool ipv6Enabled_;
	util::SocketAddress notificationAddress_;
	util::SocketAddress notificationInterfaceAddress_;
	util::SocketAddress masterAddress_;
	NodeConnection::Config connectionConfig_;
	UTIL_UNIQUE_PTR<NodeConnection> masterConnection_;
	util::NormalXArray<uint8_t> req_;
	util::NormalXArray<uint8_t> resp_;
	int64_t notificationReceiveTimeoutMillis_;
	int64_t providerTimeoutMillis_;
	uint64_t masterCacheCounter_;
	volatile size_t connectionTrialCounter_;
	bool connectionFailedPreviously_;
	NodeAddressSet cachedAddressSet_;
	NodeAddressMap nodeAddressMap_;
	size_t preferableConnectionPoolSize_;
	std::allocator<uint8_t> alloc_;
	ServiceAddressResolver serviceAddressResolver_;
	std::pair<uint32_t, uint32_t> providerCheckInterval_;
	util::Random random_;
	int32_t lastSelectedMember_;
	bool alwaysMaster_;
	ProtocolConfig *protocolConfig_;
	util::Mutex mutex_;
};

class NodeResolver::ProtocolConfig {
public:
	virtual ~ProtocolConfig();
	virtual int32_t getNotificationStatementType() = 0;
	virtual int32_t getNormalStatementType(Statement::Id statement) = 0;
};

class NodeResolver::DefaultProtocolConfig : public ProtocolConfig {
public:
	virtual ~DefaultProtocolConfig();
	virtual int32_t getNotificationStatementType();
	virtual int32_t getNormalStatementType(Statement::Id statement);
};

struct NodeResolver::AddressConfig {
	AddressConfig();
	AddressConfig(const GSChar* type);

	int32_t notificationPort_;
	const GSChar *notificationAddress_;
	const GSChar *notificationAddressV6_;
	const GSChar *serviceType_;
	bool alwaysMaster_;

	const GSChar *notificationIntrefaceAddress_;
};

template<typename T>
class NodeResolver::ClusterInfoEntry {
public:
	ClusterInfoEntry();

	const T* get() const;

	bool tryAccept(
			const T *value, const util::SocketAddress &address,
			bool byConnection, bool checkOnly);
	bool invalidate();

private:
	T value_;
	bool acceptedByAny_;
	bool acceptedByConnection_;
	util::SocketAddress acceptedAddress_;
};

struct NodeResolver::ClusterInfo {
	explicit ClusterInfo(const NodeConnection::LoginInfo &loginInfo);

	bool invalidate();
	bool acceptMasterInvalidation(uint64_t masterCacheCounter);

	const int32_t* getPartitionCount() const;
	const ContainerHashMode::Id* getHashMode() const;
	const int64_t* getDatabaseId() const;

	void setPartitionCount(const int32_t *partitionCount);

	NodeConnection::LoginInfo loginInfo_;
	ClusterInfoEntry<int32_t> partitionCount_;
	ClusterInfoEntry<ContainerHashMode::Id> hashMode_;
	ClusterInfoEntry<int64_t> databaseId_;
	uint64_t lastMasterCacheCounter_;
};


class GSInterceptorManager;

class GridStoreChannel {
public:
	struct Config {
		Config();

		void set(util::Mutex &mutex, const Config &config);
		bool set(Properties properties);

		int64_t getFailoverTimeoutMillis(util::Mutex &mutex);
		int64_t getFailoverRetryIntervalMillis(util::Mutex &mutex);
		NodeConnection::Config getConnectionConfig(util::Mutex &mutex);

		Config create(
				const Properties &transProps,
				NodeConnection::SocketFactoryMap &socketFactories) const;
		NodeConnection::Config createConnectionConfig(
				const Properties &transProps,
				NodeConnection::SocketFactoryMap &socketFactories) const;

		NodeConnection::Config connectionConfig_;
		int64_t failoverTimeoutMillis_;
		int64_t failoverRetryIntervalMillis_;
		int64_t notificationReceiveTimeoutMillis_;
		int32_t maxConnectionPoolSize_;
		util::LibraryFunctions::ProviderFunc transportProvider_;
	};

	struct Key {
		Key();

		bool passive_;
		util::SocketAddress address_;
		util::SocketAddress notificationInterfaceAddress_;
		std::string clusterName_;

		std::string providerURL_;
		int64_t providerTimeoutMillis_;
		ServiceAddressResolver::Config sarConfig_;
		std::vector<util::SocketAddress> memberList_;
		Properties transProps_;
	};

	struct KeyLess {
		bool operator()(const Key &key1, const Key &key2) const;
	};

	struct ConnectionId;
	struct LocalConfig;
	struct Source;
	struct Context;
	class ContextQueryOptions;

	struct LocatedSchema;
	struct SessionInfo;
	class ContainerCache;
	class TransportProvider;

	static bool v1ProtocolCompatibleSpecified_;
	static bool v1ProtocolCompatible_;
	static bool v10ResourceCompatible_;
	static bool v15TSPropsCompatible_;
	static bool v15DDLCompatible_;
	static bool v20AffinityCompatible_;
	static bool v21StatementIdCompatible_;
	static bool v40QueryCompatible_;
	static bool v40ContainerHashCompatible_;
	static bool v40SchemaCompatible_;

	GridStoreChannel(const Config &config,const Source &source);

	NodeConnectionPool& getConnectionPool();
	GSInterceptorManager* getInterceptorManager() throw();
	void apply(const Config &config);
	NodeConnection::Config getConnectionConfig();
	int64_t getFailoverTimeoutMillis(const Context &context);
	void setStatementRetryMode(int32_t statementRetryMode);
	void setMonitoring(bool monitoring);
	bool isMonitoring();

	void initializeRequestBuffer(
			util::NormalXArray<uint8_t> &req,
			size_t capacity = INITIAL_BUFFER_SIZE);
	void initializeResponseBuffer(
			util::NormalXArray<uint8_t> &resp,
			size_t capacity = INITIAL_BUFFER_SIZE);

	XArrayByteOutStream getRequestOutStream(
			util::NormalXArray<uint8_t> &initializedReq);

	void clearContext(Context &context, bool doClose);
	void applyPartitionId(Context &context, int32_t partitionId);
	void checkActiveConnection(
			const Context &context, int32_t partitionId,
			const ConnectionId &connectionId);

	ArrayByteInStream executeStatement(
			Context &context, Statement::Id statement, int64_t statementId,
			util::NormalXArray<uint8_t> &req, util::NormalXArray<uint8_t> &resp);

	void invalidateMaster(Context &context);
	void checkContextAvailable(const Context &context);

	int64_t getDatabaseId(Context &context);

	void getNodeAddressList(
			Context &context, int32_t partitionId,
			std::vector<util::SocketAddress> &addressList);

	int32_t getPartitionCount(Context &context);

	int32_t resolvePartitionId(
			Context &context, const ContainerKey &containerKey,
			const ContainerKeyConverter &keyConverter);
	static int32_t calculatePartitionId(
			const ContainerKey &containerKey,
			const ContainerKeyConverter &keyConverter,
			ContainerHashMode::Id hashMode, int32_t partitionCount);
	static int32_t calculatePartitionId(
			const GSChar *containerName, ContainerHashMode::Id hashMode,
			int32_t partitionCount);

	static bool isMasterResolvableByConnection();
	static ContainerHashMode::Id getDefaultContainerHashMode();
	static int32_t statementToNumber(Statement::Id statement);
	static bool isRecoverableError(GSResult result) throw();

private:
	static const int32_t FAILOVER_TIMEOUT_DEFAULT;
	static const int32_t FAILOVER_RETRY_INTERVAL;
	static const size_t INITIAL_BUFFER_SIZE;
	static const size_t MAPPER_CACHE_SIZE;

	struct ResolverExecutor;
	struct ResolverExecutorScope;

	GridStoreChannel(const GridStoreChannel&);
	GridStoreChannel& operator=(const GridStoreChannel&);

	void executeResolver(Context &context, ResolverExecutor &executor);

	void updateConnection(Context &context, bool preferConnectionPool);

	static bool isConnectionDependentStatement(Statement::Id statement);
	static bool isContainerKeyComposed();

	NodeConnection::SocketFactoryMap socketFactories_;
	Config config_;
	NodeConnectionPool pool_;
	int32_t statementRetryMode_;
	util::Atomic<bool> monitoring_;
	const Key key_;
	NodeResolver nodeResolver_;
	size_t reqHeadLength_;
	GSInterceptorManager *interceptorManager_;
	util::Mutex mutex_;
};

struct GridStoreChannel::ConnectionId {
public:
	ConnectionId();

	bool isEmpty() const;
	const util::SocketAddress& getAddress() const;

	ConnectionId newId(const util::SocketAddress &address) const;
	bool matches(const ConnectionId &connectionId) const;

private:
	uint64_t value_;
	util::SocketAddress address_;
};

struct GridStoreChannel::LocalConfig {
	LocalConfig();

	void set(const Properties &properties);

	int64_t failoverTimeoutMillis_;
	int64_t transactionTimeoutMillis_;
	int32_t fetchBytesSize_;
	int32_t containerCacheSize_;
};

struct GridStoreChannel::Source {
	friend class GridStoreChannel;

	Source();
	~Source();

	const Key& getKey() const;
	NodeResolver::ClusterInfo createClusterInfo() const;
	Context createContext() const;

	void set(const Properties &properties, const Config &baseConfig);

	static double resolveStoreMemoryAgingSwapRate(
			const Properties &properties);
	static util::TimeZone resolveTimeZoneOffset(const Properties &properties);
	static NodeConnection::AuthType resolveAuthType(
			const Properties &properties);
	static NodeConnection::ConnectionRoute resolveConnectionRoute(
			const Properties &properties);
	static Properties resolveTransportProperties(
			const Properties &properties,
			util::LibraryFunctions::ProviderFunc transProvider);

	Key key_;
	int32_t partitionCount_;
	LocalConfig localConfig_;
	NodeConnection::LoginInfo loginInfo_;
	GSInterceptorManager *interceptorManager_;
};

struct GridStoreChannel::Context {
public:
	friend class GridStoreChannel;
	friend struct ResolverExecutorScope;

	~Context();

	Context(const Context &another);
	Context& operator=(const Context &another);

	int64_t getTransactionTimeoutMillis() const;
	ContextQueryOptions bindQueryOptions(
			const ContextQueryOptions *source) const;
	int32_t getFailoverCount() const;

	util::NormalXArray<uint8_t>& getRequestBuffer();
	util::NormalXArray<uint8_t>& getResponseBuffer();

	const uuid_t& getSessionUUID() const;
	int64_t generateSessionId();
	NodeConnection::ClientId generateClientId();

	ConnectionId getLastConnectionId() const;
	ContainerCache* getContainerCache();

	void setPreferableHost(
			int32_t partitionId, const util::SocketAddress *host);
	const util::SocketAddress* getPreferableHost(int32_t partitionId) const;

	const ContainerKeyConverter& getKeyConverter() const;

private:
	typedef std::pair<ConnectionId, NodeConnection*> ConnectionEntry;
	typedef std::map<util::SocketAddress, ConnectionEntry,
			SocketAddressLess> ConnectionMap;
	typedef std::map<int32_t, util::SocketAddress> PreferableHostMap;

	Context(
			const LocalConfig &localConfig,
			const NodeConnection::LoginInfo &loginInfo,
			const NodeResolver::ClusterInfo &clusterInfo);

	LocalConfig localConfig_;
	int32_t partitionId_;
	ConnectionEntry lastConnection_;
	int64_t lastHeartbeatCount_;
	ConnectionMap activeConnections_;
	NodeConnection::LoginInfo loginInfo_;
	NodeResolver::ClusterInfo clusterInfo_;
	bool closed_;

	int32_t failoverCount_;

	util::NormalXArray<uint8_t> req_;
	util::NormalXArray<uint8_t> resp_;
	int64_t lastSessionId_;
	ConnectionId connectionId_;
	UTIL_UNIQUE_PTR<ContainerCache> containerCache_;
	PreferableHostMap preferableHosts_;

	ResolverExecutor *resolverExecutor_;

	ContainerKeyConverter keyConverter_;
};

class GridStoreChannel::ContextQueryOptions :
		public NodeConnection::OptionalRequestSource {
public:
	ContextQueryOptions(
			const LocalConfig &localConfig, const ContextQueryOptions *source);

	bool hasOptions() const;
	void putOptions(NodeConnection::OptionalRequest &optionalRequest) const;

private:
	const LocalConfig &localConfig_;
	const ContextQueryOptions *source_;
};

struct GridStoreChannel::LocatedSchema {
public:
	friend class ContainerCache;

	LocatedSchema();

	const RowMapper* getMapper() const;
	int64_t getContainerId() const;
	int32_t getVersionId() const;

private:
	LocatedSchema(
			uint64_t schemaCacheId,
			const RowMapper *mapper, int64_t containerId, int32_t versionId);

	uint64_t schemaCacheId_;
	const RowMapper *mapper_;
	int64_t containerId_;
	int32_t versionId_;
};

struct GridStoreChannel::SessionInfo {
public:
	friend class ContainerCache;

	SessionInfo();
	SessionInfo(
			uint64_t sessionCacheId, int32_t partitionId, int64_t containerId,
			int64_t sessionId, int64_t lastStatementId);

	int32_t getPartitionId() const;
	int64_t getContainerId() const;
	int64_t getSessionId() const;
	int64_t getLastStatementId() const;

private:
	typedef std::pair<int32_t, int64_t> Key;

	uint64_t sessionCacheId_;
	Key key_;
	int64_t sessionId_;
	int64_t lastStatementId_;
};

class GridStoreChannel::ContainerCache {
public:
	explicit ContainerCache(int32_t cacheSize);
	~ContainerCache();

	const LocatedSchema* findSchema(
			const ContainerKey &normalizedContainerKey,
			RowMapper::BindingBuilder *bindingBuilder,
			const GSContainerType *containerType, bool general,
			const RowMapper::Config &config) const;
	void cacheSchema(
			const ContainerKey&normalizedContainerKey,
			const RowMapper &mapper, int64_t containerId, int32_t versionId);
	bool removeSchema(const ContainerKey &normalizedContainerKey);

	bool takeSession(
			int32_t partitionId, int64_t containerId, SessionInfo &sessionInfo);
	bool cacheSession(
			int32_t partitionId, int64_t containerId,
			int64_t sessionId, int64_t lastStatementId,
			SessionInfo &oldSessionInfo);
	void takeAllSessions(std::vector<SessionInfo> &sessionList);

private:
	ContainerCache(const ContainerCache&);
	ContainerCache& operator=(const ContainerCache&);

	typedef std::map<uint64_t, ContainerKey> SchemaNameMap;
	typedef std::map<ContainerKey, LocatedSchema> SchemaCache;
	typedef std::map<uint64_t, SessionInfo::Key> SessionKeyMap;
	typedef std::map<SessionInfo::Key, SessionInfo> SessionCache;

	int32_t cacheSize_;

	SchemaNameMap schemaNameMap_;
	SchemaCache schemaCache_;
	uint64_t lastSchemaCacheId_;

	SessionKeyMap sessionKeyMap_;
	SessionCache sessionCache_;
	uint64_t lastSessionCacheId_;
};

class GridStoreChannel::TransportProvider {
public:
	TransportProvider();
	void initialize(util::LibraryFunctions::ProviderFunc provider);

	void filterProperties(const Properties &src, Properties &transProps);
	bool isPlainSocketAllowed(const Properties &props);
	bool createSecureSocketFactory(
			const Properties props, SocketFactory &factory);

private:
	typedef ExtTransportProvider::Functions Functions;
	typedef util::LibraryFunctionTable<Functions> FuncTableRef;

	class PropertiesRef {
	public:
		explicit PropertiesRef(FuncTableRef &funcTable);
		~PropertiesRef();

		void clear() throw();
		ExtTranportPropertiesTag*& get() throw();

	private:
		PropertiesRef(const PropertiesRef&);
		PropertiesRef& operator=(const PropertiesRef&);

		FuncTableRef &funcTable_;
		ExtTranportPropertiesTag *obj_;
	};

	FuncTableRef funcTable_;
};

struct GridStoreChannel::ResolverExecutor {
	enum Command {
		COMMAND_GET_DATABASE_ID,
		COMMAND_GET_ADDRESS_LIST,
		COMMAND_GET_PARTITION_COUNT,
		COMMAND_RESOLVE_PARTITION_ID
	};

	explicit ResolverExecutor(Command command);
	void execute(
			NodeResolver &resolver, NodeResolver::ClusterInfo &clusterInfo);

	Command command_;
	const ContainerKey *containerKey_;
	const ContainerKeyConverter *keyConverter_;
	std::vector<util::SocketAddress> *addressList_;
	int32_t partitionId_;
	int32_t partitionCount_;
	int64_t databaseId_;
};

struct GridStoreChannel::ResolverExecutorScope {
public:
	ResolverExecutorScope(Context &context, ResolverExecutor &executor);
	~ResolverExecutorScope();

private:
	Context &context_;
};


class GSResourceType {
public:
	enum Id {
		GRID_STORE_FACTORY,
		GRID_STORE,
		CONTAINER,
		QUERY,
		ROW_SET,
		AGGREGATION_RESULT,
		ROW,
		ROW_KEY_PREDICATE,
		PARTITION_CONTROLLER,

		TYPE_ID_MAX
	};

	template<typename T>
	struct Resolver {
		static const Id TYPE =
				util::IsSame<T, GSGridStoreFactory>::VALUE ?
						GRID_STORE_FACTORY :
				util::IsSame<T, GSGridStore>::VALUE ? GRID_STORE :
				util::IsSame<T, GSContainer>::VALUE ? CONTAINER :
				util::IsSame<T, GSQuery>::VALUE ? QUERY :
				util::IsSame<T, GSRowSet>::VALUE ? ROW_SET :
				util::IsSame<T, GSAggregationResult>::VALUE ?
						AGGREGATION_RESULT :
				util::IsSame<T, GSRow>::VALUE ? ROW :
				util::IsSame<T, GSRowKeyPredicate>::VALUE ?
						ROW_KEY_PREDICATE :
				util::IsSame<T, GSPartitionController>::VALUE ?
						PARTITION_CONTROLLER :
				TYPE_ID_MAX;
	};
};

struct GSResourceHeader {
public:
	GSResourceHeader(
			GSResourceType::Id type, void *parentResource,
			GSInterceptorManager *interceptorManager);
	~GSResourceHeader();

	static bool getType(
			const void *resource, GSResourceType::Id &type) throw();
	static bool checkType(
			const void *resource, GSResourceType::Id type) throw();

	template<typename T>
	static GSResourceType::Id getStaticType(T *resource) throw();
	template<typename T>
	static GSResourceType::Id getStaticType(T **resource) throw();

	static ErrorStack* findErrorStack(
			void *resource, util::Mutex *&mutex) throw();
	static GSInterceptorManager* findInterceptorManager(
			void *resource) throw();
	static void findStoreOrFactory(
			void *resource, GSGridStore *&store,
			GSGridStoreFactory *&factory) throw();

	static void clearLastError(void *resource) throw();
	static GSResult setCurrentException(void *resource) throw();

#ifdef GS_CLIENT_UNIT_TEST
	static int64_t getResourceCount(GSResourceType::Id type);
#endif

private:
	static const uint32_t RESOURCE_TYPE_MASK;
	static const uint32_t FLAG_INTERCEPTABLE;

	static bool resolveInterceptable(
			GSResourceType::Id type, void *parentResource,
			GSInterceptorManager *interceptorManager);

	GSResourceType::Id getType() const throw();
	bool isInterceptable() const throw();

	static uint32_t maskType(
			GSResourceType::Id type, bool interceptable) throw();
	static GSResourceType::Id unmaskType(uint32_t maskedType) throw();

	const uint32_t maskedType_;

#ifdef GS_CLIENT_UNIT_TEST
	static int64_t resourceCountList_[];
#endif
};

class GSInterceptor {
public:
	typedef uint32_t Id;

	class FunctionInfo;
	class Parameter;
	class ParameterList;

	explicit GSInterceptor(GSInterceptorManager &manager);
	virtual ~GSInterceptor();

	Id getId() const;

	virtual bool isActivated(GSResourceType::Id type);

	virtual bool start(
			const FunctionInfo &funcInfo, const ParameterList &args,
			const Parameter &ret);

	virtual void finish(
			const FunctionInfo &funcInfo, const ParameterList &args);

private:

	GSInterceptor(const GSInterceptor&);
	GSInterceptor& operator=(const GSInterceptor&);

	GSInterceptorManager &manager_;
	Id id_;
};

class GSInterceptor::FunctionInfo {
public:
	FunctionInfo(const GSChar *rawName, GSResourceType::Id resourceType);

	const GSChar* getRawName() const;
	GSResourceType::Id getResourceType() const;

	bool matchName(const GSChar *name) const;
	void formatName(std::ostream &stream) const;

	bool isEmpty() const;
	static FunctionInfo emptyInfo();

private:
	static const GSChar* findMinorSuffix(const GSChar *rawName);

	const GSChar *rawName_;
	GSResourceType::Id resourceType_;
};

std::ostream& operator<<(
		std::ostream &stream, const GSInterceptor::FunctionInfo &funcInfo);

class GSInterceptor::Parameter {
public:
	explicit Parameter(const GSChar *name = NULL);

	const GSChar* getName() const;

	bool isResource() const;
	GSResourceType::Id getResourceType() const;
	void* findResource() const;

	bool isString() const;
	void setNoString();

	bool isSize() const;
	size_t& getSize() const;
	size_t*& getSizePtr() const;

	util::FalseType with(const util::FalseType&) const {
		return util::FalseType();
	}

	template<typename T> Parameter with(T &value) const {
		Parameter param = *this;
		param.typeInfo_ = TypeInfo::create<T>();
		param.storage_ = &value;
		return param;
	}

	template<typename T> T& get() const {
		typeInfo_.check(TypeInfo::create<T>());
		return *static_cast<T*>(storage_);
	}

	void formatValue(std::ostream &os) const;

private:
	struct TypeInfo {
		typedef void (*CheckerFunc)();
		typedef void (*FormatterFunc)(std::ostream&, void*);

		TypeInfo();

		void check(const TypeInfo &another) const;

		template<typename T>
		static TypeInfo create() {
			UTIL_STATIC_ASSERT(
					util::IsPointer<T>::VALUE ||
							(std::numeric_limits<T>::is_specialized &&
							!util::IsSame<T, bool>::VALUE));
			typedef typename util::Conditional<
					util::IsPointer<T>::VALUE, void*, T>::Type FormatterType;
			CheckerFunc sizeCheckerFunc = &checkerFunc<size_t>;

			TypeInfo info;
			info.resourceType_ = getResourceType(static_cast<T*>(NULL));
			info.checkerFunc_ = &checkerFunc<T>;
			info.formatterFunc_ = &formatterFunc<FormatterType>;
			info.forString_ = (util::IsSame<const GSChar*, T>::VALUE);
			info.forSize_ = (info.checkerFunc_ == sizeCheckerFunc);
			return info;
		}

		template<typename R>
		static GSResourceType::Id getResourceType(R**) {
			return GSResourceType::Resolver<R>::TYPE;
		}

		template<typename T>
		static GSResourceType::Id getResourceType(T*) {
			return GSResourceType::TYPE_ID_MAX;
		}

		template<typename T>
		static void checkerFunc() {}

		template<typename V>
		static void formatterFunc(std::ostream &os, void *ptr) {
			UTIL_STATIC_ASSERT(
					(!util::IsPointer<V>::VALUE || util::IsSame<void*, V>::VALUE));
			typedef typename util::Conditional<
					std::numeric_limits<V>::is_signed, int64_t, uint64_t>::Type
					IntType;
			typedef typename util::Conditional<
					std::numeric_limits<V>::is_integer, IntType, V>::Type
					FilteredType;
			if (util::IsPointer<V>::VALUE) {
				os << "0x";
			}
			os << static_cast<FilteredType>(*static_cast<V*>(ptr));
		}

		static void stringFormatterFunc(std::ostream &os, void *ptr) {
			const GSChar *value = *static_cast<const GSChar**>(ptr);
			if (value == NULL) {
				os << "(null)";
			}
			else {
				os << value;
			}
		}

		GSResourceType::Id resourceType_;
		CheckerFunc checkerFunc_;
		FormatterFunc formatterFunc_;
		bool forString_;
		bool forSize_;
	};

	const GSChar *name_;
	TypeInfo typeInfo_;
	void *storage_;
};

class GSInterceptor::ParameterList {
public:
	template<
			typename P1, typename P2, typename P3, typename P4,
			typename P5, typename P6, typename P7, typename P8,
			typename P9, typename P10>
	ParameterList(
			const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4,
			const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8,
			const P9 &p9, const P10 &p10, ...);

	size_t getSize() const;
	const Parameter& at(size_t index) const;

private:
	enum {
		MAX_PARAMETER_COUNT = 8
	};

	typedef Parameter BaseList[MAX_PARAMETER_COUNT];

	template<typename P>
	static void checkTooManyArguments(const P&);

	void add(const Parameter &param);
	void add(const util::FalseType&);

	BaseList baseList_;
	size_t size_;
};

class GSInterceptorManager {
public:
	class Scope;

	typedef GSInterceptor::FunctionInfo FunctionInfo;
	typedef GSInterceptor::Parameter Parameter;
	typedef GSInterceptor::ParameterList ParameterList;
	typedef GSInterceptor::Id InterceptorId;

	GSInterceptorManager();

	bool start(
			const FunctionInfo &funcInfo, const ParameterList &args,
			const Parameter &ret, InterceptorId &endId);
	void finish(
			const FunctionInfo &funcInfo, const ParameterList &args,
			InterceptorId endId);

	bool filterByResourceType(GSResourceType::Id type);

	void activate(InterceptorId id, bool enabled);

private:
	friend class GSInterceptor;

	enum {
		MAX_INTERCEPTOR_COUNT = 3
	};

	struct Entry {
		Entry();

		InterceptorId id_;
		GSInterceptor *interceptor_;
		bool enabled_;
	};

	class CheckerScope {
	public:
		CheckerScope();
		~CheckerScope();

	private:
		static void abortByResursiveAccess();

		static void (*const volatile abortByResursiveAccessFunc_)();
		static UTIL_THREAD_LOCAL size_t counter_;
	};

	typedef Entry EntryList[MAX_INTERCEPTOR_COUNT];

	InterceptorId add(GSInterceptor &interceptor);
	void remove(InterceptorId id);

	void getActiveEntryList(
			util::LockGuard<util::Mutex>&, GSResourceType::Id type,
			EntryList &entryList, InterceptorId &count);

	EntryList entryList_;
	InterceptorId entryCount_;

	util::Mutex mutex_;
};

class GSInterceptorManager::Scope {
public:
	Scope() throw();
	~Scope();

	bool set(
			GSInterceptorManager &manager, const FunctionInfo &funcInfo,
			const ParameterList &args, const Parameter &ret) throw();

private:
	void setCurrentException(const ParameterList &args) throw();

	struct Data {
		Data(
				GSInterceptorManager &manager, const FunctionInfo &funcInfo,
				const ParameterList &args);

		GSInterceptorManager &manager_;
		FunctionInfo funcInfo_;
		ParameterList args_;
		InterceptorId endId_;
	};

	UTIL_UNIQUE_PTR<Data> data_;
};

struct GSGridStoreFactoryTag {
public:
	friend struct GSResourceHeader;

	struct LoaderOption {
		LoaderOption();

		bool configEnabled_;
		bool extensionEnabled_;
	};

	GSGridStoreFactoryTag() throw();
	~GSGridStoreFactoryTag();

	static bool isAlive() throw();

	static GSGridStoreFactory& getDefaultFactory(
			const LoaderOption &option = LoaderOption()) throw();
	static void close(GSGridStoreFactory **factory, bool allRelated) throw();

	void loadDefault(const LoaderOption &option) throw();

	GSGridStore* getGridStore(
			const GSPropertyEntry *properties, const size_t *propertyCount);
	void setProperties(
			const GSPropertyEntry *properties, const size_t *propertyCount,
			bool forInitial = false);

	NodeConnection::Config getConnectionConfig(const Properties &props);
	void setTransportProvider(util::LibraryFunctions::ProviderFunc provider);

	struct Initializer {
	public:
		Initializer() throw();
		~Initializer();

	private:
		static size_t counter_;
	};

private:
	typedef std::map<GridStoreChannel::Key, GridStoreChannel*,
			GridStoreChannel::KeyLess> ChannelMap;
	typedef const char8_t *(LibraryNameInfo)[2];

	typedef GridStoreChannel::TransportProvider TransportProvider;

	typedef ExtGridStoreFactory::Functions Functions;
	typedef util::LibraryFunctionTable<
			Functions>::Builder<Functions::END_FUNC> FuncTable;

	struct FuncInitializer {
		explicit FuncInitializer(FuncTable &table);
	};

	class ReentranceChecker;
	class ErrorHolder;
	class ConfigLoader;
	struct Data;

	GSGridStoreFactoryTag(const GSGridStoreFactory&);
	GSGridStoreFactory& operator=(const GSGridStoreFactory&);

	bool prepareConfigFile() throw();

	void setPropertiesInternal(
			util::LockGuard<util::Mutex> &guard, bool forInitial,
			const GSPropertyEntry *properties, const size_t *propertyCount);

	void setLoggingProperties(
			util::LockGuard<util::Mutex> &guard, const Properties &properties,
			bool forInitial);
#if GS_CLIENT_LOGGING_ENABLED
	util::TraceOption::OutputType extractOutputType(const Properties &properties);
	void setLoggingLevel(const Properties &properties);
	void setLoggingLevel(const std::string &logLevel, const std::string &errorMessage);
	void setLoggingRotationMode(const Properties &properties);
	void setLoggingOutputDirectoryPath(const Properties &properties);
	void setLoggingOutputFileName(const Properties &properties);
	void appendFileNum(std::string &fileName);
	void setLoggingMaxRotationFileCount(const Properties &properties);
	void setLoggingMaxRotationFileSize(const Properties &properties);
#endif

	void setTransportProviderInternal(
			util::LockGuard<util::Mutex> *guard,
			util::LibraryFunctions::ProviderFunc provider);

	void setMonitoring(
			util::LockGuard<util::Mutex>&, bool monitoring);

	void checkLoaded(util::LockGuard<util::Mutex>&);

	static int32_t provideFunctions(
			const void *const **funcList, size_t *funcCount) throw();

	static int32_t setTransportProviderExternal(
			GSGridStoreFactory *factory,
			util::LibraryFunctions::ProviderFunc provider,
			UtilExceptionTag **ex) throw();

	static const LibraryNameInfo KNOWN_LIBRARY_NAMES[];

	static FuncTable FUNC_TABLE;
	static FuncInitializer FUNC_TABLE_INITIALIZER;

	GSResourceHeader resourceHeader_;
	UTIL_UNIQUE_PTR<Data> data_;

	static GSGridStoreFactory *defaultFactory_;
};

class GSGridStoreFactoryTag::ReentranceChecker {
public:
	class Scope {
	public:
		Scope(ReentranceChecker &checker, int64_t expectedCount);
		~Scope();

	private:
		ReentranceChecker *checker_;
		int64_t expectedCount_;
	};

	static void setEnabled(bool enabled);

private:
	static bool enabled_;

	util::Atomic<int64_t> counter_;
};

class GSGridStoreFactoryTag::ErrorHolder {
public:
	ErrorHolder() throw();

	void handleError(std::exception&) throw();
	void checkError();

private:
	bool errorOccurred_;
	UTIL_UNIQUE_PTR<ErrorStack> initialError_;
};

class GSGridStoreFactoryTag::ConfigLoader {
public:
	ConfigLoader();

	bool isPrepared() const;

	void applyFactoryConfig(Properties &props);
	void applyStoreConfig(Properties &props);

	void handleConfigError(std::exception &e) throw();
	void checkConfigError();

private:
	typedef Properties::PropertyMap PropertyMap;

	void prepare();

	static void applyConfig(const Properties *src, Properties &dest);

	void acceptFileData(std::string &buf, bool eof, uint64_t &lineNumber);
	void acceptFileLine(const char8_t *line, size_t size);
	void acceptProperty(const char8_t *name, const char8_t *value);

	static std::string unescape(const std::string &src);

	static const char8_t CONFIG_FILE_NAME[];

	bool configFileEnabled_;
	bool prepared_;
	ErrorHolder initialError_;
	UTIL_UNIQUE_PTR<Properties> factoryProps_;
	UTIL_UNIQUE_PTR<Properties> storeProps_;
};


struct GSGridStoreFactoryTag::Data {
	Data();

	void setUpInterceptors();

	ChannelMap channelMap_;
	GridStoreChannel::Config channelConfig_;
	ErrorStack stack_;
	GSInterceptorManager interceptorManager_;
	bool monitoring_;
	ConfigLoader configLoader_;

	UTIL_UNIQUE_PTR<GSInterceptor> callLogger_;

	ReentranceChecker reentranceChecker_;
	util::Mutex mutex_;
};

namespace {
GSGridStoreFactory::Initializer g_gridStoreFactoryInitializer;
}

struct GSGridStoreTag {
public:
	friend struct GSResourceHeader;

	enum ContainerPropertyKey {
		CONTAINER_PROPERTY_ID,
		CONTAINER_PROPERTY_SCHEMA,
		CONTAINER_PROPERTY_INDEX,
		CONTAINER_PROPERTY_EVENT_NOTIFICATION,
		CONTAINER_PROPERTY_TRIGGER,
		CONTAINER_PROPERTY_ATTRIBUTE,
		CONTAINER_PROPERTY_INDEX_DETAIL,

		CONTAINER_PROPERTY_KEY_MAX
	};

	class ContainerPropertyKeySet {
	public:
		typedef ContainerPropertyKeySet Keys;

		static const ContainerPropertyKeySet KEYS_DEFAULT;
		static const ContainerPropertyKeySet KEYS_COMPATIBLE_TRIGGER;
		static const ContainerPropertyKeySet KEYS_COMPATIBLE_INDEX;
		static const ContainerPropertyKeySet KEYS_FOR_OBJECT;

		ContainerPropertyKeySet(
				ContainerPropertyKey key1 = CONTAINER_PROPERTY_KEY_MAX,
				ContainerPropertyKey key2 = CONTAINER_PROPERTY_KEY_MAX,
				ContainerPropertyKey key3 = CONTAINER_PROPERTY_KEY_MAX);

		static ContainerPropertyKeySet all();

		ContainerPropertyKeySet merge(bool exclusive, const Keys &keys) const;

		uint32_t size() const;

		ContainerPropertyKey begin() const;
		ContainerPropertyKey next(ContainerPropertyKey lastKey) const;

	private:
		uint32_t flags_;
	};

	struct ContainerIdInfo {
		ContainerIdInfo();

		int32_t versionId_;
		int64_t containerId_;
		ContainerKey remoteKey_;
		const GSChar *remoteName_;
	};

	static const GSChar *const CONTEXT_CONTROLLER_NAME;

	GSGridStoreTag(
			GridStoreChannel &channel, GridStoreChannel::Context context);
	~GSGridStoreTag();

	static void setPathKeyOperationEnabled(bool enabled);

	static void close(GSGridStore **store, bool allRelated) throw();

	void createReference(void *resource);
	static void removeReference(GSGridStore *&store, void *resource);

	GridStoreChannel& getChannel();
	GridStoreChannel::Context& getContext();
	util::NormalXArray<uint8_t>& getRequestBuffer();
	util::NormalXArray<uint8_t>& getResponseBuffer();
	RowMapper::VarDataPool& getVarDataPool();

	bool getContainerInfo(
			const GSChar *name, RowMapper::ContainerInfoRef<> &infoRef,
			const ContainerPropertyKeySet *propKeySet = NULL,
			RowMapper::VarDataPool *varDataPool = NULL,
			ContainerIdInfo *idInfo = NULL);
	static GSResult getContainerInfo(
			GSGridStore *store, const GSChar *name, GSContainerInfo *info,
			GSBool *exists, const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	GSContainer* getContainer(
			const GSChar *name, const RowMapper::BindingRef &bindingRef,
			GSContainerType containerType);
	GSCollection* getCollection(
			const GSChar *name, const GSBinding &binding);
	GSTimeSeries* getTimeSeries(
			const GSChar *name, const GSBinding &binding);

	static GSResult getCollection(
			GSGridStore *store, const GSChar *name,
			const GSBinding *binding, GSCollection **collection,
			const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();
	static GSResult getTimeSeries(
			GSGridStore *store, const GSChar *name,
			const GSBinding *binding, GSTimeSeries **timeSeries,
			const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	GSContainer* putContainer(
			const GSChar *name, const RowMapper::BindingRef &bindingRef,
			const RowMapper::ContainerInfoRef<true> &containerInfoRef,
			GSBool modifiable, const GSContainerType *containerType);
	static GSResult putContainer(
			GSGridStore *store, const GSChar *name, bool nameRequired,
			const GSBinding *binding, const GSContainerInfo *info,
			GSBool modifiable, GSContainer **container,
			const GSContainerType *containerType,
			const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	GSContainer* getContainer(
			const GSChar *name, const GSContainerType *expectedType);

	GSContainer* putContainer(
			const GSChar *name,
			const RowMapper::ContainerInfoRef<true> &containerInfoRef,
			GSBool modifiable, const GSContainerType *containerType);
	static GSResult putContainer(
			GSGridStore *store, const GSChar *name,
			const GSContainerInfo *info, GSBool modifiable,
			GSContainer **container, const GSContainerType *containerType,
			const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	void dropContainer(
			const GSChar *name, const GSContainerType *containerType);
	void dropCollection(const GSChar *name);
	void dropTimeSeries(const GSChar *name);

	bool getRow(const GSChar *pathKey, void *rowObj);
	bool putRow(const GSChar *pathKey, const void *rowObj);
	bool removeRow(const GSChar *pathKey);

	void fetchAll(GSQuery *const *queryList, size_t queryCount);
	void multiPut(
			const GSContainerRowEntry *entryList, size_t entryCount);
	void multiGet(
			const GSRowKeyPredicateEntry *const &predicateList,
			size_t predicateCount,
			const GSContainerRowEntry *&entryList, size_t &entryCount);

	GSRow* createRow(
			const RowMapper::ContainerInfoRef<true> &infoRef, bool forKey);
	static GSResult createRow(
			GSGridStore *store, const GSContainerInfo *info, GSRow **row,
			const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();
	static GSResult createRowKey(
			GSGridStore *store, const GSContainerInfo *info, GSRow **key,
			const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	GSRowKeyPredicate* createRowKeyPredicate(GSType keyType);

	GSRowKeyPredicate* createRowKeyPredicateGeneral(
			const RowMapper::ContainerInfoRef<true> &infoRef);
	static GSResult createRowKeyPredicateGeneral(
			GSGridStore *store, const GSContainerInfo *info,
			GSRowKeyPredicate **predicate, const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	GSPartitionController* getPartitionController();

	static void importSchemaProperty(
			ArrayByteInStream &in, const RowMapper::Config &config,
			RowMapper::VarDataPool &varDataPool,
			GSContainerInfo &containerInfo,
			std::vector<GSColumnInfo> &columnInfoList, bool withContainerType);

	static void importIndexInfo(
			ArrayByteInStream &in, RowMapper::VarDataPool &varDataPool,
			GSIndexInfo &indexInfo);
	static void exportIndexInfo(
			XArrayByteOutStream &out, const GSIndexInfo &indexInfo);
	static int32_t getIndexTypeOrdinal(
			GSIndexTypeFlags typeFlag, bool emptyOrDefaultAllowed);

	static bool isContainerStatementUnified();
	static bool isSessionUUIDSummarized();
	static bool isTSDivisionAndAffinityEnabled();

	static bool isClientIdEnabled();
	static bool isIndexDetailEnabled();
	static bool isAttributeVerifiable();
	static bool isNullableColumnAllowed();
	static bool isNullableColumnAllowed(int32_t protocolVersion);

	static bool isQueryOptionsExtensible();
	static const RowMapper::Config& getRowMapperConfig();
	static const RowMapper::Config& getRowMapperConfig(
			int32_t protocolVersion);

private:
	typedef std::set<void*> ResourceSet;
	typedef NodeConnection::OptionalRequestSource OptionalRequestSource;
	typedef GridStoreChannel::ContainerCache ContainerCache;
	typedef std::multimap<ContainerKey, GSContainer*> ContainerMap;

	struct ContainerSchemaOption;
	struct ContainerPropertiesOption;

	struct MultiQueryStatement {
		explicit MultiQueryStatement(GridStoreChannel::Context &context);
		static void check(GSQuery &query, GSGridStore &store);
		void add(GSQuery &query);

		bool makeCreateSessionRequest(XArrayByteOutStream &req,
				GridStoreChannel &channel, GridStoreChannel::Context &context);
		void acceptCreateSessionResponse(ArrayByteInStream &resp);
		bool makeMainRequest(
				XArrayByteOutStream &req, GridStoreChannel::Context &context);
		void acceptMainResponse(ArrayByteInStream &resp,
				const GridStoreChannel::ConnectionId &connectionId);
		bool makeCloseSessionRequest(XArrayByteOutStream &req);
		void acceptSessionClosed();
		bool acceptStatementErrorForSession(
				const StatementException &cause);

		typedef std::vector<GSQuery*> QueryList;

		QueryList queryList_;
		QueryList optionalQueryList_;
		uuid_t sessionUUID_;
		bool updateQueryFound_;
	};

	struct MultiPutStatement {
		explicit MultiPutStatement(GridStoreChannel::Context &context);
		void add(
				const GSContainerRowEntry &rowEntry, const RowMapper *mapper,
				const ContainerKeyConverter &keyConverter);

		bool makeCreateSessionRequest(XArrayByteOutStream &req,
				GridStoreChannel &channel, GridStoreChannel::Context &context);
		void acceptCreateSessionResponse(ArrayByteInStream &resp);
		bool makeMainRequest(
				XArrayByteOutStream &req, GridStoreChannel::Context &context);
		void acceptMainResponse(ArrayByteInStream &resp,
				const GridStoreChannel::ConnectionId &connectionId);
		bool makeCloseSessionRequest(XArrayByteOutStream &req);
		void acceptSessionClosed();
		bool acceptStatementErrorForSession(
				const StatementException &cause);

		struct SubEntry {
			SubEntry();

			std::vector<GSRow*> rowList_;
			int32_t mapperIndex_;
			int64_t containerId_;
			int64_t sessionId_;
		};

		typedef std::vector<const RowMapper*> MapperList;
		typedef std::vector<ContainerKey> ContainerKeyList;
		typedef std::map<ContainerKey, SubEntry> SubEntryMap;

		MapperList mapperList_;
		ContainerKeyList containerKeyList_;
		SubEntryMap subEntryMap_;
		uuid_t sessionUUID_;
		RowMapper::SchemaFeatureLevel featureLevel_;
	};

	struct MultiGetRequest {
		enum PredicateType {
			PREDICATE_RANGE,
			PREDICATE_DISTINCT
		};

		typedef std::vector<GSRowKeyPredicate*> PredicateList;
		typedef std::vector<GSRowKeyPredicateEntry> EntryList;

		MultiGetRequest();

		void add(const GSRowKeyPredicateEntry &predicateEntry);
		bool makeRequest(
				XArrayByteOutStream &req,
				GridStoreChannel &channel, GridStoreChannel::Context &context);

		PredicateList predicateList_;
		EntryList entryList_;
		RowMapper::SchemaFeatureLevel featureLevel_;
	};

	static bool pathKeyOperationEnabled_;

	static RowMapper::Config DEFAULT_MAPPER_CONFIG;
	static RowMapper::Config COMPATIBLE_MAPPER_CONFIG_14;
	static RowMapper::Config COMPATIBLE_MAPPER_CONFIG_13;

	GSGridStoreTag(const GSGridStore&);
	GSGridStore& operator=(const GSGridStore&);

	GSContainer* findContainerByCache(
			ContainerCache &cache, const ContainerKey &key,
			const ContainerKeyConverter &keyConverter,
			RowMapper::BindingBuilder *bindingBuilder,
			const GSContainerType *containerType, bool general);
	UTIL_UNIQUE_PTR<ContainerKey> acceptRemoteContainerKey(
			ArrayByteInStream *in, const ContainerKey &localKey,
			const ContainerKeyConverter &keyConverter, bool &cached);

	void splitPathKey(
			const GSChar *pathKey,
			ContainerKey &containerKey, std::string &rowKeyStr);
	static void splitPathKey(
			const GSChar *pathKey,
			std::string &containerName, std::string &rowKeyStr);

	static void tryPutSystemOptionalRequest(
			XArrayByteOutStream &reqOut, GridStoreChannel::Context &context,
			bool forCreationDDL, const OptionalRequestSource *source = NULL);

	static ContainerSchemaOption containerSchemaToOption(
			RowMapper::SchemaFeatureLevel level, bool accepting);
	static ContainerPropertiesOption containerPropertiesToOption(
			const RowMapper &mapper);
	static int32_t getFeatureVersionForSchema(
			RowMapper::SchemaFeatureLevel level);

	static void exportContainerProperties(
			XArrayByteOutStream &out, const GSContainerType type,
			const GSContainerInfo *info, const RowMapper &mapper);
	static void importContainerProperties(
			ArrayByteInStream &in, RowMapper::VarDataPool &varDataPool,
			GSContainerInfo &containerInfo,
			const std::vector<GSColumnInfo> &columnInfoList);

	static GSCompressionMethod checkCompressionMethod(
			GSCompressionMethod compressionMethod);
	static double checkCompressionRate(double rate);

	const GSContainer& resolveContainer(const ContainerKey &containerKey);
	UTIL_UNIQUE_PTR<GSContainer> duplicateContainer(const GSContainer &src);

	static Statement::Id getContainerStatement(
			Statement::Id statement, const GSContainerType *containerType);
	static void putContainerKey(
			XArrayByteOutStream &reqOut, GridStoreChannel &channel,
			GridStoreChannel::Context &context, const ContainerKey &key,
			const ContainerKeyConverter &keyConverter);
	static void tryPutContainerType(
			XArrayByteOutStream &reqOut, const GSContainerType *containerType);

	static void importIdProperty(
			ArrayByteInStream &in, RowMapper::VarDataPool &varDataPool,
			ContainerIdInfo &idInfo, const ContainerKeyConverter &keyConverter);
	static void importIndexProperty(
			ArrayByteInStream &in, std::vector<GSColumnInfo> &columnInfoList);
	static void importEventNotificationProperty(
			ArrayByteInStream &in, RowMapper::VarDataPool &varDataPool,
			std::vector<std::string> *eventNotificationInfoList);
	static void importTriggerProperty(
			ArrayByteInStream &in, RowMapper::VarDataPool &varDataPool,
			GSContainerInfo &containerInfo,
			const std::vector<GSColumnInfo> &columnInfoList);
	static void importIndexDetailProperty(
			ArrayByteInStream &in, RowMapper::VarDataPool &varDataPool,
			std::vector<GSIndexInfo> &indexInfoList);

	static void applyIndexInfoList(
			const std::vector<GSIndexInfo> &indexInfoList,
			const std::vector<GSColumnInfo> &columnInfoList,
			bool indexFlagsSpecified, RowMapper::VarDataPool &varDataPool,
			RowMapper::ContainerInfoRef<> &infoRef);

	static const GSChar* resolveContainerName(
			const GSChar *name, const GSContainerInfo *info);
	static const GSContainerType* resolveContainerType(
			const GSContainerType *type, const GSContainerInfo *info);

	template<typename MultiStatement>
	void executeStatement(int32_t partitionId, Statement::Id statement,
			MultiStatement &multiStatement);

	GSCollection* getContextControllerCollection(
			const GSContainerType *expectedType);

	GSResourceHeader resourceHeader_;

	size_t referenceCount_;

	GridStoreChannel &channel_;
	GridStoreChannel::Context context_;
	util::NormalXArray<uint8_t> &req_;
	util::NormalXArray<uint8_t> &resp_;
	RowMapper::VarDataPool varDataPool_;
	ResourceSet activeResources_;
	ContainerMap containerMap_;
	ErrorStack stack_;
};

struct GSGridStoreTag::ContainerSchemaOption :
		public NodeConnection::OptionalRequestSource {
public:
	ContainerSchemaOption(
			int32_t featureVersion, int32_t acceptableFeatureVersion);

	const OptionalRequestSource* get() const;

	bool hasOptions() const;
	void putOptions(NodeConnection::OptionalRequest &optionalRequest) const;

private:
	int32_t featureVersion_;
	int32_t acceptableFeatureVersion_;
};

struct GSGridStoreTag::ContainerPropertiesOption :
		public NodeConnection::OptionalRequestSource {
public:
	explicit ContainerPropertiesOption(int32_t featureVersion);

	const OptionalRequestSource* get() const;

	bool hasOptions() const;
	void putOptions(NodeConnection::OptionalRequest &optionalRequest) const;

private:
	int32_t featureVersion_;
};

struct GSContainerTag {
public:
	friend struct GSResourceHeader;
	friend struct GSGridStoreTag;

	struct AnyKeyTraits;
	struct GeneralKeyTraits;

	struct PartialFetchStatus;
	struct PartialExecutionStatus;
	struct QueryFormatter;
	struct QueryData;
	struct QueryParameters;

	static const int32_t SESSION_NOT_FOUND_ERROR_CODE;
	static const int32_t UUID_UNMATCHED_ERROR_CODE;
	static const int32_t ROW_SET_NOT_FOUND_ERROR_CODE;

	static const int8_t ROW_SET_TYPE_PARTIAL_ROWS;

	GSContainerTag(
			GSGridStore &store, RowMapper::Reference &mapper,
			int32_t schemaVerId, int32_t partitionId, int64_t containerId,
			UTIL_UNIQUE_PTR<ContainerKey> &normalizedContainerKey, bool cached);
	~GSContainerTag();

	bool isClosed() const;
	static void close(GSContainer **container, bool allRelated) throw();

	void createReference(void *resource);
	static void removeReference(GSContainer *&container, void *resource);
	static RowMapper::MappingMode getRowMappingMode();

	const RowMapper& getMapper() const;
	int32_t getSchemaVersionId() const;
	int32_t getPartitionId() const;
	int64_t getContainerId() const;
	const ContainerKey* getContainerKey() const;
	const ContainerKey* getNormalizedContainerKey() const;
	GSContainerType getType() const;

	RowMapper::VarDataPool& getVarDataPool();

	void createEventNotification(const GSChar *url);
	void dropEventNotification(const GSChar *url);

	void createTrigger(const GSTriggerInfo *info);
	void dropTrigger(const GSChar *name);

	void createOrDropIndex(
			const GSChar *columnName, GSIndexTypeFlags flags,
			bool forCreation);
	void createOrDropIndex(const GSIndexInfo &info, bool forCreation);

	template<bool ForCreation>
	static GSResult createOrDropIndex(
			GSContainer *container, const GSIndexInfo *info,
			const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	void flush();

	bool getRow(
			const GSType *keyType, const void *key, void *rowObj,
			bool forUpdate, bool keyFormatted);
	bool putRow(
			const GSType *keyType, const void *key, const void *rowObj,
			bool keyFormatted);
	bool removeRow(
			const GSType *keyType, const void *key, bool keyFormatted);

	bool getRow(
			bool keyGeneral, const GSType *keyType, const void *key,
			bool rowGeneral, void *rowObj, bool forUpdate, bool keyFormatted);
	bool putRow(
			bool keyGeneral, const GSType *keyType, const void *key,
			bool rowGeneral, const void *rowObj, bool keyFormatted);
	bool putMultipleRows(size_t rowCount, const void *const *rowObjs);
	bool removeRow(
			bool keyGeneral, const GSType *keyType, const void *key,
			bool keyFormatted);

	GSQuery* query(const GSChar *queryString);
	GSRowSet* queryAndFetch(
			const QueryParameters &parameters, bool forUpdate);

	void makeQueryRequest(
			const QueryParameters &parameters, bool forUpdate,
			XArrayByteOutStream &reqOut, bool noUUID);
	void formatQuery(
			const QueryParameters &parameters,
			XArrayByteOutStream &reqOut);
	GSRowSet* acceptQueryResponse(
			const QueryParameters &parameters, bool forUpdate,
			ArrayByteInStream &respIn, bool bufSwapAllowed);

	void closeRowSet(
			const PartialFetchStatus &fetchStatus,
			GridStoreChannel::ConnectionId &connectionId);
	void fetchRowSet(
			int64_t remainingCount, const PartialFetchStatus &fetchStatus,
			const QueryParameters &parameters,
			const RowMapper &resultMapper,
			util::NormalXArray<uint8_t> &resultData,
			ArrayByteInStream &resultInStream,
			RowMapper::InputCursor &cursor,
			GridStoreChannel::ConnectionId &connectionId);

	void removeRow(
			const RowMapper &resolvedMapper, int64_t transactionId,
			const bool *transactionStarted, bool updatable, int64_t rowId,
			bool keyGeneral, const void *key);
	void updateRow(
			const RowMapper &resolvedMapper, int64_t transactionId,
			const bool *transactionStarted, bool updatable, int64_t rowId,
			bool keyGeneral, const void *key, const void *rowObj);

	void abort();
	void commit();
	void setAutoCommit(bool enabled);

	GSQuery* queryByGeometry(const GSChar *column, const GSChar *geometry,
			GSGeometryOperator geometryOp);
	GSQuery* queryByGeometry(const GSChar *column,
			const GSChar *geometryIntersection, const GSChar *geometryDisjoint);

	GSAggregationResult* aggregateTimeSeries(
			GSTimestamp start, GSTimestamp end,
			const GSChar *column, GSAggregation aggregation);
	bool appendTimeSeriesRow(const void *rowObj);
	bool getTimeSeriesRow(
			GSTimestamp base, GSTimeOperator timeOp, void *rowObj);
	bool interpolateTimeSeriesRow(GSTimestamp base, const GSChar *column,
			void *rowObj);
	GSQuery* queryByTime(
			const GSTimestamp *start, const GSTimestamp *end,
			GSQueryOrder order);
	GSQuery* queryByTime(
			GSTimestamp start, GSTimestamp end,
			const GSChar *const *columnSet,
			size_t columnCount, bool useColumnCount,
			GSInterpolationMode mode,
			int32_t interval, GSTimeUnit intervalUnit);

	template<typename Traits, bool RowGeneral>
	static GSResult getRowChecked(
			GSContainer *container, const typename Traits::Object *key,
			void *rowObj, GSBool forUpdate, GSBool *exists,
			const GSInterceptor::FunctionInfo &funcInfo);
	template<typename Traits, bool RowGeneral>
	static GSResult putRowChecked(
			GSContainer *container, const typename Traits::Object *key,
			const void *rowObj, GSBool *exists,
			const GSInterceptor::FunctionInfo &funcInfo);
	template<typename Traits>
	static GSResult removeRowChecked(
			GSContainer *container, const typename Traits::Object *key,
			GSBool *exists, const GSInterceptor::FunctionInfo &funcInfo);

	GSRow* createRow();

private:
	typedef std::set<void*> ResourceSet;
	typedef NodeConnection::OptionalRequestSource OptionalRequestSource;
	typedef GridStoreChannel::ContainerCache ContainerCache;

	enum StatementFamily {
		STATEMENT_FAMILY_QUERY,
		STATEMENT_FAMILY_LOCK,
		STATEMENT_FAMILY_UPDATE,
		STATEMENT_FAMILY_POST,
		STATEMENT_FAMILY_NONE
	};

	enum TransactionMode {
		TRANSACTION_MODE_AUTO,
		TRANSACTION_MODE_BEGIN,
		TRANSACTION_MODE_CONTINUE
	};

	enum SessionMode {
		SESSION_MODE_AUTO,
		SESSION_MODE_CREATE,
		SESSION_MODE_GET
	};

	enum TransactionInfoType {
		TRANSACTION_INFO_DEFAULT,
		TRANSACTION_INFO_NO_UUID,
		TRANSACTION_INFO_SKIP_COMMIT_MODE
	};

	enum QueryResultType {
		RESULT_ROW_SET,
		RESULT_AGGREGATION,
		RESULT_QUERY_ANALYSIS,
		RESULT_PARTIAL_FETCH_STATE,
		RESULT_PARTIAL_EXECUTION_STATE
	};

	static const bool TIME_SERIES_UPDATE_ENABLED;

	static bool queryStatementIdPreserved_;

	static const int32_t MAX_SESSION_REPAIR_COUNT;

	static const Statement::Id TIME_SERIES_STATEMENT_UNIFIED_LIST[];
	static const Statement::Id TIME_SERIES_STATEMENT_SEPARATED_LIST[];
	static const Statement::Id FIXED_SESSION_MODE_STATEMENT_LIST[];

	struct SessionSortFunc : public std::binary_function<
			GridStoreChannel::SessionInfo, GridStoreChannel::SessionInfo, bool> {
		bool operator()(
				const GridStoreChannel::SessionInfo &left,
				const GridStoreChannel::SessionInfo &right) const {
			return left.getPartitionId() < right.getPartitionId();
		}
	};

	GSContainerTag(const GSContainer&);
	GSContainer& operator=(const GSContainer&);

	void checkOpened() const;

	GridStoreChannel& getChannel();
	GridStoreChannel::Context& getContext();
	util::NormalXArray<uint8_t>& getRequestBuffer();
	util::NormalXArray<uint8_t>& getResponseBuffer();

	static GSInterpolationMode checkInterpolationMode(
			GSInterpolationMode interpolationMode);
	static GSQueryOrder checkQueryOrder(GSQueryOrder order);

	ArrayByteInStream executeStatement(
			Statement::Id statement, StatementFamily familyForSession);
	ArrayByteInStream executeMultiStepStatement(
			Statement::Id statement, StatementFamily familyForSession,
			int32_t statementStep);

	int64_t getSessionIdDirect();
	void setSessionIdDirect(int64_t sessionId, bool statusUpdatable);
	int64_t updateStatementIdDirect();

	static bool isInitialSessionRetrialEnabled();
	static bool isNewSessionConflicted(const StatementException &cause);
	static bool isInitialSessionLost(
			Statement::Id statement, int64_t statementId,
			bool transactionStarted,
			const StatementException &cause);
	void putSessionInfo(XArrayByteOutStream &reqOut, int64_t sessionId);

	void commitForDDL();

	XArrayByteOutStream getRequestOutStream();

	StatementFamily prepareSession(StatementFamily family);
	void createSession();
	void putTransactionInfo(
			XArrayByteOutStream &reqOut, StatementFamily familyForSession,
			TransactionInfoType type = TRANSACTION_INFO_DEFAULT,
			const bool *forUpdate = NULL,
			const OptionalRequestSource *source = NULL);
	void tryPutOptionalRequest(
			XArrayByteOutStream &reqOut,
			bool forUpdate, bool containerLockAware, bool forCreationDDL,
			const OptionalRequestSource *source = NULL,
			int32_t featureVersion = -1);

	static bool isSessionIdGeneratorEnabled();
	static bool isDDLSessionEnabled();
	static bool isRowSetIdHintDisabled();
	static bool isPartialRowSetLostAcceptable();
	static bool isMultiStepStatementIdEnabled();

	static void putNewSessionProperties(
			XArrayByteOutStream &reqOut,
			GridStoreChannel &channel,
			GridStoreChannel::Context &context);
	void closeSession(bool invalidating);
	static void closeSession(
			GridStoreChannel &channel,
			GridStoreChannel::Context &context,
			const GridStoreChannel::SessionInfo &sessionInfo);
	static void closeAllSessions(
			GridStoreChannel &channel,
			GridStoreChannel::Context &context,
			const GridStoreChannel::SessionInfo *sessionInfoList,
			size_t sessionInfoCount);
	void closeSubResources(bool silent, bool transactionalOnly);
	void closeRemote() throw();

	void disableCache();

	StatementFamily prepareQuerySession(
			const QueryParameters &parameters, bool forUpdate,
			bool neverCreate);

	static QueryResultType resolveQueryResultType(int8_t rawType);
	static GSRowSetType resolveRowSetType(QueryResultType type);
	const RowMapper& getResultRowMapper(QueryResultType type) const;
	RowMapper::MappingMode getResultRowMappingMode(QueryResultType type);
	bool isResultRowIdIncluded(QueryResultType type);

	void checkTransactionPreserved(
			bool forUpdate, int64_t transactionId,
			const bool *transactionStarted, bool updatable);

	bool filterIndexInfo(
			const GSIndexInfo &info, bool forCreation,
			GSIndexInfo &filteredInfo,
			std::vector<int32_t> &columnListStorage) const;
	GSIndexTypeFlags getDefaultIndexTypeFlag(int32_t columnId) const;

	static GSTimestamp wrapOptionalTimestamp(const GSTimestamp *timestamp);

	static bool isAnyQueryResultTypeEnabled();

	bool getRowForInternalController(
			const GSType *keyType, const void *key, void *rowObj);
	bool putRowForInternalController(
			const GSType *keyType, const void *key, const void *rowObj);

	GSResourceHeader resourceHeader_;

	size_t referenceCount_;

	GSGridStore *store_;
	ResourceSet activeResources_;

	RowMapper::Reference mapper_;
	const int32_t schemaVerId_;
	const int32_t partitionId_;
	const int64_t containerId_;
	UTIL_UNIQUE_PTR<ContainerKey> normalizedContainerKey_;

	int64_t sessionId_;
	int64_t transactionId_;
	int64_t statementId_;
	bool closed_;
	bool sessionPrepared_;
	bool containerLocked_;
	bool transactionStarted_;
	bool autoCommit_;
	bool cacheDisabled_;
};

struct GSContainerTag::AnyKeyTraits {
	typedef void Object;
	static const bool GENERAL_KEY = false;
	static const GSType* findKeyFullObjectType() { return NULL; }
};

struct GSContainerTag::GeneralKeyTraits {
	typedef GSRowKey Object;
	static const bool GENERAL_KEY = true;
	static const GSType* findKeyFullObjectType() { return NULL; }
};

struct GSContainerTag::PartialFetchStatus {
	PartialFetchStatus();

	static PartialFetchStatus get(ArrayByteInStream &in);

	bool isEnabled() const;

	int64_t totalRowCount_;
	int64_t rowSetId_;
	int64_t rowSetIdHint_;
};

struct GSContainerTag::PartialExecutionStatus {
	typedef std::vector<uint8_t> EntryBytes;
	typedef std::map<int32_t, EntryBytes> EntryMap;

	static const PartialExecutionStatus STATUS_DISABLED;
	static const PartialExecutionStatus STATUS_ENABLED_INITIAL;

	explicit PartialExecutionStatus(bool enabled);

	PartialExecutionStatus(const PartialExecutionStatus &another);
	PartialExecutionStatus& operator=(const PartialExecutionStatus &another);

	static PartialExecutionStatus get(ArrayByteInStream &in);
	void put(XArrayByteOutStream &out) const;

	bool isEnabled() const;

	const PartialExecutionStatus& inherit(
			const PartialExecutionStatus &next) const;

	bool enabled_;
	UTIL_UNIQUE_PTR<EntryMap> entryMap_;
};

struct GSContainerTag::QueryFormatter {
public:
	template<Statement::Id S> struct Typed;

	explicit QueryFormatter(Statement::Id statement);

	Statement::Id getStatement() const;

	virtual void getString(std::ostream &os, ArrayByteInStream &in) const;

private:
	Statement::Id statement_;
};

template<Statement::Id S>
struct GSContainerTag::QueryFormatter::Typed : public QueryFormatter {
public:
	Typed() : QueryFormatter(S) {}
};

struct GSContainerTag::QueryData {
	QueryData();

	QueryData(const QueryData &another);
	QueryData& operator=(const QueryData &another);

	util::NormalXArray<uint8_t> data_;
};

struct GSContainerTag::QueryParameters {
	struct StringFormatter;

	static const int64_t DEFAULT_SIZE_OPTION_VALUE;

	explicit QueryParameters(const QueryFormatter &formatter);

	Statement::Id getStatement() const;
	StringFormatter toString() const;

	void putFixed(XArrayByteOutStream &out) const;

	void setFetchLimit(int64_t fetchLimit);
	void setFetchSize(int64_t fetchSize);
	void setPartialExecutionEnabled(bool enabled);
	bool isPartialExecutionConfigured() const;

	static void checkPartialOptions(
			int64_t fetchSize, const PartialExecutionStatus &executionStatus);
	static bool isPartialFetch(int64_t fetchSize);

	bool isForUpdate(bool forUpdate) const;

	QueryParameters inherit(
			bool forUpdate, int64_t transactionId, bool transactionStarted,
			const PartialExecutionStatus &executionStatus) const;

	const QueryFormatter *formatter_;
	QueryData queryData_;

	int64_t fetchLimit_;
	int64_t fetchSize_;
	PartialExecutionStatus executionStatus_;
	bool executionPartial_;
	bool forUpdate_;
	bool transactionIdSpecified_;
	bool initialTransactionStarted_;
	int64_t initialTransactionId_;
};

struct GSContainerTag::QueryParameters::StringFormatter {
	explicit StringFormatter(const QueryParameters &parameters);

	void format(std::ostream &os) const;

	const QueryParameters &parameters_;
};

std::ostream& operator<<(
		std::ostream &os,
		const GSContainerTag::QueryParameters::StringFormatter &formatter);

struct GSQueryTag {
public:
	friend struct GSResourceHeader;
	friend struct GSContainerTag;

	typedef GSContainer::QueryFormatter QueryFormatter;
	typedef GSContainer::QueryParameters QueryParameters;
	typedef QueryParameters::StringFormatter StringFormatter;

	GSQueryTag(GSContainer &container, const QueryFormatter &formatter);
	~GSQueryTag();

	static void close(GSQuery **query) throw();

	GSContainer* getContainer();
	Statement::Id getStatement() const;
	StringFormatter toString() const;

	XArrayByteOutStream getParametersOutStream();

	GSRowSet* fetch(bool forUpdate);
	GSRowSet* getRowSet();

	void setFetchOption(
			GSFetchOption option, const void *value, GSType valueType);

	static bool isFetchSizeEnabled();

	void setForUpdate(bool forUpdate);
	bool isForUpdate() const;

	void makeRequest(XArrayByteOutStream &reqOut, bool noUUID);
	void acceptResponse(
			ArrayByteInStream &respIn,
			const GridStoreChannel::ConnectionId &connectionId,
			bool bufSwapAllowed);

private:
	GSQueryTag(const GSQuery&);
	GSQuery& operator=(const GSQuery&);

	void closeRemote() throw();

	void checkOpened();
	void clearLastRowSet() throw();

	static int64_t filterSizedFetchOption(
			GSFetchOption option, const void *value, GSType valueType);

	template<RowMapper::ElementType T>
	static const typename RowMapper::ObjectTypeTraits<T, false>::Object*
	filterFetchOption(
			GSFetchOption option, const void *value,
			const RowMapper::DetailElementType &valueType, bool force);

	GSResourceHeader resourceHeader_;

	GSContainer *container_;
	QueryParameters parameters_;
	GSRowSet *lastRowSet_;
	bool lastRowSetVisible_;
	bool closed_;
};

struct GSRowSetTag {
public:
	friend struct GSResourceHeader;
	friend struct GSContainerTag;

	typedef GSContainer::PartialFetchStatus PartialFetchStatus;
	typedef GSContainer::QueryParameters QueryParameters;

	GSRowSetTag(
			GSContainer &container, const RowMapper &mapper,
			int64_t rowCount, util::NormalXArray<uint8_t> &resultData,
			const ArrayByteInStream &resultInStream,
			RowMapper::MappingMode mappingMode, bool rowIdIncluded,
			GSRowSetType type, const QueryParameters &queryParameters,
			const PartialFetchStatus &fetchStatus,
			const GridStoreChannel::ConnectionId &connectionId,
			bool bufSwapAllowed);
	~GSRowSetTag();

	static void close(GSRowSet **rowSet) throw();

	void createReference() throw();
	static void removeReference(GSRowSet *&rowSet) throw();

	GSQuery::StringFormatter toQueryString() const;

	int32_t getSize() const;
	GSRowSetType getType() const;

	static GSResult getSchema(
			GSRowSet *rowSet, GSContainerInfo *schemaInfo, GSBool *exists,
			const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();
	bool getSchema(RowMapper::ContainerInfoRef<> &infoRef);

	bool isPartial() const;
	bool hasNext() const;

	GSContainer* getContainer() const;
	int64_t getTransactionId() const;
	bool isTransactionStarted() const;

	int64_t getRowIdForUpdate() const;
	int64_t getRowId() const;

	void closeRemote(bool transactionalOnly);

	void next(void *rowObj);
	void nextAggregation(GSAggregationResult **aggregationResult);
	void nextQueryAnalysis(GSQueryAnalysisEntry *queryAnalysis);

	void remove();
	void update(const void *rowObj);

	void getRowFixedPart(const uint8_t *&data, size_t &size) const;
	void getRowVariablePart(const uint8_t *&data, size_t &size) const;

	void prepareFollowing();
	void prepareFollowingDirect();

	void fetchFollowing();

	void executeFollowing();

private:
	GSRowSetTag(const GSRowSet&);
	GSRowSet& operator=(const GSRowSet&);

	static ArrayByteInStream swapAndCreateInput(
			util::NormalXArray<uint8_t> &destBuf,
			util::NormalXArray<uint8_t> &srcBuf,
			const ArrayByteInStream &srcInStream,
			bool bufSwapAllowed);

	void checkOpened() const;
	void checkInRange() const;

	void initializeLastKey();

	bool isUpdatable() const;

	GSResourceHeader resourceHeader_;

	size_t referenceCount_;

	GSContainer *container_;
	const RowMapper &mapper_;
	util::NormalXArray<uint8_t> resultData_;
	ArrayByteInStream resultInStream_;
	RowMapper::VarDataPool &varDataPool_;
	RowMapper::InputCursor cursor_;
	const GSRowSetType type_;

	RowMapper::GeneralRowHolder lastKey_;
	RowMapper::VarDataPool keyVarDataPool_;

	const int64_t totalRowCount_;
	int64_t remainingRowCount_;
	UTIL_UNIQUE_PTR<RowMapper> nextRowSchema_;
	QueryParameters queryParameters_;
	const PartialFetchStatus fetchStatus_;
	GridStoreChannel::ConnectionId connectionId_;
	bool previousFound_;
	bool followingLost_;
	bool closed_;
};

struct GSAggregationResultTag {
public:
	friend struct GSResourceHeader;
	friend struct GSContainerTag;
	friend class RowMapper;

	explicit GSAggregationResultTag(GSContainer &container);
	~GSAggregationResultTag();

	static void close(GSAggregationResult **aggregationResult) throw();
	static UTIL_UNIQUE_PTR<GSAggregationResult> newStandaloneInstance();

	void setValueAsLong(const int64_t &value);
	void setValueAsDouble(const double &value);
	void setValueAsTimestamp(const GSTimestamp &value);
	void setValueAsPreciseTimestamp(const GSPreciseTimestamp &value);

	bool getValue(void *value, const RowMapper::DetailElementType &valueType);

	template<typename Traits>
	static GSResult getValueTyped(
			GSAggregationResult *aggregationResult,
			typename Traits::Object *value, GSBool *assigned,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

private:
	GSAggregationResultTag();
	GSAggregationResultTag(const GSAggregationResult&);
	GSAggregationResult& operator=(const GSAggregationResult&);

	GSResourceHeader resourceHeader_;

	GSContainer *container_;
	const RowMapper::DetailElementType *resultType_;
	GSValue value_;
};

struct GSRowTag {
public:
	friend struct GSResourceHeader;

	static GSRow* create(
			GSGridStore &store, RowMapper::Reference &mapper,
			bool forKey = false);
	static GSRow* create(
			GSContainer &container, RowMapper::Reference &mapper,
			bool forKey = false);
	static GSRow* create(
			RowMapper::VarDataPool &pool, RowMapper::Reference &mapper,
			bool forKey = false);

	GSRow* create(bool forKey) const;

	static void close(GSRow **row) throw();

	static const GSRow& resolve(const void *resource);
	static GSRow& resolve(void *resource);

	static void createKeyMapper(
			RowMapper::Cache &cache, const RowMapper &srcMapper,
			const RowMapper::Config &config, RowMapper::VarDataPool &pool,
			RowMapper::Reference &mapperRef);

	const RowMapper& getRowMapper() const;
	void getContainerSchema(RowMapper::ContainerInfoRef<> &infoRef);

	static GSResult getContainerSchema(
			GSRow *row, GSContainerInfo *schemaInfo,
			const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	template<typename Traits>
	static GSResult getPrimitiveField(
			GSRow *row, int32_t columnId, typename Traits::Object *value,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	template<typename Traits>
	static GSResult getArrayField(
			GSRow *row, int32_t columnId, typename Traits::Object *value,
			size_t *arraySize,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	template<typename Traits>
	static GSResult setPrimitiveField(
			GSRow *row, int32_t columnId, const typename Traits::Object *value,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	template<typename Traits>
	static GSResult setArrayField(
			GSRow *row, int32_t columnId, typename Traits::Object value,
			size_t arraySize,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	void getField(
			int32_t columnId, GSValue &value,
			const RowMapper::DetailElementType *&type,
			const RowMapper::DetailElementType *expectedType);
	void getField(
			int32_t columnId, GSValue &value,
			const RowMapper::DetailElementType *&type,
			const RowMapper::DetailElementType *expectedType,
			RowMapper::VarDataPool &pool) const;
	void setField(
			int32_t columnId, const GSValue &value,
			const RowMapper::DetailElementType &expectedType);

	void clear(bool silent);

	void* allocate(size_t size);
	void deallocate(void *varData);

	const RowMapper::DetailElementType& getTypeGeneral(
			const RowMapper::Entry &entry) const;
	RowMapper::Entry getEntryGeneral(const RowMapper::Entry &src) const;

	bool isNull(int32_t columnId) const;
	void setNull(int32_t columnId, bool nullValue);

	bool isNullDirect(int32_t columnId) const;
	void setNullDirect(
			int32_t columnId, const RowMapper::Entry &entry, bool nullValue,
			bool withClear);

	const uint8_t* getNulls() const;
	uint8_t* getNulls();

	static size_t getInternalDataOffset();

	struct FieldClearer {
		template<typename Traits>
		void operator()(
				GSRow &row, const RowMapper::Entry &entry, const Traits&);
	};

private:

	static const size_t DATA_OFFSET;

	GSRowTag(
			void *parentResource, RowMapper::Reference &mapper,
			size_t objectSize, bool forKey);
	~GSRowTag() noexcept(false);

	GSRowTag(const GSRow&);
	GSRow& operator=(const GSRow&);

	static GSRow* create(
			void *parentResource, RowMapper::Reference &mapper, bool forKey);

	const RowMapper::Entry& getMappingEntry(int32_t columnId) const;
	RowMapper::VarDataPool& getVarDataPool();
	const RowMapper::DetailElementType& checkType(
			int32_t columnId, const RowMapper::Entry &entry,
			const RowMapper::DetailElementType *expectedType,
			bool overwriting) const;

	struct FieldGetter {
		FieldGetter(GSValue &value, RowMapper::VarDataPool &pool);

		template<typename Traits>
		void operator()(
				const GSRow &row, const RowMapper::Entry &entry, const Traits&);
		void operator()(
				const GSRow &row, const RowMapper::Entry &entry,
				const RowMapper::AnyNullTraits&);

		GSValue &value_;
		RowMapper::VarDataPool &pool_;
	};

	struct FieldSetter {
		FieldSetter(
				const GSValue &value, const RowMapper::DetailElementType &type);

		template<typename Traits>
		void operator()(
				GSRow &row, const RowMapper::Entry &entry, const Traits&);
		void operator()(
				GSRow &row, const RowMapper::Entry &entry,
				const RowMapper::AnyNullTraits&);

		const GSValue &value_;
		const RowMapper::DetailElementType &type_;
		bool deallocated_;
	};

	struct FieldDeallocator {
		template<typename Traits>
		void operator()(
				GSRow &row, const RowMapper::Entry &entry, const Traits&);
		void operator()(
				GSRow &row, const RowMapper::Entry &entry,
				const RowMapper::AnyNullTraits&);
	};

	struct FieldInitializer {
		template<typename Traits>
		void operator()(
				GSRow &row, const RowMapper::Entry &entry, const Traits&);
		void operator()(
				GSRow &row, const RowMapper::Entry &entry,
				const RowMapper::AnyNullTraits&);
	};

	template<typename Traits, bool ArrayType = Traits::ARRAY_TYPE>
	struct DirectFieldGetter {
		GSValue operator()(const GSRow &row, const RowMapper::Entry &entry);
	};

	template<typename Traits, bool ArrayType = Traits::ARRAY_TYPE>
	struct DirectFieldSetter {
		void operator()(
				GSRow &row, const RowMapper::Entry &entry,
				const GSValue &value);
	};

	template<typename Traits, typename T> void deallocate(
			const RowMapper::Entry&, T, const Traits&);

	template<typename Traits, typename E>
	void deallocate(
			const RowMapper::Entry&, const E *value, const Traits&);

	template<typename Traits>
	void deallocate(
			const RowMapper::Entry &entry, const GSChar *const *value,
			const Traits&);

	template<typename Traits>
	void deallocate(
			const RowMapper::Entry&, const GSBlob &value, const Traits&);

	template<bool ArrayType>
	void initializeArraySize(const RowMapper::Entry &entry);

	uint8_t* data();
	const uint8_t* data() const;

	size_t getGeneralRowSize() const;
	static size_t getGeneralRowSize(const RowMapper &mapper, bool forKey);

	GSResourceHeader resourceHeader_;

	void *parentResource_;
	RowMapper::Reference mapper_;
	RowMapper::VarDataPool *varDataPool_;
	bool forKey_;
};

struct GSRowKeyPredicateTag {
private:
	struct KeyLess;

public:
	friend struct GSResourceHeader;

	class KeyIterator;

	enum RangeElementType {
		RANGE_START,
		RANGE_FINISH,

		RANGE_COUNT
	};

	static const RowMapper::Config KEY_MAPPER_CONFIG;

	GSRowKeyPredicateTag(GSGridStore &store, RowMapper::Reference &mapper);
	~GSRowKeyPredicateTag();

	static void close(GSRowKeyPredicate **predicate) throw();

	static GSResult getKeySchema(
			GSRowKeyPredicate *predicate, GSContainerInfo *info,
			const ClientVersion &version,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	template<typename Traits, RangeElementType RangeType>
	static GSResult getRangeKey(
			GSRowKeyPredicate *predicate, const typename Traits::Object **key,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	template<typename Traits, RangeElementType RangeType>
	static GSResult setRangeKey(
			GSRowKeyPredicate *predicate, const typename Traits::Object *key,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	template<typename Traits>
	static GSResult getDistinctKeys(
			GSRowKeyPredicate *predicate,
			const typename Traits::Object **keyList, size_t *size,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	template<typename Traits>
	static GSResult addDistinctKey(
			GSRowKeyPredicate *predicate, const typename Traits::Object *key,
			const GSInterceptor::FunctionInfo &funcInfo) throw();

	static GSContainerInfo createSingleKeySchema(
			GSType keyType, GSColumnInfo &columnInfoStorage);

	const RowMapper::DetailElementType& getKeyType() const;
	const RowMapper& getRowMapper() const;

	bool hasRangeKey(RangeElementType rangeElemType) const;
	size_t getDistinctKeyCount() const;

	KeyIterator keyBegin() const;
	KeyIterator keyEnd() const;

	void getRangeKey(
			GSRowKey *&key, RangeElementType rangeElemType) const;
	void getRangeKey(
			const GSValue *&key,
			const RowMapper::DetailElementType *expectedType,
			RangeElementType rangeElemType) const;

	void getDistinctKeys(GSRowKey *const *&keyList, size_t &size) const;
	void getDistinctKeys(const GSValue *&keyList, size_t &size) const;

	void setRangeKey(const GSRowKey *key, RangeElementType rangeElemType);
	void setRangeKey(
			const GSValue *key,
			const RowMapper::DetailElementType &expectedType,
			RangeElementType rangeElemType);

	void addDistinctKey(const GSRowKey &key);
	void addDistinctKey(
			const GSValue &key,
			const RowMapper::DetailElementType &expectedType);

	void* allocate(size_t size);
	void deallocate(void *varData);

private:
	GSRowKeyPredicateTag(const GSRowKeyPredicate&);
	GSRowKeyPredicate& operator=(const GSRowKeyPredicate&);

	template<typename Traits>
	struct SingleTypedKeyReceiver;
	struct SingleUntypedKeyReceiver;
	struct GeneralKeyReceiver;

	typedef std::vector<GSValue> TinyRowKey;
	typedef std::pair<TinyRowKey, bool> RangeKeyEntry;
	typedef std::set<TinyRowKey, KeyLess> DistinctKeySet;

	static int64_t compareKey(
			const RowMapper &mapper,
			const TinyRowKey &key1, const  TinyRowKey &key2);
	static int64_t compareValue(
			const RowMapper::DetailElementType &keyType,
			const  GSValue &value1, const  GSValue &value2);

	template<typename T, typename Receiver>
	void getRangeKey(
			const T *&key, RangeElementType rangeElemType,
			const Receiver &receiver) const;

	void setRangeKey(TinyRowKey &key, RangeElementType rangeElemType);

	template<typename T, typename Receiver>
	void getDistinctKeys(
			const T *&keyList, size_t &size,
			const RowMapper::DetailElementType *expectedType,
			bool singleOnly, const Receiver &receiver) const;

	void addDistinctKey(TinyRowKey &key);

	void toTinyKey(const GSValue &src, TinyRowKey &dest);
	void toTinyKey(
			const GSRowKey &src, TinyRowKey &dest,
			RowMapper::VarDataPool &pool);

	GSValue toSingleKeyValue(
			const TinyRowKey &src, RowMapper::VarDataPool &pool) const;
	GSRowKey* toRowKey(const TinyRowKey &src) const;

	void checkKeyType(const GSRowKey &key) const;
	void checkKeyType(
			const RowMapper::DetailElementType *expectedType,
			bool singleOnly) const;

	static void checkMapper(const RowMapper &mapper);

	const RowMapper& resolveKeyMapper() const;
	static const RowMapper& resolveKeyMapper(const RowMapper &mapper);

	void clear();
	void clearRangeKeyEntry(RangeKeyEntry &keyEntry);
	void clearKey(TinyRowKey &key);
	void clearValue(GSValue &value, const RowMapper::DetailElementType &type);

	GSResourceHeader resourceHeader_;

	GSGridStore *store_;
	RowMapper::Reference mapper_;

	RangeKeyEntry rangeKeyEntries_[RANGE_COUNT];
	UTIL_UNIQUE_PTR<DistinctKeySet> distinctKeys_;

	TinyRowKey keyStorage_;
};

struct GSRowKeyPredicateTag::KeyLess {
	explicit KeyLess(const RowMapper &mapper);

	bool operator()(const TinyRowKey &key1, const TinyRowKey &key2) const;

	const RowMapper &mapper_;
};

class GSRowKeyPredicateTag::KeyIterator {
public:
	KeyIterator(const GSRowKeyPredicate &predicate, bool forBegin);

	bool operator!=(const KeyIterator &another) const;
	const GSRowKey* operator*() const;

	KeyIterator& operator++();

private:
	typedef DistinctKeySet::const_iterator DistinctKeyIterator;

	void updateIterator(bool nextOnly);

	const GSRowKeyPredicate &predicate_;
	RangeElementType rangeElemType_;
	DistinctKeyIterator keyIt_;
	RowMapper::GeneralRowHolder row_;
};

template<typename Traits>
struct GSRowKeyPredicateTag::SingleTypedKeyReceiver {
	typename Traits::Object receive(
			const GSRowKeyPredicate &predicate,
			const TinyRowKey &src, RowMapper::VarDataPool &pool) const {
		return Traits::as(predicate.toSingleKeyValue(src, pool));
	}
	void clear(typename Traits::Object &key) const {
		static_cast<void>(key);
	}
};

struct GSRowKeyPredicateTag::SingleUntypedKeyReceiver {
	GSValue receive(
			const GSRowKeyPredicate &predicate,
			const TinyRowKey &src, RowMapper::VarDataPool &pool) const {
		static_cast<void>(predicate);
		static_cast<void>(pool);
		return src.front();
	}
	void clear(GSValue &key) const {
		static_cast<void>(key);
	}
};

struct GSRowKeyPredicateTag::GeneralKeyReceiver {
	GSRowKey* receive(
			const GSRowKeyPredicate &predicate,
			const TinyRowKey &src, RowMapper::VarDataPool &pool) const {
		static_cast<void>(pool);
		return predicate.toRowKey(src);
	}
	void clear(GSRowKey *&key) const {
		GSRow::close(&key);
	}
};

struct GSPartitionControllerTag {
public:
	friend struct GSResourceHeader;

	explicit GSPartitionControllerTag(GSGridStore &store);
	~GSPartitionControllerTag();

	static void close(GSPartitionController **controller) throw();

	int32_t getPartitionCount();
	int64_t getContainerCount(int32_t partitionIndex);

	void getContainerNames(int32_t partitionIndex,
			int64_t start, const int64_t *limit,
			const GSChar *const *&nameList, size_t &size);

	void getHosts(int32_t partitionIndex,
			const GSChar *const *&addressList, size_t &size);
	void getOwnerHost(int32_t partitionIndex, const GSChar *&address);
	void getBackupHosts(int32_t partitionIndex,
			const GSChar *const *&addressList, size_t &size);

	int32_t getPartitionIndexOfContainer(const GSChar *containerName);

	void assignPreferableHost(
			int32_t partitionIndex, const GSChar *host);

private:
	GSPartitionControllerTag(const GSPartitionController&);
	GSPartitionController& operator=(const GSPartitionController&);

	void checkOpened();
	void checkPartitionIndex(int32_t partitionIndex);

	const GSChar *const* toAddressList(
			const std::vector<util::SocketAddress> &baseAddressList,
			size_t &resultListSize, RowMapper::VarDataPool &varDataPool);

	GSResourceHeader resourceHeader_;

	GSGridStore *store_;
};


template<typename T> inline bool ClientUtil::parseValue(
		const GSChar *strValue, T &resultValue) {
	return util::StrictLexicalConverter<T>()(strValue, resultValue);
}

template<typename T> inline T ClientUtil::parseValue(const GSChar *strValue) {
	T resultValue;
	if (!parseValue(strValue, resultValue)) {
		GS_CLIENT_THROW_ERROR(GS_ERROR_CC_ILLEGAL_VALUE_FORMAT, strValue);
	}

	return resultValue;
}

template<typename T> inline T ClientUtil::getNonAlignedValue(
		const void *ptr) {
	T value;
	memcpy(&value, ptr, sizeof(T));

	return value;
}

template<typename T> inline void ClientUtil::setNonAlignedValue(
		void *ptr, const T &value) {
	memcpy(ptr, &value, sizeof(T));
}

template<typename T>
inline const T* ClientUtil::findFromArray(
		const T *target, size_t totalByteSize, const T& value) {

	const T *end = target + totalByteSize / sizeof(T);
	const T *it = std::find(target, end, value);

	if (it == end) {
		return NULL;
	}

	return it;
}

template<typename C>
ArrayByteInStream ClientUtil::subStream(
		const C &buf, const ArrayByteInStream &in, size_t size) {
	if (size > in.base().remaining()) {
		GS_CLIENT_THROW_ERROR(GS_ERROR_CC_MESSAGE_CORRUPTED, "");
	}

	const size_t beginPos = in.base().position();
	const size_t endPos = beginPos + size;
	if (endPos > buf.size()) {
		GS_CLIENT_THROW_ERROR(GS_ERROR_CC_INTERNAL_ERROR, "");
	}

	ArrayByteInStream subIn((util::ArrayInStream(buf.data(), endPos)));
	subIn.base().position(beginPos);
	return subIn;
}


inline bool ClientUtil::varSizeIs1Byte(uint8_t val) {
	return ((val & 0x01) == 0x01);
}
inline bool ClientUtil::varSizeIs4Byte(uint8_t val) {
	return ((val & 0x03) == 0x00);
}
inline bool ClientUtil::varSizeIs8Byte(uint8_t val) {
	return ((val & 0x03) == 0x02);
}


inline uint32_t ClientUtil::decode1ByteVarSize(uint8_t val) {
	return val >> 1;
}
inline uint32_t ClientUtil::decode4ByteVarSize(uint32_t val) {
	return val >> 2;
}
inline uint64_t ClientUtil::decode8ByteVarSize(uint64_t val) {
	return val >> 2;
}


inline uint8_t ClientUtil::encode1ByteVarSize(uint8_t val) {
	assert(val < VAR_SIZE_1BYTE_THRESHOLD);
	return static_cast<uint8_t>((val << 1) | 0x01);
}
inline uint32_t ClientUtil::encode4ByteVarSize(uint32_t val) {
	assert(VAR_SIZE_1BYTE_THRESHOLD <= val
			&& val < VAR_SIZE_4BYTE_THRESHOLD);
	return val << 2;
}
inline uint64_t ClientUtil::encode8ByteVarSize(uint64_t val) {
	assert(VAR_SIZE_4BYTE_THRESHOLD <= val
			&& val < VAR_SIZE_8BYTE_THRESHOLD);
	return (val << 2) | 0x02;
}


inline uint32_t ClientUtil::getEncodedVarSize(size_t val) {
	if (val < VAR_SIZE_1BYTE_THRESHOLD) {
		return 1;
	}
	else if (val < VAR_SIZE_4BYTE_THRESHOLD) {
		return 4;
	}
	else {
		sizeValueToInt32(val); 
		return 8;
	}
}


inline size_t ClientUtil::calcNullsByteSize(size_t columnNum) {
	return (columnNum + 7) / 8;
}

#endif	
