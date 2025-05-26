//
// Created by akony on 30.09.2024.
//

#ifndef CICADA_DATA_HANDLER_H
#define CICADA_DATA_HANDLER_H

#include "process.h"
#include <memory>
#include <vector>

// template <typename T>
class data_handler {

public:
  data_handler(size_t size = 0, long delay = 0);
  ~data_handler();

  virtual std::vector<double> data() = 0;

  void start();
  void stop();

  void set_delay(long delay);
  void set_data_size(std::size_t size);

  [[maybe_unused]] std::size_t data_size();
  void set_function(std::function<void(void)> function);

protected:
  std::vector<double> m_data;

private:
  std::unique_ptr<process> m_process;
  std::function<void(void)> m_func;
  long m_delay;
};

#endif // CICADA_DATA_HANDLER_H
