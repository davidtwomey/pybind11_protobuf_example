#include <pybind11/cast.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include "google/protobuf/message.h"
#include "pybind11_protobuf/wrapped_proto_caster.h"
// #include "pybind11_protobuf/native_proto_caster.h"

#include "example.pb.h"

using pybind11::test::TestMessage;


TestMessage createMessage(std::string text) {
  TestMessage msg;
  msg.set_string_value(std::move(text));
  return msg;
}


void printMessage(const google::protobuf::Message& msg) {
  std::cout << msg.DebugString();
}


PYBIND11_MODULE(my_extension, m) {
  m.def("print_message",  pybind11::google::WithWrappedProtos(&printMessage), pybind11::arg("in"));
  m.def("create_message", pybind11::google::WithWrappedProtos(&createMessage), pybind11::arg("text") = "");  
}