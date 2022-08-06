// gameobjects.h
#ifndef MAKE_EMBED_H
#define MAKE_EMBED_H
#include <fstream>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
using json = nlohmann::json;

namespace gameobjects {
  class gameobjects
  {
    private:
      std::ifstream file;
      json data;

    public:
      json parse_file(std::ifstream file){ return data; }
  };
}
#endif
