#include "memory.h"
#include <cstdint>

class ExtInterrupt {
public:
	explicit ExtInterrupt();
	enum Line {
		Line00, Line01, Line02, Line03, Line04, 
		Line05, Line06, Line07, Line08, Line09, 
		Line10, Line11, Line12, Line13, Line14, 
		Line15, Line16, Line17, Line18, Line19, 
		Line20, Line21, Line22
	};
	
	ExtInterrupt& set_falling_trigger(ExtInterrupt::Line line);
	ExtInterrupt& set_rising_trigger(ExtInterrupt::Line line);

	ExtInterrupt& clear_falling_trigger(ExtInterrupt::Line line);
	ExtInterrupt& clear_rising_trigger(ExtInterrupt::Line line);

	ExtInterrupt& enable(ExtInterrupt::Line line);
	ExtInterrupt& disable(ExtInterrupt::Line line);
	ExtInterrupt& clear_pending(ExtInterrupt::Line line);
private:
	struct Registers {
		std::uint32_t imr;
		std::uint32_t emr;
		std::uint32_t rtsr;
		std::uint32_t ftsr;
		std::uint32_t swier;
		std::uint32_t pr;
	};
	
	volatile Registers* const registers;
};
