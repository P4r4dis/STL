#include "../test_include/test_EventManager.hpp"
#include "../test_include/test_Event.hpp"

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// static std::list<Event> createTodoList ()
// {
//     std::list<Event> todo;
//     todo.push_front(Event(19, "The vengeance of the Koala"));
//     todo.push_front(Event(20, "The return of the vengeance of the Koala"));
//     todo.push_front(Event(21, "The come back of the vengeance of the Koala"));
//     todo.push_front(Event(22, "The sequel to the vengeance."));
//     todo.push_front(Event(9, "What the hell do you mean 'this morning' ?!"));
//     todo.push_front(Event(1, "No, no, you're pushing it now ..."));
    
//     return todo;
// }

// static populateEvents(EventManager &em)
// {
//     em.addEvent(Event(10, "Eat"));
//     em.addEvent(Event(12, "Finish the exercises"));
//     em.addEvent(Event(12, "Understand the thing"));
//     em.addEvent(Event(15, "Set the rights"));
//     em.addEvent(Event(8, "Ask what the hell a const_iterator is"));
//     em.addEvent(Event(11, "Wash my hands so that my keyboard doesn't smell like kebab"));
// }

Test(test, test)
{
    cr_assert(1 == 1);
}

// Test(Main, test_main)//, .init = redirect_all_stdout)
// {
//     EventManagerem      em;

//     populateEvents(em);
//     em.dumpEvents();
//     std::cout << "=====" << std::endl;

//     // Following a massive rotten leaves of eucalyptus ingestion , all the exercises of the day are canceled .
//     em.removeEventsAt(12);
//     em.dumpEvents();
//     std::cout << "=====" << std::endl;

//     // Hey , the time is flying !
//     em.addTime(10);
//     std::cout << "=====" << std::endl;
//     em.dumpEvents();
//     std::cout << "=====" << std::endl;

//     // Following the aforementioned ingestion and to help you improve your skill level , an exercises serie will be added .
//     em.addEventList(createTodoList());
//     em.dumpEvents();
//     std::cout << "=====" << std::endl;

//     // I forgot something , but what ??
//     em.dumpEventAt(15);
//     std::cout << "=====" << std::endl;
    
//     // And we finish the day with joy and good humour .
//     em.addTime(14);
// }
