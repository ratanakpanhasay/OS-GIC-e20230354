# Operating Systems Lab 1 Report

## 1. Kernel and Linux Distribution

The Linux kernel is the core of the operating system. It manages hardware resources, memory, processes, and communication between software and hardware.

A Linux distribution includes the Linux kernel and additional software, system utilities, and applications.

From my experiment, the kernel version was `7.0.0-38-generic`, and the distribution was Ubuntu `26.04.1 LTS`, with the codename `resolute`.

The `uname -a` command displays kernel information, while `lsb_release -a` displays information about the Linux distribution.

## 2. Difference Between apt-get remove and apt-get purge

In Task 3, I installed Midnight Commander (`mc`) and examined its configuration directory, `/etc/mc`.

The command `sudo apt-get remove mc -y` uninstalled the program but kept its configuration directory. My experiment confirmed that `/etc/mc` still existed after removal.

The command `sudo apt-get purge mc -y` uninstalled the package and removed its configuration files. After purging, the command `ls -ld /etc/mc` reported that the directory did not exist.

Therefore, `remove` uninstalls the package while retaining its configuration files, whereas `purge` also removes the package's configuration files.

## 3. Difference Between a Program and a Process

A program is a set of instructions stored in a file. A process is an instance of a program that is being executed.

For example, a program can exist on disk without running. When the operating system executes that program, it creates a process. Multiple instances of the same program can run as separate processes.

The `ps` command displays information about running processes. This helps us observe which programs are currently executing.

Therefore, a program is the stored instructions, while a process is a running instance of those instructions.

## 4. Virtual Machines and Virtualization

Virtualization allows an operating system to run in a virtualized environment rather than directly controlling the physical hardware.

A virtual machine (VM) behaves like a computer with virtual hardware, including virtual processors, memory, and storage. A hypervisor manages the virtual machines and their access to physical resources.

In Task 6, the `systemd-detect-virt` command returned `kvm`, and the hypervisor vendor reported `KVM`. These results indicate that the environment I examined was running inside a KVM virtual machine.

The `lscpu` command provides processor information, while `uname -r` displays the kernel release and `hostname` displays the system's hostname.

Virtualization allows multiple isolated computing environments to share the resources of one physical machine.
