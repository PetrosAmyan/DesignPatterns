#include "Filesystem.h"

FileSystemItem::FileSystemItem(const string& name)
    : name(name)
{}


File::File(const string& name)
    : FileSystemItem(name)
{}

void File::print(int indent) const {

    cout << string(indent, ' ') << "File is `  " << name         << '\n';
}


Folder::Folder(const string& name)
    : FileSystemItem(name)
{}

void Folder::add(unique_ptr<FileSystemItem> item) {
    children.push_back(move(item));
}

void Folder::print(int indent) const {

    cout << string(indent, ' ') << "Folder name is" << name         << '\n';

    for (const auto& child : children) {
        child->print(indent + 2);
    }
}

int main() {

    auto root = make_unique<Folder>("Root of system");

    root->add(make_unique<File>("file.txt"));

    root->add(
        make_unique<File>("image.png")
    );


    auto documents = make_unique<Folder>("Documents");

    documents->add(make_unique<File>("cv.pdf"));

    documents->add(make_unique<File>("homework.cpp"));


    auto projects = make_unique<Folder>("Projects");

    projects->add(
        make_unique<File>("main.cpp")
    );

    projects->add(
        make_unique<File>("test.cpp")
    );


    documents->add(move(projects));

    root->add(move(documents));


    root->print();

    return 0;
}