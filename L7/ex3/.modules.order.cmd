cmd_/home/banan/labs/linux-labs/L7/ex3/modules.order := {   echo /home/banan/labs/linux-labs/L7/ex3/hello-1.ko;   echo /home/banan/labs/linux-labs/L7/ex3/hello-2.ko; :; } | awk '!x[$$0]++' - > /home/banan/labs/linux-labs/L7/ex3/modules.order
