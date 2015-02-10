#ifndef _TIMER_H_
#define _TIMER_H_
/**
 * \file Timer.h
 * \brief A timer class that provides a cross platform timer for use
 * in timing code progress with a high degree of accuracy.
 */
#ifdef _WIN32
/**
 * \typedef __int64 i64
 * \brief Maps the windows 64 bit integer to a uniform name
 */
typedef __int64 i64 ;
#else
/**
 * \typedef long long i64
 * \brief Maps the linux 64 bit integer to a uniform name
 */
typedef long long i64;
#endif

typedef struct CPerfCounterRec
{
    i64 _freq;
    i64 _clocks;
    i64 _start;
} CPerfCounter;

void Setup(int);

/**
 * \brief Start the timer
 * \sa Stop(), Reset(), Setup()
 */
void Start(int);

/**
 * \brief Stop the timer
 * \sa Start(), Reset(), Setup()
 */
void Stop(int);

/**
 * \brief Reset the timer to 0
 * \sa Start(), Stop(), Setup()
 */
void Reset(int);

/**
 * \return Amount of time that has accumulated between the \a Start()
 * and \a Stop() function calls
 */
double GetElapsedTime(int);

/**
 * Print the amount of time elapsed
 */

void PrintTime(int);


#endif // _TIMER_H_

