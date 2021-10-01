# reown
This is basically a C utility to run `chown root:root [file]`, however since it is a system executable it can be given the setuid bit. Therefore if you execute `sudo chmod +s reown` it will allow you to execute as root, and change the ownership of pretty much any file or directory back to root.

I used this to repair a system where a user with super-user privileges had accidentally `chown`ed /usr/ and `sudo` was no longer owner by root, which meant no one on the system could become a super user.

Using this setuid trick I was able to exploit NFS permissions on a shared mount with this system from a different system whose sudo was still intact. I compiled the execute, placed the setuid bit as root, and copied the executable to the NFS mount. The broken system saw the file with the intended permissions (owned by root), and then I could run `./reown /usr/bin/sudo` to successfully change ownership of sudo back to root:root without needing sudo itself to do so.

# install
```
make && make install
sudo chown -R root:root ./bin/reown
sudo chmod +s ./bin/reown
```

After these commands `reown` will be armed to set ownership of any file to root.