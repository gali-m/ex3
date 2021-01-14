#ifndef CLOSED_EVENT_H
#define CLOSED_EVENT_H

#include <iostream>
#include "date_wrap.h"
#include "base_event.h"
#include "exceptions.h"

namespace mtm {

    class ClosedEvent : public BaseEvent{
        StudentNode* guest_list;
    
    public:
        ClosedEvent(DateWrap date, std::string name);
        // ClosedEvent(const ClosedEvent& open_event);

        void addInvitee(StudentNode* student);
        void registerParticipant(StudentNode* student);
        BaseEvent* clone() override;

    };

}


#endif //CLOSED_EVENT_H