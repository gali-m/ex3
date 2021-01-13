#ifndef OPEN_EVENT_H
#define OPEN_EVENT_H

#include <iostream>
#include "date_wrap.h"
#include "base_event.h"
#include "exceptions.h"

namespace mtm {

    class OpenEvent : public BaseEvent{
        DateWrap date;
        std::string name;
        StudentNode* students_list;
    
    public:
        OpenEvent(DateWrap date, std::string name);
        OpenEvent(const OpenEvent& open_event);

        void registerParticipant(StudentNode* student);
        void unregisterParticipant(StudentNode* student);
        std::ostream& printShort(std::ostream& os);
        std::ostream& printLong(std::ostream& os);
        BaseEvent* clone() override;

    private:
        bool is_student_in_list(StudentNode* students_list, StudentNode* student);
    };

}


#endif //OPEN_EVENT_H