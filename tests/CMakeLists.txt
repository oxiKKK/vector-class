set(SOURCES
	main.cc
)

# create the target
add_executable(vector-class-tests ${SOURCES})

target_link_libraries(vector-class-tests PRIVATE
	vector-class
)