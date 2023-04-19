#pragma Once
#include "Semaphore.h"
#include <vector>
#include "Event.h"
class SafeBuffer{
private:
	std::vector<Event> buffer;
	std::shared_ptr<Semaphore> mutex1;
	std::shared_ptr<Semaphore> spaces;
	std::shared_ptr<Semaphore> items;
public:
	SafeBuffer();
	int put(Event);
	Event get();
};
