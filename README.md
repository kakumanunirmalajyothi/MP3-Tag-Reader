# 🎵 MP3 Tag Reader

A console-based **MP3 Tag Reader** developed in **C programming** that reads and displays metadata stored in MP3 files using the **ID3v2** tag format. 
This project demonstrates file handling, binary file processing, string manipulation, and modular programming concepts in C.

---

## 📌 Project Overview

MP3 files contain metadata such as song title, artist, album, genre, and year. 
This application extracts and displays that information by reading the ID3v2 tags stored in the MP3 file.

---

## ✨ Features

- 🎵 Read MP3 metadata
- 👤 Display Artist Name
- 🎶 Display Song Title
- 💿 Display Album Name
- 📅 Display Year
- 🎼 Display Genre
- 📝 Display Comments
- ✏️ Edit MP3 tag information
- 💾 Save updated metadata back to the MP3 file
- ✔️ Validate MP3 file format

---

## 🛠️ Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Platform:** Linux (Ubuntu/WSL)
- **Concepts Used:**
  - File Handling
  - Binary File Processing
  - Structures
  - Command Line Arguments
  - String Handling
  - Modular Programming

---

## 📂 Project Structure

```
MP3-Tag-Reader/
│── main.c
│── read.c
│── edit.c
│── mp3.h
│── README.md
│── sample.mp3
```

---

## 📖 Metadata Fields

The program can read and edit the following ID3 tags:

- Title
- Artist
- Album
- Year
- Genre
- Comment

---

## ▶️ Compilation

```bash
gcc *.c -o mp3tag
```

---

## ▶️ Execution

### View MP3 Tags

```bash
./mp3tag -v sample.mp3
```

### Edit MP3 Tags

```bash
./mp3tag -e -t "New Song" sample.mp3
```

---

## 📷 Sample Output

```
-----------------------------
MP3 TAG INFORMATION
-----------------------------
Title   : Shape of You
Artist  : Ed Sheeran
Album   : Divide
Year    : 2017
Genre   : Pop
Comment : Sample MP3 File
-----------------------------
```

---

## 💡 Concepts Covered

- File Handling
- Binary File Operations
- Structures
- Command Line Arguments
- Memory Management
- String Manipulation
- Modular Programming

---

## 🚀 Future Enhancements

- Support ID3v1 and ID3v2.4 tags
- Display Album Artwork
- Batch Edit Multiple MP3 Files
- Unicode Character Support
- Playlist Generation
- Graphical User Interface (GUI)

---

## 🎯 Learning Outcomes

This project helped strengthen my understanding of:

- Binary file processing
- MP3 metadata structure
- File pointers
- Command-line applications
- Modular software design
- Data manipulation in C

---

## 👩‍💻 Author

**Nirmala Jyothi**

- GitHub: https://github.com/kakumanunirmalajyothi
- LinkedIn: www.linkedin.com/in/nirmalajyothi

---

## 📜 License

This project is developed for educational and learning purposes.
