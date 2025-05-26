#include "iostream"
#include "vector"
#include "../src/thermodata_handler.h"

int main(int argc, char *argv[]){
  std::vector<int> cs = {0, 1, 2};
  temperature_sensors_handler temperatureSensorsHandler(cs);
  return 0;
}