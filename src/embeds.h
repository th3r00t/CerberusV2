// embeds.h
#ifndef MAKE_EMBED_H
#define MAKE_EMBED_H
#include <dpp/message.h>
#include <string>
namespace embeds
{
  class Embed_object
  {
    public:
      dpp::embed system_embed( 
        std::string title,
        std::string url,
        std::string description,
        std::string thumbnail,
        std::string image
      );
  };
}
#endif
