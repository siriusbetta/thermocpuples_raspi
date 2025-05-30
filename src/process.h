//
// Created by akony on 08.10.2024.
//

#ifndef JETENGINE_LOGGER_PROCESS_H
#define JETENGINE_LOGGER_PROCESS_H

#include <functional>
#include <thread>

class process {
public:
  process(std::function<void(void)> func, const long &delay);
  virtual ~process();

  void start();
  void stop();

private:
  std::unique_ptr<std::thread> m_thread_ptr;
  // std::thread m_thread;
  bool is_running = false;
  long m_delay;
  std::function<void(void)> m_func;
};

#endif // JETENGINE_LOGGER_PROCESS_H
