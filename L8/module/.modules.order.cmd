cmd_/home/banan/labs/linux-labs/L8/module/modules.order := {   echo /home/banan/labs/linux-labs/L8/module/chardev.ko; :; } | awk '!x[$$0]++' - > /home/banan/labs/linux-labs/L8/module/modules.order
