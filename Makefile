all: cmake
	@cd build && ninja

cmake:
	@cmake -B build -G Ninja