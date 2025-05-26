//
// Created by akony on 10.10.2024.
//

#include "data_handler.h"

/*template <typename T>*/ data_handler::data_handler(size_t size, long delay) {
  set_data_size(size);
  set_delay(delay);
}

/*template <typename T>*/ data_handler::~data_handler() { m_process->stop(); }

/*template <typename T>*/ void data_handler::start() {
  try {
    m_process.reset(new process(m_func, m_delay));
    m_process->start();
  } catch (std::bad_function_call &e) {
    e.what();
  }
}

/*template <typename T>*/ void data_handler::set_delay(long delay) {
  m_delay = delay;
}

/*template <typename T> */ void data_handler::stop() { m_process->stop(); }

/*template <typename T>*/ void data_handler::set_data_size(std::size_t size) {
  m_data.resize(size);
}

/*template <typename T>*/ std::size_t data_handler::data_size() {
  return m_data.size();
}

/*template <typename T>*/ void
data_handler::set_function(std::function<void(void)> function) {
  m_func = std::move(function);
}
