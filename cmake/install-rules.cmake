install(
    TARGETS noditto_elf
    RUNTIME COMPONENT noditto_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
