#include <iostream>
#include "base_event.h"
#include "date_wrap.h"
#include "exceptions.h"


namespace mtm {

    BaseEvent::BaseEvent(DateWrap date, std::string name)
    {
        this->event.date = date;
        this->event.name = name;
        this->event.students_list = NULL;
    }

}