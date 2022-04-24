cmd_/home/banan/lab6/ex6/Module.symvers := sed 's/ko$$/o/' /home/banan/lab6/ex6/modules.order | scripts/mod/modpost -m -a -E  -o /home/banan/lab6/ex6/Module.symvers -e -i Module.symvers   -T -
