# build example, tested in linux 10.0.0-3, gcc 12, wine-9.0
# make libwinpe libwinpe_test CC=i686-w64-mingw32-gcc BUILD_TYPE=32d
# make libwinpe libwinpe_test CC=x86_64-w64-mingw32-gcc BUILD_TYPE=64d
# wine build/libwinpe_test32d.exe
# wine build/libwinpe_test64d.exe

# general config
CC:=gcc # clang (llvm-mingw), gcc (mingw-w64), tcc (x86 stdcall name has problem)
BUILD_TYPE:=32# 32, 32d, 64, 64d
BUILD_DIR:=build
INCS:=-I../../src
LIBS:=-luser32 -lgdi32 -lpsapi
CFLAGS:=-fPIC -std=gnu99 \
	-fvisibility=hidden \
	-ffunction-sections -fdata-sections
LDFLAGS:=-Wl,--enable-stdcall-fixup \
		 -Wl,--kill-at \
		 -Wl,--gc-sections \
		 -D_WIN32_WINNT=0X0400 \
		 -Wl,--subsystem,console:4.0 # compatible for xp

# build config
ifneq (,$(findstring 64, $(BUILD_TYPE)))
CFLAGS+=-m64
else
CFLAGS+=-m32
endif
ifneq (,$(findstring d, $(BUILD_TYPE)))
CFLAGS+=-g -D_DEBUG
else
CFLAGS+=-O3 # winpe_memGetProcAddress might fail if use inline and -O3 by llvm-clang
endif
ifneq (,$(findstring tcc, $(CC)))
LDFLAGS= # tcc can not remove at at stdcall in i686
else
endif

all: prepare libwinpe libwinpe_test

clean:
	@rm -rf $(BUILD_DIR)/*libwinpe*

prepare:
	@mkdir -p $(BUILD_DIR)

libwinpe: src/libwinpe.c
	@echo "## $@"
	$(CC) -shared $< -o $(BUILD_DIR)/$@$(BUILD_TYPE).dll \
		$(INCS) $(LIBS) \
		$(CFLAGS) $(LDFLAGS)

# can not use tcc here
libwinpe_test: src/libwinpe_test.c
	@echo "## $@"
	$(CC) $< -o $(BUILD_DIR)/$@$(BUILD_TYPE).exe \
		-L$(BUILD_DIR) -lwinpe$(BUILD_TYPE) -DWINPE_NOINLINE \
		$(INCS) $(LIBS) \
		$(CFLAGS) $(LDFLAGS)

.PHONY: all clean prepare libwinpe libwinpe_test