//
// Created by akony on 08.10.2024.
//

#include "process.h"

process::process(std::function<void(void)> func, const long &delay) {
  m_func = func;
  m_delay = delay;
}

process::~process() { stop(); }

void process::start() {
  is_running = true;
  // m_thread = std::thread([&](){
  m_thread_ptr.reset(new std::thread([&]() {
    while (is_running) {
      auto delta =
          std::chrono::steady_clock::now() + std::chrono::milliseconds(m_delay);
      std::this_thread::sleep_until(delta);
      m_func();
    }
  }));
  m_thread_ptr->detach();
  // m_thread.detach();
}

void process::stop() {
  is_running = false;
  // m_thread.~thread();
  m_thread_ptr->~thread();
}
