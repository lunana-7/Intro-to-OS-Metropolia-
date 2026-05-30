# Introduction to Operating Systems

Updated on 11.11.2024

## System Setup With Docker

### 1. Install Docker Desktop

Install Docker Desktop from [https://www.docker.com/](https://www.docker.com/).

### 2. Start the Alpine Container

Open PowerShell with Administrator rights and run:

```powershell
docker pull alpine
docker run -it --name alpine-gcc alpine
```

You are now inside an Alpine Linux container named `alpine-gcc`.

### 3. Install Basic Tools and Create a User

Run the following commands inside the Alpine container:

```sh
apk update
apk add nano
apk add sudo
adduser Jeffrey
passwd Jeffrey
addgroup Jeffrey wheel
```

When prompted for the password, enter:

```text
Pa55w.rd
Pa55w.rd
```

If you get an error that the `wheel` group does not exist, run:

```sh
apk add shadow
groupadd wheel
usermod -aG wheel Jeffrey
```

### 4. Enable `sudo` for the `wheel` Group

Open the `sudoers` file:

```sh
nano /etc/sudoers
```

Add this line:

```text
%wheel ALL=(ALL) ALL
```

Then save and exit:

```text
Ctrl+O, Enter, Ctrl+X
```

### 5. Log In as `Jeffrey`

```sh
login Jeffrey
```

Then install the compiler tools:

```sh
sudo apk update
sudo apk add musl-dev gcc
```

### 6. Customize the Shell Prompt

Open the profile:

```sh
nano ~/.profile
```

Add:

```sh
PS1='Jeffrey@alpine-linux: \w\$ '
```

Save and exit:

```text
Ctrl+O, Enter, Ctrl+X
```

Apply the change:

```sh
source ~/.profile
```

### 7. Create the First C Program

Create the working directories:

```sh
mkdir operating_systems
cd operating_systems
mkdir lesson_1
cd lesson_1
```

Create the source file:

```sh
nano hello_world.c
```

Paste this code into the file:

```c
#include <stdio.h>

int main(void) {
    printf("Hello world!\n");
    return 0;
}
```

Save and exit:

```text
Ctrl+O, Enter, Ctrl+X
```

Compile the program:

```sh
gcc hello_world.c -o hello_world
```

Run it:

```sh
./hello_world
```

If you see:

```text
Hello world!
```

then the compiler is working correctly.

## Reconnect to the Existing Container

Later, to attach to the same container again, open PowerShell with Administrator rights and run:

```powershell
docker start alpine-gcc
docker attach alpine-gcc
```

## Notes

- The original sample `hello_world.c` was cleaned up to remove an unused variable and add `return 0;`.
- In `nano`, `Ctrl+O` saves the file and `Ctrl+X` exits the editor.
