#ifndef CLOSED_EVENT_H
#define CLOSED_EVENT_H

#include <iostream>
#include "date_wrap.h"
#include "base_event.h"
#include "exceptions.h"

namespace mtm {

    class ClosedEvent : public BaseEvent{
        DateWrap date;
        std::string name;
        StudentNode* students_list;
        // TODO: add guest list
    
    public:
        ClosedEvent(DateWrap date, std::string name);
        ClosedEvent(const ClosedEvent& open_event);

        void addInvitee(StudentNode* student);
        void registerParticipant(StudentNode* student);
        void unregisterParticipant(StudentNode* student);
        std::ostream& printShort(std::ostream& os);
        std::ostream& printLong(std::ostream& os);
        BaseEvent* clone() override;

    private:
        bool is_student_in_list(StudentNode* students_list, StudentNode* student);
    };

}


#endif //CLOSED_EVENT_H