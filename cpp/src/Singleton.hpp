#pragma once
#include <mutex>
#include <memory>
template <typename Type>
class Singleton
{
private:
    static inline std::mutex Mutex;
    static inline std::unique_ptr<Type> Instance;

protected:
    Singleton() = default;

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Default Get (only works if default-constructible)
    [[nodiscard]] static Type& Get()
    {
        static_assert(
            std::is_default_constructible_v<Type>,
            "Type is not default-constructible. Call Get(args...) instead."
        );

        std::lock_guard lock(Mutex);
        if (!Instance)
        {
            Instance = std::make_unique<Type>();
        }
        return *Instance;
    }

    // Argument-inferred Get
    template <typename... Args>
    [[nodiscard]] static Type& Get(Args&&... args)
    {
        static_assert(
            std::is_constructible_v<Type, Args...>,
            "Type is not constructible with the given arguments"
        );

        std::lock_guard lock(Mutex);
        if (!Instance)
        {
            Instance = std::make_unique<Type>(std::forward<Args>(args)...);
        }
        return *Instance;
    }

    static bool Exists()
    {
        std::lock_guard lock(Mutex);
        return static_cast<bool>(Instance);
    }
};
