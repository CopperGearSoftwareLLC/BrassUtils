include(FetchContent)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 0.9.9.8  # you can change this to a newer release if needed
)
FetchContent_MakeAvailable(glm)