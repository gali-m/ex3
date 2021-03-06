#ifndef CLOSED_EVENT_H
#define CLOSED_EVENT_H

#include <iostream>
#include "../partA/date_wrap.h"
#include "base_event.h"
#include "../partA/exceptions.h"

namespace mtm {

    class ClosedEvent : public BaseEvent{
        StudentNode* guest_list;
    
    public:
        ClosedEvent(const DateWrap date, const std::string name);
        ClosedEvent(const ClosedEvent& closed_event);
        ~ClosedEvent();

        void addInvitee(int student_id);
        void registerParticipant(int student_id) override;
        ClosedEvent* clone() const override;

    };

}


#endif //CLOSED_EVENT_H