#include <exception>

class A
{
public:
    A()
    {
        throw(std::exception("It's too cold!"));
    }
};

class B
{
public:
    bool Do()
    {
        try
        {
            A a;
            return true;
        }
        catch (const std::exception&)
        {
            return false;
        }
    }
};

class Log
{
public:
    void Notify(const char* msg)
    {
        message = msg;
    }

private:
    const char* message;
};

class C
{
public:
    C()
    {
        B b;
        if (!b.Do())
            reinterpret_cast<Log*>(1)->Notify("I don't know what happened!");   // Simulating tracer lifetime error
    }
};

int main()
{
    C c;
    return 0;
}

