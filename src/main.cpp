#include "embeds.h"
#include "nlohmann/json.hpp"
#include <dpp/appcommand.h>
#include <dpp/colors.h>
#include <dpp/dispatcher.h>
#include <dpp/dpp.h>
#include <dpp/message.h>
#include <dpp/nlohmann/json_fwd.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
using namespace std;
using namespace dpp;
using namespace embeds;
using json = nlohmann::json;

static uint32_t color;
string title;
string url;
string author;
string description;
string thumbnail;
string image;
Embed_object _embed;
string BOT_TOKEN =
    "OTkxMTI1MTYyMDM0NDYyNzMw.G6CGnr.af39SlbOaDd6tc04ruAl7CdV2blXdlVTf3D7Qk";
json gamedata(std::string _file) {
  std::ifstream _fp;
  _fp.open(_file, std::ifstream::in);
  /* char c = _fp.get();
    //  NOTE: This is how you print character by character
    // https://m.cplusplus.com/reference/fstream/ifstream/open/
   while (_fp.good()) {
     std::cout << c;
     c = _fp.get();
  } */
  // NOTE: This is how you read a file into a string.
  // https://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c
  std::string _container((std::istreambuf_iterator<char>(_fp)),
                         (std::istreambuf_iterator<char>()));
  // std::cout << _container << endl;
  json data = json::parse(_container);
  return data;
}
json factiondata(std::string _file) {
  std::ifstream _fp;
  _fp.open(_file, std::ifstream::in);
  std::string _container((std::istreambuf_iterator<char>(_fp)),
                         (std::istreambuf_iterator<char>()));
  json data = json::parse(_container);
  return data;
}
json playerdata(std::string _file) {
  std::ifstream _fp;
  _fp.open(_file, std::ifstream::in);
  std::string _container((std::istreambuf_iterator<char>(_fp)),
                         (std::istreambuf_iterator<char>()));
  json data = json::parse(_container);
  return data;
}
json moddata(std::string _file) {
  std::ifstream _fp;
  _fp.open(_file, std::ifstream::in);
  std::string _container((std::istreambuf_iterator<char>(_fp)),
                         (std::istreambuf_iterator<char>()));
  json data = json::parse(_container);
  return data;
}
dpp::embed Embed_object::system_embed(string title, string url,
                                      string description, string thumbnail,
                                      string image) {
  color = dpp::colors::cinnabar;
  title = title;
  url = url;
  description = description;
  thumbnail = thumbnail;
  /* dpp::embed_footer().set_text("Some footer text
   * here").set_icon("https://dpp.dev/DPP-Logo.png"); */
  string footer = "this is just a test";
  return embed()
      .set_color(color)
      .set_title(title)
      .set_url(url)
      .set_description(description)
      .set_thumbnail(thumbnail)
      .set_image(image)
      .set_timestamp(time(0))
      .set_author("th3r00t", "https://github.com/th3r00t",
                  "https://avatars.githubusercontent.com/u/5428538?v=4")
      .set_footer(dpp::embed_footer()
                      .set_text("SeDiver by: th3r00t")
                      .set_icon("https://external-content.duckduckgo.com/iu/"
                                "?u=https%3A%2F%2Fwallpaperaccess.com%2Ffull%"
                                "2F4862681.jpg&f=1&nofb=1"));
}

int main() {
  json _sdata = gamedata("Sandbox.json");
  cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);
  bot.on_log(utility::cout_logger());

  bot.on_slashcommand([&](const slashcommand_t event) {
    if (event.command.get_command_name() == "ping") {
      event.reply("Pong!");
    }
    if (event.command.get_command_name() == "factions") {
      std::string _reply;
      std::string _str;
      _str = _str + "I have the following factions on file.\n";
      json _fdata = factiondata("factions.json");
      for (auto &[key, val] : _fdata.items()) {
        _str = _str + "`" + to_string(val["tag"]) + ": " +
               to_string(val["name"]) + "`\n";
      }
      event.reply(_str);
    }
    if (event.command.get_command_name() == "players") {
      std::string _reply;
      std::string _str;
      _str = _str + "I have the following players on file.\n";
      json _pdata = playerdata("players.json");
      for (auto &[key, val] : _pdata.items()) {
        _str = _str + "`" + to_string(val["lastlogin"]) + ": " +
               to_string(val["name"]) + "`\n";
      }
      event.reply( _str);
    }
    if (event.command.get_command_name() == "mods") {
      json _mdata = moddata("mods.json");
      event.reply("Pong!");
    }
  });
  bot.on_message_create([&bot](const dpp::message_create_t &event) {
    if (event.msg.content == "!about") {
      dpp::embed about =
          _embed.system_embed("-- SeDiver --", "http://home.mylt.dev",
                              "A C++ based discord link into Space Engineers",
                              "https://external-content.duckduckgo.com/iu/"
                              "?u=https%3A%2F%2Fwallpaperaccess.com%2Ffull%"
                              "2F4862681.jpg&f=1&nofb=1",
                              "https://external-content.duckduckgo.com/iu/"
                              "?u=https%3A%2F%2Fwallpaperaccess.com%2Ffull%"
                              "2F4862681.jpg&f=1&nofb=1");
      about.add_field("List Commands", "!commands");
      bot.message_create(dpp::message(event.msg.channel_id, about)
                             .set_reference(event.msg.id));
    }
    if (event.msg.content == "!commands") {
      dpp::embed about =
          _embed.system_embed("Commands", "http://home.mylt.dev", "",
                              "https://external-content.duckduckgo.com/iu/"
                              "?u=https%3A%2F%2Fwallpaperaccess.com%2Ffull%"
                              "2F4862681.jpg&f=1&nofb=1",
                              "https://external-content.duckduckgo.com/iu/"
                              "?u=https%3A%2F%2Fwallpaperaccess.com%2Ffull%"
                              "2F4862681.jpg&f=1&nofb=1");
      about.add_field("About", "!about");
      about.add_field("List Commands", "!commands");
      bot.message_create(dpp::message(event.msg.channel_id, about)
                             .set_reference(event.msg.id));
    }
  });
  // Register Commands
  bot.on_ready([&bot](const ready_t &event) {
    if (run_once<struct register_bot_commands>()) {
      bot.global_command_create(slashcommand("ping", "Ping pong!", bot.me.id));
      bot.global_command_create(slashcommand(
          "factions", "Output faction data.", bot.me.id));
        bot.global_command_create(slashcommand(
                "players", "Output player data.", bot.me.id));
    }
  });
  bot.start(st_wait);
}
