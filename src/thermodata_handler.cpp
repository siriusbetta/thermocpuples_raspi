//
// Created by akony on 26.09.2024.
//

#include "thermodata_handler.h"

temperature_sensors_handler::temperature_sensors_handler( std::shared_ptr<max31855::MAX31855> max31855, std::vector<int> temperature_chip_select):
                                        _max31855(max31855), _temperature_chip_select(temperature_chip_select), _data_size(10)
{
    for(auto cs : _temperature_chip_select){
        max31855->addCS(cs);
    }

    max31855->begin();

    _data.resize(_data_size);
    _result.resize(_data_size);
    _is_handler_active = true;
}

temperature_sensors_handler::~temperature_sensors_handler() noexcept {
    stop();
}

void temperature_sensors_handler::start()
{
    _handler.reset( new std::thread([&](){
        while(_is_handler_active){
            _collectingData();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

    } ));
}

void temperature_sensors_handler::stop()
{
    _is_handler_active = false;
    if(_handler->joinable())
        _handler->join();
}

std::vector<double> temperature_sensors_handler::data()
{
    std::lock_guard<std::mutex> lock(_mtxData);
    return _result;
}

size_t temperature_sensors_handler::size()
{
    return _data_size;
}

void temperature_sensors_handler::_collectingData()
{
    std::lock_guard<std::mutex> lock(_mtxData);
    int cnt = 0;
    for(auto cs :_temperature_chip_select){
        _max31855->setCS(cs);
        _data[cnt] = _max31855->getTemperature();
        cnt++;
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

