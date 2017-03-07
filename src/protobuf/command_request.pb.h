// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: command_request.proto

#ifndef PROTOBUF_command_5frequest_2eproto__INCLUDED
#define PROTOBUF_command_5frequest_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3002000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3002000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "raft_enum.pb.h"
// @@protoc_insertion_point(includes)
namespace raft_msg {
class CommandRequest;
class CommandRequestDefaultTypeInternal;
extern CommandRequestDefaultTypeInternal _CommandRequest_default_instance_;
class CommandRequest_Entry;
class CommandRequest_EntryDefaultTypeInternal;
extern CommandRequest_EntryDefaultTypeInternal _CommandRequest_Entry_default_instance_;
}  // namespace raft_msg

namespace raft_msg {

namespace protobuf_command_5frequest_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_command_5frequest_2eproto

// ===================================================================

class CommandRequest_Entry : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:raft_msg.CommandRequest.Entry) */ {
 public:
  CommandRequest_Entry();
  virtual ~CommandRequest_Entry();

  CommandRequest_Entry(const CommandRequest_Entry& from);

  inline CommandRequest_Entry& operator=(const CommandRequest_Entry& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CommandRequest_Entry& default_instance();

  static inline const CommandRequest_Entry* internal_default_instance() {
    return reinterpret_cast<const CommandRequest_Entry*>(
               &_CommandRequest_Entry_default_instance_);
  }

  void Swap(CommandRequest_Entry* other);

  // implements Message ----------------------------------------------

  inline CommandRequest_Entry* New() const PROTOBUF_FINAL { return New(NULL); }

  CommandRequest_Entry* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CommandRequest_Entry& from);
  void MergeFrom(const CommandRequest_Entry& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(CommandRequest_Entry* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string key = 1;
  bool has_key() const;
  void clear_key();
  static const int kKeyFieldNumber = 1;
  const ::std::string& key() const;
  void set_key(const ::std::string& value);
  #if LANG_CXX11
  void set_key(::std::string&& value);
  #endif
  void set_key(const char* value);
  void set_key(const char* value, size_t size);
  ::std::string* mutable_key();
  ::std::string* release_key();
  void set_allocated_key(::std::string* key);

  // optional string value = 2;
  bool has_value() const;
  void clear_value();
  static const int kValueFieldNumber = 2;
  const ::std::string& value() const;
  void set_value(const ::std::string& value);
  #if LANG_CXX11
  void set_value(::std::string&& value);
  #endif
  void set_value(const char* value);
  void set_value(const char* value, size_t size);
  ::std::string* mutable_value();
  ::std::string* release_value();
  void set_allocated_value(::std::string* value);

  // @@protoc_insertion_point(class_scope:raft_msg.CommandRequest.Entry)
 private:
  void set_has_key();
  void clear_has_key();
  void set_has_value();
  void clear_has_value();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr key_;
  ::google::protobuf::internal::ArenaStringPtr value_;
  friend struct  protobuf_command_5frequest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class CommandRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:raft_msg.CommandRequest) */ {
 public:
  CommandRequest();
  virtual ~CommandRequest();

  CommandRequest(const CommandRequest& from);

  inline CommandRequest& operator=(const CommandRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CommandRequest& default_instance();

  static inline const CommandRequest* internal_default_instance() {
    return reinterpret_cast<const CommandRequest*>(
               &_CommandRequest_default_instance_);
  }

  void Swap(CommandRequest* other);

  // implements Message ----------------------------------------------

  inline CommandRequest* New() const PROTOBUF_FINAL { return New(NULL); }

  CommandRequest* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CommandRequest& from);
  void MergeFrom(const CommandRequest& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(CommandRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef CommandRequest_Entry Entry;

  // accessors -------------------------------------------------------

  // required string passwd = 2;
  bool has_passwd() const;
  void clear_passwd();
  static const int kPasswdFieldNumber = 2;
  const ::std::string& passwd() const;
  void set_passwd(const ::std::string& value);
  #if LANG_CXX11
  void set_passwd(::std::string&& value);
  #endif
  void set_passwd(const char* value);
  void set_passwd(const char* value, size_t size);
  ::std::string* mutable_passwd();
  ::std::string* release_passwd();
  void set_allocated_passwd(::std::string* passwd);

  // required .raft_msg.CommandRequest.Entry command = 4;
  bool has_command() const;
  void clear_command();
  static const int kCommandFieldNumber = 4;
  const ::raft_msg::CommandRequest_Entry& command() const;
  ::raft_msg::CommandRequest_Entry* mutable_command();
  ::raft_msg::CommandRequest_Entry* release_command();
  void set_allocated_command(::raft_msg::CommandRequest_Entry* command);

  // required uint64 command_id = 1;
  bool has_command_id() const;
  void clear_command_id();
  static const int kCommandIdFieldNumber = 1;
  ::google::protobuf::uint64 command_id() const;
  void set_command_id(::google::protobuf::uint64 value);

  // required .raft_msg.CommandType command_type = 3;
  bool has_command_type() const;
  void clear_command_type();
  static const int kCommandTypeFieldNumber = 3;
  ::raft_msg::CommandType command_type() const;
  void set_command_type(::raft_msg::CommandType value);

  // @@protoc_insertion_point(class_scope:raft_msg.CommandRequest)
 private:
  void set_has_command_id();
  void clear_has_command_id();
  void set_has_passwd();
  void clear_has_passwd();
  void set_has_command_type();
  void clear_has_command_type();
  void set_has_command();
  void clear_has_command();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr passwd_;
  ::raft_msg::CommandRequest_Entry* command_;
  ::google::protobuf::uint64 command_id_;
  int command_type_;
  friend struct  protobuf_command_5frequest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// CommandRequest_Entry

// required string key = 1;
inline bool CommandRequest_Entry::has_key() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CommandRequest_Entry::set_has_key() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CommandRequest_Entry::clear_has_key() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CommandRequest_Entry::clear_key() {
  key_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_key();
}
inline const ::std::string& CommandRequest_Entry::key() const {
  // @@protoc_insertion_point(field_get:raft_msg.CommandRequest.Entry.key)
  return key_.GetNoArena();
}
inline void CommandRequest_Entry::set_key(const ::std::string& value) {
  set_has_key();
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:raft_msg.CommandRequest.Entry.key)
}
#if LANG_CXX11
inline void CommandRequest_Entry::set_key(::std::string&& value) {
  set_has_key();
  key_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:raft_msg.CommandRequest.Entry.key)
}
#endif
inline void CommandRequest_Entry::set_key(const char* value) {
  set_has_key();
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:raft_msg.CommandRequest.Entry.key)
}
inline void CommandRequest_Entry::set_key(const char* value, size_t size) {
  set_has_key();
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:raft_msg.CommandRequest.Entry.key)
}
inline ::std::string* CommandRequest_Entry::mutable_key() {
  set_has_key();
  // @@protoc_insertion_point(field_mutable:raft_msg.CommandRequest.Entry.key)
  return key_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CommandRequest_Entry::release_key() {
  // @@protoc_insertion_point(field_release:raft_msg.CommandRequest.Entry.key)
  clear_has_key();
  return key_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CommandRequest_Entry::set_allocated_key(::std::string* key) {
  if (key != NULL) {
    set_has_key();
  } else {
    clear_has_key();
  }
  key_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), key);
  // @@protoc_insertion_point(field_set_allocated:raft_msg.CommandRequest.Entry.key)
}

// optional string value = 2;
inline bool CommandRequest_Entry::has_value() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CommandRequest_Entry::set_has_value() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CommandRequest_Entry::clear_has_value() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CommandRequest_Entry::clear_value() {
  value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_value();
}
inline const ::std::string& CommandRequest_Entry::value() const {
  // @@protoc_insertion_point(field_get:raft_msg.CommandRequest.Entry.value)
  return value_.GetNoArena();
}
inline void CommandRequest_Entry::set_value(const ::std::string& value) {
  set_has_value();
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:raft_msg.CommandRequest.Entry.value)
}
#if LANG_CXX11
inline void CommandRequest_Entry::set_value(::std::string&& value) {
  set_has_value();
  value_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:raft_msg.CommandRequest.Entry.value)
}
#endif
inline void CommandRequest_Entry::set_value(const char* value) {
  set_has_value();
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:raft_msg.CommandRequest.Entry.value)
}
inline void CommandRequest_Entry::set_value(const char* value, size_t size) {
  set_has_value();
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:raft_msg.CommandRequest.Entry.value)
}
inline ::std::string* CommandRequest_Entry::mutable_value() {
  set_has_value();
  // @@protoc_insertion_point(field_mutable:raft_msg.CommandRequest.Entry.value)
  return value_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CommandRequest_Entry::release_value() {
  // @@protoc_insertion_point(field_release:raft_msg.CommandRequest.Entry.value)
  clear_has_value();
  return value_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CommandRequest_Entry::set_allocated_value(::std::string* value) {
  if (value != NULL) {
    set_has_value();
  } else {
    clear_has_value();
  }
  value_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set_allocated:raft_msg.CommandRequest.Entry.value)
}

// -------------------------------------------------------------------

// CommandRequest

// required uint64 command_id = 1;
inline bool CommandRequest::has_command_id() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CommandRequest::set_has_command_id() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CommandRequest::clear_has_command_id() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CommandRequest::clear_command_id() {
  command_id_ = GOOGLE_ULONGLONG(0);
  clear_has_command_id();
}
inline ::google::protobuf::uint64 CommandRequest::command_id() const {
  // @@protoc_insertion_point(field_get:raft_msg.CommandRequest.command_id)
  return command_id_;
}
inline void CommandRequest::set_command_id(::google::protobuf::uint64 value) {
  set_has_command_id();
  command_id_ = value;
  // @@protoc_insertion_point(field_set:raft_msg.CommandRequest.command_id)
}

// required string passwd = 2;
inline bool CommandRequest::has_passwd() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CommandRequest::set_has_passwd() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CommandRequest::clear_has_passwd() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CommandRequest::clear_passwd() {
  passwd_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_passwd();
}
inline const ::std::string& CommandRequest::passwd() const {
  // @@protoc_insertion_point(field_get:raft_msg.CommandRequest.passwd)
  return passwd_.GetNoArena();
}
inline void CommandRequest::set_passwd(const ::std::string& value) {
  set_has_passwd();
  passwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:raft_msg.CommandRequest.passwd)
}
#if LANG_CXX11
inline void CommandRequest::set_passwd(::std::string&& value) {
  set_has_passwd();
  passwd_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:raft_msg.CommandRequest.passwd)
}
#endif
inline void CommandRequest::set_passwd(const char* value) {
  set_has_passwd();
  passwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:raft_msg.CommandRequest.passwd)
}
inline void CommandRequest::set_passwd(const char* value, size_t size) {
  set_has_passwd();
  passwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:raft_msg.CommandRequest.passwd)
}
inline ::std::string* CommandRequest::mutable_passwd() {
  set_has_passwd();
  // @@protoc_insertion_point(field_mutable:raft_msg.CommandRequest.passwd)
  return passwd_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CommandRequest::release_passwd() {
  // @@protoc_insertion_point(field_release:raft_msg.CommandRequest.passwd)
  clear_has_passwd();
  return passwd_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CommandRequest::set_allocated_passwd(::std::string* passwd) {
  if (passwd != NULL) {
    set_has_passwd();
  } else {
    clear_has_passwd();
  }
  passwd_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), passwd);
  // @@protoc_insertion_point(field_set_allocated:raft_msg.CommandRequest.passwd)
}

// required .raft_msg.CommandType command_type = 3;
inline bool CommandRequest::has_command_type() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void CommandRequest::set_has_command_type() {
  _has_bits_[0] |= 0x00000008u;
}
inline void CommandRequest::clear_has_command_type() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void CommandRequest::clear_command_type() {
  command_type_ = 0;
  clear_has_command_type();
}
inline ::raft_msg::CommandType CommandRequest::command_type() const {
  // @@protoc_insertion_point(field_get:raft_msg.CommandRequest.command_type)
  return static_cast< ::raft_msg::CommandType >(command_type_);
}
inline void CommandRequest::set_command_type(::raft_msg::CommandType value) {
  assert(::raft_msg::CommandType_IsValid(value));
  set_has_command_type();
  command_type_ = value;
  // @@protoc_insertion_point(field_set:raft_msg.CommandRequest.command_type)
}

// required .raft_msg.CommandRequest.Entry command = 4;
inline bool CommandRequest::has_command() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CommandRequest::set_has_command() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CommandRequest::clear_has_command() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CommandRequest::clear_command() {
  if (command_ != NULL) command_->::raft_msg::CommandRequest_Entry::Clear();
  clear_has_command();
}
inline const ::raft_msg::CommandRequest_Entry& CommandRequest::command() const {
  // @@protoc_insertion_point(field_get:raft_msg.CommandRequest.command)
  return command_ != NULL ? *command_
                         : *::raft_msg::CommandRequest_Entry::internal_default_instance();
}
inline ::raft_msg::CommandRequest_Entry* CommandRequest::mutable_command() {
  set_has_command();
  if (command_ == NULL) {
    command_ = new ::raft_msg::CommandRequest_Entry;
  }
  // @@protoc_insertion_point(field_mutable:raft_msg.CommandRequest.command)
  return command_;
}
inline ::raft_msg::CommandRequest_Entry* CommandRequest::release_command() {
  // @@protoc_insertion_point(field_release:raft_msg.CommandRequest.command)
  clear_has_command();
  ::raft_msg::CommandRequest_Entry* temp = command_;
  command_ = NULL;
  return temp;
}
inline void CommandRequest::set_allocated_command(::raft_msg::CommandRequest_Entry* command) {
  delete command_;
  command_ = command;
  if (command) {
    set_has_command();
  } else {
    clear_has_command();
  }
  // @@protoc_insertion_point(field_set_allocated:raft_msg.CommandRequest.command)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace raft_msg

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_command_5frequest_2eproto__INCLUDED