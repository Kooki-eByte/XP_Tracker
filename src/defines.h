/**
 * @file defines.h
 * @author Cristian Hornedo
 * @brief This file contains global type definitions which are used
 * throughout the entire engine and applications referencing it.
 * Numeric types are asserted statically to gurantee expected size.
 * @version 1.0
 * @date 01/19/2025
 *
 * @copyright Eureka Game Engine is Copyright (c) Cristian Hornedo 2025-CURRENT
 *
 */

#pragma once

// Unsigned int types.

/** @brief Unsigned 8-bit integer */
typedef unsigned char u8;

/** @brief Unsigned 16-bit integer */
typedef unsigned short u16;

/** @brief Unsigned 32-bit integer */
typedef unsigned int u32;

/** @brief Unsigned 64-bit integer */
typedef unsigned long long u64;

// Signed int types.

/** @brief Signed 8-bit integer */
typedef signed char i8;

/** @brief Signed 16-bit integer */
typedef signed short i16;

/** @brief Signed 32-bit integer */
typedef signed int i32;

/** @brief Signed 64-bit integer */
typedef signed long long i64;

// Floating point types

/** @brief 32-bit floating point number */
typedef float f32;

/** @brief 64-bit floating point number */
typedef double f64;

/** @brief 32-bit boolean type, used for APIs which require it */
typedef int b32;

// Properly define static assertions.
#if defined(__clang__) || defined(__GNUC__)
/** @brief Static assertion */
#define STATIC_ASSERT(cond, msg) typedef char static_assertion_##msg[(cond) ? 1 : -1]
#else

/** @brief Static assertion */
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size.

/** @brief Assert u8 to be 1 byte.*/
STATIC_ASSERT(sizeof(u8) == 1, u8_must_be_1_byte);

/** @brief Assert u16 to be 2 bytes.*/
STATIC_ASSERT(sizeof(u16) == 2, u16_to_be_2_bytes);

/** @brief Assert u32 to be 4 bytes.*/
STATIC_ASSERT(sizeof(u32) == 4, u32_to_be_4_bytes);

/** @brief Assert u64 to be 8 bytes.*/
STATIC_ASSERT(sizeof(u64) == 8, u64_to_be_8_bytes);

/** @brief Assert i8 to be 1 byte.*/
STATIC_ASSERT(sizeof(i8) == 1, i8_to_be_1_byte);

/** @brief Assert i16 to be 2 bytes.*/
STATIC_ASSERT(sizeof(i16) == 2, i16_to_be_2_bytes);

/** @brief Assert i32 to be 4 bytes.*/
STATIC_ASSERT(sizeof(i32) == 4, i32_to_be_4_bytes);

/** @brief Assert i64 to be 8 bytes.*/
STATIC_ASSERT(sizeof(i64) == 8, i64_to_be_8_bytes);

/** @brief Assert f32 to be 4 bytes.*/
STATIC_ASSERT(sizeof(f32) == 4, f32_to_be_4_bytes);

/** @brief Assert f64 to be 8 bytes.*/
STATIC_ASSERT(sizeof(f64) == 8, f64_to_be_8_bytes);

/** @brief Gets the number of bytes from amount of gibibytes (GiB) (1024*1024*1024) */
#define GIBIBYTES(amount) ((amount) * 1024ULL * 1024ULL * 1024ULL)
/** @brief Gets the number of bytes from amount of mebibytes (MiB) (1024*1024) */
#define MEBIBYTES(amount) ((amount) * 1024ULL * 1024ULL)
/** @brief Gets the number of bytes from amount of kibibytes (KiB) (1024) */
#define KIBIBYTES(amount) ((amount) * 1024ULL)

/** @brief Gets the number of bytes from amount of gigabytes (GB) (1000*1000*1000) */
#define GIGABYTES(amount) ((amount) * 1000ULL * 1000ULL * 1000ULL)
/** @brief Gets the number of bytes from amount of megabytes (MB) (1000*1000) */
#define MEGABYTES(amount) ((amount) * 1000ULL * 1000ULL)
/** @brief Gets the number of bytes from amount of kilobytes (KB) (1000) */
#define KILOBYTES(amount) ((amount) * 1000ULL)