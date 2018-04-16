#include <nan.h>
#include <node.h>
#include <node_object_wrap.h>
#include <iostream>
#include <fstream>
#include "../library/json.hpp"
#include "snapshot_parser.h"

#ifndef _PARSER_H
#define _PARSER_H

namespace parser {
using nlohmann::json;

class Parser : public node::ObjectWrap {
public:
	static void Init(v8::Local<v8::Object> exports);
	static void NewInstance(const Nan::FunctionCallbackInfo<v8::Value>& info);

private:
	explicit Parser(char* filename, int filelength);
	~Parser();
	v8::Local<v8::Object> GetNodeById_(long id, int current, int limit);
	static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
	static void GetFileName(const Nan::FunctionCallbackInfo<v8::Value>& info);
	static void Parse(const Nan::FunctionCallbackInfo<v8::Value>& info);
	static void GetNodeId(const Nan::FunctionCallbackInfo<v8::Value>& info);
	static void GetNodeByOrdinalId(const Nan::FunctionCallbackInfo<v8::Value>& info);
	static void GetNodeByAddress(const Nan::FunctionCallbackInfo<v8::Value>& info);
	static void GetNodeIdByAddress(const Nan::FunctionCallbackInfo<v8::Value>& info);
	static Nan::Persistent<v8::Function> constructor;
	// snapshot info
	int filelength_;
	char* filename_;
	snapshot_parser::SnapshotParser* snapshotParser;
};
}

#endif