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
        ClosedEvent(const DateWrap date, const std::string name);
        // ClosedEvent(const ClosedEvent& open_event);

        void addInvitee(int student_id);
        void registerParticipant(int student_id) override;
        BaseEvent* clone() const override;

    };

}


#endif //CLOSED_EVENT_H