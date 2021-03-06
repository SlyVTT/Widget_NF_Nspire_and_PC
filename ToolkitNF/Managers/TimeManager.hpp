#ifndef TIMEMANAGER_HPP
#define TIMEMANAGER_HPP

#if TARGET_NSPIRE == 1
    #include <os.h>
#else
    #include <stdint.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <errno.h>
    #include <math.h>
#endif


class TimeManager
{
    public:

    TimeManager(TimeManager&) = delete;
	TimeManager& operator= (const TimeManager&) = delete;

	static TimeManager& Get( void );

    static void Delay( uint32_t ms ) {Get().InternalDelay( ms ); };
    static void StartTicks( void ) { Get().InternalStartTicks( ); };
    static uint32_t GetTicks( void ) { return Get().InternalGetTicks( ); };

    static void Initialize( void ) { Get().InternalInitialize(); };
    static void Close( void ) { Get().InternalClose(); };

    protected:

    private:

        TimeManager();
        static TimeManager m_timer;

        void InternalDelay( uint32_t ms );
        void InternalStartTicks( void );
        uint32_t InternalGetTicks( void );

        void InternalInitialize( void );
        void InternalClose( void );

//        static volatile unsigned *value;
//        static volatile unsigned *control;

        uint32_t tick_sum;
        uint32_t start;
};

#endif // TIMEMANAGER_HPP
