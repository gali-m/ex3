#include <iostream>
#include "base_event.h"
#include "open_event.h"
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"


namespace mtm {
    
    OpenEvent::OpenEvent(const DateWrap date, const std::string name) : BaseEvent(date, name) {}

    OpenEvent::OpenEvent(const OpenEvent& open_event) : BaseEvent(open_event) {}

    OpenEvent* OpenEvent::clone() const
    {
        return new OpenEvent(*this);
    }

}