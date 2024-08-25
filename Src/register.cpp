/*
 * register.cpp
 *
 *  Created on: Aug 20, 2024
 *      Author: Valerii_Pavlov
 */

#include "register.h"

template <std::size_t sz>
class Register {
public:
	using reg_type = typename Register_traits<sz>::internal_type;
	explicit Register(std::uint32_t addr);

	Register& operator=(reg_type bit_mask);
	inline Register& operator|=(reg_type bit_mask){
		*raw_ptr |= bit_mask;
		return *this;
	}
	inline Register& operator&=(reg_type bit_mask){
		*raw_ptr &= bit_mask;
		return *this;
	}
	inline Register& operator^=(reg_type bit_mask){
		*raw_ptr ^= bit_mask;
		return *this;
	}
private:
	volatile reg_type* raw_ptr;
};


