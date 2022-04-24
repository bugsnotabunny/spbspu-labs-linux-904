cmd_/home/banan/labs/linux-labs/L7/ex5/modules.order := {   echo /home/banan/labs/linux-labs/L7/ex5/hello-3.ko; :; } | awk '!x[$$0]++' - > /home/banan/labs/linux-labs/L7/ex5/modules.order
