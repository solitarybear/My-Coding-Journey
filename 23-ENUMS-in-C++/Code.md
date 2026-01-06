# 1
>main.cpp
#include <iostream>

int main()
{
    std::cin.get();
}
# 2
>main.cpp
#include <iostream>

int A=0;
int B=1;
int C=2;

int main()
{
    int value = B;

    if 
     (value == B)
     {
        // Do something here
     }
    std::cin.get();
}

# 3
>main.cpp
#include <iostream>

enum Example
{
    A, B, C                           

};

int main()
{
    Example value = A;

    if 
     (value == B) // at the end of the day A, B, C  are integer so instead this we can also write (value == 1)
     {
        // Do something here
     }
    std::cin.get();
}


# 4 
>main.cpp
#include <iostream>

enum Example : unsigned char  //here is specify which type of integer you want this enum to be
{
    A=6, B=1, C               // we also assign intergers to these variables as well            

};

int main()
{
    Example value = A;

    if 
     (value == B) // at the end of the day A, B, C  are integer so instead this we can also write (value == 1)
     {
        // Do something here
     }
    std::cin.get();
}

# 5 
>main.cpp
#include <iostream>

enum Example :  char  //here is specify which type of integer you want this enum to be
{
    A=6, B=1, C               // we also assign intergers to these variables as well            

};

int main()
{
    Example value = A;

    if 
     (value == B) // at the end of the day A, B, C  are integer so instead this we can also write (value == 1)
     {
        // Do something here
     }
    std::cin.get();
}

# 1 Log.cpp
>log.cpp
#include <iostream>

class Log
{
public: 
        const int LogLevelError = 0;
        const int LogLevelWarning = 1;
        const int LogLevelInfo    = 2;
private:
        int m_LogLevel = LogLevelInfo;                             //this m_ will tells us that m_LogLevel is class member variable ,that is private.
public:                                             //public methods
        void SetLevel(int level)
        {
            m_LogLevel = level;

        }

       void Error(const char* message)
       {
        if (m_LogLevel >= LogLevelError)
        std::cout<< "[ERROR]: " <<message << std::endl;
       }

       void Warn(const char* message)
       {
        if (m_LogLevel >= LogLevelWarning)
        std::cout<< "[WARNING] :"<< message << std::endl;
       }

       void Info(const char* message)
       {
        if (m_LogLevel >= LogLevelInfo)
        std::cout<< "[INFO] : " << message << std::endl;
       }

};

int main()
{
    Log log;
    log.SetLevel(log.LogLevelError);
    log.Warn("SolitaryBear");
    log.Error("TheCherno");
    log.Info("CodeIsRunning");
    std::cin.get();
}

# 2 
>log.cpp
instead of having an int as my log level, which I could still have, of course, I could still assign this to info. And since an enum is just an int, this would still work. However, in this case, I would be able to set any value to log level, any integer value to log level. And I want to restrict it to just being these three. So, I will actually set this to be level.

#include <iostream>

class Log
{
public: 

        enum Level
        {
          LevelError = 0, LevelWarning, LevelInfo
        };     
private:
        Level m_LogLevel = LevelInfo;                             //this m_ will tells us that m_LogLevel is class member variable ,that is private.
public:                                             //public methods
        void SetLevel(Level level)
        {
            m_LogLevel = level;

        }

       void Error(const char* message)
       {
        if (m_LogLevel >= LevelError)
        std::cout<< "[ERROR]: " <<message << std::endl;
       }

       void Warn(const char* message)
       {
        if (m_LogLevel >= LevelWarning)
        std::cout<< "[WARNING] :"<< message << std::endl;
       }

       void Info(const char* message)
       {
        if (m_LogLevel >= LevelInfo)
        std::cout<< "[INFO] : " << message << std::endl;
       }

};

int main()
{
    Log log;
    log.SetLevel(Log::LevelError);
    log.Warn("SolitaryBear");
    log.Error("TheCherno");
    log.Info("CodeIsRunning");
    std::cin.get();
}


