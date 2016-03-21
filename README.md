# sifilis-PoC


PoC para bypassear open_basedir y disable_functions basado en https://bugs.php.net/bug.php?id=46741

gcc -c -fPIC hook.c -o hook
gcc -shared hook -o hook.so


