// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: append_entries_response.proto

#ifndef PROTOBUF_append_5fentries_5fresponse_2eproto__INCLUDED
#define PROTOBUF_append_5fentries_5fresponse_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)
namespace raft_msg {
class AppendEntriesResponse;
class AppendEntriesResponseDefaultTypeInternal;
extern AppendEntriesResponseDefaultTypeInternal _AppendEntriesResponse_default_instance_;
}  // namespace raft_msg

namespace raft_msg {

namespace protobuf_append_5fentries_5fresponse_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_append_5fentries_5fresponse_2eproto

// ===================================================================

class AppendEntriesResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:raft_msg.AppendEntriesResponse) */ {
 public:
  AppendEntriesResponse();
  virtual ~AppendEntriesResponse();

  AppendEntriesResponse(const AppendEntriesResponse& from);

  inline AppendEntriesResponse& operator=(const AppendEntriesResponse& from) {
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
  static const AppendEntriesResponse& default_instance();

  static inline const AppendEntriesResponse* internal_default_instance() {
    return reinterpret_cast<const AppendEntriesResponse*>(
               &_AppendEntriesResponse_default_instance_);
  }

  void Swap(AppendEntriesResponse* other);

  // implements Message ----------------------------------------------

  inline AppendEntriesResponse* New() const PROTOBUF_FINAL { return New(NULL); }

  AppendEntriesResponse* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const AppendEntriesResponse& from);
  void MergeFrom(const AppendEntriesResponse& from);
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
  void InternalSwap(AppendEntriesResponse* other);
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

  // required uint64 term = 1;
  bool has_term() const;
  void clear_term();
  static const int kTermFieldNumber = 1;
  ::google::protobuf::uint64 term() const;
  void set_term(::google::protobuf::uint64 value);

  // required uint64 current_index = 2;
  bool has_current_index() const;
  void clear_current_index();
  static const int kCurrentIndexFieldNumber = 2;
  ::google::protobuf::uint64 current_index() const;
  void set_current_index(::google::protobuf::uint64 value);

  // required uint64 commit_index = 3;
  bool has_commit_index() const;
  void clear_commit_index();
  static const int kCommitIndexFieldNumber = 3;
  ::google::protobuf::uint64 commit_index() const;
  void set_commit_index(::google::protobuf::uint64 value);

  // required bool success = 4;
  bool has_success() const;
  void clear_success();
  static const int kSuccessFieldNumber = 4;
  bool success() const;
  void set_success(bool value);

  // @@protoc_insertion_point(class_scope:raft_msg.AppendEntriesResponse)
 private:
  void set_has_term();
  void clear_has_term();
  void set_has_current_index();
  void clear_has_current_index();
  void set_has_commit_index();
  void clear_has_commit_index();
  void set_has_success();
  void clear_has_success();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::uint64 term_;
  ::google::protobuf::uint64 current_index_;
  ::google::protobuf::uint64 commit_index_;
  bool success_;
  friend struct  protobuf_append_5fentries_5fresponse_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// AppendEntriesResponse

// required uint64 term = 1;
inline bool AppendEntriesResponse::has_term() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void AppendEntriesResponse::set_has_term() {
  _has_bits_[0] |= 0x00000001u;
}
inline void AppendEntriesResponse::clear_has_term() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void AppendEntriesResponse::clear_term() {
  term_ = GOOGLE_ULONGLONG(0);
  clear_has_term();
}
inline ::google::protobuf::uint64 AppendEntriesResponse::term() const {
  // @@protoc_insertion_point(field_get:raft_msg.AppendEntriesResponse.term)
  return term_;
}
inline void AppendEntriesResponse::set_term(::google::protobuf::uint64 value) {
  set_has_term();
  term_ = value;
  // @@protoc_insertion_point(field_set:raft_msg.AppendEntriesResponse.term)
}

// required uint64 current_index = 2;
inline bool AppendEntriesResponse::has_current_index() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void AppendEntriesResponse::set_has_current_index() {
  _has_bits_[0] |= 0x00000002u;
}
inline void AppendEntriesResponse::clear_has_current_index() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void AppendEntriesResponse::clear_current_index() {
  current_index_ = GOOGLE_ULONGLONG(0);
  clear_has_current_index();
}
inline ::google::protobuf::uint64 AppendEntriesResponse::current_index() const {
  // @@protoc_insertion_point(field_get:raft_msg.AppendEntriesResponse.current_index)
  return current_index_;
}
inline void AppendEntriesResponse::set_current_index(::google::protobuf::uint64 value) {
  set_has_current_index();
  current_index_ = value;
  // @@protoc_insertion_point(field_set:raft_msg.AppendEntriesResponse.current_index)
}

// required uint64 commit_index = 3;
inline bool AppendEntriesResponse::has_commit_index() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void AppendEntriesResponse::set_has_commit_index() {
  _has_bits_[0] |= 0x00000004u;
}
inline void AppendEntriesResponse::clear_has_commit_index() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void AppendEntriesResponse::clear_commit_index() {
  commit_index_ = GOOGLE_ULONGLONG(0);
  clear_has_commit_index();
}
inline ::google::protobuf::uint64 AppendEntriesResponse::commit_index() const {
  // @@protoc_insertion_point(field_get:raft_msg.AppendEntriesResponse.commit_index)
  return commit_index_;
}
inline void AppendEntriesResponse::set_commit_index(::google::protobuf::uint64 value) {
  set_has_commit_index();
  commit_index_ = value;
  // @@protoc_insertion_point(field_set:raft_msg.AppendEntriesResponse.commit_index)
}

// required bool success = 4;
inline bool AppendEntriesResponse::has_success() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void AppendEntriesResponse::set_has_success() {
  _has_bits_[0] |= 0x00000008u;
}
inline void AppendEntriesResponse::clear_has_success() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void AppendEntriesResponse::clear_success() {
  success_ = false;
  clear_has_success();
}
inline bool AppendEntriesResponse::success() const {
  // @@protoc_insertion_point(field_get:raft_msg.AppendEntriesResponse.success)
  return success_;
}
inline void AppendEntriesResponse::set_success(bool value) {
  set_has_success();
  success_ = value;
  // @@protoc_insertion_point(field_set:raft_msg.AppendEntriesResponse.success)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace raft_msg

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_append_5fentries_5fresponse_2eproto__INCLUDED
