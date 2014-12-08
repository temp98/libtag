#include "marginManager.h"
#include "marginPopup.h"
#include "marginCell.h"
#include "clickablePopup.h"
#include "whisperPopup.h"
#include "chatBalloon.h"
#include "nametag.h"
#include "nametag2d.h"
#include "nametag3d.h"
#include "nametagFloat2d.h"
#include "nametagFloat3d.h"
#include "nametagGroup.h"

#include <pandabase.h>
#include <dconfig.h>

void init_libtag();

Configure(config_tag);

ConfigureFn(config_tag)
{
    init_libtag();
}

void init_libtag()
{
  static bool initialized = false;
  if (initialized)
    return;

  initialized = true;

  MarginManager::init_type();
  MarginPopup::init_type();
  MarginCell::init_type();
  ClickablePopup::init_type();
  WhisperPopup::init_type();
  ChatBalloon::init_type();
  Nametag::init_type();
  Nametag2d::init_type();
  Nametag3d::init_type();
  NametagFloat2d::init_type();
  NametagFloat3d::init_type();
  NametagGroup::init_type();
}
