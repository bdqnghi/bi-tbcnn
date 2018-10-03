
#include "event_queue.hpp"

using namespace wlcpp;

event_queue::event_queue(wl_event_queue* queue, bool managed)
    : _queue(queue),
      _managed(managed) {
}

event_queue::event_queue(event_queue&& rhs)
    : _queue(rhs._queue),
      _managed(rhs._managed) {
    rhs.invalidate();
}

event_queue::~event_queue() {
    destroy();
}

bool event_queue::valid() const {
    return _queue != nullptr;
}

bool event_queue::managed() const {
    return _managed;
}

void event_queue::invalidate() {
    _queue = nullptr;
}

wl_event_queue* event_queue::wl_obj() const {
    return _queue;
}

event_queue& event_queue::operator=(event_queue&& rhs) {
    destroy();
    _queue = rhs._queue;
    _managed = rhs._managed;
    rhs.invalidate();
    return *this;
}

event_queue::operator bool() const {
    return valid();
}

bool event_queue::operator==(const event_queue& rhs) const {
    return _queue == rhs._queue;
}

bool event_queue::operator!=(const event_queue& rhs) const {
    return _queue != rhs._queue;
}

void event_queue::destroy() {
    if(valid() && _managed) {
        wl_event_queue_destroy(_queue);
    }
}

