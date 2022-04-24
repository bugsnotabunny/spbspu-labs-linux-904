cmd_/home/banan/labs/linux-labs/L7/ex1/modules.order := {   echo /home/banan/labs/linux-labs/L7/ex1/hello-1.ko; :; } | awk '!x[$$0]++' - > /home/banan/labs/linux-labs/L7/ex1/modules.order
