//
// Created by akony on 26.09.2024.
//

#ifndef ASIO_TEST_THERMODATA_HANDLER_H
#define ASIO_TEST_THERMODATA_HANDLER_H

#include <thread>
#include <mutex>
#include <memory>
#include <vector>
#include "MAX31855.h"
#include "data_handler.h"

class temperature_sensors_handler : public data_handler{
public:
    temperature_sensors_handler(std::shared_ptr<max31855::MAX31855> max31855, std::vector<int> temperature_chip_select);
    virtual ~temperature_sensors_handler() noexcept;


    void start();
    void stop();

    size_t size();

    std::vector<double> data();

private:
    void _collectingData();
    std::unique_ptr<std::thread> _handler;
    bool _is_handler_active;
    std::mutex _mtxData;
    std::shared_ptr<max31855::MAX31855> _max31855;
    std::vector<int> _temperature_chip_select;

    std::vector<double> _data;
    std::vector<double> _result;
    size_t _data_size;
};


#endif //ASIO_TEST_THERMODATA_HANDLER_H
