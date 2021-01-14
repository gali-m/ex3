#ifndef COSTOM_EVENT_H
#define COSTOM_EVENT_H

#include <iostream>
#include "date_wrap.h"
#include "base_event.h"
#include "exceptions.h"

namespace mtm {

    template <class CanRegister>
    class CustomEvent : public BaseEvent{
        CanRegister can_register_func;
    
    public:
        CustomEvent(DateWrap date, std::string name, CanRegister can_register_func);
        CustomEvent(const CustomEvent& open_event);

        void addInvitee(StudentNode* student);
        void registerParticipant(StudentNode* student);
        BaseEvent* clone() override;

    };

}


#endif //COSTOM_EVENT_H