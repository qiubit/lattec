all:
	rm -rf bin build latc_llvm latc
	mkdir build && cd build && cmake .. && make && cd ..
	cp latc_llvm latc

clean:
	rm -rf bin build latc_llvm latc
