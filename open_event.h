#ifndef OPEN_EVENT_H
#define OPEN_EVENT_H

#include <iostream>
#include "date_wrap.h"
#include "base_event.h"
#include "exceptions.h"

namespace mtm {

    class OpenEvent : public BaseEvent{
    
    public:
        OpenEvent(DateWrap date, std::string name);
        // OpenEvent(const OpenEvent& open_event);

        // void registerParticipant(int student_id);
        BaseEvent* clone() const override;

    };

}


#endif //OPEN_EVENT_H