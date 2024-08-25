/*
 * register.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Valerii_Pavlov
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#include <cstdint>

template<uint32_t sz>
struct Register_traits{};

template<>
struct Register_traits<8> {using internal_type = std::uint8_t;};

template<>
struct Register_traits<16> {using internal_type = std::uint16_t;};

template<>
struct Register_traits<32> {using internal_type = std::uint32_t;};

template<>
struct Register_traits<64> {using internal_type = std::uint64_t;};



#endif /* REGISTER_H_ */
