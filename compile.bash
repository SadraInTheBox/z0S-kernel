rm -rf output/*

nasm -f elf32 ./src/kernel.asm -o ./output/kasm.o
gcc -m32 -I./include -c ./src/kernel.c -o ./output/kc.o
ld -m elf_i386 -T ./src/link.ld -o ./output/kernel ./output/kasm.o ./output/kc.o

clear

echo completed successfully