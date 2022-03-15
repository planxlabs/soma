# 1. WSL & Ubuntu 20.04
-  **run cmd as administrator**
```sh
> wsl --list --online
> wsl --install -d Ubuntu-20.04
```

- Ubuntu 20.04 install (**one of the two below**)
- [x] *reboot system and Ubuntu install*
- [ ] *continue Ubuntu install*

- Show new window(Ubuntu-20.04) and create a user account
```SH
> id: <user_id>
> passwd: <user_passwd>
> repasswd: <user_passwd>
```

# 2. Ubuntu 20.04 Settings
- system update
```sh
sudo apt update
sudo apt upgrade
```

- openssh-server reinstall
```sh
sudo apt purge openssh-server
sudo apt install openssh-server
sudo service ssh start
sudo ss -autoSnp
```
- net-tools install
```sh
sudo apt install net-tools
```

- gcc & gdb install
```
sudo apt install gcc gdb
```

# 3. Install VS Code in portable mode
- https://code.visualstudio.com/
> download .zip 64bit

- Unzip it in the Downloads folder
- Change the unzipped folder name
- Create a subfolder with the name **data**
- Move the renamed folder to C:\

# 4. Install 'remote-ssh' extension
- Run vscode > Select the extension tab > remote-ssh > Install

# 5. Ubuntu-20.04 remote connection
- check ubuntu ip
```sh
> ifconfig
```
