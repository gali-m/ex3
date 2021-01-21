// #include "one_time_event.h"

// namespace mtm
// {
//     template <class EventType>
//     OneTimeEvent<EventType>::OneTimeEvent(DateWrap event_date, std::string event_name)
//     {
//         DateWrap date = DateWrap(event_date);
//         std::string name = event_name;
//         BaseEvent* event = new EventType(date, name);

//         event_node* node = new event_node();
//         node->event = event;
//         node->next = this->event_list;

//         this->event_list = node;
//     }

//     template <class EventType>
//     void OneTimeEvent<EventType>::add(const BaseEvent& event)
//     {
//         throw NotSupported();
//     }
// }