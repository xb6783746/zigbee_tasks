
all:
	mkdir -p ./build
	cd ./build && cmake .. -DCMAKE_TOOLCHAIN_FILE=../stm32f4.cmake

