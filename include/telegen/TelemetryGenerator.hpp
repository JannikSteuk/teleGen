#pragma once

#include <cstdint>
#include <string>

struct TelemetryPacket {
  uint32_t id;
  uint64_t timestamp_ns;
  double value;
};

class TelemetryGenerator {
protected:
  uint32_t id;
  std::string name;

public:
  TelemetryGenerator(uint32_t id, std::string name) {
    this->id = id;
    this->name = name;
  }

  virtual ~TelemetryGenerator() = default;
  virtual TelemetryPacket generate_next() = 0;
  virtual void set_parameter(const std::string &key, double value) {}

  uint32_t get_id() const { return id; }
  const std::string &get_name() const { return name; }
  void set_name(std::string name) { this->name = name;}
};
