#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

enum FileType
{
  FOLDER_TYPE,
  FILE_TYPE
};

class NTree
{
  std::string name;
  FileType type;
  NTree *parent;
  std::vector<NTree> children;

public:
  NTree(std::string &name, FileType type, NTree *parent = nullptr)
      : name(name), type(type), children(), parent(parent)
  {
  }
  NTree(const char *name, FileType type, NTree *parent = nullptr)
      : name(name), type(type), children(), parent(parent)
  {
  }
  NTree *move(std::string &path)
  {
    return move_impl(this, path);
  }

  void add(std::string &name, FileType fileType)
  {
    add_impl(this, name, fileType);
  }

  void print()
  {
  }

private:
  void print_impl(NTree *start)
  {
  }
  void add_impl(NTree *start, std::string &name, FileType fileType)
  {
    start->children.push_back(NTree(name, fileType, start));
  }
  NTree *move_impl(NTree *start, std::string &path)
  {
    std::istringstream ss(path);
    std::string buffer;
    auto current = start;
    while (getline(ss, buffer, '/'))
    {
      if (buffer.compare("."))
        continue;
      if (buffer.compare(".."))
        current = current->parent;
      else
      {
        auto v = std::find_if(current->children.begin(), current->children.end(), [&](NTree &first)
                              { return first.name.compare(buffer) == 0; });
        if (v != current->children.end())
          current = &(*v);
        else
          return nullptr;
      }
      return current;
    }
  }
};

int main()
{
  auto file_system = new NTree("/", FileType::FOLDER_TYPE);
  auto current = file_system;

  return 0;
}