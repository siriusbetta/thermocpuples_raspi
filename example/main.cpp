#include "iostream"
#include "vector"
#include "../MCP23017_raspi/src/MCP23017.h"
#include "../MAX31855_raspi/src/MAX31855.h"
#include "../src/thermodata_handler.h"

int main(int argc, char *argv[]){
  std::vector<int> cs = {0, 1, 2};
  std::shared_ptr<mcp32017::MCP23017> mcp23017;
  std::shared_ptr<max31855::MAX31855> max31 = std::make_shared<max31855::MAX31855>(mcp23017);
  temperature_sensors_handler temperatureSensorsHandler(max31, cs);
  return 0;
}