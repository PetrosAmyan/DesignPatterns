#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;


class FileSystemItem {
protected:
    string name;

public:
    FileSystemItem(const string& name);

    virtual void print(int indent = 0) const = 0;

    virtual ~FileSystemItem() = default;
};


class File : public FileSystemItem {
public:
    File(const string& name);

    void print(int indent = 0) const override;
};


class Folder : public FileSystemItem {
private:
    vector<unique_ptr<FileSystemItem>> children;

public:
    Folder(const string& name);

    void add(unique_ptr<FileSystemItem> item);

    void print(int indent = 0) const override;
};

#endif