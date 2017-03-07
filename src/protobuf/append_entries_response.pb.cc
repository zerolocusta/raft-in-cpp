// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: append_entries_response.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "append_entries_response.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace raft_msg {
class AppendEntriesResponseDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<AppendEntriesResponse> {
} _AppendEntriesResponse_default_instance_;

namespace protobuf_append_5fentries_5fresponse_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];

}  // namespace

const ::google::protobuf::uint32 TableStruct::offsets[] = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AppendEntriesResponse, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AppendEntriesResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AppendEntriesResponse, term_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AppendEntriesResponse, index_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AppendEntriesResponse, commit_index_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AppendEntriesResponse, success_),
  0,
  1,
  2,
  3,
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, 8, sizeof(AppendEntriesResponse)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_AppendEntriesResponse_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "append_entries_response.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace

void TableStruct::Shutdown() {
  _AppendEntriesResponse_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _AppendEntriesResponse_default_instance_.DefaultConstruct();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\035append_entries_response.proto\022\010raft_ms"
      "g\"[\n\025AppendEntriesResponse\022\014\n\004term\030\001 \002(\004"
      "\022\r\n\005index\030\002 \002(\004\022\024\n\014commit_index\030\003 \002(\004\022\017\n"
      "\007success\030\004 \002(\010"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 134);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "append_entries_response.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&TableStruct::Shutdown);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_append_5fentries_5fresponse_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int AppendEntriesResponse::kTermFieldNumber;
const int AppendEntriesResponse::kIndexFieldNumber;
const int AppendEntriesResponse::kCommitIndexFieldNumber;
const int AppendEntriesResponse::kSuccessFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

AppendEntriesResponse::AppendEntriesResponse()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_append_5fentries_5fresponse_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:raft_msg.AppendEntriesResponse)
}
AppendEntriesResponse::AppendEntriesResponse(const AppendEntriesResponse& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&term_, &from.term_,
    reinterpret_cast<char*>(&success_) -
    reinterpret_cast<char*>(&term_) + sizeof(success_));
  // @@protoc_insertion_point(copy_constructor:raft_msg.AppendEntriesResponse)
}

void AppendEntriesResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(&term_, 0, reinterpret_cast<char*>(&success_) -
    reinterpret_cast<char*>(&term_) + sizeof(success_));
}

AppendEntriesResponse::~AppendEntriesResponse() {
  // @@protoc_insertion_point(destructor:raft_msg.AppendEntriesResponse)
  SharedDtor();
}

void AppendEntriesResponse::SharedDtor() {
}

void AppendEntriesResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AppendEntriesResponse::descriptor() {
  protobuf_append_5fentries_5fresponse_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_append_5fentries_5fresponse_2eproto::file_level_metadata[0].descriptor;
}

const AppendEntriesResponse& AppendEntriesResponse::default_instance() {
  protobuf_append_5fentries_5fresponse_2eproto::InitDefaults();
  return *internal_default_instance();
}

AppendEntriesResponse* AppendEntriesResponse::New(::google::protobuf::Arena* arena) const {
  AppendEntriesResponse* n = new AppendEntriesResponse;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void AppendEntriesResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:raft_msg.AppendEntriesResponse)
  if (_has_bits_[0 / 32] & 15u) {
    ::memset(&term_, 0, reinterpret_cast<char*>(&success_) -
      reinterpret_cast<char*>(&term_) + sizeof(success_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool AppendEntriesResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:raft_msg.AppendEntriesResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 term = 1;
      case 1: {
        if (tag == 8u) {
          set_has_term();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &term_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required uint64 index = 2;
      case 2: {
        if (tag == 16u) {
          set_has_index();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &index_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required uint64 commit_index = 3;
      case 3: {
        if (tag == 24u) {
          set_has_commit_index();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &commit_index_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required bool success = 4;
      case 4: {
        if (tag == 32u) {
          set_has_success();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &success_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:raft_msg.AppendEntriesResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:raft_msg.AppendEntriesResponse)
  return false;
#undef DO_
}

void AppendEntriesResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:raft_msg.AppendEntriesResponse)
  // required uint64 term = 1;
  if (has_term()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->term(), output);
  }

  // required uint64 index = 2;
  if (has_index()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->index(), output);
  }

  // required uint64 commit_index = 3;
  if (has_commit_index()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->commit_index(), output);
  }

  // required bool success = 4;
  if (has_success()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->success(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:raft_msg.AppendEntriesResponse)
}

::google::protobuf::uint8* AppendEntriesResponse::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic;  // Unused
  // @@protoc_insertion_point(serialize_to_array_start:raft_msg.AppendEntriesResponse)
  // required uint64 term = 1;
  if (has_term()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->term(), target);
  }

  // required uint64 index = 2;
  if (has_index()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->index(), target);
  }

  // required uint64 commit_index = 3;
  if (has_commit_index()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->commit_index(), target);
  }

  // required bool success = 4;
  if (has_success()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->success(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:raft_msg.AppendEntriesResponse)
  return target;
}

size_t AppendEntriesResponse::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:raft_msg.AppendEntriesResponse)
  size_t total_size = 0;

  if (has_term()) {
    // required uint64 term = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->term());
  }

  if (has_index()) {
    // required uint64 index = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->index());
  }

  if (has_commit_index()) {
    // required uint64 commit_index = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->commit_index());
  }

  if (has_success()) {
    // required bool success = 4;
    total_size += 1 + 1;
  }

  return total_size;
}
size_t AppendEntriesResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:raft_msg.AppendEntriesResponse)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  if (((_has_bits_[0] & 0x0000000f) ^ 0x0000000f) == 0) {  // All required fields are present.
    // required uint64 term = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->term());

    // required uint64 index = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->index());

    // required uint64 commit_index = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->commit_index());

    // required bool success = 4;
    total_size += 1 + 1;

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void AppendEntriesResponse::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:raft_msg.AppendEntriesResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const AppendEntriesResponse* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const AppendEntriesResponse>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:raft_msg.AppendEntriesResponse)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:raft_msg.AppendEntriesResponse)
    MergeFrom(*source);
  }
}

void AppendEntriesResponse::MergeFrom(const AppendEntriesResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:raft_msg.AppendEntriesResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from._has_bits_[0 / 32] & 15u) {
    if (from.has_term()) {
      set_term(from.term());
    }
    if (from.has_index()) {
      set_index(from.index());
    }
    if (from.has_commit_index()) {
      set_commit_index(from.commit_index());
    }
    if (from.has_success()) {
      set_success(from.success());
    }
  }
}

void AppendEntriesResponse::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:raft_msg.AppendEntriesResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AppendEntriesResponse::CopyFrom(const AppendEntriesResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:raft_msg.AppendEntriesResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AppendEntriesResponse::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;
  return true;
}

void AppendEntriesResponse::Swap(AppendEntriesResponse* other) {
  if (other == this) return;
  InternalSwap(other);
}
void AppendEntriesResponse::InternalSwap(AppendEntriesResponse* other) {
  std::swap(term_, other->term_);
  std::swap(index_, other->index_);
  std::swap(commit_index_, other->commit_index_);
  std::swap(success_, other->success_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata AppendEntriesResponse::GetMetadata() const {
  protobuf_append_5fentries_5fresponse_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_append_5fentries_5fresponse_2eproto::file_level_metadata[0];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// AppendEntriesResponse

// required uint64 term = 1;
bool AppendEntriesResponse::has_term() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void AppendEntriesResponse::set_has_term() {
  _has_bits_[0] |= 0x00000001u;
}
void AppendEntriesResponse::clear_has_term() {
  _has_bits_[0] &= ~0x00000001u;
}
void AppendEntriesResponse::clear_term() {
  term_ = GOOGLE_ULONGLONG(0);
  clear_has_term();
}
::google::protobuf::uint64 AppendEntriesResponse::term() const {
  // @@protoc_insertion_point(field_get:raft_msg.AppendEntriesResponse.term)
  return term_;
}
void AppendEntriesResponse::set_term(::google::protobuf::uint64 value) {
  set_has_term();
  term_ = value;
  // @@protoc_insertion_point(field_set:raft_msg.AppendEntriesResponse.term)
}

// required uint64 index = 2;
bool AppendEntriesResponse::has_index() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void AppendEntriesResponse::set_has_index() {
  _has_bits_[0] |= 0x00000002u;
}
void AppendEntriesResponse::clear_has_index() {
  _has_bits_[0] &= ~0x00000002u;
}
void AppendEntriesResponse::clear_index() {
  index_ = GOOGLE_ULONGLONG(0);
  clear_has_index();
}
::google::protobuf::uint64 AppendEntriesResponse::index() const {
  // @@protoc_insertion_point(field_get:raft_msg.AppendEntriesResponse.index)
  return index_;
}
void AppendEntriesResponse::set_index(::google::protobuf::uint64 value) {
  set_has_index();
  index_ = value;
  // @@protoc_insertion_point(field_set:raft_msg.AppendEntriesResponse.index)
}

// required uint64 commit_index = 3;
bool AppendEntriesResponse::has_commit_index() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
void AppendEntriesResponse::set_has_commit_index() {
  _has_bits_[0] |= 0x00000004u;
}
void AppendEntriesResponse::clear_has_commit_index() {
  _has_bits_[0] &= ~0x00000004u;
}
void AppendEntriesResponse::clear_commit_index() {
  commit_index_ = GOOGLE_ULONGLONG(0);
  clear_has_commit_index();
}
::google::protobuf::uint64 AppendEntriesResponse::commit_index() const {
  // @@protoc_insertion_point(field_get:raft_msg.AppendEntriesResponse.commit_index)
  return commit_index_;
}
void AppendEntriesResponse::set_commit_index(::google::protobuf::uint64 value) {
  set_has_commit_index();
  commit_index_ = value;
  // @@protoc_insertion_point(field_set:raft_msg.AppendEntriesResponse.commit_index)
}

// required bool success = 4;
bool AppendEntriesResponse::has_success() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
void AppendEntriesResponse::set_has_success() {
  _has_bits_[0] |= 0x00000008u;
}
void AppendEntriesResponse::clear_has_success() {
  _has_bits_[0] &= ~0x00000008u;
}
void AppendEntriesResponse::clear_success() {
  success_ = false;
  clear_has_success();
}
bool AppendEntriesResponse::success() const {
  // @@protoc_insertion_point(field_get:raft_msg.AppendEntriesResponse.success)
  return success_;
}
void AppendEntriesResponse::set_success(bool value) {
  set_has_success();
  success_ = value;
  // @@protoc_insertion_point(field_set:raft_msg.AppendEntriesResponse.success)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace raft_msg

// @@protoc_insertion_point(global_scope)
