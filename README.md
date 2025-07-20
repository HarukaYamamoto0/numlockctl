# numlockctl

> A simple command line utility to enable or disable the **NumLock** key in the Linux graphical environment (X11).

## 🔧 What is it?

`numlockctl` is a minimalist tool written in C that allows you to functionally enable or disable NumLock (not just by turning on the LED) directly in the graphical environment, without external dependencies other than the standard X11 libraries.

## 🧩 Features

- ✅ Enables or disables NumLock with `true` or `false`
- ✅ Compatible with any X11-based graphical session (Cinnamon, Xfce, MATE, etc.)
- ✅ Can be used in session scripts to keep NumLock always enabled
- ✅ Lightweight and has no extra dependencies other than X11
- ✅ Available as a `.deb` package for easy installation

## 💻 How to use

```bash
numlockctl true  # Enables NumLock
numlockctl false # Disables NumLock
```

## 📦 Installation via `.deb`

If you already have the `.deb` package compiled:

```bash
sudo apt install ./numlockctl_1.0.0.deb
```

## 🔄 Make NumLock automatic on login

Add this command to your session file (e.g. `~/.xsessionrc` or `~/.profile`):

```bash
numlockctl true
```

## 🛠️ Manual compilation

### Prerequisites

Install the X11 development headers:

```bash
sudo apt install build-essential libx11-dev libxtst-dev
```

### Compilation

```bash
make deb
```

## 🧪 Tested on

- Linux Mint 22.1 Cinnamon

## 📄 License

This project is licensed under the **MIT License**. See the [LICENSE](./LICENSE) file for more details.
