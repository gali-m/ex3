#include <iostream>
#include "base_event.h"
#include "closed_event.h"
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"


namespace mtm {
    
    ClosedEvent::ClosedEvent(const DateWrap date, const std::string name) : BaseEvent(date, name), guest_list(nullptr) {}

    ClosedEvent::ClosedEvent(const ClosedEvent& closed_event) : BaseEvent(closed_event)
    {
        this->guest_list = copyStudentsList(closed_event.guest_list);
    }

    ClosedEvent::~ClosedEvent()
    {
        StudentNode* current = this->guest_list;
        StudentNode* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void ClosedEvent::addInvitee(int student_id)
    {
        isValidStudent(student_id);

        bool is_student_in_list_return = isStudentInList(this->guest_list, student_id);
        if (is_student_in_list_return)
        {
            throw AlreadyInvited();
        }

        if(this->guest_list == nullptr)
        { // if list is empty
            this->guest_list = new StudentNode(student_id, nullptr);
        }
        else if(this->guest_list->student_id > student_id)
        { // the first student is bigger
            this->guest_list = new StudentNode(student_id, this->guest_list);
        }
        else
        {
            addToStudentsList(this->guest_list, student_id);
        }
    }

    void ClosedEvent::registerParticipant(int student_id)
    {
        isValidStudent(student_id);

        bool is_student_in_list_return = isStudentInList(this->students_list, student_id);
        if (is_student_in_list_return)
        {
            throw AlreadyRegistered();
        }

        bool is_student_in_guest_list_return = isStudentInList(this->guest_list, student_id);
        if (is_student_in_guest_list_return == false)
        {
            throw RegistrationBlocked();
        }

        
        if(this->students_list == nullptr)
        { // if list is empty
            this->students_list = new StudentNode(student_id, nullptr);
        }
        else if(this->students_list->student_id > student_id)
        { // the first student is bigger
            this->students_list = new StudentNode(student_id, this->students_list);
        }
        else
        {
            addToStudentsList(this->students_list, student_id);
        }
    }

    ClosedEvent* ClosedEvent::clone() const
    {
        return new ClosedEvent(*this);
    }

}