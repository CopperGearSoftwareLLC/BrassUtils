#pragma once
#include <mutex>
#include <memory>

template <typename Type>
class Singleton
{
private:
    static inline std::mutex GetMutex;
    static inline std::unique_ptr<Type> Instance;

public:
    Singleton() = delete;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    template <typename... Args>
    static Type& Make(Args&&... args)
    {
        static_assert(
            std::is_constructible_v<Type, Args...>,
            "Type is not constructible with the given arguments"
        );

        std::lock_guard lock(GetMutex);
        ASSERT(!Instance, "Singleton already exists");

        Instance = std::make_unique<Type>(std::forward<Args>(args)...);
        return *Instance;
    }

    [[nodiscard]] static Type& Get()
    {
        std::lock_guard lock(GetMutex);
        ASSERT(Instance, "Singleton not created yet");
        return *Instance;
    }

    static bool Exists()
    {
        std::lock_guard lock(GetMutex);
        return static_cast<bool>(Instance);
    }

    static void Destroy()
    {
        std::lock_guard lock(GetMutex);
        Instance.reset();
    }
};
